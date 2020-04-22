#include "../zyc-libs/utils.h"
#include "quick_sort_recur.h"

/**
 * Quick sort
 * @param {int*} arr The initial address of the array
 * @param {int} l The leftmost index
 * @param {int} r The rightmost index
 */
static void sort(int* arr, int l, int r) {
  int tmp = arr[l];     // The reference item
  int i = l + 1;
  int j = r;
  for (; i <= j;) {
    while (i < j && arr[j] >= tmp) j--;
    while (i < j && arr[i] <= tmp) i++;
    if (i == j) {
      if (arr[i] < tmp) swap(arr + l, arr + i);
      else (i = j = l);
      break;
    }
    if (arr[i] > tmp && arr[j] < tmp) {
      swap(arr + i, arr + j);
    }
  }
  if (l < j - 1) sort(arr, l, j - 1);
  if (j + 1 < r) sort(arr, j + 1, r);
}

/**
 * Sorting interface
 * @param {int*} arr The initial address of the array
 * @param {int} len The length of the array
 */
void quick_sort(int* arr, int len) {
  sort(arr, 0, len - 1);
}