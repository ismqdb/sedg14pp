/* ******************************************************************************** */

#include "./treeNode.h"

/* ******************************************************************************** */

treeNode* treeNodeInit(){
    treeNode *n = (treeNode*)malloc(sizeof(treeNode));
    return n;
};

treeNode* treeNodeInitChar(char c){
    treeNode *n = (treeNode*)malloc(sizeof(treeNode));
    n->info = c;
    return n;
};

void treeNodeDeinit(treeNode *n){
    free(n);
}

void visitTreeNode(treeNode *t){
    if(t == NULL)
        return;
    
    printf("%c ", t->info);
}

/* ******************************************************************************** */

int tnode_compare(const void *t1, const void *t2){
    struct tnodePair *d1 = *(struct tnodePair**)t1;
    struct tnodePair *d2 = *(struct tnodePair**)t2;

    return d1->index > d2->index;
}

/* ******************************************************************************** */

int binaryTreeDrawRecursive(struct treeNode* t, struct tnodePair **pairs, int left, int right){
        static int current = 0;
        if(t == NULL)
            return -1;
        else {
            struct tnodePair *x = (struct tnodePair*)malloc(sizeof(struct tnodePair));
            x->node = t;
            x->index = (left+right)/2;
            pairs[current++] = x;
        }

        if(t->left != NULL){
            int middle = (left+right)/2;
            binaryTreeDrawRecursive(t->left, pairs, left, middle);
        }

        if(t->right != NULL){
            int middle = (left+right)/2;
            binaryTreeDrawRecursive(t->right, pairs, middle, right);
        }

        return current;
}

/* ******************************************************************************** */

void externalPathLenTreeNode(treeNode *t, int level, int *len){
    if(t->left || t->right)
        level++;

    if(t->left)
        externalPathLenTreeNode(t->left, level, len);
    else
        len += level;

    if(t->right)
        externalPathLenTreeNode(t->right, level, len);
    else
        len += level;
}

/* ******************************************************************************** */

int binaryTreeDrawRecursiveDriver(){
    int screenWidth = 80;

    treeNode *t = build_parse_tree();
    struct tnodePair **pairs = (struct tnodePair**)calloc(20, sizeof(struct tnodePair**));

    int k = binaryTreeDrawRecursive(t, pairs, 0, screenWidth);

    qsort(pairs, k, sizeof(struct tnodePair*), tnode_compare);

    putchar(10);
    for(int pos = 0, printed = 0; pos < screenWidth; pos++){
        if(pairs[printed] == NULL){
            continue;
        }

        if(pairs[printed]->index == pos)
            printf("%c", (pairs[printed++]->node->info));
        else
            putchar(' ');
    }

    putchar(10);
    putchar(10);

    return 1;
}

/* ******************************************************************************** */