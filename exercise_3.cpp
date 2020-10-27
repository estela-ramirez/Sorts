// Assignment 2, exercise 3
// To compile, run:
//    g++ -std=c++11 exercise_3.cpp

#include <chrono>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*
 * Implement the 4 in-place sort functions for exercise 3.a.
 */
//insertion_sort() can be very very slow when dealing with large size of arrays.
//You can abort it if you don't want to spend too much time waiting for the result, but just state this point in the report.
void insertion_sort(int array[], size_t size)
{
  for (int i = 1; i < size; i++)
  {
    int j = i;
    while ((j > 0) && (array[j - 1] > array[j]))
    {
      swap(&array[j], &array[j - 1]);
      --j;
    }
  }
}

// return index of max value (between parent and children)
int max(int array[], int size, const int pindex)
{
  int max_index = pindex;
  int l_index = (max_index * 2) + 1;
  int r_index = (max_index * 2) + 2;

  if (l_index < size && array[l_index]> array[max_index])  
    max_index = l_index;

  if (r_index < size && array[r_index]> array[max_index])  
    max_index = r_index;
    
  return max_index;
}


void heapify(int array[], size_t size, int p_index)
{
    int max_index = max(array, size, p_index);

    while(max_index != p_index){
      if (array[max_index] > array[p_index]){
          swap(&array[max_index], &array[p_index]);
          p_index = max_index;
          max_index = max(array, size, p_index);
          
      }else{
          break;
      }
    }
}

void heap_sort(int array[], size_t size)
{
  // turn to max heap
  for (int p_index = (size / 2) - 1; p_index >= 0; p_index--){
      heapify(array, size, p_index);
  }
  
  // delete one by one
  for (int i = 1; i < size; ++i){
      swap(&array[0], &array[size-i]);
      heapify(array, size-i, 0);
  }
}


void merge(int array[], int l, int nl, int nr){

  cout << "l = " << ", nl = " <<nl << ", nr = " << nr << endl;
  int * temp = new int[nl+nr];
  int * left = new int[nl];
  int * right = new int[nr];

  int count = 0;
  for (int i = l; i<nl; i++){
    left[count] = array[i];
    count++;
  }

  cout << "LEFT -> ";
  for (int i =0; i < nl; i++){
    cout << left[i] << ",";
  }

  count = 0;
  for (int j = l+nl; j<nr; j++){
    left[count] = array[j];
    count++;
  }

  cout << "RIGHT -> ";
  for (int i =0; i < nr; i++){
    cout << right[i] << ",";
  }

  int i = 0;
  int j = 0;
  int k = 0;

  
  while(i != nl && j != nr){
    cout << "nl = " << nl << ", nr =" << nr<< endl;
    if(array[i] < array[j]){
      temp[k] = array[i];
      i++;
    }else{
      temp[k++] = array[j++];
 
      j++;
    }
    k++;
  }


  for(; i < nl; i++){
    temp[k] = array[i];
    k++;
  }

  for(; j < nr; j++){
    temp[k++] = array[j];
    k++;
  }

  count = 0;
  for (i = l; i < (nl+nr); i++){
    array[i] = temp[count++];

  }

  delete[] temp;
  delete[] left;
  delete[] right;

}

void merge_sort_internal(int array[], int l, int size){

  if (size>1){
        int leftSize, rightSize;
        leftSize = size / 2;
				if (size % 2 != 0) { // it's odd
					rightSize = leftSize + 1;
				} else {
					rightSize = leftSize;
				}

        merge_sort_internal(array, l, leftSize);
				merge_sort_internal(array, l + leftSize, rightSize);
				merge(array, l, leftSize, rightSize);

  }
}

void merge_sort(int array[], size_t size)
{
  merge_sort_internal(array, 0, (int)size-1);
}



//returns pivot index
//returns pivot index
int partition(int array[], int l, int h){

  swap(&array[((h-l)/2)+ l], &array[l]);
  int pivot = array[l];
  int i = l;
  int j = h;

  while(i<j){

    while(array[i] <= pivot){  // stops once it finds a bigger number
      i++;
    }

    while(array[j]> pivot){   // stops once it finds a smaller number
      --j;
    }

    if (i<j){
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[l], &array[j]);
  return j;
}

void quick_sort_internal(int array[], int l, int h){
  if (l < h){
    int pivot_index = partition(array, l, h);
    
    quick_sort_internal(array, l, pivot_index-1);
    quick_sort_internal(array, pivot_index+1, h);
  }
}

void quick_sort(int array[], size_t size)
{ 
  quick_sort_internal(array, 0, (int)size-1);
}





/*
 * Generate random integers for exercise 3.b
 */
int *random_ints(size_t size)
{
  int *numbers = new int[size];
  // Generate random numbers here
  return numbers;
}
//For exercise 3 we must create a whole program. this includes a main function.
//30 iterations of each. Calculate average. Final step is outputting average run time in a readable format.

/*
for (i = 0; i<30; i++)
  array = random_ints(N)
  get time_start
  insertion_sort(array)
  get time_end
  duration = time_end - time_start
  // Then add to measure the average time*/

/* Here is an example to measure a function's running time in nanoseconds
long long time_example() {
  auto start_time = std::chrono::high_resolution_clock::now();

  // Run function to measure the time in nanoseconds

  auto end_time = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
      end_time - start_time);
  return elapsed.count();
}
*/

int main(){

  int arr[] = {-4, 10, 20, -1, 15, 12, 40, 1};
  size_t size = 8;
  
  for (int i = 0; i < size; i++){
      cout << arr[i] << ", ";
  }
  cout << endl;
  
  
  quick_sort(arr, size);
  for (int i = 0; i < size; i++){
      cout << arr[i] << ", ";
  }

  
  return 0;
}