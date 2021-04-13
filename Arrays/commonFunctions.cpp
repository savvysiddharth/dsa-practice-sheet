#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> input) {
  int length = input.size();
  cout << "VectorContent: [ ";
  for(int i=0; i<length; i++) {
    cout << input[i];
    if(i != length-1) cout << ",";
    cout << " ";
  }
  cout << "]" << endl;
}

void printArray(int input[], int length) {
  cout << "ArrayContent: [ ";
  for(int i=0; i<length; i++) {
    cout << input[i];
    if(i != length-1) cout << ",";
    cout << " ";
  }
  cout << "]" << endl;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}