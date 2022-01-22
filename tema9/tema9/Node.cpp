//#include "Node.h"
//#include <iostream>
//#include<Windows.h>
//using namespace std;
//
//void ProgramFunctions::displayMenu()
//{ 
//	changeConsoleColour(14);
//	cout << "Pick something from the menu:" << endl << endl;
//	changeConsoleColour(11);
//	cout << "------------------------------" << endl;
//	cout << "1. Add" << endl;
//	cout << "2. Display all" << endl;
//	cout << "------------------------------" << endl;
//	changeConsoleColour(14);
//	changeConsoleColour(15);
//
//
//}
//
//void ProgramFunctions::changeConsoleColour(int color_code)
//{
//	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(console, color_code);
//}
//
//void ProgramFunctions::runProgram()
//{
//	Node* head = NULL;
//	do
//	{
//		displayMenu();
//		int c;
//		cin >> c;
//		changeConsoleColour(10);
//		switch (c)
//		{ 
//		case 1: 
//			int data;
//			cout << "Please enter a value:" << endl;
//			cin >> data;
//			NodeFunctions::addNode(&head, data);
//			cout << "You entered:"<<data << endl;
//			break;
//		case 2:
//			NodeFunctions::printList(head);
//			//cout << "You picked 2" << endl;
//			break;
//		default: 
//			exit(0);
//			break;
//		}
//	} while (true);
//}
//
//void NodeFunctions::addNode(Node** headRef, int newData)
//{
//	Node* newNode = new Node(newData);
//	if (!*headRef)
//	{
//		*headRef = newNode;
//		return;
//	}
//
//}
//
//void NodeFunctions::printList(Node* nodes)
//{
//	cout << "Printing the list" << endl;
//	while (nodes)
//	{
//		cout << nodes->data << " ";
//		nodes = nodes->next;
//
//	}
//	cout << endl;
//}
//
//Node::Node(int newData)
//{
//	data = newData;
//	prev = NULL;
//	next = NULL;
//}
