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

// Bruteforce Approach
// Time Complexity : O(n^2)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<vector<int>> result;
  result = intervals; // copying original vector to new vector
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result.size(); j++) {
      if(j != i) { // to not compare it with itself
        if(OverlapExists(result[i], result[j])) { // if overlaps
          int leftBound = min(result[i][0], result[j][0]);
          int rightBound = max(result[i][1], result[j][1]);
          vector<int> merged{leftBound, rightBound};
          result.erase(result.begin() + i);
          result.erase(result.begin() + j-1);
          result.push_back(merged);
          i = -1; break;
        }
      }
    }
  }
  return result;
}



int main() {
  vector<vector<int>> input{{1,4},{2,3}};
  // vector<vector<int>> input{{1,4},{0,4}};
  // vector<vector<int>> input{{1,3},{2,6},{8,10},{15,18}};
  // printVectorOfVector(input);
  vector<vector<int>> ans = merge(input);
  printVectorOfVector(ans);
}