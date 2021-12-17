#pragma once
#include <stdexcept>
#include "iostream"
#include "LinkedList.h"

using namespace std;

void LinkedList::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList()
{
	reset_list();
	size = 0;
}

LinkedList::~LinkedList()
{
	if (!isEmpty())//if the list is already empty, nothing happens
	{
		clear();
	}
}

void LinkedList::add_first(int newElem)
{
	head = new Node(newElem);
	tail = head;
}

void LinkedList::push_back(int newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		tail->next = new Node(newElem, nullptr);
		tail = tail->next;
	}
	size++;
}

void LinkedList::push_front(int newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		head = new Node(newElem, head);
	}
	size++;
}

void LinkedList::pop_back()
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* cur = head;
		while (cur->next != tail) {
			cur = cur->next;
		}
		cur->next = nullptr;
		delete tail;
		tail = cur;
	}
	size--;
}

void LinkedList::pop_front()
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* cur = head->next;
		delete head;
		head = cur;
	}
	size--;
}

void LinkedList::insert(int newElem, size_t index)
{
	if (index >= size) {
		throw out_of_range("out of range");
	}
	else if (index == 0) {
		push_front(newElem);
	}
	else {
		Node* cur = head;
		Node* prev = head;
		size_t cnt = 0;
		while (cnt != index - 1) {
			cur = cur->next;
			cnt++;
			if (cnt > 0)
			{
				prev = prev->next;
			}
		}
		cur->next = new Node(newElem, cur->next);
		size++;
	}
}

int LinkedList::at(size_t index)
{
	if (index >= size) {
		throw out_of_range("out of range");
	}
	else {
		Node* cur = head;
		size_t cnt = 0;
		while (cnt != index) {
			cur = cur->next;
			cnt++;
		}
		return cur->data;
	}
}

void LinkedList::remove(size_t index)
{
	if (index >= size) {
		throw out_of_range("out of range");
	}
	else if (index == 0) {
		pop_front();
	}
	else if (index == size - 1) {
		pop_back();
	}
	else {
		Node* cur = head;
		Node* prev = head;
		size_t cnt = 0;
		while (cnt != index) {
			cur = cur->next;
			if (cnt > 0)
			{
				prev = prev->next;
			}
			cnt++;
		}
		prev->next = cur->next;
		delete cur;
		size--;
	}
}

size_t LinkedList::get_size()
{
	return size;
}

void LinkedList::print_to_console()
{
	if (!isEmpty())
	{
		Node* cur = head;
		while (cur->next != nullptr) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << cur->data << " ";
	}
}

void LinkedList::clear()
{
	Node* cur = head->next;
	while (cur->next != nullptr) {
		delete head;
		head = cur;
		cur = head->next;
	}
	delete head;
	delete tail;
	size = 0;
}

void LinkedList::set(size_t index, int newElem)
{
	if (index >= size) {
		throw out_of_range("out of range");
	}
	Node* cur = head;
	size_t cnt = 0;
	while (cnt != index) {
		cur = cur->next;
		cnt++;
	}
	cur->data = newElem;
}

bool LinkedList::isEmpty() // if empty - true, else false
{
	return !size;
}

void LinkedList::reverse()
{
	Node* cur = head, * prev = nullptr, * next = nullptr;

	while (cur != nullptr) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	tail = head;
	head = prev;
	
}