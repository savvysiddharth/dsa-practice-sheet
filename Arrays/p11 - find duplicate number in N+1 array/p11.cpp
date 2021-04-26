// this problem can be solved using three different approaches
#include <bits/stdc++.h>
using namespace std;

// Sorting Approach
int findDuplicate_sort(int input[], int length) {
  sort(input.begin(), input.end());
  for(int i=0; i<length-1; i++) { 
    if(input[i] == input[i+1]) return input[i]; 
  }
  return -1;
}

// Hashmap Approach
int findDuplicate_map(int input[], int length) {
  unordered_map<int,int> map;
  for(int i=0; i<length; i++) { 
    if(map[input[i]] == 1) return input[i]; 
    else map[input[i]] = 1; 
  }
  return -1;
}

// Floyd's Tortoise and Hare
int findDuplicate_cycle_detection(int input[], int length) {
  
}

int main() {

}