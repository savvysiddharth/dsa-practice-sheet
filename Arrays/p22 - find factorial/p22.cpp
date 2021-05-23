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

void multiply(vector<int> &input, int x) {
  int carry = 0;
  int length = input.size();
  for(int i=0; i<length; i++) {
    int tempMul = input[i]*x + carry; 
    int lastDigit;
    if(tempMul >= 10) {
      lastDigit = tempMul%10;
      carry = tempMul/10; // removing last digit from the tempMul, and rest goes to carry
    } else {
      lastDigit = tempMul;
      carry = 0;
    }
    input[i] = lastDigit;
  }
  if(carry > 0) { // if after multiplication carry remains
    while(carry != 0) {
      int lastDigit = carry%10;
      input.push_back(lastDigit);
      carry /= 10;
    }
  }
}

vector<int> findFactorial(int n){
  vector<int> result;
  result.push_back(1);
  for(int i=2; i<=n; i++) {
    multiply(result, i);
  }
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  int n = 99;
  printVector(findFactorial(n));
}