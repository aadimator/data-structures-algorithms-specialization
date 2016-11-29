#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
public:
    int bucket_count;
    // store all strings in one vector
    vector<vector<string>> elems;

    size_t hash_func(const string &s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

    explicit QueryProcessor(int bucket_count) : bucket_count(bucket_count) {
        elems.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void add(const string &S) {
        vector<string> list = elems[hash_func(S)];

        for (int i = 0; i < list.size(); i++) {
            if (list[i] == S) return;
        }

        list.insert(list.begin(), S);
        elems[hash_func(S)] = list; // set this new list back to the 2D list from before
    }

    void del(string S) {
        if (!find(S)) return;

        vector<string> list = elems[hash_func(S)];

        for (int i = 0; i < list.size(); i++) {
            if (list[i] == S) list.erase(list.begin() + i); // deleting when found
        }

        elems[hash_func(S)] = list; // reassigning the list
    }

    bool find(const string &S) {
        vector<string> list = elems[hash_func(S)];

        for (int i = 0; i < list.size(); i++) {
            if (list[i] == S) return true;
        }

        return false;
    }

    void check(size_t ind) {
        vector<string> list = elems[ind];
        for (int i = 0; i < list.size(); i++) {
            std::cout << list[i] << ' ';
        }

        std::cout << '\n';
    }

    void processQuery(const Query &query) {

        if (query.type == "check") {
            check(query.ind);
        }

        if (query.type == "add") {
            add(query.s);
        }

        if (query.type == "del") {
            del(query.s);
        }

        if (query.type == "find") {
            writeSearchResult(find(query.s));
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
