#include <iostream>

long long get_fibonacci_last_digit(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
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

int fibonacci_sum_squares(long long n) {
    long long piasno_period_10 = get_pisano_period(10);
    int sum = get_fibonacci_last_digit(n % piasno_period_10)* get_fibonacci_last_digit((n + 1) % piasno_period_10);
    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n) << std::endl;
}
