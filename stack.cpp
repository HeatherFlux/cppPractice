using namespace std;

struct Node{
  int data;
  Node* next;
};

void addNode(Node** top, int data){
  Node* temp = (Node*)malloc(sizeof(Node));
  Node* ptr = *top;
  temp->data = data;
  temp->next = NULL;
  ptr->next = temp;
}

void display(Node* top)
{
    while (top != NULL) {
        cout << top->data << " ";
        top = top->next;
    }
}

int main(){

  Node* top = NULL;
  addNode(&top, 5);
  // addNode(&top, 8);
  // addNode(&top, 9);

  return 0;
}
