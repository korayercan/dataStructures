#include <iostream>

#define STACKSIZE 100

using namespace std;


struct Stack{
    int top = -1;
    int items[STACKSIZE];
};

struct Stack s;

int empty(struct Stack *ps){
    if(ps->top == -1){
        return true;
    }
    else{
        return false;
    }
}

void push(struct Stack *ps,int x){
    if(ps->top==STACKSIZE-1){
        cout << "Stack overflow" << endl;
        exit(1);
    }
    else{
        int y = (ps->top)++;
        ps->items[y]=x;
        cout<< "Pushed" <<endl;
    }
}

int pop(struct Stack *ps){
    if(empty(ps)){
        cout << "Stack underflow" << endl;
        exit(1);
    }
    int y = ps->items[top];
    (ps->top)--;

    return y;
}


int main()
{

    return 0;
}
