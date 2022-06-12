#include <stdlib.h>
#include <stdio.h>

struct node{
    int row;
    int col;
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node * NODEPTR;  

NODEPTR getnode(int row, int col, int data){
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    p->row=row;
    p->col=col;
    p->data=data;
    p->next=p->prev=NULL;
    return p;
}

NODEPTR insertend(NODEPTR head, int row, int col, int data){
    NODEPTR p,temp;
    p=getnode(row,col,data);
    if(head==NULL){
        head=p;
        return head;
    }
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=p;
    p->prev=temp;
    return head;
}

NODEPTR createlist(){
    int row, col, num,r,c,data;
    NODEPTR p,head;
    head=NULL;
    printf("enter no of row col of elements: ");
    scanf("%d %d",&row, &col);
    printf("enter no of non zero ele: ");
    scanf("%d",&num);
    p=getnode(row,col,num);
    for(int i=0;i<num;i++){
        printf("enter element row col data: ");
        scanf("%d %d %d",&r,&c,&data);
        head=insertend(head,r,c,data);
    }
    p->next=head;
    head->prev=p;
    head=p;
    return head;
}

void display(NODEPTR head){
    int r,c,data,i,j,k;
    NODEPTR p;
    p=head->next;
    r=head->row;
    c=head->col;
    data=head->data;
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(p!=NULL && p->row==i && p->col==j){
                printf("%d\t",p->data);
                p=p->next;
            }
            else printf("0\t");
        }
        printf("\n");
    }
    return;
}

void disp(NODEPTR head){
    if(head==NULL){
        printf("No elements\n");
        return;
    }
    NODEPTR temp;
    temp=head->next;
    while(temp!=NULL){
        printf("the data is row:%d col:%d and item: %d\n",temp->row,temp->col,temp->data);
        temp=temp->next;
    }
    return;
}

int main(){
    NODEPTR head;
    head=NULL;
    head=createlist();
    disp(head);
    printf("\n\n");
    display(head);
    return 0;
}