#pragma once

class Node
{
public:
	Node();
	Node(int k, int d);
	int key;
	int data;
	Node* next;
};

class Queue
{
public:
	Queue();
	bool is_empty();
	bool check_if_node_exist(Node* n);
	void enqueue(Node* n);
	Node* dequeue();
	int count();
	void display();
	Node* front;
	Node* rear;
};