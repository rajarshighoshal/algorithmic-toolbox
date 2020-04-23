#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;


int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);
    int num_refills = 0;
    int current_refill = 0;
    while(current_refill <= stops.size()) {
        int last_refill = current_refill;
        while(current_refill <=  stops.size() && (stops[current_refill+1] - stops[last_refill]) <= tank) 
            current_refill++;
        if(current_refill == last_refill)
            return -1;
        if (current_refill <=  stops.size())
            num_refills++;
    }
    return num_refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
