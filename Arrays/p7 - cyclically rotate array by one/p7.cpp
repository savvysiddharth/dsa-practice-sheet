#include <bits/stdc++.h>
using namespace std;

void printArray(int input[], int n) {
  cout << "ArrayStatus: [ ";
  for(int i=0; i<n; i++) {
    cout << input[i] << " ";
  }
  cout << "]" << endl;
}

void rotateArray(int input[], int length) {
  int lastElement = input[length-1];
  for(int i=length-2; i >= 0; i--) {
    input[i+1] = input[i];
  }
  input[0] = lastElement;
}

int main() {
  int input[] = {1,2,3,4,5};
  int len = sizeof(input)/sizeof(int);
  printArray(input, len);
  rotateArray(input, len);
  printArray(input, len);
}