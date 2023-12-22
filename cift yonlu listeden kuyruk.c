#include <stdio.h>
#include <stdlib.h>

struct dll{
	struct dll * prev;
	int data;
	struct dll * next;
};

typedef struct dll node;
node*start=NULL;
node * getnode(){
	node * newnode;
	newnode=(node*)malloc(sizeof(node));
	printf("Data giriniz\n");
	scanf("%d",&newnode->data);
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}

void enqueue(node * newnode){
	node * temp;
	temp=start;
	if(temp==NULL){
		start=newnode;
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
	}
}

node * dequeue(){
	node * temp;
	temp=start;
	start=start->next;
	start->prev=NULL;
	return temp;
}

void display(){
	node * temp;
	temp=start;
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
}

void displayreverse(){
	node * bas;
	bas=start;
	while(bas->next!=NULL){
		bas=bas->next;
	}
	do{
		printf("%d -> ",bas->data);
		bas=bas->prev;
	}while(bas!=NULL);
}

int main() {
	int secim;
	node * newnode;
while(1){
menu:
	printf("_________________________________________________\n");
	printf("KUYRUGA ELEMAN EKLEME MENUSUNE HOS GELDINIZ\n");
	printf("_________________________________________________\n");
	printf("1-Kuyruga Eleman Ekleme\n");
	printf("2-Kuyruktan Eleman Cikarma\n");
	printf("3-Goruntule\n");
	printf("4-Tersten Goruntule\n");
	printf("5-Cikis\n");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			newnode=getnode();
			enqueue(newnode);
			break;
		case 2:
			newnode=dequeue();
			free(newnode);
			break;
		case 3:
			display();
			printf("\n");
			break;
		case 4:
			displayreverse();
			printf("\n");
			break;
		case 5:
			exit(0);
			break;
		default:
			goto menu;
			
	}
}
}
