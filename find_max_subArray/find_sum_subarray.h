#ifndef FIND_SUM_SUBARRAY_H
#define FIND_SUM_SUBARRAY_H

typedef struct{
  int index_begin;
  int index_end;
  int sum;
} SubArray_t;

void find_sum_max_subarray(int *array, int length, SubArray_t *res);
void find_sum_max_subarray_recurs(int *array, int length, SubArray_t *res);
void find_max_recurs(int *array, int i_low, int i_high, SubArray_t *res);
void find_max_subarray_crossing(int *array, int i_low, int i_mid, int i_high,
                                SubArray_t *res);

#endif