#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string> &result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query> &queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
//    vector<Query> contacts;
    const int max_7_digits = 9999999;
    vector<string> A;
    const string not_initialized = "not initialized";

    for (int i = 0; i < max_7_digits; i++) {
        A.push_back(not_initialized);
    }

    for (size_t i = 0; i < queries.size(); ++i) {
        if (queries[i].type == "add") {
            // if it's already present, update it
            // otherwise, update it :)
            A[queries[i].number] = queries[i].name;
        } else if (queries[i].type == "del") {
            A[queries[i].number] = not_initialized;
        } else {
            string response = "not found";
            if (A[queries[i].number] != not_initialized) {
                response = A[queries[i].number];
            }
            result.push_back(response);
        }
    }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
