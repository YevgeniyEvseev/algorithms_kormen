#include "find_sum_subarray.h"

void find_max_subarray_crossing(int *array, int i_low, int i_mid, int i_high, SubArray_t *res){
  int sum =0, sum_low= array[i_low];
  int middle = i_mid;
  while (i_mid > i_low) {
    sum += array[i_mid];
    if(sum>sum_low){
      sum_low = sum;
      res->index_begin = i_mid;
    }
    i_mid--;
  }
  sum = 0;
  int sum_high = array[i_high];
  i_mid = middle + 1;
  while (i_mid < i_high) {
    sum += array[i_mid];
    if(sum>sum_high){
      sum_high= sum;
      res->index_end = i_mid;
    }
    i_mid++;
  }
  res->sum = sum_low + sum_high;
}

void find_max_recurs(int *array, int i_low, int i_high, SubArray_t *res){
  SubArray_t res_low;
  SubArray_t res_high;
  SubArray_t res_cross;
  if (i_low == i_high) {
    res->sum = array[i_low];
    res->index_begin = i_low;
    res->index_end = i_high;
    return;
  }
  int middle = (i_high + i_low) / 2;
  find_max_recurs(array, i_low, middle, &res_low);
  find_max_recurs(array, middle + 1, i_high, &res_high);
  find_max_subarray_crossing(array, i_low, middle, i_high, &res_cross);
  if (res_low.sum > res_cross.sum && res_low.sum > res_high.sum) *res = res_low;
  if (res_high.sum>res_cross.sum && res_high.sum>res_low.sum)
    *res = res_high;
  if(res_cross.sum>=res_high.sum && res_cross.sum>=res_low.sum)
    *res = res_cross;
}

void find_sum_max_subarray_recurs(int *array, int length, SubArray_t *res){
  SubArray_t sum;
  find_max_recurs(array, 0, length - 1, &sum);
  *res = sum;
}