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

void cyclicRight(int input[], int i, int j) {
  int last = input[j];
  for(int k=j-1; k>=i; k--) {
    input[k+1] = input[k];
  }
  input[i] = last;
}

// Time Complexity : O(n^2)
// Space Complexity : O(1)
void rearrangeNegPos(int input[], int length) {
  int bad_index;
  for(int i=0; i<length; i++) {
    if(i%2 == 0) { // even index
      if(input[i] >= 0) {
        bad_index = i;
        int replacer_index = i+1;
        while(replacer_index < length && input[replacer_index] >= 0) {
          replacer_index++;
        }
        if(replacer_index < length) {
          cyclicRight(input, bad_index, replacer_index);
        }
      }
    } else { // odd index
      if(input[i] < 0) {
        bad_index = i;
        int replacer_index = i+1;
        while(replacer_index < length && input[replacer_index] < 0) {
          replacer_index++;
        }
        if(replacer_index < length) {
          cyclicRight(input, bad_index, replacer_index);
        }
      }
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