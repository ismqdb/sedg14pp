/* ******************************************************************************** */

#include <iostream>
#include <vector>

/* ******************************************************************************** */

struct node {
    public:
        node(int val) : key{val}, next{NULL}{}
        node() : key{0}, next{NULL}{}

        int key;
        struct node *next;
};

/* ******************************************************************************** */

class linkedList {
    public:
        linkedList();
        ~linkedList();

        void deleteNext(struct node*);
        struct node* insertAfter(int, struct node*);
        struct node* moveNextToFront(struct node*);
        void exchange(struct node*, struct node*);
    private:
        struct node* head;
        struct node* tail;
};

/* ******************************************************************************** */

linkedList::~linkedList(){
    delete(head);
    delete(tail);
}

linkedList::linkedList(){
    this->head = new node{};
    this->tail = new node{};

    head->next = tail;
    tail->next = tail;
}

/* ******************************************************************************** */

void linkedList::deleteNext(struct node *t){
    struct node *x = t->next;
    t->next = t->next->next;
    delete(x);
}

struct node* linkedList::insertAfter(int v, struct node *t){
    if(t == NULL)
        return NULL;

    struct node *x = new node{};
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

struct node* linkedList::moveNextToFront(struct node *t){
    struct node *temp = t->next;
    t->next = t->next->next;
    
    temp->next = head->next;
    head->next = temp;
    return temp;
}

void linkedList::exchange(struct node *t, struct node *u){
    struct node *temp = t->next;
    
    t->next = t->next->next;
    temp->next = u->next->next;
    
    u->next->next = t->next;
    t->next = u->next;

    u->next = temp;
}

/* ******************************************************************************** */

void massSuicide(int n, int m){
    if(n <= 0 || m <= 0)
        return;

    if(n<m)
        return;

    int i;
    struct node *head;

    struct node *t = new node{};
    t->key = 0;
    head = t;

    for(i = 0; i < n; i++){
        t->next = new node{};
        t = t->next;
        t->key = (i+1);
    }
    t->next = head;

    while(t != t->next){
        for(i = 0; i < m; i++)
            t = t->next;
            
        std::cout << t->next->key << ' ';
        head = t->next;
        t->next = t->next->next;
        delete(head);
    }

    std::cout << t->key << '\n';
}

/* ******************************************************************************** */

int masssuicideArray(int n, int m){
    if(n <= 0 || m <= 0)
        return -1;

    if(n<m)
        return -1;

    std::vector<int> array(n);

    int noOfDead = 0;
    int currentCount;

    for(int i = 0; i < n; i++)
        array[i] = 1;

    int i = 0;

    while(noOfDead < (n-1)){
        currentCount = 0;
        int idx;

        while(1){
            if(currentCount == m){
                idx = i-1;
                break;
            }
            if(i == n)
                i = 0;
            if(array[i++] == 1)
                currentCount++;
        }

        std::cout << idx << '\n';
        array[idx] = 0;
        noOfDead++;
    }

    for(int i = 0; i < n; i++)
        if(array[i] == 1){
            return i;
        }
}

/* ******************************************************************************** */

int main(){
    linkedList list{};
    
}

/* ******************************************************************************** */