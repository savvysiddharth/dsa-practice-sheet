#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(n)
string isSubset(int a1[], int a2[], int n, int m) {
  unordered_set<int> myset;
  bool subset = true;
  if(n >= m) {
    for(int i=0; i<n; i++) { // put longer set into set
      myset.insert(a1[i]);
    }
    for(int i=0; i<m; i++) { // check if all elements of shorter set exists in set
      if(myset.find(a2[i]) == myset.end()) { // not found in set
        subset = false; break;
      }
    }
  } else subset = false;
  if(subset) return "Yes";
  else return "No";
}

int main() {

}