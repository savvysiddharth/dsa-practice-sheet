//Find the maximum and minimum element in an array
#include <iostream>
using namespace std;

// Linear Scan Method: 1 + 2(n-2) comparisions
void basic_approach() { // ROOT
  int input[] = {23,64,12,887,9,23};
  int len = sizeof(input)/sizeof(int);
  int max,min;
  if(len == 1) {
    printf("only one element exists, so it is both max and min.\n");
    return;
  }
  // 1 Comparision
  if(input[0] > input[1]) {
    max = input[0];
    min = input[1];
  } else {
    max = input[1];
    min = input[0];
  }
  // 2(n-2) Comparisions
  for(int i=2; i<len; i++) {
    if(input[i] > max) max = input[i];
    else if(input[i] < min) min = input[i];
  }
  printf("max is %d\nmin is %d\n", max,min);
}

// Tournament Method: (3n/2) - 2 comparisions
struct Pair {
  int max;
  int min;
};

struct Pair tournament_split(int input[], int first, int last) {
  int len = last - first + 1;
  struct Pair p;
  if(len == 1) { // base case #1 (assign this same number to max & min both)
    p.max = input[first];
    p.min = p.max;
    return p;
  } else if(len == 2) { // base case #2
    if(input[first] >= input[last]) { // find max & min among these 2 numbers
      p.max = input[first];
      p.min = input[last];
    } else {
      p.max = input[last];
      p.min = input[first];
    }
    return p;
  } else { // recursive case
    int mid = (first + last)/2;
    struct Pair left = tournament_split(input, first, mid-1);
    struct Pair right = tournament_split(input, mid, last);
    struct Pair result;
    if(left.max >= right.max) result.max = left.max;
    else result.max = right.max;
    if(left.min <= right.min) result.min = left.min;
    else result.min = right.min;
    return result;
  }
}

void tournament_approach() { //ROOT
  int input[] = {23,64,12,887,9,23};
  int len = sizeof(input)/sizeof(int); 
  struct Pair final = tournament_split(input, 0, len-1);
  printf("max is %d\nmin is %d\n", final.max, final.min);
}

// Compare in Pairs Method:
// if n is even: 1 + (n-2)/2 + 2*[(n-2)/2] = 1 + 3(n-2)/2
// if n is odd: (n-1)/2 + 2*[(n-1)/2] = 3(n-1)/2
void compare_in_pairs_approach() { //ROOT
  int input[] = {23,64,12,887,9,23};
  int len = sizeof(input)/sizeof(int);
  int max,min, i;
  if(len%2 == 0) { // length is even
    if(input[0] >= input[1]) {
      max = input[0];
      min = input[1];
    } else {
      max = input[1];
      min = input[0];
    }
    i = 2;
  } else { // length is odd
    max = input[0];
    min = input[0];
    i = 1;
  }

  for(;i<len;i+=2) {
    if(input[i] >= input[i+1]) { // input[i] could be max and input[i+1] could be min
      if(input[i] > max) max = input[i];
      if(input[i+1] < min) min = input[i+1];
    } else { // input[i] could be min and input[i+1] could be max
      if(input[i+1] > max) max = input[i+1];
      if(input[i] < min) min = input[i];
    }
  }
  printf("max is %d\nmin is %d\n", max,min);
}

int main() {
	// basic_approach();
  // tournament_approach();
  compare_in_pairs_approach();
}

