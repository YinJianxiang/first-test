/*************************************************************************
    > File Name: binThrTree.c
    > Author: YinJianxiang
    > Mail: YinJianxiang123@gmail.com
    > Created Time: 2017年10月19日 星期四 23时39分38秒
 ************************************************************************/


#include<stdio.h>
#include<stdlib.h>


typedef enum {
	Link,	
	Thread
} PointerTag;

typedef struct BinThrNode {
	char data;
	struct BinThrNode *l_child;
	struct BinThrNode *r_child;
	PointerTag l_tag;
	PointerTag r_tag;
} BinThrNode,*BinThrTree;

BinThrTree pre;  //存储前驱节点


void CreateBinThrTree(BinThrTree *T) {
	char c;

	scanf("%c",&c);
	if(' ' == c) {
		*T = NULL;
	} else {
		*T = (BinThrNode *)malloc(sizeof(BinThrNode));
		(*T)->data = c;
		(*T)->l_tag = Link;
		(*T)->r_tag = Link;

		CreateBinThrTree(&(*T)->l_child);
		CreateBinThrTree(&(*T)->r_child);
	}
}

void InThreading(BinThrTree T) {
	if(T) {
		InThreading(T->l_child);
		
		if(!T->l_child) {
			T->l_tag = Thread;
			T->l_child = pre;
		}

		if(!pre->r_child) {
			pre->r_tag = Thread;
			pre->r_child = T;
		}

		pre = T;

		InThreading(T->r_child);
	}

}

void InOrderThreading(BinThrTree *p,BinThrTree T) {
	*p = (BinThrTree)malloc(sizeof(BinThrNode));
	if(!T) {
		(*p)->l_child = *p;
	} else {
		(*p)->l_child = T;
		pre = *p;
		InThreading(T);
		pre->r_child = *p;
		pre->r_tag = Thread;
		(*p)->r_child = pre;
	}
}

void visit(char c) {
	printf("%c",c);	
}

void InOrderTraverse(BinThrTree T) {
	BinThrTree p;
	p = T->l_child;

	while(p != T) {
		while(p->l_tag == Link) {
			p = p->l_child;
		}
		visit(p->data);
		
		while(p->r_tag == Thread && p->r_child != T) {
			p = p->r_child;
			visit(p->data);
		}
	}
}

int main() {
	BinThrTree P,T = NULL;

	CreateBinThrTree(&T);
	
	InOrderThreading(&P,T);

	InOrderTraverse(P);
	return 0;
}
