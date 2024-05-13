#include<bits/stdc++.h>
using namespace std;
struct LinkedListNode
{
    int data;
    LinkedListNode *next;
};
struct LinkedList{
    LinkedListNode *head = NULL;
    LinkedListNode *tail = NULL;
    void insert_last(int value){
        LinkedListNode *newNode = new LinkedListNode();
        newNode->data = value;
        newNode->next = NULL;
        if(tail){
            tail->next = newNode;
            tail = newNode;
        }
        else{
            head = newNode;
            tail = newNode;
        }
    }
    void print(){
        LinkedListNode *temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
struct LinkedListofLinkedListNode{
    LinkedList *list;
    LinkedListofLinkedListNode *next;
};
struct LinkedListofLinkedList{
    LinkedListofLinkedListNode *head = NULL;
    LinkedListofLinkedListNode *tail = NULL;
    void insert_last(LinkedList *value){
        LinkedListofLinkedListNode *newNode = new LinkedListofLinkedListNode();
        newNode->list = value;
        newNode->next = NULL;
        if(tail){
            tail->next = newNode;
            tail = newNode;
        }
        else{
            head = newNode;
            tail = newNode;
        }
    }
    
};

LinkedList* sortLinkedListofLinkedList(LinkedListofLinkedList *list){
    LinkedList *sortedList = list->head->list;
    LinkedListofLinkedListNode *temp = list->head->next;
    if(!temp) return sortedList;
    while(temp){
        LinkedList* nextList = temp->list;
        LinkedListNode *currentNode = sortedList->head;
        LinkedListNode *nextNode = nextList->head;
        LinkedList *newList = new LinkedList();
        while(currentNode && nextNode){
            if(currentNode->data > nextNode->data){
                newList->insert_last(nextNode->data);
                nextNode = nextNode->next;
            }
            
            else if(currentNode->data < nextNode->data){
                newList->insert_last(currentNode->data);
                currentNode = currentNode->next;
            }
            else{
                newList->insert_last(nextNode->data);
                newList->insert_last(currentNode->data);
                nextNode = nextNode->next;
                currentNode = currentNode->next;
            }
        }
        while(currentNode){
            newList->insert_last(currentNode->data);
            currentNode = currentNode->next;
        }
        while(nextNode){
            newList->insert_last(nextNode->data);
            nextNode = nextNode->next;
        }
        sortedList = newList;
        temp = temp->next;
    }
    return sortedList;
}

int main()
{
    int n,m,v;
    cin>>n;
    LinkedListofLinkedList *list = new LinkedListofLinkedList();
    for(int i=0;i<n;i++){
        cin>>m;
        LinkedList *newList = new LinkedList();
        for(int j=0;j<m;j++){
            cin>>v;
            newList->insert_last(v);
        }
        list->insert_last(newList);
    }
    LinkedList *sortedList = sortLinkedListofLinkedList(list);
    sortedList->print();
}