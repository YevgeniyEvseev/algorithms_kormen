#include "find_sum_subarray.h"


void find_sum_max_subarray(int *array, int length, SubArray_t *res){
  res->sum = array[0];
  for (int i = 2; i < length; ++i) {
    
    for (int j = 0; j < length - i+1; ++j) {
      int sum_sub_array = 0;
      for (int k = j; k < i+j; k++)
      {
        sum_sub_array += array[k];
      }
      if (res->sum < sum_sub_array) {
        res->sum = sum_sub_array;
        res->index_begin = j;
        res->index_end = j + i-1;
      }
    }
  }
}