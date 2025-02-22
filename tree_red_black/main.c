#include <stdio.h>

#include "rb_tree.h"

int main() {
  Tree_rb_t *root = NULL;
  new_tree(&root, 5);
  rb_insert(&root, 7);
  rb_insert(&root, 6);
  rb_insert(&root, 11);

  printf("%d\n", root->key);
}