#include <iostream>
#include <vector>

int get_fibonacci_last_digit(long long n) {
    std::vector<int> fib_tbl(n+1);
    fib_tbl[0] = 0;
    fib_tbl[1] = 1;
    for(long long i=2; i <= n; i++) {
        fib_tbl[i] = (fib_tbl[i-1] + fib_tbl[i-2]) % 10;
    }
    return fib_tbl[n];
}

int main() {
    long long n;
    std::cin >> n;
    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
    }
