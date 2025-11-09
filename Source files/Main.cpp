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
string WriteManual(string* manuals, int* manualsIndexes, int size)
{
	string result = "\nManuals:\n";
	for (int i = 0; i < size; i++)
	{
		result += to_string(i) + ". " + manuals[manualsIndexes[i]];
	}
	return result;
}

//! \brief Вывод одно из 2 сообщений.
//! \param condition Условие.
//! \param trueMessage Сообщение, если condition == true.
//! \param falseMessage Сообщение, если condition == false.
string MessageByCondition(bool condition, string trueMessage, string falseMessage)
{
	if (condition)
	{
		return trueMessage;
	}
	else
	{
		return falseMessage;
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
string WriteList(DoubleLinkedList list)
{
	string result = "List is empty.";
	if (list.size != 0)
	{
		result = "List: ";
		Node* node = list.head;
		for (int i = 0; i < list.size; i++)
		{
			result += to_string(node->value) + ' ';
			node = node->next;
		}
	}
	return result + '\n';
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
			cout << WriteList(list);

			break;
		}
		case 1:
		{
			cout << WriteList(list);

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
			cout << MessageByCondition(AddByIndex(list, value, index), "Element was added.\n", "Incorrect index.\n");

			break;
		}
		case 6:
		{
			int value = InputWithMessage("Enter value to remove the elements: ");
			cout << MessageByCondition(RemoveByValue(list, value), "Elements was removed.\n",
				"No element with this value was found.\n");

			break;
		}
		case 7:
		{
			Sort(list);
			cout << "List was sorted.\n";
			break;
		}
		case 8:
		{
			int value = InputWithMessage("Enter value to search: ");
			int index = LinearSearch(list, value);
			string trueMessage = "Your value(" + to_string(value) +
				") has index " + to_string(index) + ".\n";
			cout << MessageByCondition(index > -1, trueMessage, "Not found.\n");

			break;
		}
		case 9:
		{
			exit(0);

			break;
		}
		case 10:
		{
			ClearList(list);
			cout << "List was cleared.\n";
			break;
		}
	}
}

//! \brief 
void Task2Request(int operationNumber, string* manuals, int n, int iterationsCount)
{
	DoubleLinkedList list = CreateList(n);
	switch (operationNumber)
	{
		case 0:
		{
			auto start = chrono::high_resolution_clock::now();
			for (int i = 0; i < iterationsCount; i++)
			{
				GetNodeWithIndex(list, n / 2);
			}
			auto end = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
			double timeOfOperation = static_cast<double>(duration.count()) / iterationsCount;
			cout << timeOfOperation << '\n';
			break;
		}
		case 1:
		{
			Node* node = new Node();
			node->value = 10;
			auto start = chrono::high_resolution_clock::now();
			for (int i = 0; i < iterationsCount; i++)
			{
				Add(list, node, list.head);
			}
			auto end = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
			double timeOfOperation = static_cast<double>(duration.count()) / iterationsCount;
			cout << timeOfOperation << '\n';
			break;
		}
		case 2:
		{
			Node* node = new Node();
			node->value = 10;
			double measurementsSum = 0;
			for (int i = 0; i < iterationsCount; i++)
			{
				Node* nextNode = GetNodeWithIndex(list, n / 2);
				auto start = chrono::high_resolution_clock::now();
				Add(list, node, nextNode);
				auto end = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
				measurementsSum += static_cast<double>(duration.count());
			}
			double timeOfOperation = measurementsSum / iterationsCount;
			cout << timeOfOperation << '\n';
			break;
		}
		case 3:
		{
			auto start = chrono::high_resolution_clock::now();
			for (int i = 0; i < iterationsCount; i++)
			{
				Remove(list, list.head);
			}
			auto end = chrono::high_resolution_clock::now();
			auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
			double timeOfOperation = static_cast<double>(duration.count()) / iterationsCount;
			cout << timeOfOperation << '\n';
			break;
		}
		case 4:
		{
			double measurementsSum = 0;
			for (int i = 0; i < iterationsCount; i++)
			{
				Node* node = GetNodeWithIndex(list, list.size / 2);
				auto start = chrono::high_resolution_clock::now();
				Remove(list, node);
				auto end = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
				measurementsSum += static_cast<double>(duration.count());
			}			
			double timeOfOperation = measurementsSum / iterationsCount;
			cout << timeOfOperation << '\n';
			break;
		}
		case 5:
		{
			exit(0);

			break;
		}
	}
}

int main()
{
	cout << "\t||Data structures : Double linked list||\n";

	int taskNumber = InputWithMessage("Enter the number of task(1-2): ");
	switch (taskNumber)
	{
		case 1:
		{
			string manuals[] = { "Create list.\n", "Write list.\n",
				"Get size.\n", "Get head.\n", "Get tail.\n",
				"Add element.\n", "Remove element.\n",
				"Sort list.\n", "Linear search.\n", "Exit.\n", "Clear list.\n" };
			DoubleLinkedList list;

			while (true)
			{
				int size = list.size == 0 ? 2 : 10;
				int* manualsIndexes = size == 2
					? new int[size] { 0, 9 }
					: new int[size] { 1, 2, 3, 4, 5, 6, 7, 8, 10, 9 };

				int index = InputWithMessage(WriteManual(manuals, manualsIndexes, size));
				cout << endl;
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
			break;
		}
		case 2:
		{
			string manuals[] = { "Index access.\n", "Insert at the beginning.\n",
				"Insert in the middle.\n", "Delete from the beginning.\n",
				"Delete from the middle.\n", "Exit.\n" };
			int size = 6;
			int* manualsIndexes = new int[size] { 0, 1, 2, 3, 4, 5};
			int iterationsCount = 1000;
			while (true)
			{
				int operationNumber = InputWithMessage(WriteManual(manuals, manualsIndexes, size));
				cout << endl;
				if (operationNumber >= 0 && operationNumber < size)
				{
					int operationIndex = manualsIndexes[operationNumber];
					for (int n = 1000; n <= 1000000; n *= 10)
					{
						int iterationsCount = n == 1000 ? 100 : 1000;
						Task2Request(operationIndex, manuals, n, iterationsCount);
					}
				}
				else
				{
					cout << "Incorrect choice.\n";
				}
			}
			break;
		}
		default:
		{
			cout << "Incorrect choice.\n";
			break;
		}
	}	
}