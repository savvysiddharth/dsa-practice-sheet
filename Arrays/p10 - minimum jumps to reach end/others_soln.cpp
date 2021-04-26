#include <bits/stdc++.h>
using namespace std;

// copied from GFG
// not understood yet
// Need to rethink
// Rethink Idea: try to build basic approach with "Maximum reachable index"
int minJumps(int arr[], int n) {
    if (n <= 1) return 0; // no point in doing anything if array has only one or none element.
    if (arr[0] == 0) return -1; // Return -1 if not possible to jump
    // initialization
    int maxReach = arr[0]; // stores all time the maximal reachable index in the array.
    int step = arr[0]; // stores the number of steps we can still take
    int jump = 1; // stores the number of jumps necessary to reach that maximal reachable position.
 
    for (int i = 1; i < n; i++) { // Start traversing array
        if (i == n - 1) return jump; // Check if we have reached the end of the array
        maxReach = max(maxReach, i + arr[i]); // updating maxReach
        step--; // we use a step to get to the current index
        
        if (step == 0) { // If no further steps left         
            jump++; // we must have used a jump
            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach) return -1; 
            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }
    return -1;
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