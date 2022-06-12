#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node *  NODEPTR;

NODEPTR getnode(int ele){
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    p->data=ele;
    p->left=p->right=NULL;
    return p;
}

NODEPTR insert(NODEPTR root, int ele){
    NODEPTR temp=getnode(ele);
    if(root==NULL) return temp;
    NODEPTR p,q;
    p=q=root;
    while(p!=NULL && q->data!=ele){
        q=p;
        printf("%d\n",p->data); 
        if(ele>q->data)
            p=q->right;
        else 
            p=q->left;
    }
    if(ele>q->data){
        q->right=temp;
        printf("rt inserted\n");
    }
    else if(ele<q->data){
        q->left=temp;
        printf("left inserted\n");
    }
    else ; //duplicate
    return root;
}

void inorder(NODEPTR root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(NODEPTR root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(NODEPTR root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

NODEPTR inorder_succ(NODEPTR root){
    NODEPTR temp;
    temp=root->right;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
}

NODEPTR deletenode(NODEPTR root, int ele){
    if(root==NULL) return root;
    if(ele>root->data) root->right= deletenode(root->right,ele);
    else if(ele<root->data) root->left=deletenode(root->left,ele);
    else{
        NODEPTR temp;
        if(root->left==NULL){
            temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL){
            temp=root->left;
            free(root);
            return temp;
        }
        temp=inorder_succ(root);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);

    }
    return root;
}

int main(){
    NODEPTR root=NULL;
    int ch,ele;\
    while(1){
        printf("1.insert 2.del 3.ino 4. post 5.pre : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter ele: ");
            scanf("%d", &ele);
            root=insert(root,ele);
            break;
            case 2: printf("enter ele: ");
            scanf("%d", &ele);
            root=deletenode(root,ele);
            break;
            case 3: inorder(root);
            break;
            case 4: postorder(root);
            break;
            case 5: preorder(root);
            break;
            default: return 0;
        }
        
    }
    return 0;
}