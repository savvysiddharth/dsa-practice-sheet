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

void threeWayPartition(vector<int> &input, int min_limit, int max_limit) {
  int less = 0; // maintains list less than range (to its left)
  int more = input.size()-1; // maintains list more than range (to its right)
  int length = input.size();
  int i = 0;
  while(i <= more) {
    if(input[i] < min_limit) swap(input[i++], input[less++]);
    else if(input[i] > max_limit) swap(input[i], input[more--]);
    else i++;
  }
}

int main() {
  vector<int> input = {1, 5, 2, 1, 1};
  int min_limit = 2;
  int max_limit = 3;
  int length = sizeof(input)/sizeof(input[0]);
  printVector(input);
  threeWayPartition(input, min_limit, max_limit);
  printVector(input);
}