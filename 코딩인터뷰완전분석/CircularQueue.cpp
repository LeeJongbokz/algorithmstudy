#include <iostream>

using namespace std;

const int MAX_QUEUE_SIZE = 100;

class CircularQueue {

	int data[MAX_QUEUE_SIZE];
	int rear;
	int front;

public:
	CircularQueue() {
		rear = front = -1;
	}

	bool isFull() {
		return front == (rear+1)%MAX_QUEUE_SIZE;
	}

	bool isEmpty() {
		return front == rear;
	}


	void enqueue(int val) {
		if (isFull()) {
			cout << "Queue is Full";
		}
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "Queue is Empty";
		}
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

};
