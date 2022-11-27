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
        Node *current = head;
        int c = 0;
        while(current !=NULL){
            if(c == inx-1){
                Node *new_node = new Node(data);
                Node *next_node = current->next;
                current->next = new_node;
                new_node->prev = current;
                new_node->next = next_node;
                if(next_node != NULL){
                    next_node->prev = new_node;
                }  
            }
            else{
                c++;
                current = current->next;
            }
        }
    }
    void reversed(){
        Node *current = head;
        Node *temp = NULL;
        while(current != NULL){
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->next;
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