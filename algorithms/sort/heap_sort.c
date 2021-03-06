/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * 
 */

#include "../../zyc-libs/utils.h"

/**
 * Elevate the big item along the way to initial root
 * @param arr {int*} The initial address of the array
 * @param child {int} The index of the item whick need to be elevated
 */
void elevateBigItem(int* arr, int child) {
  if (child <= 0) return;
  int parent = (child - 1) / 2;
  while (parent >= 0 && arr[child] > arr[parent]) {
    swap(arr + parent, arr + child);
    child = parent;
    parent = (child - 1) / 2;
  }
}

/**
 * @param arr {int*} The initial address of the array
 * @param end {int} The end index of the array
 * @param root {int} The root index of the heap
 */
void createBigHeap(int* arr, int end, int root) {
  if (root * 2 + 1 > end) return;
  if (arr[root] < arr[root * 2 + 1]) swap(arr + root, arr + (root * 2 + 1));
  if (root * 2 + 2 > end) {
    elevateBigItem(arr, root);
    return;
  }
  if (arr[root] < arr[root * 2 + 2]) swap(arr + root, arr + (root * 2 + 2));
  elevateBigItem(arr, root);
  
  createBigHeap(arr, end, root * 2 + 1);
  createBigHeap(arr, end, root * 2 + 2);
}

/**
 * Heap sort.
 * @param arr {int*} The initial address of the array
 * @param len {int} The length of the array
 */
void heapSort(int* arr, int len) {
  int end = len - 1;
  while (end > 0) {
    createBigHeap(arr, end, 0);
    swap(arr + 0, arr + end);
    end--;
    if (end > 0) swap(arr + 0, arr + end);
  }
}