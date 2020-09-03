#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void push(Node** head_ref, int new_data) {

	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void printNode(Node* node) {

	while (node != NULL) {
		cout << node->data << " ";
		node = node->next; 
	}
}

void deleteNode(Node* node) {

	node->data = node->next->data;
	node->next = node->next->next;
}

void deleteLast(Node* node) {
	node = node->next;
}

void divisionByNum(Node* head, int num) {

	Node* previous = head;
	Node* current = head->next;

	while (current != NULL) {

		if (current->data < num) {
			push(&head, current->data);
			if (current->next != NULL) {
				deleteNode(current);
			}
			else {
				deleteLast(current);
			}
			current = current->next;
		}
		else {
			previous = current;
			current = current->next;
		}

	}


}

int main() {

	Node* head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 10);
	push(&head, 5);
	push(&head, 8);
	push(&head, 5);
	push(&head, 3);

	printNode(head);
	cout << '\n';
	divisionByNum(head, 5);
	printNode(head);




}
