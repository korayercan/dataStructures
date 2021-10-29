#include <iostream>

using namespace std;

struct node{
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;

NODEPTR get_node(void){
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct node));
    return p;
}
void freenode(NODEPTR p){
    free(p);
}
void push(NODEPTR p, int x){
    NODEPTR q;
    if(p == NULL){
        cout<< "void insertion" <<endl;
        exit(1);
    }
    q = get_node();
    q->info = x;
    q->next = p->next;
    p->next = q;
}

void pop(NODEPTR p, int *px){
    NODEPTR q;
    if(p == NULL || p->next == NULL){
        cout<< "void deletion"<<endl;
        exit(1);
    }
    q = p->next;
    *px = q -> info;
    p->next = q->next;
    freenode(q);
}

NODEPTR search(NODEPTR first,int x){
    NODEPTR p;

    for(p = first ; p != NULL ; p = p->next){
        if(p->info == x){
            return p;
        }
    }
    return NULL;
}


int main()
{
    return 0;
}
