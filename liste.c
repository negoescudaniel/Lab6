#include"liste.h"

void deleteList (Node **head)
{
    Node * headcopy ;
    if(*head != NULL )
    {
        headcopy =(*head)->next;
        deleteList(&headcopy);
        free(*head);
    }
    *head=NULL;
}

void modify(Node *head,int pos, Data v)
{
    int k=1;
    while (head!=NULL&&k<pos)
    {
        head=head->next;
        k++;
    }
    if(k==pos)
        head->val=v;
}

void addAtPos(Node **head, Data v, int pos )
{
    Node *aux,*headcopy=*head ;
    int p=0; // folosit la cautarea pozitiei pos
    if (*head!=NULL)
    {
        Node *newNode =(Node*)malloc(sizeof(Node));
        newNode->val=v;
// cat timp nu s-a ajuns la final sau la pozitia dorita
        while (headcopy!=NULL&&p<pos)
        {
            aux= headcopy ;
            headcopy = headcopy->next ;
            p++; // actualizeaza pozitia curenta
        }
        if (pos ==0) addAtBeginning (head, v);
        else
        {
            aux->next = newNode ;
            newNode->next = headcopy ;
        }
    }
    else if (pos ==0) addAtBeginning (head, v);
}

void addAtBeginning(Node **head, Data v)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(Node** head, Data v)
{
    Node *aux=*head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    if (*head == NULL) addAtBeginning(&*head, v);
    else
    {
        while (aux->next!=NULL) aux = aux->next;
        aux->next = newNode;
        newNode->next = NULL;
    }
}

void display(Node *head)
{
    while (head!=NULL)
    {
        printf ("%c ", head->val);
        head=head->next;
    }
    printf("\n");
}

void deleteLast(Node *head)
{
    if(head->next==NULL){
        Node *a=head;          //se retine in a

    head=head->next; //primul va deveni urmatorul element

    free(a);
    }else{
    while (head->next->next!=NULL)
    {
        head=head->next;
    }
    free(head->next);
    head->next=NULL;
}
}
