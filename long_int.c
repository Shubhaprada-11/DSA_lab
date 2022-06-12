#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
    };

typedef struct node * NODEPTR;

NODEPTR getnode(int data){
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    p->data=data;
    p->next=p;
    return p;
}

NODEPTR insertfront(NODEPTR head,int data){
    NODEPTR p=getnode(data);
    if(head->next==head){
            head->next=p;
            p->next=head;
            return head;
    }
    NODEPTR temp;
    temp=head->next;
    head->next=p;
    p->next=temp;
    return head;
}

NODEPTR insertend(NODEPTR head, int data){
    NODEPTR p,temp;
    p=getnode(data);
    temp=head->next;
    while(temp->next!=head)
        temp=temp->next;
    temp->next=p;
    p->next=head;
    return head;
}

void addzero(NODEPTR head1, NODEPTR head2){
    int c1,c2;
    c1=c2=0;
    NODEPTR temp;
    temp=head1->next;
    while(temp!=head1){
        c1++;
        temp=temp->next;
    }
    temp=head2->next;
    while(temp!=head2){
        c2++;
        temp=temp->next;
    }
    if(c1>c2){
        for(int i=c2;i<c1;i++){
            head2=insertfront(head2,0);
        }
    }
    if(c1<c2){
        for(int i=c1;i<c2;i++){
            head1=insertfront(head1,0);
        }
    }
    return;
    }

NODEPTR reverse(NODEPTR head){
    NODEPTR p,q,temp;
    p=head;
    q=head->next;
    while(q!=head){
        temp=q->next;
        q->next=p;
        p=q;
        q=temp;
    }
    head->next=p;
    return head;
}

NODEPTR add(NODEPTR head1, NODEPTR head2){
    NODEPTR add,p,q;
    int sum=0,carry=0,res;
    addzero(head1,head2);
    head1=reverse(head1);
    head2=reverse(head2);
    p=head1->next;
    q=head2->next;
    while(p!=head1){
        res=p->data+q->data+carry;
        sum=res/10;
        carry=sum%10;
        add=insertfront(add,sum);
        p=p->next;
        q=q->next;
    }
    if(carry>0)
        add=insertfront(add,carry);
    return add;
}

int main(){
    char first[20],second[20];
    NODEPTR head1, head2,res,temp;
    head1=(NODEPTR)malloc(sizeof(struct node));
    head1->next=head1;
    head2=(NODEPTR)malloc(sizeof(struct node));
    head2->next=head2;
    printf("enter no1: ");
    scanf("%s",first);
    for(int i=0;first[i]!='\0';i++)
        head1=insertend(head1,first[i]-'0');
    printf("enter no2: ");
    scanf("%s",second);
    for(int i=0;second[i]!='\0';i++)
        head2=insertend(head1,second[i]-'0');
    res=add(head1,head2);
    temp=res->next;
    while(temp!=res){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}