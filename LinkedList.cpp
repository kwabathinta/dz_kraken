#include "Linkedlist.h"

List::~List()
{
	while (_p_head != nullptr) {
		Node* tmp = _p_head;
		_p_head = _p_head->next;
		delete tmp;
	}
}

void List::add(int value)
{
	Node* tmp = new Node(value);
	if (_p_head == nullptr) {
		_p_head = _p_tail = tmp;
	}
	else {
		_p_tail->next = tmp;
		_p_tail = tmp;
	}
}

void List::insert(int value, int index)
{
	Node* new_node = new Node(value);
	if (index == 0) {
		new_node->next = _p_head;
		_p_head = new_node;
	}
	else {
		Node* tmp = _p_head;
		for (auto i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		new_node->next = tmp->next;
		tmp->next = new_node;
	}
}

void List::remove_at(int index)
{
	if (index == 0) {
		Node* tmp = _p_head;
		_p_head = _p_head->next;
		delete tmp;
	}
	else {
		Node* tmp = _p_head;
		for (auto i = 0; i < index - 1; i++) {
			tmp = tmp->next;
		}
		Node* tmp_remove = tmp->next;
		tmp->next = tmp_remove->next;
		delete tmp_remove;
	}
}

int List::find_index(int value) const
{
	Node* tmp = _p_head;
	for (auto i = 0; tmp != nullptr; i++) {
		if (tmp->value != value) {
			tmp = tmp->next;
		}
		else {
			return i;
		}
	}

	return -1;
}
