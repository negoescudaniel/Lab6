#include <stdio.h>
#include <stdlib.h>
#include"liste.h"
struct N
{   int num;
    char type;
    struct N *right,*left;
};

typedef struct N Nod;
Nod* createNod(char type, int num)
{
    Nod* newNode = (Nod*)malloc(sizeof(Nod));
    newNode->type = type;
    newNode->num = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Nod* createTree(Nod *root)
{
    root = createNod('Q',1);
    root->left = createNod('Q',2);
    root->right = createNod('Q',3);
    root->left->left = createNod('Q',4);
    root->left->right = createNod('Q',5);
    root->right->left = createNod('Q',6);
    root->right->right = createNod('C',2);
    root->left->left->left = createNod('Q',7);
    root->left->left->right = createNod('Q',8);
    root->left->right->left = createNod('Q',9);
    root->left->right->right = createNod('C',3);
    root->right->left->left = createNod('C',4);
    root->right->left->right = createNod('Q',10);
    root->left->left->left->left = createNod('C',1);
    root->left->left->left->right = createNod('C',2);
    root->left->left->right->left = createNod('C',2);
    root->left->left->right->right = createNod('C',4);
    root->left->right->left->left = createNod('C',2);
    root->left->right->left->right = createNod('C',1);
    root->right->left->right->left = createNod('C',1);
    root->right->left->right->right = createNod('C',4);
    return root;
}

void preorder (Nod *root,Node **prim)
{
    if(root->left==NULL&&root->right==NULL)
    {
        printf("%c%d: ",root->type,root->num);
        display(*prim);
    }
    else
    {
        addAtEnd(prim,'d');
        preorder(root->left,prim);
        deleteLast(*prim);
        addAtEnd(prim,'n');
        preorder(root->right,prim);
        deleteLast(*prim);
    }
}

void preorder1(Nod *root,Node **prim,char t,int m)
{
    if(root->left==NULL&&root->right==NULL&&root->num==m&&root->type==t)
    {
        //printf("%c%d: ",root->type,root->num);
        display(*prim);
    }
    else
    {
        addAtEnd(prim,'d');
        preorder1(root->left,prim,t,m);
        deleteLast(*prim);
        addAtEnd(prim,'n');
        preorder1(root->right,prim,t,m);
        deleteLast(*prim);
    }
}

void prerot(Nod *root)
{
    Node *prim=NULL;
    addAtEnd(&prim,'d');
    preorder (root->left,&prim);
    deleteList(&prim);
    addAtEnd(&prim,'n');
    preorder (root->right,&prim);
}

void prerot1(Nod *root,char t,int m)
{
    Node *prim=NULL;
    addAtEnd(&prim,'d');
    preorder1(root->left,&prim,t,m);
    deleteList(&prim);
    addAtEnd(&prim,'n');
    preorder1(root->right,&prim,t,m);
}

struct frunze
{
    int nr, cai;
    char C;
};
void search1(Nod *root,struct frunze **q,int *n)
{
    if(root->left==NULL&&root->right==NULL){
    int ok=1;
    for(int i=0; i<(*n); i++)
    {
        if((q[i]->nr==root->num)&&(q[i]->C==root->type))
        {
            (q[i]->cai)++;
            ok=0;
        }
    }
    if(ok==1)
    {   if((*n)!=0){
        *q=realloc(*q,((*n)+1)*sizeof(struct frunze));
        q[*n]->C=root->type;
        q[*n]->nr=root->num;
        q[*n]->cai=0;
         (*n)++;
        }else{
        *q=malloc(((*n)+1)*sizeof(struct frunze));
        q[*n]->C=root->type;
        q[*n]->nr=root->num;
        q[*n]->cai=0;
                (*n)++;
        }
    }
    }else{
    search1(root->left,q,n);
    search1(root->left,q,n);
    }
}
void TRD(Nod *root)
{
    struct frunze *p=NULL;
    int n=0;
    search1(root,&p,&n);
    for(int i=0;i<n;i++){
        printf("%c%d: %d cai\n",p[i].C,p[i].nr,p[i].cai);
        prerot1(root,p[i].C,p[i].nr);
    }
}

int main()
{
    Nod *rut = NULL;
    rut=createTree(rut);
    //Subiectul 1
    prerot(rut);
    //Subiectul 2
    TRD(rut);
    return 0;
}
