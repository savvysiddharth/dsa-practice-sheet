#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(n)
bool subarrayZero(int input[], int length) {
  unordered_set<int> myset;
  int sum = 0;
  for(int i=0; i<length; i++) {
    sum += input[i];
    if(myset.find(sum) != myset.end() || sum == 0) { // condition found || OR || the sum till now it self is zero
      return true;
    }
    myset.insert(sum);
  }
  return false;
}

int main() {
  int input[] = {10, -10};
  int length = sizeof(input)/sizeof(input[0]);
  if(subarrayZero(input, length)) {
    cout << "found" << endl;
  } else {
    cout << "not found" << endl;
  }
}