#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
private:
    vector<int> data_;
    vector<pair<int, int> > swaps_;

    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> data_[i];
    }

    int LeftChild(int i) {
        return (2 * i) + 1;
    }

    int RightChild(int i) {
        return (2 * i) + 2;
    }

    void SiftDown(int i) {
        int minIndex = i;
        int left = LeftChild(i);
        if (left < data_.size() && data_[left] < data_[minIndex])
            minIndex = left;

        int right = RightChild(i);
        if (right < data_.size() && data_[right] < data_[minIndex])
            minIndex = right;

        if (i != minIndex) {
            swap(data_[i], data_[minIndex]);
            swaps_.push_back(make_pair(i, minIndex));
            SiftDown(minIndex);
        }
    }

    void GenerateSwaps() {
        swaps_.clear();
        // The following naive implementation just sorts
        // the given sequence using selection sort algorithm
        // and saves the resulting sequence of swaps.
        // This turns the given array into a heap,
        // but in the worst case gives a quadratic number of swaps.
        //
        // replace by a more efficient implementation
//    for (int i = 0; i < data_.size(); ++i)
//      for (int j = i + 1; j < data_.size(); ++j) {
//        if (data_[i] > data_[j]) {
//          swap(data_[i], data_[j]);
//          swaps_.push_back(make_pair(i, j));
//        }
//      }

        for (int i = data_.size() / 2; i >= 0; i--) {
            SiftDown(i); // storing the swap pairs in this func
        }

    }

public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
