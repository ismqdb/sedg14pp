#include "./node_f.h"

node_f n_f_init(char c){
    node_f n;
    n.info = c;
    return n;
}

void visit_f(node_f *t){
    printf("%s\n", t->info);
}