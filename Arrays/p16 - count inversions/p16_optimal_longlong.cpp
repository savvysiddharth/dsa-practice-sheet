// same code as p16_optimal.cpp BUT datatype is changed to long long, as this is what hackerrank demanded
#include <bits/stdc++.h>
using namespace std;

long long merge_ci(long long  i1, long long  j1, long long  i2, long long  j2, long long  input[]) {
  long long r = i1; // polong long s to array 1
  long long s = i2; // polong long s to array 2
  long long t = 0; // polong long s to merged array
  long long len1 = j1-i1+1;
  long long len2 = j2-i2+1;
  long long merged[len1+len2];
  long long inverseCount = 0;
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
  long long k = i1; // assumption, i1..j1, i2..j2 are contagious
  for(long i=0; i<len1+len2; i++, k++) {
    input[k] = merged[i];
  }
  return inverseCount;
}

long long int ci_root(long long input[], long long N) {
  return ci(0,N-1, input);
}

long long int ci(long long i, long long j, long long input[]) {
  if(i>=j) return 0; // base case
  long long mid = (i+j)/2;
  long long left_ci = ci(i, mid, input);
  long long right_ci = ci(mid+1, j, input);
  long long ci_in_merge = merge_ci(i, mid, mid+1, j, input);
  return left_ci + right_ci + ci_in_merge;
}

int main() {
  long long input[] = {2, 4, 1, 3, 5};
  long long n = sizeof(input)/sizeof(input[0]);
  long long result = ci_root(input, n);
  cout << result << endl;
}