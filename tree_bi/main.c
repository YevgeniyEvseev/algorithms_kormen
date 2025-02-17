#include <stdio.h>

#include "tree_d.h"

int main() {
#if 0
  int tmp[17] = {34, 12, 4, 56, 2, 22, 23, -9, 0, 4, 1, 8, 45, 41, -21, 44, 75};
  int array[20] = {0};
  tree_d *root;
  new_tree(&root, *tmp);
  for (int i = 1; i < 17; ++i) {
    insert(&root, tmp[i]);
  }
  printf("min =%d\n", min_tree(root));
  printf("max = %d\n", max_tree(root));
  print_hightless_req(root, array);
  printf("\n");
  print_hightless(root, array);
  drop(&root, -21);
  drop(&root, 22);
  drop(&root, 2);
  drop(&root, 12);
  drop(&root, 56);
  drop(&root, 34);
  // print_hightless(root);
  while (root->left != NULL) {
    drop(&root, root->left->data);
    print_hightless(root, array);
  }
  while (root->right != NULL) {
    drop(&root, root->right->data);
    print_hightless(root, array);
  }

  clear(root);
#endif

  tree_d *root = NULL;

  drop(&root, root->data);
}