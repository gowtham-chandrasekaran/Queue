//Implementation of queue using linked list
#include<iostream>
using namespace std;
struct queue{
    int data;
    queue* next;
};
queue* front;
queue* rear;
void enqueue(int data){
    queue* temp = new queue();
    temp->data = data;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}
void dequeue(){
    if(front == rear){
        front = rear = NULL;
    }
    else{
        queue* temp = front;
        front = temp->next;
        delete(temp);
    }
}
void print(){
    if(front == NULL && rear == NULL){
        cout<<"\n Empty queue. ";
    }
    else{
         queue* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
    }
    cout<<"\n";
    }
}
int main(){
    front = rear = NULL; //empty queue
    enqueue(5); print(); // 5
    enqueue(4); print(); // 5 4
    enqueue(3); print(); // 5 4 3 
    enqueue(2); print(); // 5 4 3 2 
    enqueue(1); print(); // 5 4 3 2 1 
    dequeue(); print(); // 5 4 3 2 
    dequeue(); print(); // 5 4 3 
}