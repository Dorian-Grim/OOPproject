#include <iostream>
#include<Windows.h>
#include<fstream>
#include<string>
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
	void addNode(Node<T>** headRef, T newData)
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
	void createList(Node<T>** headRef)
	{
		int numberNodes;
		T value;
		cout << "Number of nodes:";
		cin >> numberNodes;
		for (int i = 1; i <= numberNodes; i++)
		{
			cout << "Please enter value for " << i << ":";
			cin >> value;
			addNode(&(*headRef), value);
		}
	}
	void printList(Node<T>* nodes)
	{
		cout << "Printing the list" << endl;
		while (nodes)
		{
			cout << nodes->data << " ";
			nodes = nodes->next;

		}
		cout << endl;
	}
	void editNode(Node<T>* nodes)
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
	void printNode(Node<T>* nodes)
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
	void deleteNode(Node<T>** nodes)
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
	void deleteList(Node<T>** nodes)
	{
		*nodes=NULL;
	}
	void saveList(Node<T>* nodes)
	{
		if (!nodes)
		{
			cout << "Please create a list!";
			return;
		}
		ofstream file("list.txt");
		string valNodes = to_string(nodes->data) + "\n";
		while(nodes->next) 
		{
			nodes = nodes->next;
			valNodes = valNodes + to_string(nodes->data) + "\n";
		}
		file << valNodes;
		file.close();
	}
	void importList(Node<T>** nodes)
	{
		deleteList(&(*nodes));
		ifstream file("list.txt");
		string line;
		while (getline(file, line)) addNode((&(*nodes)),stoi(line));
	}

};

template <typename T>
class ProgramFunctions 
{
	public:
		static void displayMenu()
		{
			changeConsolecolor(14);
			cout << "Pick something from the menu:" << endl << endl;
			changeConsolecolor(11);
			cout << "------------------------------" << endl;
			cout << "1. Create list" << endl;
			cout << "2. Add node" << endl;
			cout << "3. Display node" << endl;
			cout << "4. Edit node" << endl;
			cout << "5. Delete node" << endl;
			cout << "6. Display all" << endl;
			cout << "7. Save list" << endl;
			cout << "8. Import list" << endl;
			cout << "9. Delete list" << endl;
		
			cout << "------------------------------" << endl;
			changeConsolecolor(14);
			changeConsolecolor(15);


		}
		static void changeConsolecolor(int color_code)
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
				changeConsolecolor(10);
				switch (c)
				{
				case 1:
					f.createList(&head);
					break;
				case 2:
					T data;
					cout << "Please enter a value:" << endl;
					cin >> data;
					f.addNode(&head, data);
					cout << "You entered:" << data << endl;
					break;
				case 3:
					f.printNode(head);
					break;
				case 4:
					f.editNode(head);
					break;
				case 5:
					f.deleteNode(&head);
					break;
				case 6:
					f.printList(head);
					//cout << "You picked 2" << endl;
					break;
				case 7:
					f.saveList(head);
					break;
				case 8:
					f.importList(&head);
					break;	
				case 9:
					f.deleteList(&head);
					break;
				
				default:
					exit(0);
					break;
				}
			} while (true);
		}
};



