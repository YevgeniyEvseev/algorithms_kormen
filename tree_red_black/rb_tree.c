#include "rb_tree.h"

#include <stdlib.h>

void new_tree(Tree_rb_t **root, int data) {
  Tree_rb_t *tmp = malloc(sizeof(Tree_rb_t));
  tmp->parant = NULL;
  tmp->left = NULL;
  tmp->right = NULL;
  tmp->key = data;
  tmp->color = BLACK;
  *root = tmp;
}

Tree_rb_t *search_d(Tree_rb_t *root, int data) {
  while (root != NULL) {
    if (root->key == data) return root;
    if (root->key < data) {
      root = root->right;
    } else {
      root = root->left;
    }
  }
  return root;
}

void rotate_right(Tree_rb_t *root, int data) {}
void rotate_left(Tree_rb_t *root, int data) {
  Tree_rb_t *centr = search_d(root, data);
  if (centr == NULL || centr->right == NULL) return;
  Tree_rb_t *rad = centr->right;
  if (rad->left != NULL) {
    centr->right = rad->left;
    centr->right->parant = centr;
  }
  if (centr->parant == NULL) {
    rad->parant = NULL;
  } else {
    if (centr->parant->left == centr)
      centr->parant->left = rad;
    else
      centr->parant->right = rad;
    rad->parant = centr->parant;
  }
  rad->left=centr;
  centr->parant=rad;
}