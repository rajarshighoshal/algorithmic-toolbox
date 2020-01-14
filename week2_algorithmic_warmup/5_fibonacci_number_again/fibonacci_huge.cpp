#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    return current;
}

long long get_pisano_period(long long m) {
    long long previous = 0;
    long long current  = 1;

    for(long long i=0;;i++) { 
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        if(previous == 0 & current == 1) {
            return i+1;
        }
    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    long long pisano_period = get_pisano_period(m);
    return get_fibonacci_huge_naive(n % pisano_period, m);
}


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
