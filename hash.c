#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int hashtable[SIZE];

void insertkey(int key){
    int hkey,hindex;
    hkey=key%SIZE;
    for(int i=0;i<SIZE;i++){
        hindex=(hkey+i)%SIZE;
        if(hashtable[hindex]==-1){
            hashtable[hindex]=key;
            return;
        }
    }
    printf("cant insert\n");
    return;
}

void deletekey(int key){
    int hkey,hindex;
    hkey=key%SIZE;
    for(int i=0;i<SIZE;i++){
        hindex=(hkey+i)%SIZE;
        if(hashtable[hindex]==key){
            hashtable[hindex]=-1;
            printf("deleted\n");
            return;
        }
        
    }
    printf("element not found\n");
    return;
}

void searchkey(int key){
    int hkey,hindex;
    //printf("inside search\n");
    hkey=key%SIZE;
    for(int i=0;i<SIZE;i++){
        //printf("inside for i=%d\n",i);
        hindex=(hkey+i)%SIZE;
        if(hashtable[hindex]==key){
            printf("element found at %d\n",hindex);
            return;
        }
    }
    printf("element not found\n");
    return;
}

int main(){
    int i,ch,ele;
    for(i=0;i<SIZE;i++)
        hashtable[i]=-1;
    while(1){
        printf("1.Insert 2.Delete 3.Search\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("element to insert: ");
            scanf("%d",&ele);
            insertkey(ele);
            break;
            case 2: printf("element to delete: ");
            scanf("%d",&ele);
            deletekey(ele);
            break;
            case 3: printf("element to search: ");
            scanf("%d",&ele);
            searchkey(ele);
            break;
            default: return 0;
        }
        
    }
    return 0;
}