// Assignment 2, exercise 3
// To compile, run:
//    g++ -std=c++11 exercise_3.cpp

#include <chrono>
#include <cstdio>
#include <iostream>
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

void quick_sort(int array[], size_t size)
{
  // Implement here
}

int max(int array[], int size, const int pindex)
{
  int left_index = (pindex * 2) + 1;
  int right_index = (pindex * 2) + 2;
  if (left_index >= size)   // there is no left child
  {
    left_index = -1;
  }

  if (right_index >= size)  // there is no right child
  {
    right_index = -1;
  }

  if (left_index == -1){return -1;}             // no children

  if (left_index != -1 && right_index == -1){    //only left child
    return left_index;
  }

  if (array[left_index] > array[right_index])   //both children
  {
    return left_index;
  }
  return right_index;
}

void heapify(int array[], size_t size)
{

  for (int parent_index = (size / 2) - 1; parent_index >= 0; parent_index--)
  {
    int pindex = parent_index;
    int max_index = max(array, size, pindex);

    while(max_index != -1){
      if (array[max_index] > array[pindex])
    {
      swap(&array[max_index], &array[pindex]);
    }
    pindex = max_index;
    max_index = max(array, size, pindex);
    }
  }

}

void heap_sort(int array[], size_t size)
{
  // Implement here
}

void merge_sort(int array[], size_t size)
{
  // Implement here
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

int main()
{

  int arr[] = {10, 20, 15, 12, 40, 25, 18, 13};

  heapify(arr, 8);

  // for (int i = 0; i < 6; i++){
  //   cout << arr[i] << ", ";
  // }
  return 0;
}
