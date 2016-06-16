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


void printH(Node *n);
void insertEnd(List *l,Node *n);
void printList(List *l);
Node* initNode(int d);
void createList(List *l);
void pop(List *l);
void removeElement(List *l, int value);
Node* merge(Node *a, Node *b);
void splitList(Node *source, Node **front, Node**back);
void mergeSort(List *l);
void push(List *l, Node *n);
void reverseList(List *l);

int main()
{
    List *linkedList = (List*)malloc(sizeof(List));
    linkedList->head = NULL;
    char value = 0;
    int data;
    createList(linkedList);
    //Print the current list out
    printList(linkedList);
    while(value != 'q'){
        cout << "Please enter a command: "<< endl <<
                "\tA-add a node at end, I-insert at front" << endl <<
                "\tF-reverse list" << endl <<
                "\tP-pop first node, R-remove a node," << endl <<
                "\tS-sort list, L-display list." << endl;
        cin >> value;
        //If the value is lower case ( > 'Z' in binary),
        //remove the difference between upper and lower.
        //which is (0x32 hex or a space)

        if( value > 'Z'){ value -= ' ';}
        switch(value)
        {
        case 'A':
            cout << "Enter value to add: " << endl;
            cin >> data;
            insertEnd(linkedList, initNode(data));
            break;
        case 'F':
            reverseList(linkedList);
            break;
        case 'I':
            cout << "Enter value to push: " << endl;
            cin >> data;
            push(linkedList, initNode(data));
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
        case 'S':
            mergeSort(linkedList);
            cout << "List sorted!" << endl;
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
        l->head = n;
        return;
    }
Node *ptr = l->head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = n;
}
void push(List *l, Node *n){
    if(l->head == NULL){
        l->head = n;
        return;
    }
Node *ptr = l->head;
    n->next = ptr;
    l->head = n;
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
        return;
    }
    cout << "Current list:" << endl;
    while(ptr != NULL){
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

void createList(List *l){
    Node *a, *b, *c, *d, *e;
    a = initNode(5);
    b = initNode(2);
    c = initNode(3);
    d = initNode(4);
    e = initNode(1);

    insertEnd(l, a);
    insertEnd(l, b);
    insertEnd(l, c);
    insertEnd(l, d);
    insertEnd(l, e);


}

void reverseList(List *l){
    List *temp = (List*)malloc(sizeof(List));
    temp->head = NULL;
    Node *tempPtr = temp->head, *listPtr = l->head, *helper;

    //first node
    if(listPtr != NULL){
        helper = listPtr;
        listPtr = listPtr->next;
        tempPtr = helper;
        tempPtr->next = NULL;
    }

    while(listPtr != NULL){

        helper = listPtr;
        listPtr = listPtr->next;

        helper->next = tempPtr;
        tempPtr = helper;


    }
    cout << "The list has been reversed!" << endl;
    l->head = tempPtr;

    free(temp);


}

//*******************************Mergesort***************************
Node* merge(Node *a, Node *b){
    Node *result = NULL;
    /*
    cout << "in merge" << endl;
    List *front = (List*)malloc(sizeof(List));
    List *back = (List*)malloc(sizeof(List));
    front->head = a;
    back->head = b;
    cout<< "a" << endl ;
    printList(front);
    cout<< endl << "b" << endl ;
    printList(back);
*/

    if(a == NULL){
        return(b);
    }
    else if(b == NULL){
        return(a);
    }

    if(a->data <= b->data){
        result = a;
        result->next = merge(a->next, b);
    }
    else{
        result = b;
        result->next = merge(a, b->next);
    }
    return(result);
}

void splitList(Node *source, List *front, List *back){

    Node *fast, *slow;

    if((source == NULL) || (source->next == NULL)){

        front->head = source;
        back = NULL;
    }
    else{
        slow = source;
        fast = source->next;
        //This finds the mid point
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }


        front->head = source;
        back->head = slow->next;
        slow->next = NULL;

    }
}

void printH(Node *n){

    if(n == NULL){
        cout << "List is empty." << endl;
    }
    while(n != NULL){
        cout << n->data << endl;
        n = n->next;
    }
}



void mergeSort(List *l){

    Node *head = l->head;
    List *first = (List*)malloc(sizeof(List));
    List *second = (List*)malloc(sizeof(List));
    first->head = second->head = NULL;

    //base case
    if((l->head == NULL) || (l->head->next == NULL))
    {
        return;
    }

    //split
    splitList(head, first, second);

    mergeSort(first);
    mergeSort(second);

    l->head = merge(first->head, second->head);

}

