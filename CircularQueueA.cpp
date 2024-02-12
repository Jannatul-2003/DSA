#include <bits/stdc++.h>
using namespace std;
#define size 5
typedef int type;
struct CircluarQueue{
    type arr[size];
    int front;
    int rear;

    CircluarQueue()
    {
        front=rear=-1;
    }

    bool isEmpty()
    {
        if(front==-1)
            return true;
        return false;
   }

   bool isFull()
   {
        if(front==0 && rear==size-1)
            return true;
        else if(front==rear+1)
            return true;
        return false;
   }

   void enqueue(type x)
   {
        if(isFull())
            return;
        else
        {
            if(front==-1)
                front=0;
            rear=(rear+1)%size;
            arr[rear]=x;
            return;
        }
   }

   type dequeue()
   {
        if(isEmpty())
            return INT16_MIN;
        else
        {
            type element=arr[front];
            if(front==rear)//just one element on arr
                front=rear=-1;
            else
                front=(front+1)%size;
            return element;
        }
   }

   void print()
   {
        if(isEmpty())
            return;
        else
        {
            int i;
            for(i=front; i!=rear; i=(i+1)%size)
                cout<<arr[i]<<endl;
            
            cout<<arr[i]<<endl;
        }
   }
};

int main()
{
    struct CircluarQueue* cq=new CircluarQueue();

    cq->dequeue();

    int i=5,p=3;
    while(i--)
        cq->enqueue(p++);
    cout<<"baba"<<endl;
    cq->print();
    int x=cq->dequeue();
    //cout<<x<<endl;
    cq->enqueue(8);
        cout<<"baba"<<endl;

    cq->print();
}
