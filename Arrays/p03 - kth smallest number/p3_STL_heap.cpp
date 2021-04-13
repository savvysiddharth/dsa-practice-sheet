// Kth smallest number
// THIS CODE IS NOT COMPLETED YET
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v1 = {1,2,3,4,5};
  for(int i=0; i<5; i++) {
    cout << v1[i] << " ";
  }
  cout << endl;
  make_heap(v1.begin(), v1.end());
  for(int i=0; i<5; i++) {
    cout << v1[i] << " ";
  }
  cout << endl;
}