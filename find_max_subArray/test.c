#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "find_sum_subarray.h"

int main() {
  int test[16] = {13, -3, -25, 20, -3,  -16, -23, 18,
                20, -7, 12,  -5, -22, 15,  -4,  7};
  SubArray_t arr;
  find_sum_max_subarray(test, 16, &arr);
  printf("i begin=%d, i_end=%d, sum=%d\n", arr.index_begin, arr.index_end, arr.sum);
  SubArray_t arr2;
  find_sum_max_subarray_recurs(test, 16, &arr2);
  printf("i begin2=%d, i_end2=%d, sum2=%d\n", arr2.index_begin, arr2.index_end, arr2.sum);
}
