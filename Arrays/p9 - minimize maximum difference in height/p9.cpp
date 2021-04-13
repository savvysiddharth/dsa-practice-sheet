// Minimize the maximum difference (difference between smallest and largest element) in array
#include <bits/stdc++.h>
using namespace std;

void printArray(int input[], int length) {
  cout << "ArrayContent: [ ";
  for(int i=0; i<length; i++) {
    cout << input[i];
    if(i != length-1) cout << ",";
    cout << " ";
  }
  cout << "]" << endl;
}

// Time Complexity : O(nLogn + n)
// Case where elements can be any integer (positive or negative)
int minimizeMaxDifference_0(int input[], int length, int k) {
  sort(input, input+length); // sort the input array
  int max_item = input[length-1];
  int min_item = input[0];
  int basic_answer = max_item - min_item; // a case where all elements are either increased or decreased
  int answer = basic_answer; // initial assumption for the minimum difference
  int new_max, new_min;
  for(int i=1; i<length; i++) {
    // if we start decreasing from index i and onwards what will happen
    new_max = max(input[i-1] + k, input[length-1] - k); // new max would be this
    new_min = min(input[0] + k, input[i] - k);
    answer = min(answer, new_max - new_min);
  }
  return answer;
}

// Time Complexity : O(nLogn + n)
// Case where only non-negative numbers are allowed
int minimizeMaxDifference(int input[], int length, int k) {
  sort(input, input+length); // sort the input array
  int max_item = input[length-1];
  int min_item = input[0];
  int basic_answer = max_item - min_item; // a case where all elements are either increased or decreased
  int answer = basic_answer; // initial assumption for the minimum difference
  int new_max, new_min;
  for(int i=1; i<length; i++) {
    if(input[i] >= k) {
      // if we start decreasing from index i and onwards what will happen
      new_max = max(input[i-1] + k, input[length-1] - k); // new max would be this
      new_min = min(input[0] + k, input[i] - k);
      answer = min(answer, new_max - new_min);
    }
  }
  return answer;
}

int main() {
  // int input[] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
  int input[] = {7, 9, 7, 7, 5, 10, 2, 6, 5, 6};
  int len = sizeof(input)/sizeof(int);
  sort(input, input + len);
  printArray(input, len);
  int k = 5;
  cout << minimizeMaxDifference(input, len, k) << endl;
  // printArray(input, len);
}