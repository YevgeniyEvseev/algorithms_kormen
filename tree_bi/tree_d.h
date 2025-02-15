#ifndef TREE_D_H
#define TREE_D_H

#define TRUE 1
#define FALSE 0

typedef struct page {
  int n;
  char *str[60];
} page_t;

typedef struct tree_d {
  struct tree_d *parent;
  struct tree_d *left;
  struct tree_d *right;
  int data;
} tree_d;

void new_tree(tree_d **root, int data);
void insert(tree_d **root, int data);
void clear(tree_d *root);
void drop(tree_d **root, int data);
void print_hightless(tree_d *root, int *array);
void print_hightless_req(tree_d *root, int *array);
tree_d *search_d(tree_d *root, int key);
int min_tree(tree_d *root);
int max_tree(tree_d *root);

#endif