#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef long long ll;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<ll> &output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

ll PolyHash(const string &s, ll p, ll x) {
    ll hash = 0;
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (hash * x + s[i]) % p;
    return hash;
}

std::vector<long long> PreComputeHashes(const string &T, ll P_length, ll p, ll x) {
    ll T_P_length = (ll) (T.length() - P_length);
    std::vector<long long> H((unsigned long) (T_P_length + 1));
    string S = T.substr((unsigned long) T_P_length, (unsigned long) P_length);
    H[T_P_length] = PolyHash(S, p, x);

    ll y = 1;
    for (ll i = 1; i <= P_length; i++) {
        y = ((y * x) % p + p) % p;
    }
    for (long long i = T_P_length - 1; i >= 0; i--) {
        H[i] = ((x * H[i + 1] + T[i] - y * T[i + P_length]) % p + p) % p;
    }
    return H;
}

std::vector<ll> RabinKarp(const string &T, const string &P) {
    ll p = 500009;
    ll x = 139;
    std::vector<ll> result;
    ll pHash = PolyHash(P, p, x);
    std::vector<long long> H = PreComputeHashes(T, (ll) P.length(), p, x);

    for (ll i = 0; i <= T.length() - P.length(); i++) {
        if (pHash == H[i] && T.substr((unsigned long) i, P.length()) == P) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<ll> get_occurrences(const Data &input) {
    const string &s = input.pattern, t = input.text;
    std::vector<ll> ans;
    ans = RabinKarp(t, s);
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
