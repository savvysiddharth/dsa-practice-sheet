// Find Union and Intersection of two unsorted arrays
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> input) {
  int length = input.size();
  cout << "VectorStatus: [ ";
  for(int i=0; i<length; i++) {
    cout << input[i] << " ";
  }
  cout << "]" << endl;
}

// Hash Map Approach
// Time Complexity - O(mlogmm + nlogn)
void my_union(vector<int> input1, vector<int> input2) {
  int l1 = input1.size();
  int l2 = input2.size();

  sort(input1.begin(), input1.end());
  sort(input2.begin(), input2.end());

  printVector(input1);
  printVector(input2);

  vector<int> union_result;

  int i,j;
  i=j=0;
  while(i<l1 || j<l2) {
    if(i<l1 && j<l2) {
      if(input1[i] < input2[j]) { 
        union_result.push_back(input1[i]);
        i++; continue;
      } else if(input1[i] > input2[j]) {
        union_result.push_back(input2[j]);
        j++; continue;
      } else { // both are equal
        union_result.push_back(input1[i]); // push anyone of these two
        i++; j++;
      }
    } else if(i<l1 && !(j<l2)) {
      // empty out entire remaining input1 array
      while(i<l1) {
        union_result.push_back(input1[i++]);
      } break;
    } else if(!(i<l1) && j<l2) {
      // empty out entire remaining input2 array
      while(j<l2) {
        union_result.push_back(input2[j++]);
      } break;
    } 
  }
  printVector(union_result);
}

int main() {
  vector<int> i1 {5,3,4,1,2};
  vector<int> i2 {2,4,7,8}; 
  my_union(i1,i2);
}