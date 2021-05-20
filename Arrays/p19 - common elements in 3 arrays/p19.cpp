#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> input) {
  int length = input.size();
  cout << "VectorContent: [ ";
  for(int i=0; i<length; i++) {
    cout << input[i];
    if(i != length-1) cout << ",";
    cout << " ";
  }
  cout << "]" << endl;
}

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
  vector<int> results;
  unordered_map<int,int> res_map;
  int commonCount = 0;
  int i[3] = {0,0,0}; // array of indices
  while(i[0]<n1 || i[1]<n2 || i[2]<n3) {
    if(i[0]<n1 && i[1]<n2 && i[2]<n3) {
      if(A[i[0]] == B[i[1]] && B[i[1]] == C[i[2]]) { // all are equal
        commonCount++;
        if(res_map.find(A[i[0]]) == res_map.end()) { // if map doesn't have this already
          results.push_back(A[i[0]]);
          res_map.insert({A[i[0]], 1});
        }
        i[0]++; i[1]++; i[2]++;
      } else { // not all are equal
        int min = A[i[0]], indexToIncrement = 0;
        if(B[i[1]] < min) {
          min = B[i[1]]; indexToIncrement = 1;
        }
        if(C[i[2]] < min) {
          min = C[i[2]]; indexToIncrement = 2;
        }
        i[indexToIncrement]++;
      }
    } else { // some or all index pointer have exceeded array length
      break; // bcoz, matching of all 3 would be impossible!  <- CATCH!
    }
  }
  return results;
}

int main() {
                      // 0  1   2   3   4   5   6    7
  int n1 = 6; int A[] = {1, 5, 10, 20, 40, 80};
  int n2 = 5; int B[] = {6, 7, 20, 80, 100};
  int n3 = 8; int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
  printVector(commonElements(A,B,C,n1,n2,n3));
}