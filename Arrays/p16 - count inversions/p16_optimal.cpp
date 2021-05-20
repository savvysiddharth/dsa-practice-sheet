#include <bits/stdc++.h>
using namespace std;

int merge_ci(int i1, int j1, int i2, int j2, int input[]) {
  int r = i1; // points to array 1
  int s = i2; // points to array 2
  int t = 0; // points to merged array
  int len1 = j1-i1+1;
  int len2 = j2-i2+1;
  int merged[len1+len2];
  int inverseCount = 0;
  while(r <= j1 || s <= j2) {
    if(r <= j1 && s <= j2) {
      // do normal compare and push to merged
      if(input[r] > input[s]) { // that's an inversion
        inverseCount += j1-r+1; // update inverse count
        merged[t++] = input[s++]; 
      } else {
        merged[t++] = input[r++];
      }
    } else {
      if(r <= j1) {
        // push all remaining items of array1 to merged
        while(r <= j1) merged[t++] = input[r++]; 
      } else {
        // push all remaining items of array2 to merged
        while(s <= j2) merged[t++] = input[s++];
      }
    }
  }
  // copy back merged to input array...
  int k = i1; // assumption, i1..j1, i2..j2 are contagious
  for(int i=0; i<len1+len2; i++, k++) {
    input[k] = merged[i];
  }
  return inverseCount;
}

// Time Complexity - O(nLogn)
// Space Complexity - O(n)
int ci(int i, int j, int input[]) {
  if(i>=j) return 0; // base case
  int mid = (i+j)/2;
  int left_ci = ci(i, mid, input);
  int right_ci = ci(mid+1, j, input);
  int ci_in_merge = merge_ci(i, mid, mid+1, j, input);
  return left_ci + right_ci + ci_in_merge;
}

int main() {
  int input[] = {2, 4, 1, 3, 5};
  int n = sizeof(input)/sizeof(input[0]);
  int result = ci(0, n-1, input);
  cout << result << endl;
}