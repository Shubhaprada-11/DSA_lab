#include <stdio.h>
#define MAX 10

struct stack{
	int top;
	int stk[MAX];
	};

void push(struct stack *s,int ele){
	if(s->top==MAX-1){
		printf("stack overflow\n");
		return;
		}
	s->stk[++s->top]=ele;
	return;	
	}

int pop(struct stack *s){
	if(s->top==-1){
		printf("underflow\n");
		return -2;
		}
	return(s->stk[s->top--]);
	}
	
void display(struct stack s){
	int i;
	if(s.top!=-1)
		for(i=s.top;i>=0;i--){
			printf("\t%d\n",s.stk[i]);
			}
		printf("\n\n");	
	}
	
int ttop(struct stack *s){
	if(s->top<3){
		printf("less than 2 elements\n");
		return -2;
		}
	int a,b,y;
	a=pop(s);// no & coz s itself is pointer here acc to strcuct stack *s passed
	b=pop(s);
	y=s->stk[s->top];
	push(s,b);
	push(s,a);
	return y;	
	}

int tbot(struct stack *s){
	if(s->top<3){
		printf("less than 2 elements\n");
		return -2;
		}
	struct stack temp;
	temp.top=-1;
	int ele,y,a,b;
	while(s->top!=-1){
		ele=pop(s);
		push(&temp,ele);
		}
	a=pop(&temp);
	b=pop(&temp);
	y=temp.stk[temp.top];
	push(&temp,b);
	//printf("pushed b\n");
	push(&temp,a);
	//printf("pushed a\n");
	display(temp);
	while(temp.top!=-1){
		ele=pop(&temp);
		push(s,ele);
		}
	return y;
	}

void popn(struct stack *s,int n){
	int i;
	if(n>s->top)
			printf("less than n elements\n");  
	else{
			for(i=0;i<n;i++) pop(s);
			printf("popped n\n");
			}
	return;
}

int main(){
	int ch,ele,y,n,i;
	struct stack s;
	s.top=-1;
	while(1){
	printf("choose 1.push 2.pop 3.display 4.3rd from top 5.pop n 6.3rd from bottom\n");
	scanf("%d",&ch);
	switch(ch){
		
		case 1: printf("enter value to push: ");
			scanf("%d",&ele);
			push(&s,ele);
			break;
		case 2: ele=pop(&s);
			if(ele!=-2)
				printf("popped element %d\n",ele);
			break;
		case 3: display(s);
			break;
		case 4: y=ttop(&s);
			if(y!=-2) printf("%d is 3rd from top\n",y);
			break; 
		case 5: printf("enter n: ");
			scanf("%d",&n);
			popn(&s,n);
			break;
		case 6:
			y=tbot(&s);
			if(y!=-2) printf("%d is 3rd from bottom\n",y);
			break;
		default: 
			return 0;
		}
		}
	}
