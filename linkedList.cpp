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
void removeElement(List *l, int value);

int main()
{
    List *linkedList = (List*)malloc(sizeof(List));
    linkedList->head = NULL;
    char value = 0;
    int data;
    createList(linkedList);

    while(value != 'q'){
        cout << "Please enter a command: "<< endl <<
                "A-add a node, P-pop first node, R-remove a node, L-display list." << endl;
        cin >> value;
        //If the value is lower case ( > 'Z' in binary),
        //remove the difference between upper and lower.
        //which is (0x32 hex or a space)

        if( value > 'Z'){ value -= ' ';}
        switch(value)
        {
        case ('A'):
            cout << "Enter value to add: " << endl;
            cin >> data;
            insertEnd(linkedList, initNode(data));
            break;

        case 'P':
            pop(linkedList);
            break;
        case 'L':
            printList(linkedList);
            break;
        case 'R':
            cout << "Enter value to remove: " << endl;
            cin >> data;
            removeElement(linkedList, data);
            break;
         default:
            cout << "Invalid command" << endl;
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


//Removing a element specified we have to "look ahead"
//so we can keep the pointer on the element before.
//Otherwise, we will lose the link between elements
void removeElement(List *l, int value){
    if(l->head == NULL){
        cout << "List is empty." << endl;
        return;
    }
    Node *ptr = l->head;
    Node *remove;
    //If remove value is first, set next to list head
    if(ptr->data == value){
        l->head = ptr->next;
        remove = ptr;
        cout << "Removed: " << remove->data << endl;
        free(remove);
        return;
    }
    //Check rest of list
    while(ptr->next != NULL){
        //if next is the value,
        if(ptr->next->data == value){
            //make pointer for remove node
            //set ptr to ptr->next->next
            Node *remove = ptr->next;
            ptr->next = ptr->next->next;
            cout << "Removed: " << remove->data << endl;
            free(remove);
            return;
        }
        ptr = ptr->next;
    }

    cout << "The value specified was not in list." << endl;
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

