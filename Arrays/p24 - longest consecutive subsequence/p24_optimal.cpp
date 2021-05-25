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

  int max_subseq_len = 0;
  for(int i=0; i<length; i++) {
    if(myset.find(input[i]-1) == myset.end()) { // do the sequence counting only if current element is starting integer of the sequence
      int current_subseq_length = 1;
      int temp = input[i] + 1;
      while(myset.find(temp) != myset.end()) {
        current_subseq_length++;
        temp++;
      }
      if(current_subseq_length > max_subseq_len) max_subseq_len = current_subseq_length;
    }
  }
  return max_subseq_len;
}

int main() {
  int input[] = {2,6,1,9,4,5,3};
  int length = sizeof(input)/sizeof(input[0]);
  cout << findLongestConseqSubseq(input, length) << endl;
}