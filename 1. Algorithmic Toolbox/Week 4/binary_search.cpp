#include <iostream>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
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

int linear_search(const vector<int> &a, int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x) return i;
    }
    return -1;
}

int main() {
    unsigned int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    unsigned int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cout << binary_search(a, b[i]) << ' ';
//        std::cout << linear_search(a, b[i]) << ' ';
//        std::cout << std::endl;
    }
}
