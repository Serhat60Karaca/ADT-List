#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data, Node *next = NULL){
        this->data = data;
        this->next = next;
    }
};
class linkedList{
    Node *head;
    public:
    linkedList(){
        head = NULL;
    }
    int get(int inx){
        Node *temp;
        temp = head;
        int c =0;
        while(temp !=NULL){
            if(c == inx){
                return (temp->data);
            }
            else{
                c++;
                temp = temp->next;
            }
        }
    }
    void push_front(int data){
        Node *newnode = new Node(data);
        if(head = NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }
    void push_back(int data){
        Node *newnode = new Node(data);
        if(head==NULL){
            head = newnode;
        }
        else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }
    }
    void insert(int data, int inx){
        Node *newnode = new Node(data);
        if(head==NULL){
            head = newnode;
        }
        else{
            Node *i = find(inx-1);
            newnode->next = i->next;
            i->next = newnode;
        }
    }
    Node *find(int inx){
        Node *temp = head;
        int c = 0;
        while(temp != NULL){
            if(c == inx){
                return temp;
            }
            else{
                c++;
                temp = temp->next;
            }
        }
    }
    void print(){
        Node *temp = head; 
        while (temp !=NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        
    }
};

int main(){
    linkedList *list1 = new linkedList();
    list1->push_front(5);
    list1->push_front(12);
    list1->push_back(25);
    list1->push_back(455);
    list1->push_back(322);
    list1->insert(16, 2);
    list1->print();
}