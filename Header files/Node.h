#pragma once

#include <iostream>

using namespace std;

//! \brief Структура узла.
struct Node
{
	//! \brief Значение узла.
	int value = 0;
	//! \brief Указатель на следующий узел.
	Node* next = nullptr;
	//! \brief Указатель на предыдущий узел.
	Node* last = nullptr;
};