#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data, Node *next = NULL,Node * prev = NULL){
        this->next = next;
        this->prev = prev;
        this->data = data;
    }
};
class doublyLinkedList{
    Node *head;
    public:
    doublyLinkedList(){
        head = NULL;
    }
    void push_front(int data){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }
        else{
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
        }
    }
    void push_back(int data){
        Node *node = new Node(data);
        if(head == NULL){
            head = node;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node;
            node->prev = temp;
        }
    }
    void insert(int inx, int data){
        Node *newNode = new Node(data);
        Node *temp = head;
        int counter = 1;
        if(head==NULL){
            push_front(data);
        }

        else{
            while(temp !=NULL){
            if(counter == inx){
                Node *previous = temp->prev;
                newNode->next = previous->next;
                previous->next = newNode;
                newNode->prev = previous;
            }
            else{
            counter++;
            temp = temp->next;
            }
        }
        }
        
    }
    void print(){
        Node *temp = head;
        int counter = 0;
        while (temp != NULL)
        {
            cout<<counter<<"th index is = "<<temp->data<<endl;
            temp = temp->next;
            counter++;
        }
        
    }
};

int main(){

    doublyLinkedList *list = new doublyLinkedList();
    list->push_back(5);
    list->push_back(15);
    list->push_back(25);
    list->push_back(35);
    list->push_back(45);
    list->push_front(55);
    list->push_front(65);
    list->insert(2,31);
    list->print();
}