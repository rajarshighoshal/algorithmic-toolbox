#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dp_sequence(int n) {
  std::vector<int> sequence;
  std::vector<int>  num_ops(n+1);
  for(size_t i = 1; i < num_ops.size(); i++) {
    num_ops[i] = num_ops[i-1] + 1;
    if(i % 2 == 0)
      num_ops[i] = std::min(1 + num_ops[i/2], num_ops[i]);
    if(i % 3 == 0)
      num_ops[i] = std::min(1 + num_ops[i/3], num_ops[i]);
  }
  int i = n;
  while(i > 1) {
    sequence.push_back(i);
    if(num_ops[i - 1] == num_ops[i] - 1)
      i--;
    else if(i%2 == 0 && num_ops[i/2] == num_ops[i] - 1)
      i /= 2;
    else if(i%3 == 0 && num_ops[i/3] == num_ops[i] - 1)
      i /= 3;
  }
  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dp_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
