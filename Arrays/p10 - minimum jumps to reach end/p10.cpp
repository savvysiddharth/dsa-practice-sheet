#include <bits/stdc++.h>
using namespace std;

// Naive approach / bruteforce method
// Time Complexity -  O(n^n)
int minJumpsRecursive(int input[], int length, int current, int jumps) {
  if(current >= length - 1) return jumps;
  if(input[current] == 0) return length+1; // to make it impossible to reach
  vector<int> results;
  for(int indicesToJump = 1; indicesToJump <= input[current];  indicesToJump++) {
    results.push_back(minJumpsRecursive(input, length, current + indicesToJump, jumps+1));
  }
  return *min_element(results.begin(), results.end());
}

// Optimal approach
// Time Complexity : O(n)
int myMinJumps(int input[], int length) {
  if(length <= 1) return 0; // obviously, we don't need any jumps at all if number of elements are less than 2
  if(length == 2 && input[0] == 0) return -1;  // not possible 
  int MaxReach = input[0];
  int steps = input[0];
  int count = 0; // jump counts
  for(int i=1; i<length; i++) {
    if(i > MaxReach) return -1; // no jumps are possible, in that case.
    steps--;
    MaxReach = max(MaxReach, i + input[i]);
    if(steps == 0) {
      count++;
      if(i<length-1) steps = MaxReach - i; 
    }
    
  }
  if(steps > 0) count++; // bcoz in that case jump count has not incremented in loop, so we do it here
  return count;
}


int main() {
  // int input[] = {1, 4, 3, 2, 6, 7};
  int input[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  // int input[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
  int len = sizeof(input)/sizeof(int);
  // cout << minJumpsRecursive(input, len, 0, 0) << endl;
  // cout << minJumps(input, len) << endl;
  cout << myMinJumps(input, len) << endl;
  // cout << minJumpDynamic(input, len) << endl;
}