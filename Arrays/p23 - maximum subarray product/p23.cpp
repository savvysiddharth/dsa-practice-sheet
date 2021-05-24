#include <bits/stdc++.h>
using namespace std;

long long mymax(long long a, long long b, long long c) {
  long long Max = a;
  if(b > Max) Max = b;
  if(c > Max) Max = c;
  return Max;
}

long long mymin(long long a, long long b, long long c) {
  long long Min = a;
  if(b < Min) Min = b;
  if(c < Min) Min = c;
  return Min;
}

int maxSubarrProd(int input[], int length) {
  long long maxProd = input[0];
  long long prevMax = input[0];
  long long prevMin = input[0];
  for(int i=1; i<length; i++) {
    long long currMax = mymax(input[i], input[i]*prevMax, input[i]*prevMin);
    long long currMin = mymin(input[i], input[i]*prevMax, input[i]*prevMin);
    maxProd = mymax(maxProd, currMax, input[i]*prevMin);
    prevMax = currMax;
    prevMin = currMin;
  }
  return maxProd;
}

int main() {
  int input[] = {2, 3, 4, 5, -1, 0};
  int len = sizeof(input)/sizeof(input[0]);
  cout << "Result: " << maxSubarrProd(input, len) << endl;
}