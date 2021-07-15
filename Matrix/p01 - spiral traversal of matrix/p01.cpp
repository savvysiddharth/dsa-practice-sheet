#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
  vector<int> result;
  // initializing borders
  int rmax = c-1; // right max
  int lmax = 0; // left max
  int dmax = r-1; // down max
  int umax = 1; // up max
  int leftToExplore = r*c; // total number of cells yet to visit
  int i = 0, j = 0;
  int direction = 1;
  // 1 - right
  // 2 - down
  // 3 - left
  // 4 - up 
  while(leftToExplore != 0) {
    leftToExplore--;
    result.push_back(matrix[i][j]);
    switch(direction) {
      case 1: // right
        if (j+1 <= rmax) j++;
        else {
          direction = 2;
          i++;
          rmax--;
        }
        break;
      case 2: // down
        if(i+1 <= dmax) i++;
        else {
          direction = 3;
          j--;
          dmax--;
        }
        break;
      case 3: // left
        if(j-1 >= lmax) j--;
        else {
          direction = 4;
          i--;
          lmax++;
        }
        break;
      case 4: // up
        if(i-1 >= umax) i--;
        else {
          direction = 1;
          j++;
          umax++;
        }
        break;
    }
  }
  return result;
}

int main() {

}