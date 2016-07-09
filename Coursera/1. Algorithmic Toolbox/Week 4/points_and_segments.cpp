#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

struct Segment {
    long long position;
    char type;
};

size_t binary_search(const vector<long long> &a, long long x) {
    int left = 0, right = (int) a.size();

    while (left <= right) {
        int mid = (left + right) / 2;
        int key = a[mid];

        if (key == x) { return mid; }
        else if (key > x) { right = mid - 1; }
        else { left = mid + 1; }
    }

    return -1;
}

vector<long long> fast_count_segments(vector<long long> starts, vector<long long> ends, vector<long long> points) {
    vector<long long> cnt(points.size()); // to return the count of segments containg the points
    vector<Segment> segments;
    // put all the starting segments in the vector
    for (size_t i = 0; i < starts.size(); i++) {
        Segment s;
        s.position = starts[i];
        s.type = 'l';
        segments.push_back(s);
    }
    // put all the ending segments in the vector
    for (size_t i = 0; i < ends.size(); i++) {
        Segment s;
        s.position = ends[i];
        s.type = 'r';
        segments.push_back(s);
    }
    // put all the points in the vector
    for (size_t i = 0; i < points.size(); i++) {
        Segment s;
        s.position = points[i];
        s.type = 'p';
        segments.push_back(s);
    }

    // sort it such that positions are in ascending order, if equal, sort them
    // according to the type of the segment i-e l, p, r
    std::sort(segments.begin(), segments.end(), [](Segment a, Segment b) {
        if (a.position == b.position) return a.type < b.type;
        return a.position < b.position;
    });


    vector<long long> sortedPoints = points; // for binary search
    std::sort(sortedPoints.begin(), sortedPoints.end()); // sorting
    vector<long long> srtPntCnt(sortedPoints.size()); // to store the count of sorted points
    long long numSegment = 0; // to keep track of the segments up to a point i-e i
    size_t pIndex = 0; //
    for (size_t i = 0; i < segments.size(); i++) {
        if (segments[i].type == 'p') {
            srtPntCnt[pIndex] = numSegment;
            ++pIndex;
        } else if (segments[i].type == 'l') {
            numSegment++;
        } else {
            --numSegment;
        }
    }

    // outputting in the order the points were inputted
    for (int i = 0; i < points.size(); i++) {
        size_t index = binary_search(sortedPoints, points[i]); // find the index of the point
        cnt[i] = srtPntCnt[index]; // store the value using that index
    }

    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
//    n = 50000, m = 50;
    vector<long long> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        std::cin >> starts[i] >> ends[i];
//        starts[i] = 100000000;
//        ends[i] = 100000000;
    }
    vector<long long> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        std::cin >> points[i];
//        points[i] = 100000000;
    }
    //use fast_count_segments
    vector<long long> cnt = fast_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++) {
        std::cout << cnt[i] << ' ';
    }
}
