char *key;
char *next;
char current, head, z;

void listinitialize(int size){
    key = (char*)malloc(size*sizeof(char));
    next = (char*)malloc(size*sizeof(char));

    head = 0;
    z = 1;
    current = 2;

    next[head] = z;
    next[z] = z;
}

void listdeinit(){
    free(key);
    free(next);
}

void deletenext(char t){
    next[t] = next[next[t]];
}

char insertafter(char new, char existing){
    key[current] = new;

    next[current] = next[existing];
    next[existing] = current;

    return current++;
}

void printAll(){
    char x = next[head];

    while(x != next[x]){
        printf("%c ", key[x]);
        x = next[x];
    }

    putchar(10);
}