// Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp; 
}

void printArray(int input[], int n) {
  cout << "ArrayStatus: [ ";
  for(int i=0; i<n; i++) {
    cout << input[i] << " ";
  }
  cout << "]" << endl;
}

// IDEA: put 0s and 2s to it's proper position and 1s will be automatically handled by product of managing 0s and 2s.
// Time Complexity: O(n)
void sort012(int input[], int len) {
  if(len <= 1) return;
  int i = -1; // maintains list of 0's (numbers on this index and before this index are 0s)
  int j = len; // maintains list of 2's (number on this index and after this index are 2s)
  int k = 0; // scans through all elements
  while(k < j) {
    if(input[k] == 0) {
        swap(&input[i+1], &input[k]);
        i++; k++;
    } else if(input[k] == 2) {
      swap(&input[j-1], &input[k]);
      j--;
    } else { // input[k] == 1
      k++;
    }
  }
}

int main() {
  int input[] = {0, 2, 1, 2, 0};
  int len = sizeof(input)/sizeof(int);
  printArray(input,len);
  sort012(input,len);
  printArray(input,len);
}