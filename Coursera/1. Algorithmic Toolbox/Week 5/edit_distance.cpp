#include <iostream>
#include <vector>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
    // 2D vector : row = length(str1) + 1; column = length(str2) + 1; as to include the last element also
    vector<vector<int>> D(str1.size() + 1, vector<int>(str2.size() + 1));
    // fill first column
    for (int i = 0; i < D.size(); i++) {
        D[i][0] = i;
    }
    // fill first row
    for (int j = 0; j < D[0].size(); j++) {
        D[0][j] = j;
    }

    for (int j = 1; j < D[0].size(); j++) {
        for (int i = 1; i < D.size(); i++) {
            int insertion = D[i][j - 1] + 1;
            int deletion = D[i - 1][j] + 1;
            int match = D[i - 1][j - 1];
            int mismatch = D[i - 1][j - 1] + 1;

            // assign the minimum value to D[i][j]; used [i - 1] because we are using i as 1 based index array
            // while strings are 0 based in C++
            D[i][j] = std::min(std::min(insertion, deletion), str1[i - 1] == str2[j - 1] ? match : mismatch);
        }
    }
    // For printing the table
//    for (int i = 0; i < D.size(); i++) {
//        for (int j = 0; j < D[i].size(); j++) {
//            std::cout << D[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
    return D[str1.size()][str2.size()];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
