// QuickSelect Method
// with Randomized Pivot Partition Subroutine
// Expected Time Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition_random_pivot(int input[], int start, int end) {
  int size = end - start + 1;
  int x = rand();
  int random_index = (x%size) + start; // generated random index between start and end
  swap(&input[random_index], &input[end]); //put that randomly picked element to the right end of array
  int pivot = input[end];
  int i = start - 1;
  int j = start; 
  while(j<end) {
    if(input[j] < pivot) {
      swap(&input[i+1], &input[j]);
      i++;
      // note: we will increment j in this case too
      // you might wonder, that new element which just came to j'th index must be rechecked
      // but think about it once again, that j'th element which is about be replaced is already checked in earlier iterations!
    }
    j++;
  }
  swap(&input[i+1], &input[end]); // put pivot to it's appropriate location
  return i+1;
}

int kthSmallestElement(int input[], int start, int end, int k) {
  int k_index = partition_random_pivot(input, start, end);
  if(k == (k_index+1)) return input[k_index];
  if(k < (k_index+1)) { // just partition left of pivot
    return kthSmallestElement(input, start, k_index-1, k);
  } else { // just partition right  of pivot
    return kthSmallestElement(input, k_index+1, end, k);
  }
}

int main() {
  srand(time(0));
  int iarr[] = {12,53,1,22,14,64};
  int len = sizeof(iarr)/sizeof(int);
  int k = 4;
  int ans = kthSmallestElement(iarr,0,len-1,k);
  cout << ans << endl;
}