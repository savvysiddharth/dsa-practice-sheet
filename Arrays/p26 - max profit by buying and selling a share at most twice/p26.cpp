#include <bits/stdc++.h>
using namespace std;

void printArray(int input[], int length) {
  cout << "ArrayContent: [ ";
  for(int i=0; i<length; i++) {
    cout << input[i];
    if(i != length-1) cout << ",";
    cout << " ";
  }
  cout << "]" << endl;
}


int maxProfit_atmost_two_transactions(int input[], int length) {
  int max_profits_left[length]; // stores max profits at left of each index, including current index
  int min_price = input[0]; // min price seen till now (on left)
  max_profits_left[0] = 0;
  int max_on_left = 0;
  for(int i=1; i<length; i++) {
    int current_profit; // max profit right now (if we sell today) 0....i
    if(input[i] > min_price) {
      current_profit = input[i] - min_price;
      if(current_profit > max_on_left) max_on_left = current_profit;
    } else {
      min_price = input[i];
      current_profit = 0;
    }
    max_profits_left[i] = max(current_profit, max_on_left);
  }
  
  printArray(max_profits_left, length);

  int global_max = max_profits_left[length-1];
  int max_price = input[length-1]; // max price seen until now (on right)
  int max_on_right = 0;
  for(int i=length-2; i >= 0; i--) {
    int current_profit = max(max_price - input[i], 0); // maximum profit that we can do now (if we buy today) i...n-1
    if(input[i] > max_price) max_price = input[i];
    int current_total_profit = max_profits_left[i] + current_profit;
    if(current_total_profit > global_max) global_max = current_total_profit;
  }

  // cout << "answer: " << global_max << endl;

  return global_max;
}


int main() {
  int input[] = {2, 30, 15, 10, 8, 25, 80};
  int length = sizeof(input)/sizeof(input[0]);
  printArray(input, length);
  int answer = maxProfit_atmost_two_transactions(input, length);
  cout << "result: " << answer << endl;
}

