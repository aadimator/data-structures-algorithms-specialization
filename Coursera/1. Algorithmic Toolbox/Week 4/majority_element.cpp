#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int Voting(vector<int> &num) {
    int count = 0;
    int candidate = -1;

    for(int i = 0; i < num.size(); ++i) {
        if(count == 0) {
            candidate = num[i];
            count = 1;
        }
        else
            count = (candidate == num[i]) ? ++count : --count;
    }
    return candidate;
}

int get_majority_element(vector<int> &a, int left, int right) {
    int candidate = Voting(a);
    int count = 0;
    for (auto i : a) {
        if (i == candidate) ++count;
    }

    return (count > (a.size()/2)) ? candidate : -1;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
