#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct node{
    ElemType data;
    struct node* next;
}LNode,*LinkList;

void init_List(LinkList* L){
    *L = (LNode*)malloc(sizeof(LNode));
    if(*L != NULL){
        (*L)->next = NULL;
    }else{
        printf("No memory for the list\n");
    }
}

void print_List(LinkList L){
    LNode* p = L->next;
    while(p != NULL){
        printf("%d ->",p->data);
        p = p->next;
    }
    printf("\n");
}

LNode* create_Node(ElemType value){
    LNode* p = (LNode*)malloc(sizeof(LNode));
    p->data = value;
    p->next = NULL;
    return p;
}

LinkList create_List(LinkList L,ElemType* arr,int length){
    LNode* p = NULL;
    init_List(&L);
    for (int i = 0; i < length; i++){
        p = create_Node(arr[i]);
        p->next = L->next;
        L->next = p;
    }
    return L;
}

int main(void){
    ElemType arr[] = {56,32,18,-5,0,91,27,1,};
    int length = sizeof(arr)/sizeof(ElemType);

    LinkList L = NULL;
    L = create_List(L,arr,length);

    print_List(L);
}