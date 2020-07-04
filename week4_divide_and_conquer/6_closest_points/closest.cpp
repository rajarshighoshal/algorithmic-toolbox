#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using std::vector;
using std::string;
using std::pow;
using std::min;
using std::sqrt;


double minimal_distance(vector<std::pair<int,int>> &points, size_t left, size_t right) {
  if((right - left) <= 3) {
    double min_dist = std::numeric_limits<double>::max();
    for(size_t i = left; i < right - 1; i++) {
      for(size_t j = i+1; j < right; j++) {
        double dist = sqrt(pow((points[i].first - points[j].first), 2) + pow((points[i].second - points[j].second), 2)); 
        if(dist < min_dist)   min_dist = dist;
        }
      }
    return min_dist;
  }

  size_t mid = left + (right - left) / 2;
  double left_min = minimal_distance(points, left, mid);
  double right_min = minimal_distance(points, mid, right);
  double min_dist = min(left_min, right_min);

  vector<std::pair<int,int>> reminaing_points;
  for(size_t i = left; i < right; i++) {
    if(std::abs(points[i].first - points[mid].first) <= min_dist)    reminaing_points.push_back(std::make_pair(points[i].first, points[i].second));
  }
  std::sort(reminaing_points.begin(), reminaing_points.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
    return left.second < right.second;
});
  for(size_t i = 0; i < reminaing_points.size() - 1; i++) {
      for(size_t j = i+1; j < min(i+9, reminaing_points.size()); j++) {
        double dist = sqrt(pow((reminaing_points[i].first - reminaing_points[j].first), 2) + pow((reminaing_points[i].second - reminaing_points[j].second), 2)); 
        if(dist < min_dist)   min_dist = dist;
        }
      }

  return min_dist;
}

int main() {
  size_t n;
  std::cin >> n;
  int x, y;
  vector<std::pair<int,int>> points(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x >> y;
    points[i].first = x;
    points[i].second = y;
  }
  std::sort(points.begin(), points.end());
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points, 0, points.size()) << "\n";
}
