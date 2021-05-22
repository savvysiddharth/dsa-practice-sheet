#include <bits/stdc++.h>
using namespace std;


// Array Preprocessing method
// Time Complexity : O(n)
// Space Complexity : O(n)
int trappingWater(int input[], int length) {
  int left[length];
  int right[length];
  // Preparing left and right arrow
  for(int i=0; i<length; i++) {
    if(i-1 >= 0) left[i] = max(input[i], left[i-1]);
    else left[i] = input[i]; // happens at i=0
  }
  for(int i=length-1; i>=0; i--) {
    if(i+1 <= length-1) right[i] = max(input[i], right[i+1]);
    else right[i] = input[i]; //happens at i=length-1
  }
  
  int totalWater = 0;
  for(int i=0; i<length; i++) {
    int maxFillableHeight = min(left[i], right[i]);
    int waterCanBeFilled = maxFillableHeight - input[i];
    if(waterCanBeFilled > 0) totalWater += waterCanBeFilled;
  }
  return totalWater;
}

int main() {
  int input[] = {3,0,0,2,0,4};
  int length = sizeof(input)/sizeof(input[0]);
  // cout << "aaa";
  cout << trappingWater(input, length) << endl;
}