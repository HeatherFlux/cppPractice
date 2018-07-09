#include <bits/stdc++.h>

using namespace std;

// structure of a node
struct Node {
    int data;
    Node* next;
};

// function to create and return a node
Node* getNode(int data)
{
    // Allocating Space
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Inersting Data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int get_size(Node** head_ref){
    Node* ptr = *head_ref;
    int len = 0;

    while (ptr != NULL) {
        len++;
        ptr = ptr->next;
    }
    return len;
}

// Push Functions
void push_front(Node** head_ref, int x){
    if (*head_ref == NULL){
        *head_ref = getNode(x);
    }
    Node* newNode = getNode(x);
    newNode->next = *head_ref;
    *head_ref = newNode;
    return;
}

void push_back(Node** head_ref, int x){
    if (*head_ref == NULL){
        *head_ref = getNode(x);
        return;
    }
    else{
        Node* ptr = *head_ref;

        int len = 0;

        while (ptr->next != NULL) {
            len++;
            ptr = ptr->next;
        }

        ptr->next = getNode(x);
        return;
    }
}

void push_middle(Node** head_ref, int x)
{
    // if list is empty
    if (*head_ref == NULL)
        *head_ref = getNode(x);
    else {
        // Grab a new node
        Node* newNode = getNode(x);

        // Get size and then use size for mid point
        int len = get_size(head_ref);
        int count = ((len % 2) == 0) ? (len / 2) : (len + 1) / 2;

        // navigate to midpoint
        Node* ptr = *head_ref;
        while (count-- > 1){
            ptr = ptr->next;
        }
        // insert into midpoint
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

// Pop Functions
void pop_front(Node** head_ref){
    Node* ptr = *head_ref;
    *head_ref = ptr->next;
    free(ptr);
    return;
}

void pop_back(Node** head_ref){
    Node* ptr = *head_ref;
    int len = 0;

    while (ptr->next->next != NULL) {
        len++;
        ptr = ptr->next;
    }
    Node* temp = ptr->next;
    ptr->next = NULL;
    free(temp);
}

void pop_middle(Node** head_ref){
    int len = get_size(head_ref);
    int count = ((len % 2) == 0) ? (len / 2) - 1 : ((len + 1) / 2) - 1;
    Node* ptr = *head_ref;

    while (count-- > 1){
        ptr = ptr->next;
    }

    Node* tempNode = ptr->next;
    ptr->next = ptr->next->next;
    tempNode = NULL;
    free(tempNode);
}

// Return Functions
int front(Node** head_ref){
    Node* ptr = *head_ref;
    return ptr->data;
}

int back(Node** head_ref){
    Node* ptr = *head_ref;
    int len = 0;
    while (ptr->next->next != NULL) {
        len++;
        ptr = ptr->next;
    }
    return ptr->next->data;
}

int middle(Node** head_ref){
    int len = get_size(head_ref);
    int count = ((len % 2) == 0) ? (len / 2) - 1 : ((len + 1) / 2) - 1;
    Node* ptr = *head_ref;

    while (count-- > 1){
        ptr = ptr->next;
    }

    return ptr->next->data;
}

// Display Function
void display(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Testing
int main()
{
    // Creating the list 1->2->4->5
    Node* head = NULL;
    head = getNode(1);
    push_front(&head, 2);
    push_front(&head, 8);
    push_front(&head, 4);

    cout << "Linked list after push_front: ";
    display(head);

    push_middle(&head, 3);

    cout << "\nLinked list after push_middle: ";
    display(head);

    push_back(&head, 5);
    push_back(&head, 22);

    cout << "\nLinked list after push_back: ";
    display(head);

    pop_front(&head);
    cout << "\nLinked list after pop_front: ";
    display(head);

    pop_back(&head);
    cout << "\nLinked list after pop_back: ";
    display(head);

    pop_middle(&head);
    cout << "\nLinked list after pop_middle: ";
    display(head);

    cout << "\nFront: ";
    cout << front(&head);

    cout << "\nBack: ";
    cout << back(&head);

    cout << "\nMiddle: ";
    cout << middle(&head);

    return 0;
}
