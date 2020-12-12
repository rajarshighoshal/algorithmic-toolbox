#include <iostream>
#include <vector>

using std::vector;

int partition3(int w, int n, vector<int> &A) {
  if(n<3)
    return 0;
  else if(w%3 != 0)
    return 0;
  int count = 0;
  w  =  w/3;
  vector<vector<int>> values(w + 1, vector<int> (n + 1, 0));
  for(int i = 0; i < w+1; i++) {
    for(int j = 0; j < n+1; j++) {
      values[i][j] = values[i][j-1];
      if(A[j-1] <= i) {
        int temp = values[i-A[j-1]][j-1] + A[j-1];
        if(temp > values[i][j])
          values[i][j] = temp;
      }
      if(values[i][j] == w)
        count++;
    }
  }
  if(count < 3)
    return 0;
  return 1;
}

int main() {
  int n, total_weight = 0;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
    total_weight += A[i];
  }
  std::cout << partition3(total_weight, n, A) << '\n';
}
