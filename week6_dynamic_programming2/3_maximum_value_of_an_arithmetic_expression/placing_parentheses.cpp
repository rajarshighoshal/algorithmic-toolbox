#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
#include <tuple> 

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  // std::cout << a << " " << b << " " << op << '\n';
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

std::tuple<long long, long long> min_max(const vector<vector<long long>> &M, 
                                         const vector<vector<long long>> &m, 
                                         int i, int j, 
                                         const string &op) {
    long long min_val = LLONG_MAX;
	  long long max_val = LLONG_MIN;

    for(int k=i; k < j; k++) {
      long long a = eval(M[i][k], M[k+1][j], op[2*k+1]);
      long long b = eval(M[i][k], m[k+1][j], op[2*k+1]);
      long long c = eval(m[i][k], M[k+1][j], op[2*k+1]);
      long long d = eval(m[i][k], m[k+1][j], op[2*k+1]);
      min_val = min(min_val, min(a, min(b, min(c, d))));
      max_val = max(max_val, max(a, max(b, max(c, d))));
    }
    return std::make_tuple(min_val, max_val);
}

long long get_maximum_value(const string &exp) {
  int length = exp.size();
  int num_of_num = (length + 1) / 2;
  vector<vector<long long>> M(num_of_num, vector<long long> (num_of_num, 0));
  vector<vector<long long>> m(num_of_num, vector<long long> (num_of_num, 0));

  for (int i = 0; i < num_of_num; i++) {
    M[i][i] = std::stoll(exp.substr(2*i,1));
    m[i][i] = std::stoll(exp.substr(2*i,1));
  }

  for(int s = 0; s < num_of_num-1; s++) {
    for(int i = 0; i < num_of_num-1-s; i++) {
      int j = i + s + 1;
      std::tie(m[i][j], M[i][j]) = min_max(M, m, i, j, exp);
    }
  }
  
  return M[0][num_of_num-1];
}


int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
