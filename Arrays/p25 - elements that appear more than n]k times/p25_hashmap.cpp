#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(n)
int countOccurence(int input[], int length, int k) {
  unordered_map<int, int> mymap;
  int target = length/k;
  int count = 0;
  for(int i=0; i<length; i++) {
    if(mymap.find(input[i]) == mymap.end()) { // if not found in map
      mymap.insert({input[i], 1});
    } else {
      mymap[input[i]]++;
      if(mymap[input[i]] == target+1) count++;
    }
  }
  return count;
}

int main() {
  int input[] = {3,1,2,2,1,2,3,3};
  int length = sizeof(input)/sizeof(input[0]); 
  int k = 4;
  cout << countOccurence(input, length, k) << endl;
}