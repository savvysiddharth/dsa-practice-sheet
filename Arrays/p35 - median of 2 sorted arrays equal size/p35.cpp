#include <bits/stdc++.h>
using namespace std;

int findMedian(int arr1[], int arr2[], int length) {
  int low = 0;
  int high = length-1;
  while(true) {
    int mid1 = (low + high)/2;
    int mid2 = length-1 - (mid1 + 1);
    bool condition1 = false, condition2 = false;
    if(mid1 != length-1) condition1 = arr2[mid2] < arr1[mid1 + 1];
    else condition1 = true;
    if(mid2 != length-1) condition2 = arr1[mid1] < arr2[mid2 + 1];
    else condition2 = true;
    if(condition1 && condition2) { // split found, calculate median
      int left = max(arr1[mid1], arr2[mid2]);
      int right;
      if(mid1 != length-1) right = arr1[mid1+1];
      if(mid2 != length-1) {
        if(arr2[mid2+1] < right) right = arr2[mid2+1];
      }
      int median = (left + right) / 2;
      return median;
    } else { // update high & low
      if(!condition2 && mid1-1 >= 0) high = mid1  - 1;
      else if(!condition2 && mid1-1 < 0) high = low;
      else if(!condition1 && mid1+1 < length) low = mid1 + 1;
      else if(!condition1 && mid1+1 >= length) low = high;
    }
  }
}

int main() {
  int arr1[] = {1,4,6,7};
  int arr2[] = {2,3,5,8};
  int length = sizeof(arr1)/sizeof(int);
  int result = findMedian(arr1, arr2, length);
  cout << "Answer: " << result << endl;
}