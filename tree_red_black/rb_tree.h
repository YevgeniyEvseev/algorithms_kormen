#ifndef RB_TREE_H
#define RB_TREE_H

#define RED 5
#define BLACK 6

typedef struct Node_t {
  int color;
  struct Node_t *parant;
  struct Node_t *left;
  struct Node_t *right;
  int key;
} Tree_rb_t;

void new_tree(Tree_rb_t **root, int data);
void rotate_right(Tree_rb_t *root, int data);
void rotate_left(Tree_rb_t *root, int data);

#endif
