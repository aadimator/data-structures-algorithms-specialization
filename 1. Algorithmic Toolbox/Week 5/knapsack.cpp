#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
    // Need to understand it later; copied it from another solution posted online
    vector<vector<int>> values(w.size() + 1, vector<int>((unsigned int) (W + 1)));

    for (int i = 1; i < values.size(); i++) {
        for (int j = 1; j < values[0].size(); j++) {
            values[i][j] =
                    w[i - 1] > j
                    ? values[i - 1][j]
                    : std::max(w[i - 1] + values[i - 1][j - w[i - 1]], values[i - 1][j]);
        }
    }
    return values[w.size()][W];
}

int main() {
    int W;
    unsigned int n;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
