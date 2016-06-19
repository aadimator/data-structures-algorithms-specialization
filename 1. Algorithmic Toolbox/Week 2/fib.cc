#include <iostream>

int calc_fib(int n) {
    if (n <= 1)
        return n;

    return calc_fib(n - 1) + calc_fib(n - 2);
}


long long calc_fib_faster (int n) {
    long long arr [n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}


int main() {
    int n = 0;
    std::cin >> n;

//    std::cout << calc_fib(n) << std::endl;
    std::cout << calc_fib_faster(n) << std::endl;
    return 0;
}
