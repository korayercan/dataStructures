#include <iostream>

using namespace std;

struct node{
    int info;
    struct node *left,*right,*father;
};
typedef struct node *NODEPTR;

NODEPTR get_node(){
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct node));
    return p;
}

NODEPTR maketree(int x){
    NODEPTR p;
    p=get_node();
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void push_left(NODEPTR p, int x){
    if(p==NULL){
        cout<< "void insertion" << endl;
    }
    else if(p->left != NULL){
        cout << "invalid insertion" << endl;
    }
    else{
        p->left = maketree(x);
    }
}

void push_right(NODEPTR p, int x){
    if(p==NULL){
        cout<< "void insertion" << endl;
    }
    else if(p->right != NULL){
        cout << "invalid insertion" << endl;
    }
    else{
        p->right = maketree(x);
    }
}
//DLR
void pretrav(NODEPTR p){
    if(p != NULL){
        cout << p->info <<endl;
        pretrav(p->left);
        pretrav(p->right);
    }
}
//LDR
void intrav(NODEPTR p){
    if(p != NULL){
        intrav(p->left);
        cout << p->info <<endl;
        intrav(p->right);
    }
}
//LRD
void posttrav(NODEPTR p){
    if(p != NULL){
        posttrav(p->left);
        posttrav(p->right);
        cout << p->info <<endl;
    }
}


int main()
{
    NODEPTR ptree, p, q;
    int num;

    cin >> num;
    ptree = maketree(num);

    while(true){
        cin >> num;
        if(num == EOF){
            break;
        }

        p=q=ptree;

        while(num!=p->info && q != NULL){
            p = q;
            if(num < p->info){
                q = p->left;
            }
            else{
                q = p->right;
            }
        }

        if(num == p->info){
            cout << num << "is a dublicate" << endl;
        }
        else if(num<p->info){
            push_left(p,num);
        }
        else{
            push_right(p,num);
        }
    }
    return 0;
}
