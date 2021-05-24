// Not retaining order of appearance
#include <bits/stdc++.h>
using namespace std;

void printArray(int input[], int length) {
  cout << "ArrayContent: [ ";
  for(int i=0; i<length; i++) {
    cout << input[i];
    if(i != length-1) cout << ",";
    cout << " ";
  }
  cout << "]" << endl;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
void rearrangeNegPos(int input[], int length) {
  int i = 0; // increase by one step
  int j = 0; // increases by two step, when it is supposed to (tracks negative nums)
  while(i < length && j < length) {
    if(input[i] < 0) {
      int temp = input[j];
      input[j] = input[i];
      input[i] = temp;
      j += 2;
    } else {
      i++;
    }
  }
}

int main() {
  int arr[] = {1, 2, 3, -4, -1, 4};
  int len = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, len);
  rearrangeNegPos(arr, len);
  printArray(arr, len);
}