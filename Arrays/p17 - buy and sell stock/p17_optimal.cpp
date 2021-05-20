#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n)
// Space Complexity - O(1)
int buyAndSell(vector<int> &input) {
  int length;
  int maxProfit = 0;
  int min = input[0];
  for(int i=1; i<input.size(); i++) {
    if(input[i] - min > maxProfit) {
      maxProfit = input[i] - min;
    } else if(input[i] < min) {
      min = input[i];
    }
  }
  return maxProfit;
}

int main() {
  vector<int> input = {7, 1, 5, 3, 6, 4};
  cout << buyAndSell(input) << endl;
}