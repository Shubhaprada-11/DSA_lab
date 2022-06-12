#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct node{
    char data;
    struct node * left;
    struct node *right;
};
typedef struct node * NODEPTR;

struct stack{
    int top;
    NODEPTR data[20];
};

void push(struct stack *s,NODEPTR p){
   s->data[++s->top]=p;
}

NODEPTR pop(struct stack *s){
    return(s->data[s->top--]);
}

NODEPTR getnode(char data){
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    p->right=p->left=NULL;
    p->data=data;
    return p;
}

void inorder(NODEPTR root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c",root->data);
        inorder(root->right);
    }
}

void postorder(NODEPTR root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%c",root->data);
    }
}

void preorder(NODEPTR root){
    if(root!=NULL){
        printf("%c",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int prcd(char a, char b){
    // if(a=='(' && b==')') return 0;
	// if(a=='(') return 0;
	// if(b=='(') return 0;
	// if(b==')') return 1;
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
    return 1;
}

NODEPTR create_tree(NODEPTR root,char exp[20]){
    int i;
    char sym;
    NODEPTR p=NULL,stktop,l,r;
    struct stack op,opnd;
    opnd.top=op.top=-1;
    for(i=0;exp[i]!='\0';i++){
        sym=exp[i];
        if(isalnum(sym)){
            p=getnode(sym);
            push(&opnd,p);
        }
        else{
            //stktop=op.data[op.top];
            while(op.top!=-1 && prcd(stktop->data,sym)){
                stktop=pop(&op);
                r=pop(&opnd);
                l=pop(&opnd);
                stktop->left=l;
                stktop->right=r;
                push(&opnd,stktop);
                //stktop=op.data[op.top];
            }
            p=getnode(sym);
            push(&op,p);
            }
        }
        while(op.top!=-1){
            p=pop(&op);
            r=pop(&opnd);
            l=pop(&opnd);
            //p=getnode(sym);
            p->left=l;
            p->right=r;
            push(&opnd,p);
        }
        root=pop(&opnd);
        return root;

    }


int main(){
    char exp[20];
    NODEPTR root;
    root=NULL;
    printf("enter expression\n");
    scanf("%s",exp);
    root=create_tree(root,exp);
    printf("\n\n");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}
