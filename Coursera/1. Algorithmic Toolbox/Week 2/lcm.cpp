#include <iostream>


int euclidGCD (long a, long b) {
    if (b == 0) return a;
    return euclidGCD(b, a%b);
}

long long lcm(long long a, long long b) {
    return (a * b)/euclidGCD(a, b);
}

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}
