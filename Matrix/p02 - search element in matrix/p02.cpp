#include <bits/stdc++.h>
using namespace std;

void printVectorOfVector(vector<vector<int>> &input) {
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

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  int length = rows * cols;

  int low = 0;
  int high = length-1;

  bool found = false;

  while(low <= high) {
    int mid = (low + high) / 2;
    int i = mid/cols;
    int j = mid - cols*i;
    int currentElement = matrix[i][j];
    if(currentElement == target) return true;
    else if(target > currentElement) { // look right
      low = mid+1;
    } else { // look left
      high = mid-1;
    }
  }

  return false;
}

int main() {
  vector<vector<int>> matrix = {{ 1, 3, 5, 7},
                                {10,11,16,20},
                                {23,30,34,60}};

  bool result = searchMatrix(matrix, 3);
  if(result) {
    cout << "found" << endl;
  } else {
    cout << "not found" << endl;
  }
}