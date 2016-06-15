#include <iostream>
#include <stdlib.h>

using namespace std;


struct Node{
    int data;
    Node *next;
};

struct List{
  Node *head;
};



void insertEnd(List *l,Node *n);
void printList(List *l);
Node* initNode(int d);
void createList(List *l);
void pop(List *l);

int main()
{
    List *linkedList = (List*)malloc(sizeof(List));
    linkedList->head = NULL;
    char value;
    int data;
    createList(linkedList);

    while(value != 'q'){
        cout << "Please enter a command: A-add a node, P-pop first node, L-display list." << endl;
        cin >> value;
        switch(value)
        {
        case 'A':
            cout << "Enter value: " << endl;
            cin >> data;
            insertEnd(linkedList, initNode(data));
            break;

        case 'P':
            pop(linkedList);
            break;
        case 'L':
            printList(linkedList);
            break;

        }

    }


    return 0;
}

Node* initNode(int d){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = d;
    head->next = NULL;
    return head;
}

void insertEnd(List *l, Node *n){

    if(l->head == NULL){
        //cout << "list null added " << n->data << endl;
        l->head = n;
        return;
    }
Node *ptr = l->head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    cout << "Added " << n->data << endl;
    ptr->next = n;
}

void pop(List *l){
    if(l->head == NULL){
        cout << "There is nothing to pop" << endl;
        return;
    }
    Node *ptr = l->head;
    if(ptr->next == NULL){
        l->head = NULL;
    }
    l->head = ptr->next;
    cout << "Removed: " << ptr->data << endl;
    free(ptr);
}

void printList(List *l){
    Node *ptr = l->head;

    if(l->head == NULL){
        cout << "List is empty." << endl;
    }
    while(ptr != NULL){
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

void createList(List *l){
    Node *a, *b, *c, *d, *e;
    a = initNode(1);
    b = initNode(2);
    c = initNode(3);
    d = initNode(4);
    e = initNode(5);

    insertEnd(l, a);
    insertEnd(l, b);
    insertEnd(l, c);
    insertEnd(l, d);
    insertEnd(l, e);


}

