#include <iostream>
#include <random>
#include "../Header files/DoubleLinkedList.h"

using namespace std;

DoubleLinkedList CreateList(int size)
{
	random_device randomDevice;
	mt19937 gen(randomDevice());
	uniform_int_distribution<> distForInt(-10000, 10000);

	DoubleLinkedList list;
	list.head = nullptr;
	list.tail = nullptr;
	list.size = 0;
	for (int i = 0; i < size; i++)
	{
		Node* node = new Node();
		node->value = distForInt(gen);
		Add(list, node, nullptr);
	}

	return list;
}

Node* GetNodeWithIndex(DoubleLinkedList list, int index)
{
	Node* nodeUnderIndex = list.head;
	for (int i = 1; i <= index; i++)
	{
		nodeUnderIndex = nodeUnderIndex->next;
	}

	return nodeUnderIndex;
}

//! \brief Вставка узла перед nextNode.
//! \param list Структура двусвязного списка.
//! \param node Узел для вставки.
//! \param nextNode Узел, перед которым вставляется node (если nullptr, то узел вставляется в конец).
void InsertionNode(DoubleLinkedList& list, Node* node, Node* nextNode)
{
	if (nextNode == nullptr)
	{
		node->last = list.tail;
		list.tail->next = node;
		list.tail = node;
	}	
	else if (nextNode == list.head)
	{
		node->next = list.head;
		list.head->last = node;
		list.head = node;
	}
	else
	{
		node->last = nextNode->last;
		node->next = nextNode;
		nextNode->last->next = node;
		nextNode->last = node;
	}
}

bool AddByIndex(DoubleLinkedList& list, int value, int index)
{
	bool result = false;
	Node* newNode = new Node();
	newNode->value = value;
	if (index <= list.size && index >= 0)
	{
		Add(list, newNode, GetNodeWithIndex(list, index));
		result = true;
	}	
	return result;
}

void Add(DoubleLinkedList& list, Node* node, Node* nextNode)
{
	if (list.size != 0)
	{
		InsertionNode(list, node, nextNode);
	}
	else
	{
		list.head = node;
		list.tail = node;
	}
	list.size++;
}

//! \brief Исключает узел из двусвязного списка.
//! \param list Структура двусвязного списка.
//! \param node Узел для исключения.
void NodeExeptions(DoubleLinkedList& list, Node* node)
{
	if (list.size > 1)
	{
		if (node == list.head)
		{
			node->next->last = nullptr;
			list.head = node->next;
		}
		else if (node == list.tail)
		{
			node->last->next = nullptr;
			list.tail = node->last;
		}
		else
		{
			node->last->next = node->next;
			node->next->last = node->last;
		}
	}
	else
	{
		list.head = nullptr;
		list.tail = nullptr;
	}
	node->last = nullptr;
	node->next = nullptr;
}

bool RemoveByValue(DoubleLinkedList& list, int value)
{
	bool result = false;
	if (list.size != 0)
	{
		Node* node = list.head;
		while (node != nullptr)
		{
			Node* nextNode = node->next;
			if (node->value == value)
			{	
				Remove(list, node);
				result = true;
			}	
			node = nextNode;
		}
	}
	return result;
}

void Remove(DoubleLinkedList& list, Node* node)
{
	NodeExeptions(list, node);
	delete node;
	list.size--;
}

//! \brief Меняет местами соседние узлы.
//! \param firstNode Первый узел.
//! \param secondNode Второй узел.
void SwapNeighborNode(DoubleLinkedList& list, Node* node, Node* nextNode)
{
	NodeExeptions(list, node);
	InsertionNode(list, node, nextNode->next);
}

void Sort(DoubleLinkedList& list)
{
	if (list.size > 1)
	{
		for (int end = list.size - 1; end > 1; end--)
		{
			Node* node = list.head;
			for (int i = 0; i < end; i++)
			{
				Node* nextNode = node->next;
				if (node->value > nextNode->value)
				{
					SwapNeighborNode(list, node, nextNode);
				}
				else
				{
					node = nextNode;
				}
			}
		}
	}
}

int LinearSearch(DoubleLinkedList& list, int value)
{
	if (list.size > 0)
	{
		Node* node = list.head;
		int index = 0;
		while (node->value != value)
		{
			if (node->next != nullptr)
			{
				node = node->next;
				index++;
			}
			else
			{
				return -1;
			}
		}

		return index;
	}
	else
	{
		return -1;
	}
}

void ClearList(DoubleLinkedList& list)
{
	Node* node = list.tail;
	while (list.head != nullptr)
	{
		NodeExeptions(list, node);
		delete node;
		node = list.tail;
		list.size--;
	}
}