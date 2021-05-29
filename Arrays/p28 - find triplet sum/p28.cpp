#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int input[], int length, int X) {
  sort(input, input+length);
  for(int i=0; i<length; i++) {
    if(input[i] < X) {
      int currentElement = input[i];
      int left = 0;
      int right = length-1;
      while(left < right) {
        cout << left << " " << right << endl;
        if(left != i && right != i) {
          int triplet_sum = currentElement + input[left] + input[right];
          if(triplet_sum == X) return true;
          if(triplet_sum < X) left++;
          else right--;
        } else {
          if(left == i) left++;
          else right--;
        }
      }
    }
  }
  return false;
}

int main() {
  int input[] = {1, 4, 45, 6, 10, 8};
  int length = sizeof(input)/sizeof(input[0]);
  int target = 13;
  if(find3Numbers(input, length, target)) {
    cout << "Triplet found!" << endl;
  } else {
    cout << "404 not found" << endl;
  }
}