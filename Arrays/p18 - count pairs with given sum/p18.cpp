#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> &input, int sum) {
  int pairCount = 0;
  unordered_map<int,int> map;
  for(int i=0; i<input.size(); i++) {
    if(map.find(input[i]) != map.end()) { // it is found in the map
      pairCount += map[input[i]];
    }
    int diff = sum - input[i];
    if(map.find(diff) == map.end()) { // diff is not in map
      map.insert({diff, 1});
    } else { // if it exists in map,s increment it
      map[diff] += 1;
    }
  }
  return pairCount;
}

int main() {
  vector<int> input = {1, 5, 7, 1};
  int sum = 6;
  cout << countPairs(input, sum) << endl;
}