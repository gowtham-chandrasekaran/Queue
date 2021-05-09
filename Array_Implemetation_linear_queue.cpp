//Linear Queue implementation
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
                cout<<"\n Cannot add as the list is full!";
            }
            else{
                rear++;
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
                front++;
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
            if( rear == 9 ){
                return true;
            }
            return false;
        }
        void print(){
            if(isEmpty()){
                cout<<"\n Empty Queue! ";
            }
            else{
                for(int i = front; i <=rear; i++){
                cout<<" "<<q[i]<<" ";
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
    if(empty == 1) cout<<"\n Queue is empty.\n ";
}