#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> fast_count_segments(vector<std::pair<int,int>> &seg, vector<int> points) {
  std::sort(seg.begin(), seg.end());
  vector<int> cnt(points.size());
  size_t k;
  for(size_t i = 0; i < points.size(); i++) {
    k = 0;
    for(size_t j = 0; j < seg.size(); j++) {
      if(points[i] >= seg[j].first && points[i] <= seg[j].second)   k++;
      else if(points[i] < seg[j].first)   j = seg.size();
    }
    cnt[i] = k;
  }
  return cnt;
}

int main() {
  size_t n, m, seg_start, seg_end;
  std::cin >> n >> m;
  vector<std::pair<int,int>> seg(n);
  for (size_t i = 0; i < seg.size(); i++) {
    std::cin >> seg_start >> seg_end;
    seg[i] = std::make_pair(seg_start, seg_end);
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(seg, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
