// Move all the negative elements to one side of the array 
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

// Time Complexity: O(n)
void rearrange(int input[], int len) {
  int i=-1; // maintains list of negative numbers (numbers on this index and before this index are negative)
  int j=0; // scans through entire array
  while(j<len) {
    if(input[j] < 0) {
      if(j != i+1) {
        swap(&input[i+1], &input[j]);
      }
      i++;
    }
    j++;
  }
}

int main() {
  int input[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
  int len = sizeof(input)/sizeof(int);
  printArray(input, len);
  rearrange(input,len);
  printArray(input, len);
}