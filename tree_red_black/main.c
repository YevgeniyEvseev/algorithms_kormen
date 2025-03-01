#include <stdio.h>

#include "rb_tree.h"

int main() {
  Tree_rb_t *root = NULL;
  new_tree(&root, 17);
  for (int i = 16; i >= 0; --i) {
    rb_insert(&root, i);
  }
  print_tree_rb(&root, root);
}