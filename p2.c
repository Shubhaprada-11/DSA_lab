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
	if(a=='(' && b==')') return 0;
	if(a=='(') return 0;
	if(b=='(') return 0;
	if(b==')') return 1;
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
			//stktop=opstk.arr[opstk.top];
			while(!empty(&opstk) && prcd(opstk.arr[opstk.top],sym)){
				stktop=pop(&opstk);
				postfix[pos++]=stktop;
				//printf("appended\n");
				}
			if(empty(&opstk) || sym!=')')
				push(&opstk,sym);
			else pop(&opstk);
			}
		}
	while(!empty(&opstk))
		postfix[pos++]=pop(&opstk);
	postfix[pos++]='\0';
	printf("\n%s\n",postfix);
	return 0;
	}
