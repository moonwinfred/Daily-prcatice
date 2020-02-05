#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Addnodelist1(int a);
void Addnodelist2(int a);
void searchlist();
struct Node* SelectNode(int a);
void Freelist();
void Addrandlist(int a,int b);
void Deletehead();
void Deletetail();
void Deleterand(int a);
struct Node {
	int a;
	struct Node* pnext;
};
struct Node* head=NULL;
struct Node* tail=NULL;
int main() {
	struct Node *pt;
	pt->a = 1;

	Addnodelist1(1);
	Addnodelist2(2);
	searchlist();
	SelectNode(1);
	Freelist;
	Addrandlist(pt->a,1);
	Deletehead();
	Deletetail();
	Deleterand(1);

}
void Addnodelist1(int a) {
	struct Node* ptemp=(struct Node*)malloc(sizeof(struct Node));
	ptemp->a = a;
	ptemp->pnext = NULL;
	if (head == NULL) {
		head = ptemp;
		tail = ptemp;
	}
	else {
		ptemp->pnext = head;
		head = ptemp;
	}
}
void Addnodelist2(int a) {
	struct Node* ptemp = (struct Node*)malloc(sizeof(struct Node));
	ptemp->a = a;
	ptemp->pnext = NULL;
	if (head == NULL) {
		head = ptemp;
		tail = ptemp;
	}
	else {
		tail->pnext = ptemp;
		tail = ptemp;
	}
}
void searchlist() {
	struct Node* ptemp = head;
	
	while (ptemp!=NULL) {
		printf("%d", ptemp->a);
		ptemp = ptemp->pnext;
	}
}

struct Node* SelectNode(int a) {
	struct Node* ptemp = head;
	if (head == NULL) {
		return NULL;
	}
	else {
		while (ptemp != NULL) {
			if (ptemp->a == a) {
				return ptemp;
			}
			ptemp = ptemp->pnext;

		}
		return NULL;
	}

}
void Freelist() {
	struct Node* ptemp = head;
	while (ptemp != NULL) {
		struct Node* pt = ptemp;
		ptemp = ptemp->pnext;
		free(pt);
	}

}
void Addrandlist(int a, int b) {
	if (head == NULL) {
		printf("nothing to add");
	}
	struct Node* pt = SelectNode(a);
	if (pt == NULL)printf("nothing to add");//要记得判断 该指定点是否能够找到
	struct Node* ptemp = (struct Node*)malloc(sizeof(struct Node));
	ptemp->a = b;
	ptemp->pnext = NULL;
	//添加结点 还需要再分类为该结点是否为尾结点 
	if (pt == tail) {
		tail->pnext = ptemp;
		tail = ptemp;
	}
	else {
		ptemp->pnext = pt->pnext;
		pt->pnext = ptemp;
	}
}
void Deletehead() {
	

	if (head == NULL) {
		printf("nothing to delete");
		return;
	}
	else if (head == tail) {
		free(head);//别忘记释放内存啊
		head = NULL;
		tail = NULL;
	}
	else {
		struct Node* pt = head;
		head = head->pnext;
		free(head);


		
	}
}
void Deletetail() {
	struct Node* ptemp = head;
	if (head == NULL) {
		printf("nothing to delete");
	}
	else if (head == tail) {
		free(tail);//记得释放内存啊
		head = NULL;
		tail = NULL;
	}
	else {
		while (ptemp->pnext != tail) {
			ptemp = ptemp->pnext;
		}
		free(tail);
		tail = ptemp;

	}
}
void Deleterand(int a) {
	struct Node* ptemp = SelectNode(a);
	if (head == NULL) {
		printf("nothing to delete");
		return;
	}
	else if (head == tail) {
		free(tail);
		head = NULL;
		tail = NULL;
	}
	else {
		if (ptemp == head) {
			Deletehead();
		}
		else if (ptemp == tail) {
			Deletetail();
		}
		else {
			struct Node* pt = head;
			while (pt->pnext != ptemp) {
				pt = pt->pnext;
			}
			pt->pnext = ptemp->pnext;
			free(ptemp);
			
		}
	}
}

