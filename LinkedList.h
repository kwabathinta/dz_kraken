#pragma once
struct Node {
	Node* next = nullptr;
	int value;
	Node(int value = 0) : value(value) {}
};

class List {
public:
	List() : _p_head(nullptr), _p_tail(nullptr) {}
	~List();
	void add(int value);
	void insert(int value, int index);
	void remove_at(int index);
	int find_index(int value) const;
private:
	Node* _p_head;
	Node* _p_tail;
};