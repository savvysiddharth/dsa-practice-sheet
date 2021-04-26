#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr1[] = {1, 3, 5, 7}; int len1 = sizeof(arr1)/sizeof(int);
  int arr2[] = {0, 2, 6, 8, 9}; int len2 = sizeof(arr2)/sizeof(int);

  int i,j;
  i=j=0;
  while(i<len1 || j<len2) {
    if(i < len1 && j < len2) {
      if(arr1[i] > arr2[j]) {
        swap(arr1[i], arr2[j])
      }
    } else {
      if(i >= len1) {

      } else {

      }
    }
  }
}