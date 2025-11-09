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

//! \brief Создание массива со случайном набором узлов.
//! \param size Количество случайных узлов.
//! \return Возвращает структуру динамического массива.
DoubleLinkedList CreateList(int size);

//! \brief Добавление нового узла.
//! \param list Структура двусвязного списка.
//! \param value Значение для узла.
//! \param index Индекс для узла.
//! \return Если удалось добавить элемент, true, иначе false.
bool Add(DoubleLinkedList& list, int value, int index);

//! \brief Удаление узла по значению.
//! \param list Структура двусвязного списка.
//! \param value Значение узла.
//! \return Если удалось удалить элемент, true, иначе false.
bool Remove(DoubleLinkedList& list, int value);

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