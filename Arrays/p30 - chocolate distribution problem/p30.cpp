#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> input, long long length, long long kids){
  sort(input.begin(), input.end());
  long long min_diff = input[length-1];
  for(int i=0; i<=length-kids; i++) {
    int curr_diff = input[i+kids-1] - input[i];
    if(curr_diff < min_diff) min_diff = curr_diff;
  }
  return min_diff;
}

int main() {
  vector<long long> input = {7, 3, 2, 4, 9, 12, 56};
  long long length = input.size();
  long long kids = 3;
  cout << "answer: " << findMinDiff(input, length, kids) << endl;
}