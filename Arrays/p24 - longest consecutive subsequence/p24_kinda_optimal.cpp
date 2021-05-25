#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(n)
int findLongestConseqSubseq(int input[], int length)
{
  unordered_set<int> myset;
  for(int i=0; i<length; i++) { // insert all array elements to set
    myset.insert(input[i]);
  }

  int min_lim, max_lim;
  int max_subseq_len = 0;
  for(int i=0; i<length; i++) {
    if(input[i] >= min_lim && input[i] <= max_lim && i!=0) {
      continue;
    } else {
      int current = input[i];
      int current_min, current_max;
      int current_subseq_length = 1;
      int temp = current - 1; // to left side
      while(myset.find(temp) != myset.end()) { // check left length
        current_subseq_length++;
        if(temp == max_lim) { // to avoid unnecessary iterations
          current_min = min_lim;
          break;
        }
        temp--;
      }
      current_min = temp+1;
      temp = current + 1; // to right side
      while(myset.find(temp) != myset.end()) {
        current_subseq_length++;
        if(temp == min_lim) { // to avoid unnecessary iterations
          current_max = max_lim;
        }
        temp++;
      }
      current_max = temp-1;
      if(current_subseq_length > max_subseq_len) {
        max_subseq_len = current_subseq_length;
        max_lim = current_max;
        min_lim = current_min;
      }
    }
  }
  return max_subseq_len;
}

int main() {
  int input[] = {2,6,1,9,4,5,3};
  int length = sizeof(input)/sizeof(input[0]);
  cout << findLongestConseqSubseq(input, length) << endl;
}