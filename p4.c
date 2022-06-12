#include <stdio.h>
#include <stdlib.h>

struct node{
	int coef;
	int exp;
	struct node *next;
	};

typedef struct node * NODEPTR;

NODEPTR getnode(int coef,int exp){
	NODEPTR p;
	p=(NODEPTR)malloc(sizeof(struct node));
	p->coef=coef;
	p->exp=exp;
	p->next=NULL;
	return p;
}

NODEPTR insertfront(NODEPTR head,int coef,int exp){
	NODEPTR p;
	p=getnode(coef,exp);
	if(head==NULL)
		return p;
	p->next=head;
	head=p;
	return head;
}

NODEPTR create_poly(NODEPTR head,int n1){
	int i,coef;
	//NODEPTR head;
	printf("enter the coefficients in increasing order\n");
	for(i=0;i<=n1;i++){
		scanf("%d",&coef);
		//printf("scanned %d\n",coef);
		head=insertfront(head,coef,i);
		//printf("inserted\n");
	}
	return head;
}

NODEPTR insertend(NODEPTR head,int coef, int exp){
	NODEPTR p,temp;
	p=getnode(coef,exp);
	if(head==NULL) return p;
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=p;
	return head;
}

NODEPTR reduce(NODEPTR head){
	NODEPTR p,q,temp;
	p=head;
	//if(head==NULL || head->next==NULL) return head;
	for(p=head;p->next!=NULL;p=p->next)
		for(q=p;q!=NULL;q=q->next){
			while(q->next!=NULL && p->exp==q->next->exp){
				p->coef=p->coef+q->next->coef;
				temp=q->next;
				q->next=temp->next;
				free(temp);
			}
		}
	/*while(p->next!=NULL){
		q=p->next;
		if(p->exp==q->exp){
			p->coef=p->coef+q->coef;
			p->next=q->next;
			free(q);
			//q=p->next;
		}
		else{
			q=q->next;
		}
		p=p->next;
	}*/
	return head;
	
}

NODEPTR multiply(NODEPTR head1, NODEPTR head2){
	NODEPTR res,p,q;
	res=NULL;
	int coef,exp;
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;
	for(p=head1;p!=NULL;p=p->next)
		for(q=head2;q!=NULL;q=q->next){
			coef=(p->coef)*(q->coef);
			exp=p->exp+q->exp;
			res=insertend(res,coef,exp);
		}
	//res=reduce(res);
	return res;
}

void display(NODEPTR head){
	if(head==NULL) {
		printf("no poly\n");
		return;
	}
	NODEPTR p;
	p=head;
	while(p->next!=NULL){
		printf("%dx^%d +",p->coef,p->exp);
		p=p->next;
	}
	printf("%dx^%d\n",p->coef,p->exp);
	return;
}

int main(){
	NODEPTR head1,head2,res;
	head1=head2=res=NULL;
	int n1,n2;
	printf("enter degree of poly1: ");
	scanf("%d",&n1);
	printf("enter degree of poly2: ");
	scanf("%d",&n2);
	head1=create_poly(head1,n1);
	printf("poly1: ");
	display(head1);
	head2=create_poly(head2,n2);
	printf("poly2: ");
	display(head2);
	res=multiply(head1,head2);
	display(res);
	res=reduce(res);
	printf("resultant is: \n");
	display(res);
	return 0;

}
