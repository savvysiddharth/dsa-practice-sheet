#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n^2)
// Space Complexity - O(1)
int buyAndSell(int input[], int length) {
  int maxProfit = 0;
  for(int i=0; i<length-1; i++) {
    for(int j=i+1; j<length; j++) {
      int profit = input[j] - input[i];
      if(profit > 0) { // profit is possible
        if(profit > maxProfit) maxProfit = profit;
      }
    }
  }
  return maxProfit;
}

int main() {
  int input[] = {7, 1, 5, 3, 6, 4};
  int len = sizeof(input)/sizeof(input[0]);
  cout << buyAndSell(input, len) << endl;
}