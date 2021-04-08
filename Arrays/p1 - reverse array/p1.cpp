//Reverse the array

#include <iostream>
using namespace std;

//Non-modular-iterative - O(n)
void iterative() { //ROOT
	int input[] = {11,15,23,36,67};
	int len = sizeof(input)/sizeof(int);
	// printf("%d\n", len);
	for(int i=0, j=len-1; i<j; i++,j--) {
    // Perform Swap operation
		int temp = input[i];
		input[i] = input[j];
		input[j] = temp;
	}
	for(int i=0; i<len; i++) {
		printf("%d ", input[i]);
	}
	printf("\n");
}

//Modular-iterative - O(n)
void printArray(int input[], int len) {
	for(int i=0; i<len; i++) {
		printf("%d ", input[i]);
	}
	printf("\n");
}

void rev_itr_2(int input[], int len) {
  int start=0, last=len-1;
  while(start < last) {
    int temp = input[start];
    input[start] = input[last];
    input[last] = temp;
    start++; last--;
  }
}

void iterative2() { //ROOT
  int input[] = {11,15,23,36,67};
  int len = sizeof(input)/sizeof(int);
  printArray(input,len);
  rev_itr_2(input,len);
  printArray(input,len);
}

//Recursive - O(n)
void revRec(int input[], int start, int end) {
  if(start < end) {
    int temp = input[start];
    input[start] = input[end];
    input[end] = temp;
    revRec(input, start+1, end-1);
  }
}

void recursive() { //R00T
  int input[] = {11,15,23,36,67};
  int len = sizeof(input)/sizeof(int);
  printArray(input,len);
  revRec(input, 0, len-1);
  printArray(input,len);
}

int main() {
  // iterative();
	// iterative2();
  recursive();
}