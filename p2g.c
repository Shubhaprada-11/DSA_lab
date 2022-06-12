#include <stdio.h>
#include <ctype.h>
#define MAX 30

struct stack{
	int arr[MAX];
	int top;	
	};

int empty(struct stack *s){
	return (s->top==-1);
	}

void push(struct stack *s, char ele){
	if(s->top!=MAX-1)
		s->arr[++s->top]=ele;
	}
	
char pop(struct stack *s){
	if(s->top!=-1)
		return s->arr[s->top--];	
	}
	
int prcd(char a, char b){
	if(a=='$' && b=='$') return 0;
	if(a=='$') return 1;
	if(a=='*'||a=='/'){
		if (b=='$') return 0;
		return 1;
		}
	if(a=='+'||a=='-'){
		if (b=='$'||b=='*'||b=='/') return 0;
		return 1;
		}
	}

int main(){
	char infix[30],postfix[30];
	int i,pos=0;
	struct stack opstk;
	opstk.top=-1;
	char sym,stktop;	
	scanf("%s",infix);
	for(i=0;infix[i]!='\0';i++){
		sym=infix[i];
		//printf("%c\n",sym);
		if(isalnum(sym))
			postfix[pos++]=sym;
		else{
			switch(sym){
				case '(': push(&opstk,sym);
					  break;
				case ')': stktop=opstk.arr[opstk.top];
					  while(stktop!='('){
					  	stktop=pop(&opstk);
					  	//printf("%c\n",stktop);
					  	postfix[pos++]=stktop;
					  	stktop=opstk.arr[opstk.top];
					  	}
					  if(stktop='(') pop(&opstk);
					  break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '$':
					if(empty(&opstk) || opstk.arr[opstk.top]=='(')
						push(&opstk,sym);
					else{
						stktop=opstk.arr[opstk.top];
						while(prcd(stktop,sym) && !empty(&opstk) && stktop!='(') postfix[pos++]=pop(&opstk);
						push(&opstk,sym);
						break;
						}
				}
			}
		}
	while(!empty(&opstk)){
		stktop=opstk.arr[opstk.top];
		//if(stktop!='(' && stktop!=')'){
			//printf("  %c\n",stktop);
			postfix[pos++]=pop(&opstk);
			//}
		//else 
			//pop(&opstk);
		}
	postfix[pos]='\0';
	printf("%s\n",postfix);
	}
