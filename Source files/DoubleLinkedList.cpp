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
		Add(list, distForInt(gen), i);
	}

	return list;
}

//! \brief Получение узла по индексу.
//! \param list Структура двусвязного списка.
//! \param index Индекс узла.
//! \return Возвращает узел по индексу (если индекс равен количеству узлов в списке, то возвращает nullptr).
Node* GetNodeWithIndex(DoubleLinkedList list, int index)
{
	if (index == 0)
	{
		return list.head;
	}
	else if (index == list.size)
	{
		return nullptr;
	}
	else
	{
		Node* nodeUnderIndex = list.head;
		for (int i = 0; i < index; i++)
		{
			nodeUnderIndex = nodeUnderIndex->next;
		}

		return nodeUnderIndex;
	}
}

//! \brief Вставка узла перед nodeUnderIndex.
//! \param list Структура двусвязного списка.
//! \param node Узел для вставки.
//! \param nodeUnderIndex Узел, перед которым вставляется node (если nullptr, то узел вставляется в конец).
void InsertionNode(DoubleLinkedList& list, Node* node, Node* nodeUnderIndex)
{
	if (nodeUnderIndex == list.head)
	{
		node->next = list.head;
		list.head->last = node;
		list.head = node;
	}
	else if (nodeUnderIndex == nullptr)
	{
		node->last = list.tail;
		list.tail->next = node;
		list.tail = node;
	}
	else
	{
		node->last = nodeUnderIndex->last;
		node->next = nodeUnderIndex;
		nodeUnderIndex->last->next = node;
		nodeUnderIndex->last = node;
	}
}

bool Add(DoubleLinkedList& list, int value, int index)
{
	Node* newNode = new Node();
	newNode->value = value;
	if (index <= list.size && index >= 0)
	{
		if (list.size == 0)
		{
			list.head = newNode;
			list.tail = newNode;
		}
		else
		{
			InsertionNode(list, newNode, GetNodeWithIndex(list, index));
		}
		list.size++;
		return true;
	}	
	else
	{
		return false;
	}
}

void NodeExeptions(DoubleLinkedList& list, Node* node)
{
	if (node->last != nullptr)
	{
		node->last->next = node->next;
	}
	else
	{
		list.head = node->next;
	}
	if (node->next != nullptr)
	{
		node->next->last = node->last;
	}
	else
	{
		list.tail = node->last;
	}
}

bool Remove(DoubleLinkedList& list, int value)
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
				NodeExeptions(list, node);

				delete node;
				list.size--;
				result = true;
			}	
			node = nextNode;
		}
	}
	return result;
}

//! \brief Находит узел с минимальным значением в области от startNode до "хвоста".
//! \param list Структура двусвязного списка.
//! \param startNode Левая граница области поиска.
//! \return Узел с минимальным значением.
Node* GetMinNode(DoubleLinkedList list, Node* startNode)
{
	Node* minNode = startNode;
	Node* node = minNode->next;
	while (node != nullptr)
	{
		if (minNode->value > node->value)
		{
			minNode = node;
		}
		node = node->next;
	}

	return minNode;
}

void Sort(DoubleLinkedList& list)
{
	if (list.size > 1)
	{
		Node* startNode = list.head;
		while (startNode != nullptr)
		{
			Node* minNode = GetMinNode(list, startNode);
			if (startNode != minNode)
			{
				NodeExeptions(list, minNode);
				InsertionNode(list, minNode, startNode);
			}
			startNode = minNode->next;
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