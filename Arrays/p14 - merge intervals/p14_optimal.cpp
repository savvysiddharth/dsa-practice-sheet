#include <bits/stdc++.h>
using namespace std;

void printVectorOfVector(vector<vector<int>> input) {
  cout << "[ ";
  for(int i=0; i<input.size(); i++) {
    cout << "[";
    for(int j=0; j<input[i].size(); j++) {
      cout << input[i][j];
      if(j != input[i].size()-1) cout << ",";
    }
    cout<<"]";
    if(i != input.size()-1) cout << ", ";
  }
  cout << " ]" << endl;
}

bool OverlapExists(vector<int> i1, vector<int> i2) {
  int s1 = i1[0], f1 = i1[1];
  int s2 = i2[0], f2 = i2[1];
  if((f1 >= s2 && f1 <= f2) || (s1 >= s2 && s1 <= f2)) {
    return true;
  } else if((f2 >= s1 && f2 <= f1) || (s2 >= s1 && s2 <= f1)) {
    return true;
  } else {
    return false;
  }
}

bool compare_vector(vector<int> a, vector<int> b) {return a[0] > b[0];}

// Optimal Time Approach
// Time Complexity : O(nLogn + n)
// Space Complexity: O(n)
vector<vector<int>> merge(vector<vector<int>> &intervals) {
  int len = intervals.size();
  if(len <= 0) return intervals;
  vector<vector<int>> result;
  sort(intervals.begin(), intervals.end()); // sorts intervals based on first left bound
  vector<int> currentMerge{intervals[0][0], intervals[0][1]};
  for(int i=1; i<len; i++) {
    if(OverlapExists(intervals[i], currentMerge)) { // do merge
      currentMerge[1] = max(intervals[i][1], currentMerge[1]);
    } else { // time to insert the merged interval in the result vector
      result.push_back(currentMerge);
      currentMerge[0] = intervals[i][0];
      currentMerge[1] = intervals[i][1];
    }
  }
  if(result.size() <= 0 || result[result.size()-1] != currentMerge || currentMerge == intervals[len-1])
    result.push_back(currentMerge);
  return result;
}


int main() {
  // vector<vector<int>> input{{1,4},{2,3}};
  // vector<vector<int>> input{{1,4},{0,4}};
  vector<vector<int>> input{{1,4},{4,5}};
  // vector<vector<int>> input{{1,3},{2,6},{8,10},{15,18}};
  // vector<vector<int>> input{{2,3},{4,5},{6,7},{8,9},{1,10}};
  // printVectorOfVector(input);
  vector<vector<int>> ans = merge(input);
  printVectorOfVector(ans);
}