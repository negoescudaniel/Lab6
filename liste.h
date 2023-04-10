#include<stdio.h>
#include<stdlib.h>
typedef char Data;
typedef struct Node{
	Data val;
	struct Node *next;
}Node;
void modify(Node *head,int pos, Data v);
void addAtPos(Node **head, Data v, int pos);
void addAtBeginning(Node **head, Data v);
void addAtEnd(Node** head, Data v);
void display(Node *head);
void deleteList (Node **head);
void deleteLast(Node *head);
