// Kth smallest number
// Solution with MinHeap - Worst Case Time Complexity: O(n + klogn)
#include <bits/stdc++.h>
using namespace std;

// Binary Heap
class MinHeap {
  private:
    int *heap_array;
    int capacity; 
    int heap_size;
  public:
    MinHeap(int capacity);

    void heapify(int i);
    int parent(int i) {return i>>1;}; // floor(i/2)
    int left(int i) {return i<<1;}; // 2*i
    int right(int i) {return (i<<1) + 1;}; // 2*i + 1
    int extractMin();
    int getMin() {return heap_array[1];};
    void insertKey(int key);
    void printHeap();
    void buildHeap(int input[], int size);
};

MinHeap::MinHeap(int cap) {
  heap_size = 0;
  capacity = cap;
  heap_array = new int[capacity+1]; // +1 bcoz, place at index 0 stays unused, bcoz we pretend our array starts at index 1.
}

void MinHeap::heapify(int i) { // O(logn)
  if(i > (heap_size/2)) return;
  int root = i;
  int left = this->left(i);
  int right = this->right(i);
  int MIN = root;
  if(left <= heap_size) MIN = heap_array[left] < heap_array[root] ? left : root;
  if(right <= heap_size) MIN = heap_array[right] < heap_array[MIN] ? right : MIN;
  if(MIN != root) {
    int temp = heap_array[MIN];
    heap_array[MIN] = heap_array[root];
    heap_array[root] = temp;
    heapify(MIN);
  }
}

// Overwrites heap with given input array
void MinHeap::buildHeap(int input[], int size) { // O(n)
  if(size > capacity) {
    cout << "Build Aborted : Input size exceeds heap capacity.";
    return;
  }
  heap_size = 0; // reset heap
  for(int i=0; i<size; i++) { // Copying input array content into heap array.
    heap_size++;
    heap_array[heap_size] = input[i];
  }
  for(int i=(heap_size/2); i>=1; i--) {
    heapify(i);
  }
}

void MinHeap::insertKey(int key) { // O(logn)
  if(heap_size == capacity) {
    cout << "Overflow Occurred! Cannot insert new key." << endl;
    return;
  }
  heap_size++;
  heap_array[heap_size] = key;
  // decreaseKey(heap_size, key);
  int i = heap_size;
  while(i>1 && heap_array[parent(i)] > heap_array[i]) {
    // do swap
    int temp = heap_array[parent(i)];
    heap_array[parent(i)] = heap_array[i];
    heap_array[i] = temp;
    i = parent(i);
  }
}

int MinHeap::extractMin() {
  if(heap_size == 0) {
    cout << "Heap empty!" << endl;
    return -1;
  }
  int MIN_val = getMin();
  heap_array[1] = heap_array[heap_size]; // replacing root with last element
  heap_size--; // deleting last element
  heapify(1);
  return MIN_val;
}

void MinHeap::printHeap() {
  cout << "Heap Status: ";
  for(int i=1; i<=heap_size; i++) {
    cout << heap_array[i] << " ";
  }
  cout << endl;
}


int main() {
  MinHeap myheap(100); // creating a heap with capacity of 100 elements
  int input[] = {7,10,4,3,20,15};
  int len = sizeof(input)/sizeof(int);
  myheap.buildHeap(input, len);
  myheap.printHeap();
  
  cout << "kth Smallest Program:" << endl;
  cout << "Enter k: ";
  int k;
  cin >> k; 
  for(int i=1; i<k; i++) {
    myheap.extractMin();
  }
  cout << myheap.extractMin() << endl;
}