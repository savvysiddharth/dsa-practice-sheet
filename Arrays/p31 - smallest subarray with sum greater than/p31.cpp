#include <bits/stdc++.h>
using namespace std;

int sb(int input[], int length, int target) {
  int start = 0;
  int end = 0;
  int currentSum = 0;
  bool expand = true;
  int minLength = length + 1;
  while(end < length) {
    if(expand) currentSum += input[end];
    else currentSum -= input[start-1];
    if(currentSum > target) {
      minLength = min(minLength, end-start+1);
      expand = false; // shrink
      start++;
    } else {
      expand = true;
      end++;
    }
  }
  return minLength;
}

int main() {
  int input[] = {1, 10, 5, 2, 7};
  int length = sizeof(input)/sizeof(input[0]);
  int target = 9;
  cout << "result: " << sb(input,length,target) << endl;
}