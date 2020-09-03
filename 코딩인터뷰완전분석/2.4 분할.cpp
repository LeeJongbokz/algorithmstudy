#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node() {}
	Node(int num) :data(num) {}

};


Node* push(Node** head_ref, int new_data) {

	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;

	return new_node; 

}

void deletethisNode(Node* node) {

	node->data = node->next->data;
	node->next = node->next->next; 
}

void deleteNextNode(Node* node) {

	node->next = NULL;
}

void printNode(Node* node) {

	while (node != NULL) {
		cout << node->data << " ";
		node = node->next; 
	}
}

void addNode(Node* node1, Node* node2) {
		
	while (node1->next != NULL) {
		node1 = node1->next;
	}

	node1->next = node2; 
}

int main() {

	Node* head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 10);
	Node* deleteNode1 = push(&head, 5);
	push(&head, 8);
	Node* deleteNode2 = push(&head, 5);
	push(&head, 3);

	printNode(head);
	cout << '\n';
	deletethisNode(deleteNode1);
	deletethisNode(deleteNode2);
	Node* new_node1 = new Node(5);
	Node* new_node2 = new Node(5);

	addNode(head, new_node1);
	addNode(head, new_node2);
	printNode(head);
	
}
