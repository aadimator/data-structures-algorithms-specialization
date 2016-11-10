#include <iostream>
#include <cassert>
#include <vector>
#include <limits>

using std::vector;
using std::string;
using std::max;
using std::min;

// Implemented the algorithm shows in video lecture

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}

void MinAndMax(long long i, long long j,
                    vector<vector<long long>> &m, vector<vector<long long>> &M,
                    vector<char> &op) {
    long long minimum = std::numeric_limits<long long>::max();
    long long maximum = std::numeric_limits<long long>::min();


    for (auto k = i; k < j; k++) {
        auto a = eval(M[i][k], M[k + 1][j], op[k]);
        auto b = eval(M[i][k], m[k + 1][j], op[k]);
        auto c = eval(m[i][k], M[k + 1][j], op[k]);
        auto d = eval(m[i][k], m[k + 1][j], op[k]);

        minimum = min(minimum, min(a, min(b, min(c, d))));
        maximum = max(maximum, max(a, max(b, max(c, d))));
    }
    m[i][j] = minimum;
    M[i][j] = maximum;
}

long long get_maximum_value(const string &exp) {
    // length(exp) is 2n + 1, so no. of digits is (length(exp)/2)
    auto digitsNum = exp.size() / 2 + 1;
    auto opNum = exp.size() / 2;
    vector<long long> d(digitsNum); // digits
    vector<char> op(opNum); // operators

    for (size_t i = 0, j = 0; i < d.size() && j < exp.size(); i++, j += 2) {
        d[i] = exp.at(j) - '0';
    }

    for (size_t i = 0, j = 1; i < op.size() && j < exp.size(); i++, j += 2) {
        op[i] = exp.at(j);
    }
    vector<vector<long long>> m(digitsNum, vector<long long>(digitsNum));
    vector<vector<long long>> M(digitsNum, vector<long long>(digitsNum));

    for (size_t i = 0; i < m.size(); i++) {
        m[i][i] = d[i];
        M[i][i] = d[i];
    }



    for (auto s = 1; s < digitsNum; s++) {
        for (auto i = 0; i < digitsNum - s; i++) {
            auto j = i + s;
            MinAndMax(i, j, m, M, op);
        }
    }

    return M[0][digitsNum - 1];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
