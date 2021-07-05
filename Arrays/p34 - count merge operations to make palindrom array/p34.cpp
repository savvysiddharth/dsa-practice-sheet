#include <bits/stdc++.h>
using namespace std;

int countMerge(int input[], int length) {
  int mergeCount = 0;
  int i = 0;
  int j = length-1;
  while(i<j) {
    if(input[i] == input[j]) {
      i++; j--;
    } else {
      if(input[i] < input[j]) {
        input[i+1] = input[i] + input[i+1];
        mergeCount++;
        i++;
      } else if(input[i] > input[j]) {
        input[j-1] = input[j] + input[j-1];
        mergeCount++;
        j--;
      }
    }
  }
  return mergeCount;
}

int main() {
  int input[] = {1,2,3,5,10,1};
  int length = sizeof(input)/sizeof(int);
  cout << "Answer: " << countMerge(input, length) << endl;
}