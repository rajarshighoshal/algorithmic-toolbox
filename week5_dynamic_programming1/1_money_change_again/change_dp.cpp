#include <iostream>
#include <limits>

int get_change(int m, int coins[], int len_coins) {
  int min_num_coins[m+1];
  min_num_coins[0] = 0;
  if(m == 0)
    return 0;
  for(int i = 1; i <= m; i++) {
    min_num_coins[i] = std::numeric_limits<int>::max();
    for(int j = 0; j < len_coins; j++) {
      if(i >= coins[j]) {
        int num_coins = min_num_coins[i - coins[j]] + 1;
        if(num_coins < min_num_coins[i])
          min_num_coins[i] = num_coins;
      }
    }
  }
  return min_num_coins[m];
}

int main() {
  int m;
  int coins[] = {1, 3, 4};
  int len_coins = sizeof(coins)/sizeof(coins[0]);
  std::cin >> m;
  std::cout << get_change(m, coins, len_coins) << '\n';
}
