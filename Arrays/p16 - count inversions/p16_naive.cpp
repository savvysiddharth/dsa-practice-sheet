#include <bits/stdc++.h>
using namespace std;

// naive approach
// counts inversions at each index for each other following indices
// Time Complexity - O(n^2)
int countInversion_naive(vector<int> input) {
  int result = 0;
  for(int i=0; i<input.size(); i++) {
    for(int j=i+1; j<input.size(); j++) {
      if(input[i] > input[j]) result++;
    }
  }
  return result;
}

int main() {
  vector<int> input = {4,3,2,1};
  cout << countInversion_naive(input) << endl;
}