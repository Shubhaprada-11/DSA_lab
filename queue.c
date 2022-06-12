#include <stdio.h>
#include <string.h>
#define SIZE 5

struct cq{
	int f;
	int r;
	char msg[SIZE][20];
	};

void enq(struct cq *cq, char s[20]){
    if(cq->f==(cq->r+1)%SIZE){
        printf("cannot\n");
        return;
    }
    cq->r=(cq->r+1)%SIZE;
    if(cq->f==-1) cq->f=0;
    strcpy(cq->msg[cq->r],s);
    return;
}

void deq (struct cq *cq){
    if(cq->r==cq->f){
        printf("empty");
        return;
    }
    
    printf("%s\n",cq->msg[cq->f]);
    cq->f=(cq->f+1)%SIZE;
    return;
}

void display(struct cq cq){
    int i;
    for(i=(cq.f);i!=(cq.r)%SIZE;i=(i+1)%SIZE){
        printf("%s\n",cq.msg[i]);
    }
    printf("%s\n",cq.msg[i]);

    
    return;
}

int main(){
    struct cq cq;
    cq.r=cq.f=-1;
    char s[20];
	int ch;
	while(1){
		printf("1.send 2.recieve 3.display\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("enter msg\n");
					scanf("%s",s);
					enq(&cq,s);
					break;
			case 2: deq(&cq);
					break;
			case 3: display(cq);
					break;
			default: return 0;
		}
	}
	return 0;
}
