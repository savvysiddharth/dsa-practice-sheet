#include <bits/stdc++.h>
using namespace std;

int minSwap(int *input, int length, int k) {
    int totalCount = 0; // count of all elements less than or equal to k
    int currentConsecutive = 0;
    for(int i=0; i<length; i++) {
      if(input[i] <= k) totalCount++;
    }
    // creating a sliding window
    int start = 0, end = totalCount-1; // window of length equal to "totalCount"
    int minBadCount = length+1; // elements that are greater than k
    int currentBadCount = 0;
    for(int i = start; i<= end; i++) { // counting bad numbers in first window
      if(input[i] > k) currentBadCount++;
    }
    if(currentBadCount < minBadCount) minBadCount = currentBadCount;

    // keep sliding the window by 1 step, and count bad elements
    // window with the smallest bad count is the answer
    for(int i=start+1, j=end+1; j<length; i++,j++) {
      if(input[i-1] > k) currentBadCount--;
      if(input[j] > k) currentBadCount++;
      if(currentBadCount < minBadCount) minBadCount = currentBadCount;
    }

    return minBadCount;
}

int main() {
              //  0   1   2   3   4   5   6   7   8   9  10
  // int input[] = {10, 12, 20, 20,  5, 19, 19, 12,  1, 20,  1};
  int input[] = {4, 3};
  int length = sizeof(input)/sizeof(input[0]);
  int k = 11;
  cout << minSwap(input, length, k) << endl;
}