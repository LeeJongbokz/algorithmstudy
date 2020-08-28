#include <iostream>
#include <set>

using namespace std;

class Node {

public:
	int data;
	Node* next;
};


void push(Node** head_ref, int new_data) {

	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(Node* node) {

	while (node != NULL) {
		cout << node->data << '\n';
		node = node->next;
	}
}


void removeDuplicate(Node* node) {

	Node* previous=NULL;
	set<int> s;

	while (node != NULL) {

		int num = node->data;

		if (s.count(num) > 0) {
			previous->next = node->next;
		}
		else {
			s.insert(node->data);
			previous = node;
		}

		node = node->next;

	}



}

int main() {

	Node* head = NULL;

	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 1);
	push(&head, 3);
	push(&head, 7);

	printList(head);
	removeDuplicate(head);
	cout << '\n';
	printList(head);
		
}
