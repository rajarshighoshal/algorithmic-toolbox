#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
  int n = str1.size();
  int m = str2.size();
  // distance matrix for distance between each word of two strings
  int dist_matrix[n+1][m+1];
  
  for(int i = 0; i < n+1; i++) {
    for(int j = 0; j < m+1; j++) {
      if(i == 0)
        dist_matrix[i][j] = j;
      else if(j == 0)
        dist_matrix[i][j] = i;
      else if(str1[i-1] == str2[j-1])
        dist_matrix[i][j] = dist_matrix[i-1][j-1];
      else
        dist_matrix[i][j] = std::min(std::min(dist_matrix[i][j-1], dist_matrix[i-1][j]), dist_matrix[i-1][j-1]) + 1;
    }
  }
  return dist_matrix[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
