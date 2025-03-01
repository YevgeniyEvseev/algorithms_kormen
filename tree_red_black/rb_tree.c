#include "rb_tree.h"

#include <stdio.h>
#include <stdlib.h>

void new_tree(Tree_rb_t **root, int data) {
  Tree_rb_t *tmp = malloc(sizeof(Tree_rb_t));
  Tree_rb_t *nil = malloc(sizeof(Tree_rb_t));
  nil->color = BLACK;
  tmp->parent = nil;
  tmp->left = nil;
  tmp->right = nil;
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

void rotate_right(Tree_rb_t **root, Tree_rb_t *data) {
  Tree_rb_t *centr = data;
  Tree_rb_t *rad = centr->parent;
  if (rad == NIL) return;
  rad->left = centr->right;
  if (rad->left != NIL) rad->left->parent = rad;
  if (rad->parent == NIL) {
    centr->parent = NIL;
    *root = centr;
  } else {
    if (rad->parent->left == rad) {
      rad->parent->left = centr;
    } else {
      rad->parent->right = centr;
    }
    centr->parent = rad->parent;
  }
  centr->right = rad;
  rad->parent = centr;
}
void rotate_left(Tree_rb_t **root, Tree_rb_t *data) {
  Tree_rb_t *centr = data;
  Tree_rb_t *nil = NIL;
  if (centr == NULL || centr->right == NIL) return;
  Tree_rb_t *rad = centr->right;
  //  if (rad->left != NULL) {
  centr->right = rad->left;
  if (centr->right != NIL) centr->right->parent = centr;
  //}
  if (centr->parent == NIL) {
    *root = rad;
    rad->parent = nil;
  } else {
    if (centr->parent->left == centr)
      centr->parent->left = rad;
    else
      centr->parent->right = rad;
    rad->parent = centr->parent;
  }
  rad->left = centr;
  centr->parent = rad;
}

void rb_insert(Tree_rb_t **root, int data) {
  Tree_rb_t *p_tmp = *root;
  Tree_rb_t *new_list = malloc(sizeof(Tree_rb_t));
  while (p_tmp != NIL) {
    if (p_tmp->key <= data) {
      if (p_tmp->right == NIL) {
        p_tmp->right = new_list;
        new_list->parent = p_tmp;
        break;
      }
      p_tmp = p_tmp->right;
    } else {
      if (p_tmp->left == NIL) {
        p_tmp->left = new_list;
        new_list->parent = p_tmp;
        break;
      }
      p_tmp = p_tmp->left;
    }
  }
  new_list->key = data;
  new_list->right = NIL;
  new_list->left = NIL;
  new_list->color = RED;
  rb_insert_fix(root, new_list);
}
void rb_insert_fix(Tree_rb_t **root, Tree_rb_t *p_data) {
  while (p_data->parent->color == RED) {
    if (p_data->parent->parent->left == p_data->parent) {
      Tree_rb_t *uncle = p_data->parent->parent->right;
      if (uncle->color == RED) {
        uncle->color = BLACK;
        p_data->parent->color = BLACK;
        p_data->parent->parent->color = RED;
        // if (p_data->parent->parent == *root) break;
        p_data = p_data->parent->parent;
      } else {                                  // uncle is null or black
        if (p_data->parent->right == p_data) {  // p_data is right
          rotate_left(root, p_data->parent);
          p_data = p_data->left;
        }
        p_data->parent->color = BLACK;
        p_data->parent->parent->color = RED;
        rotate_right(root, p_data->parent);
      }
    } else {
      Tree_rb_t *uncle = p_data->parent->parent->left;
      if (uncle->color == RED) {
        uncle->color = BLACK;
        p_data->parent->color = BLACK;
        p_data->parent->parent->color = RED;
        //  if (p_data->parent->parent == *root) break;
        p_data = p_data->parent->parent;
      } else {                                 // uncle is null or black
        if (p_data->parent->left == p_data) {  // p_data is left
          rotate_right(root, p_data);
          p_data = p_data->right;
        }
        p_data->parent->color = BLACK;
        p_data->parent->parent->color = RED;
        rotate_left(root, p_data->parent->parent);
      }
    }
  }
  (*root)->color = BLACK;
}

Tree_rb_t *min_tree(Tree_rb_t *root, Tree_rb_t *p_data) {
  Tree_rb_t *min = p_data;
  while (min->left != NILl) {
    min = min->left;
  }
  return min;
}
Tree_rb_t *tree_successor(Tree_rb_t *root, Tree_rb_t *p_data) {
  if (p_data->right != NILl) return min_tree(root, p_data->right);
  Tree_rb_t *parent = p_data->parent;
  while (parent != NILl && parent->right == p_data) {
    p_data = parent;
    parent = p_data->parent;
  }
  return p_data;
}

void print_tree_rb(Tree_rb_t **root, Tree_rb_t *p_data) {
  // static int l_level = 0, r_level = 0;
  printf("%d ", p_data->key);
  if (p_data != NIL) print_tree_rb(root, p_data->left);
  if (p_data != NIL) print_tree_rb(root, p_data->right);
}