#include "tree_d.h"

#include <stdio.h>
#include <stdlib.h>

void new_tree(tree_d **root, int data) {
  tree_d *tmp = malloc(sizeof(tree_d));
  tmp->parent = NULL;
  tmp->left = NULL;
  tmp->right = NULL;
  tmp->data = data;
  *root = tmp;
}

void insert(tree_d **root, int n) {
  tree_d *p_tmp = *root;
  tree_d *new_list = malloc(sizeof(tree_d));
  while (p_tmp != NULL) {
    if (p_tmp->data <= n) {
      if (p_tmp->right == NULL) {
        p_tmp->right = new_list;
        new_list->parent = p_tmp;
        break;
      }
      p_tmp = p_tmp->right;
    } else {
      if (p_tmp->left == NULL) {
        p_tmp->left = new_list;
        new_list->parent = p_tmp;
        break;
      }
      p_tmp = p_tmp->left;
    }
  }
  new_list->data = n;
  new_list->left = NULL;
  new_list->right = NULL;
}
void clear(tree_d *root) {
  if (root == NULL) return;
  if (root->left != NULL) clear(root->left);
  if (root->right) clear(root->right);
  free(root);
}
void drop(tree_d **root, int data) {
  tree_d *p_key = search_d(*root, data);
  tree_d *p_tmp = p_key;
  if (p_key == NULL) return;
  // if (p_key->parent == NULL) free(root);
  if (p_key->left == NULL && p_key->right == NULL) {
    if (p_key->parent != NULL) {
      if (p_key == p_tmp->parent->left) {
        p_tmp->parent->left = NULL;
      } else {
        p_tmp->parent->right = NULL;
      }
    }
    free(p_key);
    if (p_key == *root) *root = NULL;
    return;
  }
  if (p_key->left == NULL && p_key->right != NULL) {
    p_tmp = p_tmp->parent;
    if (p_key == *root) {
      *root = p_key->right;
    } else {
      if (p_tmp->right == p_key) {
        p_tmp->right = p_key->right;
        p_tmp->right->parent = p_tmp;
      } else {
        p_tmp->left = p_key->right;
        p_tmp->left->parent = p_tmp;
      }
    }
    free(p_key);
    return;
  }
  if (p_key->right == NULL && p_key->left != NULL) {
    p_tmp = p_tmp->parent;
    if (p_key == *root) {
      *root = p_key->left;
    } else {
      if (p_tmp->left == p_key) {
        p_tmp->left = p_key->left;
        p_tmp->left->parent = p_tmp;
      } else {
        p_tmp->right = p_key->left;
        p_tmp->right->parent = p_tmp;
      }
    }
    free(p_key);
    return;
  }
  if (p_key->right != NULL && p_key->right != NULL) {
    tree_d *min = p_tmp->right;
    while (min->left != NULL) {
      min = min->left;
    }

    if (min->right == NULL) {
      if (min->parent != p_key) {  // if left child
        min->parent->left = NULL;
      } else  // right child
        min->parent->right = NULL;
    } else {
      if (min->parent != p_key) {
        min->parent->left = min->right;
        min->right->parent = min->parent;
      } else {
        p_tmp->right = min->right;
      }
    }

    min->right = p_tmp->right;
    min->left = p_tmp->left;
    min->parent = p_tmp->parent;
    if (p_tmp->parent != NULL)
      if (p_tmp->parent->left == p_tmp) {
        p_tmp->parent->left = min;  // left branch
      } else {
        p_tmp->parent->right = min;  // right branch
                                     //      p_tmp->right->parent = min;
      }
    else {
      *root = min;
      p_tmp->right->parent = min;
    }
    p_tmp->left->parent = min;
    free(p_key);
  }
}
void print_hightless_req(tree_d *root, int *array) {
  tree_d *tmp = root;
  static int i = 0;
  if (tmp == NULL) return;
  print_hightless_req(tmp->left, array);
  // printf("n%d %d\n", i++, tmp->data);
  array[i++] = tmp->data;
  print_hightless_req(tmp->right, array);
}

void print_hightless(tree_d *root, int *array) {
  tree_d *r_tmp = NULL;
  tree_d *p_tmp = root;
  int i = 0;
  do {
    if (p_tmp->left != NULL && p_tmp->left != r_tmp &&
        p_tmp->right != r_tmp)  // left branching
      while (p_tmp->left != NULL) {
        p_tmp = p_tmp->left;
      }
    if (p_tmp->right != r_tmp ||
        (p_tmp->left == NULL && p_tmp->right == NULL)) {  // right branch
      // printf("%d ", p_tmp->data);
      array[i++] = p_tmp->data;
    }
    if (p_tmp->right != NULL && p_tmp->right != r_tmp) {
      r_tmp = p_tmp;
      p_tmp = p_tmp->right;
      continue;
    }
    r_tmp = p_tmp;
    p_tmp = p_tmp->parent;

  } while (p_tmp != NULL);
  // printf("\n");
}

// return ptr if equil key. return NULL if key is not find
tree_d *search_d(tree_d *root, int key) {
  while (root != NULL) {
    if (root->data == key) return root;
    if (root->data < key) {
      root = root->right;
    } else {
      root = root->left;
    }
  }
  return root;
}
int min_tree(tree_d *root) {
  tree_d *p_tmp = root;
  while (p_tmp->left != NULL) {
    p_tmp = p_tmp->left;
  }
  return p_tmp->data;
}
int max_tree(tree_d *root) {
  tree_d *p_tmp = root;
  while (p_tmp->right != NULL) {
    p_tmp = p_tmp->right;
  }
  return p_tmp->data;
}