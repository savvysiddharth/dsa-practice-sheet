#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> input) {
  int length = input.size();
  cout << "VectorContent: [ ";
  for(int i=0; i<length; i++) {
    cout << input[i];
    if(i != length-1) cout << ",";
    cout << " ";
  }
  cout << "]" << endl;
}

// Kadane's Algorithm
// Time Complexity - O(n)
// Space Complexity - O(1)
int maxSubarraySum(vector<int> input) {
  int len = input.size();
  if(len == 0) return 0;
  int MAX, previous, current;
  MAX = previous = input[0];
  for(int i=1; i<len; i++) {
    current = max(input[i], input[i]+previous);
    previous = current;
    if(current > MAX) MAX = current;
  }
  return MAX;
}

int main() {
  vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
  printVector(input);
  
  int ans = maxSubarraySum(input);
  cout << "Max Subarray Sum: " << ans << endl;
}