#include <iostream>
#include "Queue.h"

Node::Node()
{
	key = 0;
	data = 0;
	next = nullptr;
}

Node::Node(int k, int d)
{
	key = k;
	data = d;
	next = nullptr;
}

Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
}

bool Queue::is_empty()
{
	if (front == nullptr && rear == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Queue::check_if_node_exist(Node* n)
{
	Node* temp = front;
	bool exist = false;
	while (temp != nullptr)
	{
		if (temp->key == n->key)
		{
			exist = true;
			break;
		}
		temp = temp->next;
	}
	return exist;
}

void Queue::enqueue(Node* n)
{
	if (is_empty())
	{
		front = n;
		rear = n;
		std::cout << "Node enqueued" << std::endl;
	}
	else if (check_if_node_exist(n))
	{
		std::cout << "Node already exist with this Key value."
			<< "Enter different Key value" << std::endl;
	}
	else
	{
		rear->next = n;
		rear = n;
		std::cout << "Node enqueued" << std::endl;
	}

}

Node* Queue::dequeue()
{
	Node* temp = nullptr;
	if (is_empty())
	{
		std::cout << "Queue is empty" << std::endl;
		return nullptr;
	}
	else
	{
		if (front == rear)
		{
			temp = front;
			front = nullptr;
			rear = nullptr;
			return temp;
		}
		else
		{
			temp = front;
			front = front->next;
			return temp;
		}

	}
}

int Queue::count()
{
	int count = 0;
	Node* temp = front;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void Queue::display()
{
	if (is_empty())
	{
		std::cout << "Queue is empty" << std::endl;
	}
	else
	{
		Node* temp = front;
		while (temp != nullptr)
		{
			std::cout << "(" << temp->key << "," << temp->data << ")" << " -> ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
}
