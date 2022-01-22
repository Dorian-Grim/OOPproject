#include <iostream>
#include<Windows.h>
using namespace std;

template <typename T>
class Node
{
public: 
	T data; 
	Node<T>* prev, * next;
	Node(T newData)
	{
		data = newData;
		prev = NULL;
		next = NULL;
	}

};

template <typename T>
class NodeFunctions
{
public:
	static void addNode(Node<T>** headRef, T newData)
	{
		Node<T>* newNode = new Node<T>(newData);
		if (!*headRef)
		{
			*headRef = newNode;
			return;
		}

	}
	static void printList(Node<T>* nodes)
	{
		cout << "Printing the list" << endl;
		while (nodes)
		{
			cout << nodes->data << " ";
			nodes = nodes->next;

		}
		cout << endl;
	}
};

template <typename T>
class ProgramFunctions 
{
	public:
		static void displayMenu()
		{
			changeConsoleColour(14);
			cout << "Pick something from the menu:" << endl << endl;
			changeConsoleColour(11);
			cout << "------------------------------" << endl;
			cout << "1. Add" << endl;
			cout << "2. Display all" << endl;
			cout << "------------------------------" << endl;
			changeConsoleColour(14);
			changeConsoleColour(15);


		}
		static void changeConsoleColour(int color_code)
		{
			HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(console, color_code);
		}
		static void runProgram()
		{
			Node<T>* head = NULL;
			NodeFunctions<T> f;
			do
			{
				displayMenu();
				int c;
				cin >> c;
				changeConsoleColour(10);
				switch (c)
				{
				case 1:
					T data;
					cout << "Please enter a value:" << endl;
					cin >> data;
					f.addNode(&head, data);
					cout << "You entered:" << data << endl;
					break;
				case 2:
					f.printList(head);
					//cout << "You picked 2" << endl;
					break;
				default:
					exit(0);
					break;
				}
			} while (true);
		}
};



