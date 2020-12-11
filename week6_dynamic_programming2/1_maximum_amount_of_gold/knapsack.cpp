#include <iostream>
#include <vector>
#include <algorithm> 

using std::vector;


int optimal_weight(unsigned long W, const vector<unsigned long> &w) {
  // create matrix for storing weights
  vector<vector<unsigned long>> weights(w.size() + 1, vector<unsigned long> (W + 1, 0));

  for(size_t i = 0; i <= w.size(); i++){
    for(size_t j = 0; j <= W; j++){
      if(i == 0 || j == 0)
        weights[i][j] = 0;
      else if(w[i-1] <= j)
        weights[i][j] = std::max(w[i -1] + weights[i - 1][j - w[i - 1]], weights[i - 1][j]);
      else
        weights[i][j] = weights[i - 1][j];
    }
  }
  int max_weight = weights[w.size()][W];

  return max_weight;
}

int main() {
  unsigned long n, W;
  std::cin >> W >> n;
  vector<unsigned long> w(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
