#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  int n = a.size();
  int m = b.size();
  int l[n+1][m+1];
  for(int i = 0; i < n+1; i++) {
    for(int j = 0; j < m+1; j++) {
      if(i == 0 || j == 0)
        l[i][j] = 0;
      else if(a[i-1] == b[j-1])
        l[i][j] = l[i-1][j-1] + 1;
      else
        l[i][j] = std::max(l[i-1][j], l[i][j-1]);
    }
  }
  return l[n][m];
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
