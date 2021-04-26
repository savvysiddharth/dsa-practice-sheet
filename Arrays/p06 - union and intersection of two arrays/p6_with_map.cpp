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

// Map Approach
// Time Complexity - O(m + n)
void my_union(vector<int> input1, vector<int> input2) {
  int l1 = input1.size();
  int l2 = input2.size();

  unordered_map<int,int> map;
  vector<int> union_result;
  for(int i=0; i<l1; i++) {
    if(map[input1[i]] != 1) { // if this element isn't already added into union result
      union_result.push_back(input1[i]);
      map[input1[i]] = 1;
    }
  }
  for(int i=0; i<l2; i++) {
    if(map[input2[i]] != 1) { // if this element isn't already added into union result
      union_result.push_back(input2[i]);
      map[input2[i]] = 1;
    }
  }

  printVector(union_result);
}

// Hash Map Approach
// Time Complexity - O(m + n)
void my_intersection(vector<int> input1, vector<int> input2) {
  int l1 = input1.size();
  int l2 = input2.size();
  
  unordered_map<int,int> map;
  vector<int> intersection_result;
  for(int i=0; i<l1; i++) {
    if(map[input1[i]] != 1) {
      map[input1[i]] = 1;
    }
  }
  for(int i=0; i<l2; i++) {
    if(map[input2[i]] == 1) intersection_result.push_back(input2[i]);
  }
  printVector(intersection_result);
}


int main() {
  vector<int> i1 {1,2,3,4,5};
  vector<int> i2 {2,4,7,8};
  my_intersection(i1,i2);
  my_union(i1,i2);
}