#ifndef RB_TREE_H
#define RB_TREE_H

#define RED 5
#define BLACK 6
#define WIDTH_WIN 80
#define NIL (*root)->parent
#define NILl root->parent

typedef struct Node_t {
  int color;
  struct Node_t *parent;
  struct Node_t *left;
  struct Node_t *right;
  int key;
} Tree_rb_t;

void new_tree(Tree_rb_t **root, int data);
void rotate_right(Tree_rb_t **root, Tree_rb_t *data);
void rotate_left(Tree_rb_t **root, Tree_rb_t *data);
void rb_insert(Tree_rb_t **root, int data);
void rb_insert_fix(Tree_rb_t **root, Tree_rb_t *p_data);
Tree_rb_t *min_tree(Tree_rb_t *root, Tree_rb_t *p_data);
Tree_rb_t *tree_successor(Tree_rb_t *root, Tree_rb_t *p_data);
void delete_tree_rb(Tree_rb_t **root, Tree_rb_t *p_data);
void rb_del_fix(Tree_rb_t *p_data);

    void print_tree_rb(Tree_rb_t **root, Tree_rb_t *p_data);

#endif
