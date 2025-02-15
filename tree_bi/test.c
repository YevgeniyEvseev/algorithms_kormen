#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tree_d.h"

void create_array(int *array, int lenght) {
  srand(time(NULL));
  for (int i = 0; i < lenght; ++i) {
    array[i] = rand() % 1000;
  }
}

int equel_array(int *array1, int *array2, int len) {
  for (int i = 0; i < len; ++i) {
    if (array1[i] != array2[i]) return i;
  }
  return -1;
}

START_TEST(PRINT_TOP1) {
  int len = 1000;
  int array[1000];
  int array_t1[1002] = {0}, array_t2[1002] = {0};
  create_array(array, len);
  tree_d *root;
  new_tree(&root, *array);
  for (int i = 1; i < len; ++i) {
    insert(&root, array[i]);
  }
  print_hightless(root, array_t1);
  print_hightless_req(root, array_t2);
  ck_assert_int_eq(-1, equel_array(array_t1, array_t2, 1000));
}
END_TEST

Suite *tree_d_suite() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("TREE BI");

  /*Core test case*/
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, PRINT_TOP1);
  suite_add_tcase(s, tc_core);
  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = tree_d_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? TRUE : FALSE;
}