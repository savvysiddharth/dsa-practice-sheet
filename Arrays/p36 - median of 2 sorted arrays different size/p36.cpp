#include <bits/stdc++.h>
using namespace std;

int findMedian(int arr1[], int arr2[], int len1, int len2) {
  int low = 0;
  int high = len1-1;
  int length = (len1 + len2) / 2; // half length
  while(true) {
    int mid1 = (low + high)/2;
    int mid2 = length-1 - (mid1 + 1);
    bool condition1 = false, condition2 = false;
    if(mid1 != len1-1) condition1 = arr2[mid2] < arr1[mid1 + 1];
    else condition1 = true;
    if(mid2 != len2-1) condition2 = arr1[mid1] < arr2[mid2 + 1];
    else condition2 = true;
    if(condition1 && condition2) { // split found, calculate median
      if((len1+len2)%2 == 0) { // even length
        int left = max(arr1[mid1], arr2[mid2]);
        int right;
        if(mid1 != length-1) right = arr1[mid1+1];
        if(mid2 != length-1) {
          if(arr2[mid2+1] < right) right = arr2[mid2+1];
        }
        int median = (left + right) / 2;
        return median;
      } else { // odd length
        int median = INT_MAX;
        if(mid1+1 != len1-1) median = arr1[mid1+1];
        if(mid2+1 != len2-1) {
          if(arr2[mid2+1] < median) median = arr2[mid2+1];
        }
        return median;
      }
    } else { // update high & low
      if(!condition2 && mid1-1 >= 0) high = mid1  - 1;
      else if(!condition2 && mid1-1 < 0) high = low;
      else if(!condition1 && mid1+1 < len1) low = mid1 + 1;
      else if(!condition1 && mid1+1 >= len1) low = high;
    }
  }
}

int main() {
  int arr1[] = {2,4,9};
  int arr2[] = {1,3,5,7,8};
  int len1 = sizeof(arr1)/sizeof(int);
  int len2 = sizeof(arr2)/sizeof(int);
  int result = findMedian(arr1, arr2, len1, len2);
  cout << "Answer: " << result << endl;
}