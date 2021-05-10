#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
  bool flag = false;
  for(int i = nums.size()-2; i>=0; i--) {
    if(nums[i] < nums[i+1]) {
      flag = true;
      // imaginary split : (0, i) (i+1, end)
      sort(nums.begin() + i+1, nums.end());
      // swap n[i] and n[i+1], but...
      int leftIndex = i;
      int rightIndex = i+1; // to swap with

      while(nums[leftIndex] > nums[rightIndex]) {
        rightIndex++;
      }
      int temp = nums[leftIndex];
      nums[leftIndex] = nums[rightIndex];
      nums[rightIndex] = temp;
      return;
    }
  }
  if(!flag) sort(nums.begin(), nums.end());
}

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

int main() {
  vector<int> input = {2,3,1};
  printVector(input);
  nextPermutation(input);
  printVector(input);
}