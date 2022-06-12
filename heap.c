#include <stdio.h>
#define MAX 10

int h[MAX];
int n=0;

void heapify(){
    int i,j,k,heap,v;
    for(i=n/2;i>=1;i--){
        k=i;
        v=h[k];
        heap=0;
        while(!heap && 2*k<=n){
            j=2*k;
            if(j<n){
                if(h[j]<h[j+1]){
                    j=j+1;
                }
            }
            if(v>h[j])
                heap=1;
            else{
                h[k]=h[j];
                k=j;
            }

        }
        h[k]=v;
    }
}

void insert(int ele){
    if(n>MAX) printf("cant insert full\n");
    else{
        h[n+1]=ele;
        n=n+1;
    }
    heapify();
}

void delete(){
    if(n==0) printf("empty\n");
    else{
        h[1]=h[n];
        n=n-1;
    }
    heapify();
}

void display(){
    int i;
    if(n==0){
        printf("empty\n");
        return;
    }
    for(i=1;i<=n;i++){
        printf("%d ",h[i]);
    }
    printf("\n");
    return;
}

int main(){
    int ch,ele;
    while(1){
        printf("1.insert 2.delete 3.display: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("enter element: ");
            scanf("%d",&ele);
            insert(ele);
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            default: return 0;
        }
    }
return 0;
}