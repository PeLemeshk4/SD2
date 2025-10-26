#include <iostream>
#include <string>
#include <chrono>
#include <time.h>
#include "../Header files/DoubleLinkedList.h"

using namespace std;

//! \brief Выводит инструкции в консоль и возвращает выбор.
//! \param manuals Список со всеми инструкциями.
//! \param manualsIndexes Список с индексами для списка с инструкциями.
//! \param size Длина массива manualsIndexes.
//! \return Возвращает выбор.
int WriteManualAndChoice(string* manuals, int* manualsIndexes, int size)
{
	cout << "\nManuals:\n";
	for (int i = 0; i < size; i++)
	{
		cout << i << ". " << manuals[manualsIndexes[i]];
	}
	int choice;
	cin >> choice;
	cout << endl;

	return choice;
}

//! \brief Вывод одно из 2 сообщений.
//! \param condition Условие.
//! \param trueMessage Сообщение, если condition == true.
//! \param falseMessage Сообщение, если condition == false.
void OutputWithCondition(bool condition, string trueMessage, string falseMessage)
{
	if (condition)
	{
		cout << trueMessage;
	}
	else
	{
		cout << falseMessage;
	}
}

//! \brief Ввод с сообщением.
//! \param message Сообщение.
//! \return Возвращает введённое значение.
int InputWithMessage(string message)
{
	cout << message;
	int varriable;
	cin >> varriable;
	return varriable;
}

//! \brief Выводит в консоль двусвязный список.
//! \param list Структура двусвязного списка.
void WriteList(DoubleLinkedList list)
{
	if (list.size != 0)
	{
		cout << "List: ";
		Node* node = list.head;
		for (int i = 0; i < list.size; i++)
		{
			cout << node->value << ' ';
			node = node->next;
		}
	}
	else
	{
		cout << "List is empty.";
	}
	cout << endl;
}

//! \brief Выполнение выбранной инструкции.
//! \param choice номер выбранной инструкции.
//! \param manuals Список со всеми инструкциями.
//! \param list Структура двусвязного списка.
void RequestExecution(int choice, string* manuals, DoubleLinkedList& list)
{
	switch (choice)
	{
		case 0:
		{
			int size = InputWithMessage("Enter the size of list: ");
			list = CreateList(size);
			//WriteList(list);

			break;
		}
		case 1:
		{
			WriteList(list);

			break;
		}
		case 2:
		{
			cout << "Size: " << list.size << ".\n";

			break;
		}
		case 3:
		{
			cout << "Head: " << list.head->value << ".\n";

			break;
		}
		case 4:
		{
			cout << "Tail: " << list.tail->value << ".\n";

			break;
		}
		case 5:
		{
			int value = InputWithMessage("Enter value for new element: ");
			int index = InputWithMessage("Enter index for new element(0-" + to_string(list.size) + "): ");
			chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
			OutputWithCondition(Add(list, value, index), "Element was added.\n", "Incorrect index.\n");
			chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "mcs";

			break;
		}
		case 6:
		{
			int value = InputWithMessage("Enter value to remove the elements: ");
			chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
			OutputWithCondition(Remove(list, value), "Elements was removed.\n",
				"No element with this value was found.\n");
			chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "mcs";

			break;
		}
		case 7:
		{
			auto start = chrono::steady_clock::now();
			Sort(list);
			auto end = chrono::steady_clock::now();
			auto elapsed_mcs = chrono::duration_cast<std::chrono::microseconds>(end - start);
			cout << "The time: " << elapsed_mcs.count() << " mcs\n";
			//WriteList(list);

			break;
		}
		case 8:
		{
			int value = InputWithMessage("Enter value to search: ");
			auto start = chrono::steady_clock::now();
			int index = LinearSearch(list, value);
			auto end = chrono::steady_clock::now();
			auto elapsed_mcs = chrono::duration_cast<std::chrono::microseconds>(end - start);
			cout << "The time: " << elapsed_mcs.count() << " mcs\n";
			string trueMessage = "Your value(" + to_string(value) +
				") has index " + to_string(index) + ".\n";
			OutputWithCondition(index > -1, trueMessage, "Not found.\n");

			break;
		}
		case 9:
		{
			exit(0);

			break;
		}
		case 10:
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
	}
}

int main()
{
	string manuals[] = { "Create list.\n", "Write list.\n",
		"Get size.\n", "Get head.\n", "Get tail.\n",
		"Add element.\n", "Remove element.\n",
		"Sort list.\n", "Linear search.\n", "Exit.\n", "Delete list.\n"};
	DoubleLinkedList list;

	cout << "\t||Data structures : Double linked list||";
	while (true)
	{
		int* manualsIndexes;
		int size;
		if (list.size == 0)
		{
			size = 2;
			manualsIndexes = new int[size] { 0, 9 };
		}
		else
		{
			size = 10;
			manualsIndexes = new int[size] { 1, 2, 3, 4, 5, 6, 7, 8, 10, 9 };
		}

		int index = WriteManualAndChoice(manuals, manualsIndexes, size);
		if (index >= 0 && index < size)
		{
			int choice = manualsIndexes[index];
			RequestExecution(choice, manuals, list);
		}
		else
		{
			cout << "Incorrect choice.\n";
		}
	}
}