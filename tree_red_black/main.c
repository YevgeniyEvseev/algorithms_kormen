#include <stdio.h>
#include "rb_tree.h"

int main(){
    Tree_rb_t *root=NULL;
    new_tree(&root, 5);
    
    printf("%d\n",root->key);
}