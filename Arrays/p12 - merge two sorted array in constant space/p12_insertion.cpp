#include <bits/stdc++.h>
using namespace std;

// idea: implement using insertion sort algorithm
// time complexity: O(m*n)
void mergeLowMemory_slow(int arr1[], int arr2[], int len1, int len2) { 
  for(int i = len2-1; i>=0; i--) { // iterate from right to left in arr2 
    int last = arr1[len1-1]; // storing last element of array1 as we might overwrite it
    int j;
    for(j=len1-2; (j >=0 && arr1[j] > arr2[i]); j--) { // iterate from right to left in arr1
      arr1[j+1] = arr1[j];
    }
    if(j < len1-2 || last > arr2[i]) {
      arr1[j+1] = arr2[i];
      arr2[i] = last;
    }
  }
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

int main() {
  int arr1[] = {1, 3, 5, 7}; int len1 = sizeof(arr1)/sizeof(int);
  int arr2[] = {0, 2, 6, 8, 9}; int len2 = sizeof(arr2)/sizeof(int);
  printArray(arr1,len1);
  printArray(arr2,len2);
  cout << "-------AFTER MERGE-------\n";
  mergeLowMemory_slow(arr1, arr2, len1, len2);
  printArray(arr1,len1);
  printArray(arr2,len2);
}