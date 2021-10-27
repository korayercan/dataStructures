#include <iostream>

#define MAXSIZE 100

using namespace std;

struct Queue{
 int items[MAXSIZE];
 int front=MAXSIZE-1,rear=MAXSIZE-1;
};

int empty(struct Queue *pq){
    return pq->front == pq->rear ? true : false;
}

void push(struct Queue *pq , int x){

    if(pq->rear==MAXSIZE-1){
        pq->rear = 0;
    }
    else{
        pq->rear++;
    }
    if(pq->rear == pq->front){
        cout<< "Queue overflow" << endl;
        exit(1);
    }
    pq->items[pq->rear] = x;
}

int pop(struct Queue *pq){

    if(empty(pq)){
        cout << "Queue underflow" << endl;
        exit(1);
    }
    if(pq->front == MAXSIZE -1){
        pq->front = 0;
    }
    else{
        pq->front++;
    }
    return pq->items[pq->front];
}

int main()
{
    struct Queue q;
    struct Queue *pq = &q;
    int x = 10 ;
    push(pq,x);
    cout<<pop(pq);
    return 0;
}
