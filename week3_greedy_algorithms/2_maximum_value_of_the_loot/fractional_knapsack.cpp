#include <iostream>
#include <algorithm> 
#include <functional> 
#include <vector>

using std::vector;

double get_optimal_value(int n, int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<std::pair<double,int>> value_per_unit(n); 
  for(int i = 0; i < n; i++) {
    value_per_unit[i].first = double(values[i])/double(weights[i]);
    value_per_unit[i].second = weights[i];
  }
  // sort from highest vale per unit to lowest value per unit
  std::sort(value_per_unit.begin(), value_per_unit.end(), std::greater<std::pair<double,int>>());
  for(int i = 0; i < n && capacity > 0; i++) {
    value += std::min(value_per_unit[i].second, capacity) * value_per_unit[i].first;
    capacity -= std::min(value_per_unit[i].second, capacity);
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n, capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
