#include <bits/stdc++.h>
using namespace std;

// FAILED TO WORK
// Always do full jump Approach (shouldn't work in all cases)
// also fall to infinite loop in case input[i] = 0
int FAILED_minJumps(int input[], int length) {
  int i = 0;
  int jump = 0;
  while(i < length) {
    if(input[i + input[i]] != 0) i = i + input[i];  // move index by input[i]
    else {
      int indicesToJump = input[i]-1;
      while(indicesToJump >= 1) {
        if(input[i+ indicesToJump] != 0) {
          i = i + indicesToJump;
          break;
        }
        indicesToJump--;
      }
    }
    jump++;
  }
  return jump;
}


struct IndexData {
  int jumps; // jumps did till now to reach here
  int remaining_jumps; // remaining jumps from index from where we reach here
  int from_index; // from which index we jumped here
};

// FAILED TO WORK
// Attempt to O(n) soln
int FAILED_minJumpDynamic(int input[], int length) {
  vector<struct IndexData> results;
  struct IndexData firstIndex = {0,0,0};
  results.push_back(firstIndex); // initialize vector with first index
  int i = 1; // current index
  while(i < length) {
    struct IndexData previousIndex = results[i-1];
    struct IndexData currentIndex;
    if(previousIndex.remaining_jumps > 0 && results[previousIndex.from_index].jumps < previousIndex.jumps) { // then jump from that index
        currentIndex.jumps = results[previousIndex.from_index].jumps + 1;
        currentIndex.remaining_jumps = previousIndex.remaining_jumps - 1;
        currentIndex.from_index = previousIndex.from_index;
    } else { // then jump from previous index
      currentIndex.jumps = previousIndex.jumps + 1;
      currentIndex.remaining_jumps = input[i-1] - 1;
      currentIndex.from_index = i-1;
    }
    results.push_back(currentIndex);
    i++;
  }
  return results[length-1].jumps;
}