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
		Node<T>* last = *headRef;
		if (!*headRef) *headRef = newNode;
		else
		{
			while (last->next) last = last->next;
			last->next = newNode;
			newNode->prev = last;
		}

	}
	static void createList(Node<T>** headRef)
	{
		int numberNodes;
		T value;
		cout << "Number of nodes:";
		cin >> numberNodes;
		for (int i = 1; i <= numberNodes; i++)
		{
			cout << "Please enter value for " << i << ":";
			cin >> value;


append(&(*headRef));
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
	static void editNode(Node<T>* nodes)
	{
		if (!nodes)
		{
			cout << "Please create a list!";
			return;
		}
		int index;
		cout << "Insert index:";
		cin >> index;
		cout << "Insert value:";
		T value;
		cin >> value;
		Node<T>* temp = nodes;
		for (int i = 1; i < index; i++)
		{
			if (!temp->next)
			{
				cout << "Invalid index" << endl;
				return;
			}
			temp = temp->next;
		}
		temp->data = value;
		cout << "Node at index " << index << " now has the value " << value << endl;

	}
	static void printNode(Node<T>* nodes)
	{
		if (!nodes)
		{
			cout << "Please create a list!";
			return;
		}
		int index;
		cout << "Insert index:";
		cin >> index;
		Node<T>* temp = nodes;
		for (int i = 1; i < index; i++)
		{
			if (!temp->next)
			{
				cout << "Invalid index" << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Node at index " << index << " has the value " << temp->data << endl;
		
	}
	static void deleteNode(Node<T>** nodes)
	{
		if (!nodes)
		{
			cout << "Please create a list!";
			return;
		}
		int index;
		cout << "Insert index:";
		cin >> index;
		Node<T>* temp = *nodes;
		if (index == 1)
		{
			*nodes = temp->next;
			cout << "Element at index 1 was deleted";
			return;
		}
		
		for (int i = 2; i < index; i++)
		{
			if (!temp->next)
			{
				cout << "Invalid index" << endl;
				return;
			}
			temp = temp->next;
		}
		temp->next = temp->next->next;
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
			cout << "3. Edit node" << endl;
			cout << "4. Display node" << endl;
			cout << "5. Delete node" << endl;
			cout << "6. Create list" << endl;
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
				case 3:
					f.editNode(head);
					break;
				case 4:
					f.printNode(head);
					break;
				case 5:
					f.deleteNode(&head);
					break;
				case 6:
					f.createList(&head);
					break;
				default:
					exit(0);
					break;
				}
			} while (true);
		}
};



