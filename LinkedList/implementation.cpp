#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int x){
        data = x;
    }
};

class LinkedList{
    public:
    Node * head;

    LinkedList(){ // default constructor
        head = nullptr;
    }

    LinkedList(int data){ // parameterized constructor
       head = new Node(data);
    }

    void insertAtBeginning(int data){
        Node * temp = new Node(data);
        temp -> next = head;
        head = temp;
    }

    void insertNode(int pos, int data){
        Node * temp = head;
        int i = 1;
        while(i < pos){
            temp = temp -> next;
            i++;
        }

        Node * temp2 = new Node(data);
        temp2 -> next = temp -> next;
        temp -> next = temp2;
    }

    void printlist(){
        Node * temp = head;
        while(temp != nullptr){
            cout << temp -> data << " " ;
            temp = temp -> next;
        }
        cout << endl;
    }

    void deleteAtBeginning(){
        if(head == nullptr || head -> next == nullptr) return;

        Node * temp = head;
        head = head -> next;
        delete(temp);
    }

    void deleteNode(int pos){
        int i = 1;
        Node * temp = head;
        while(i < pos){
            temp = temp -> next;
            i++;
        }

        Node * removalNode = temp -> next;
        temp -> next = removalNode -> next;
        delete(removalNode);
    }
};

int main(){

    Node header = Node(4); //Stack implementation of class ie Static memory allocation
    cout << header.data << endl; 

    Node * head = new  Node(2); //Heap implementation of class ie dynamic memory allocation
    cout << head -> data << endl;

    //inserting a node
    LinkedList * ll = new LinkedList();

    ll->insertAtBeginning(4);
    ll->insertAtBeginning(5);
    ll->insertNode(2,3);
    ll->printlist(); // 5 4 3

    //deleting a node
    ll->deleteNode(2);
    ll->deleteAtBeginning();
    ll->printlist(); // 4
    return 0;
}