#include <bits/stdc++.h>
using namespace std;

// arr1[] = {1, 3, 5, 7}
// arr2[] = {0, 4, 6, 8, 9}


void merge(int one[], int two[], int sizeOne, int sizeTwo) {
  int i=sizeOne-1, j = 0;
  while(i>=0 and j<sizeTwo){
    if(one[i]>two[j])
        swap(one[i],two[j]);
    i--,j++;
  }
  sort(one,one+sizeOne);
  sort(two,two+sizeTwo);
}


int main() {

}