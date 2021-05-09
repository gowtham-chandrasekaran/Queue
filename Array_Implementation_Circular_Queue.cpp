//Circular Queue Implementation. Only difference in code between this and linear implementation is front++ and rear++ and print function
#include<iostream>
using namespace std;
class queue{
    int q[10];
    int front;
    int rear;
    public:
    queue(){
        front = -1;
        rear = -1;
    }
    void enqeue(int x){
            if(isEmpty()){
                front = rear = 0;
                q[rear] = x;
            }
            else if(isFull()){
                cout<<"\n Cannot add as the list is full!"; return;
            }
            else{
                rear = (rear+1)%9;
                q[rear] = x;
            }
        }
        void deqeue(){
            if(isEmpty()){
                cout<<"\n Cannot delete as already empty!";
            }
            else if(front==rear){
                front = rear = -1;
            }
            else{
                front = (front+1)%9;
            }
        }
        int front_item(){
            return q[front];
        }
        bool isEmpty(){
            if(front==-1 && rear==-1) return true;
            return false;
        }
        bool isFull(){
            if( (rear+1)%9 == front ){
                return true;
            }
            return false;
        }
        void print(){
            if(isEmpty()){
                cout<<"\n Empty Queue! ";
            }
            else{
                int count = (rear+9-front)%9 + 1;
                cout<<"Queue       : ";
                for(int i = 0; i <count; i++)
                {
                    int index = (front+i) % 9; // Index of element while travesing circularly from front
                    cout<<q[index]<<" ";
                }
                cout<<"\n";
            }    
        }
};
int main(){

    queue Q;
    int front,empty;
    Q.enqeue(5); Q.print();// 5
    Q.enqeue(4); Q.print();// 5 4  
    Q.enqeue(3); Q.print();// 5 4 3
    Q.enqeue(2); Q.print();// 5 4 3 2 
    Q.enqeue(1); Q.print();// 5 4 3 2 1 
    front = Q.front_item(); // 5
    cout<<"\n Front: "<<front<<"\n";
    Q.deqeue(); Q.print();// 4 3 2 1 
    Q.deqeue(); Q.print();// 3 2 1
    front = Q.front_item(); // 3
    cout<<"\n Front: "<<front<<"\n";
    empty = Q.isEmpty();
    if(empty == 0) cout<<"\n Queue is not empty.\n ";
    Q.deqeue(); Q.print();// 2 1 
    Q.deqeue(); Q.print();// 1
    Q.deqeue(); Q.print();// 
    empty = Q.isEmpty();

}