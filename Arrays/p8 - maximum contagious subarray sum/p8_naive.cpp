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

// Naive Algorithm / Bruteforce Method
// Time Complexity - O(n^2)
// Space Complexity - O(n)
int maxSubarraySum(vector<int> input) {
  int len = input.size();
  if(len == 0) return 0;
  int MAX = input[0];
  int lastSum, currentSum;
  for(int i=0; i<len; i++) { // i = starting index
    for(int j=i; j<len; j++) { // j = ending index
      if(j==i) currentSum = input[j];
      else currentSum = input[j] + lastSum;
      lastSum = currentSum;
      if(currentSum > MAX) MAX = currentSum;
    }
  }
  return MAX;
}

int main() {
  vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
  printVector(input);
  
  int ans = maxSubarraySum(input);
  cout << "Max Subarray Sum: " << ans << endl;
}