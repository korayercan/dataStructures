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
void reverse(NODEPTR first){
    NODEPTR p;
    NODEPTR temp;
    NODEPTR previous = NULL;
    p = first;
    while(p!=NULL){
        temp = p->next;
        p->next = previous;
        previous = p;
        p = temp;
    }
    first = previous;
}

void sirali(NODEPTR p,int x){

    NODEPTR q,r;
    while(p!=NULL){
        q=p->next;
        if(q!=NULL){
            if(p->info>x&&q->info<x){
                r=get_node();
                r->info = x;
                p->next = r;
                r->next = q;
            }
            else{
                p=q;
            }
        }
        else{
            q=get_node();
            q->info=x;
            p->next = q;
        }
    }
}


int main()
{
    int x;
    NODEPTR first = get_node();
    first->info=NULL;
    NODEPTR p=first;
    //first->next = p;
    p->next = NULL;
    while(true){
        cin>>x;
        if(x == EOF){
            break;
        }
        push(p,x);
        p = p->next;
    }

    for(p = first->next; p != NULL ; p = p -> next){
        cout << p->info << endl;
    }


    return 0;
}
