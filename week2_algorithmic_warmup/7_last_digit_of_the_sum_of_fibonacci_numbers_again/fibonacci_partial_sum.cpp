#include <iostream>
#include <vector>
using std::vector;


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

long long get_fibonacci_partial_sum(long long from, long long to) {
    long long piasno_period_10 = get_pisano_period(10);
    int last_digit_from = get_fibonacci_last_digit((from + 1) % piasno_period_10);
    int last_digit_to = get_fibonacci_last_digit((to + 2) % piasno_period_10);
    return (10 + last_digit_to - last_digit_from) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
