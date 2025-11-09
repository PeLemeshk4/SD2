#pragma once

#include "Node.h"

//! \brief Структура двусвязного списка.
struct DoubleLinkedList
{
	//! \brief Первый элемент списка.
	Node* head = nullptr;
	//! \brief Последний элемент списка.
	Node* tail = nullptr;
	//! \brief Размер списка.
	int size = 0;
};

//! \brief Создание двусвязного списка со случайными узлами.
//! \param size Количество случайных узлов.
//! \return Возвращает структуру динамического массива.
DoubleLinkedList CreateList(int size);

//! \brief Получение узла по индексу.
//! \param list Структура двусвязного списка.
//! \param index Индекс узла.
//! \return Возвращает узел по индексу (если индекс равен количеству узлов в списке, то возвращает nullptr).
Node* GetNodeWithIndex(DoubleLinkedList list, int index);

//! \brief Добавление нового узла.
//! \param list Структура двусвязного списка.
//! \param value Значение для узла.
//! \param index Индекс для узла.
//! \return Если удалось добавить элемент, true, иначе false.
bool AddByIndex(DoubleLinkedList& list, int value, int index);

//! \brief Вставка узла перед nextNode.
//! \param list Структура двусвязного списка.
//! \param node Узел для вставки.
//! \param nextNode Узел, перед которым вставляется node (если nullptr, то узел вставляется в конец).
void Add(DoubleLinkedList& list, Node* node, Node* nextNode);

//! \brief Удаление узла по значению.
//! \param list Структура двусвязного списка.
//! \param value Значение узла.
//! \return Если удалось удалить элемент, true, иначе false.
bool RemoveByValue(DoubleLinkedList& list, int value);

//! \brief Удаление узла.
//! \param list Структура двусвязного списка.
//! \param node Узел.
void Remove(DoubleLinkedList& list, Node* node);

//! \brief Сортировка списка пузырьком.
//! \param list Структура двусвязного списка.
void Sort(DoubleLinkedList& list);

//! \brief Поиск индекса узла.
//! \param list Структура двусвязного списка.
//! \param value Значение узла.
//! \return Индекс, если удалось найти, иначе -1.
int LinearSearch(DoubleLinkedList& list, int value);

//! \brief Удалякт все элементы списка.
//! \param list Структура двусвязного списка.
void ClearList(DoubleLinkedList& list);