#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};
// function for sorting segments
bool segment_sorter(Segment const& lhs, Segment const& rhs) {
    return lhs.end < rhs.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  // sort segments based on right end position; from lower right end position to higher right end position
  std::sort(segments.begin(), segments.end(), &segment_sorter);
  
  vector<int> points;
  int point = segments[0].end;
  points.push_back(point);

  for(size_t i = 1; i < segments.size(); i++) {
    if(point < segments[i].start || point > segments[i].end) {
      point = segments[i].end;
      points.push_back(point);
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << "\n";
}
