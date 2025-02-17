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
  clear(root);
}
END_TEST

START_TEST(PRINT_TOP2) {
  int len = 100000;
  int array[100000];
  int array_t1[100002] = {0}, array_t2[100002] = {0};
  create_array(array, len);
  tree_d *root;
  new_tree(&root, *array);
  for (int i = 1; i < len; ++i) {
    insert(&root, array[i]);
  }
  print_hightless(root, array_t1);
  print_hightless_req(root, array_t2);
  ck_assert_int_eq(-1, equel_array(array_t1, array_t2, 100000));
  clear(root);
}
END_TEST

START_TEST(PRINT_TOP3) {
  int len = 10000;
  int array[10000] = {0};
  for (int i = 0; i < len; ++i) {
    array[i] = 1;
  }
  int array_t1[10002] = {0}, array_t2[10002] = {0};
  // create_array(array, len);
  tree_d *root;
  new_tree(&root, *array);
  for (int i = 1; i < len; ++i) {
    insert(&root, array[i]);
  }
  print_hightless(root, array_t1);
  print_hightless_req(root, array_t2);
  ck_assert_int_eq(-1, equel_array(array_t1, array_t2, 10000));
  clear(root);
}
END_TEST

START_TEST(DROP_child) {
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  drop(&root, -21);
  ck_assert_int_ne(-21, min_tree(root));
  clear(root);
}
END_TEST

START_TEST(DROP_node_right_child1) {
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  tree_d *node = search_d(root, 41);
  node = node->parent;
  drop(&root, 41);
  ck_assert_int_eq(44, node->left->data);
  clear(root);
}
END_TEST

START_TEST(DROP_node_right_child2) {
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  tree_d *node = search_d(root, 22);
  node = node->parent;
  drop(&root, 22);
  ck_assert_int_eq(23, node->right->data);
  clear(root);
}
END_TEST

START_TEST(DROP_node_left_child1) {
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  insert(&root, 9);
  tree_d *node = search_d(root, 8);
  node = node->parent;
  drop(&root, 8);
  ck_assert_int_eq(9, node->right->data);
  clear(root);
}
END_TEST

START_TEST(DROP_node_left_child2) {
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  tree_d *node = search_d(root, 45);
  node = node->parent;
  drop(&root, 45);
  ck_assert_int_eq(41, node->left->data);
  clear(root);
}
END_TEST

START_TEST(DROP_node1) {
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  tree_d *node = search_d(root, 4);
  node = node->parent;
  drop(&root, 4);
  ck_assert_int_eq(4, node->left->data);
  clear(root);
}
END_TEST

START_TEST(DROP_node2) {
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  tree_d *node = search_d(root, 56);
  node = node->parent;
  drop(&root, 56);
  ck_assert_int_eq(75, node->right->data);
  clear(root);
}
END_TEST

START_TEST(DROP_root1) {
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  drop(&root, 34);
  ck_assert_int_eq(41, root->data);
  clear(root);
}
END_TEST

START_TEST(DROP_root2) {
  tree_d *root;
  new_tree(&root, 5);
  drop(&root, root->data);
  ck_assert_ptr_null(root);
}
END_TEST

START_TEST(DROP_root3) {
  tree_d *root;
  new_tree(&root, 5);
  insert(&root, 10);
  drop(&root, root->data);
  ck_assert_int_eq(10, root->data);
}
END_TEST

START_TEST(DROP_root4) {
  tree_d *root;
  new_tree(&root, 5);
  insert(&root, 2);
  drop(&root, root->data);
  ck_assert_int_eq(2, root->data);
}
END_TEST

START_TEST(DROP_search) {
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  tree_d *find = search_d(root, 22);
  ck_assert_int_eq(22, find->data);
}
END_TEST

START_TEST(DROP_search2) {
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  tree_d *find = search_d(root, 2222);
  ck_assert_ptr_null(find);
}
END_TEST

Suite *tree_d_suite() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("TREE BI");

  /*Core test case*/
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, PRINT_TOP1);
  tcase_add_test(tc_core, PRINT_TOP2);
  tcase_add_test(tc_core, PRINT_TOP3);
  tcase_add_test(tc_core, DROP_child);
  tcase_add_test(tc_core, DROP_node_right_child1);
  tcase_add_test(tc_core, DROP_node_right_child2);
  tcase_add_test(tc_core, DROP_node_left_child1);
  tcase_add_test(tc_core, DROP_node_left_child2);
  tcase_add_test(tc_core, DROP_node1);
  tcase_add_test(tc_core, DROP_node2);
  tcase_add_test(tc_core, DROP_root1);
  tcase_add_test(tc_core, DROP_root2);
  tcase_add_test(tc_core, DROP_root3);
  tcase_add_test(tc_core, DROP_root4);
  tcase_add_test(tc_core, DROP_search);
  tcase_add_test(tc_core, DROP_search2);
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