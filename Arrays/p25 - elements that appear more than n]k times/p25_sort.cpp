#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(nLogn)
// Space Complexity : O(1)
int countOccurence(int input[], int &length, int &k) {
  sort(input, input+length);
  int count = 0;
  int target = length/k;
  int curr_num = input[0];
  int curr_len = 1;
  for(int i=1; i<length; i++) {
    if(input[i] == curr_num) {
      curr_len++;
      if(curr_len > target) count++;
    } else {
      curr_num = input[i];
      curr_len = 1;
    }
  }
  return count;
}

int main() {
  int input[] = {3,1,2,2,1,2,3,3};
  int length = sizeof(input)/sizeof(input[0]); 
  int k = 4;
  cout << countOccurence(input, length, k) << endl;
}