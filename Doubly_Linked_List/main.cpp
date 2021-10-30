#include <iostream>

using namespace std;

struct node{
    int info;
    struct node *left, *right;
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
    NODEPTR r,q;
    if(p==NULL){
        cout<< "void insertion" <<endl;
        exit(1);
    }
    if(p->right ==NULL){
        q = get_node();
        q->info = x;
        p->right = q;
        q->left = p;
        q->right=NULL;
    }
    else{
        q = get_node();
        //r= get_node();
        q->info = x;
        r = p->right;
        r->left = q;
        q->right = r;
        q->left = p;
        p->right = q;
    }

}

void pop(NODEPTR p, int *px){
    NODEPTR q,r;
    if(p==NULL){
        cout<<"void deletion"<<endl;
        exit(1);
    }
    *px = p->info;
    q = p->left;
    r = p->right;
    q->right = r;
    r->left = q;
    freenode(p);
}
int main()
{
    NODEPTR first = get_node();
    first->info=5;
    push(first,10);
    push(first->right,15);
    cout<< "first" << first->right->right->info << endl;

    return 0;
}
