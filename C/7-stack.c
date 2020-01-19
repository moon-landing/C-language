//1、完成栈，队列编写
//(1)链式栈
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int elem_t;
typedef struct node {
	elem_t data;
	struct node* pnext;
} stackNode_t, * pstackNode_t;
typedef struct stack {
	pstackNode_t phead;
	int size;
} stack_t, * pstack_t;

void stackInit(pstack_t pstack) {
	memset(pstack, 0, sizeof(stack_t));
}
void push(pstack_t pstack, elem_t data) {
	pstackNode_t newnode = (pstackNode_t)malloc(sizeof(stackNode_t));
	newnode->data = data;
	newnode->pnext = pstack->phead;
	pstack->phead = newnode;
	++pstack->size;
}
void pop(pstack_t pstack) {
	if (isEmpty(pstack)) {
		puts("The stack was already empty.");
	}
	else {
		pstackNode_t pnode = pstack->phead;
		pstack->phead = pnode->pnext;
		pstack->size--;
		free(pnode);
		pnode = NULL;
	}
}

elem_t top(pstack_t pstack) {
	if (isEmpty(pstack)) {
		puts("The stack was already empty.");
	}
	return pstack->phead->data;
}
int isEmpty(pstack_t pstack) {
	if (pstack->size == 0)
		return 1;
		return 0;
}
int getSize(pstack_t pstack) {
	return pstack->size;
}
void printStack(pstack_t pstack) {
	if (isEmpty(pstack)) {
		puts("The stack was already empty.");
		return;
	}
	pstackNode_t pnode = pstack->phead;
	while (pnode) {
		printf("%d ", pnode->data);
		pnode = pnode->pnext;
	}
	puts(" ");
}

int main() {
	stack_t stack;
	stackInit(&stack);
	elem_t data;
	while (scanf("%d", &data) != EOF){
		push(&stack, data);
	}
	printStack(&stack);
	data = top(&stack);
	printf("top = %d\n", data);
	pop(&stack);
	printStack(&stack);
}

//(2)线性循环队列
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef int elem_t;
typedef struct queue {
	elem_t arr[MAX];
	int front;
	int rear;
	int size;
} queue_t, * pqueue_t;
void queueInit(pqueue_t pqueue) {
	memset(pqueue, 0, sizeof(queue_t));
}
void enQueue(pqueue_t pqueue, elem_t data) {
	if (isFull(pqueue)) {
		putsJ("Error, the queue is full.");
		return;
	}
	pqueue->arr[pqueue->rear] = data;
	pqueue->rear = (pqueue->rear + 1) % MAX;
	++pqueue->size;
}
elem_t deQueue(pqueue_t pqueue) {
	if (isEmlpty(pqueue)) {	
		putsJ("Error, the queue is emplty.");
		return;
	}
	elem_t data = pqueue->arr[pqueue->front];
	pqueue->front = (pqueue->front + 1) % MAX;
	--pqueue->size;
	return data;
}
elem_t getFront(pqueue_t pqueue) {
	if (isEmlpty(pqueue)) {
		putsJ("Error, the queue is emplty.");
		return;
	}
	elem_t data = pqueue->arr[pqueue->front];
	return data;
}
elem_t getRear(pqueue_t pqueue) {
	if (isEmlpty(pqueue)) {
		putsJ("Error, the queue is emplty.");
		return;
	}
	elem_t data;
	if (pqueue->rear == 0)
		data = pqueue->arr[MAX - 1];
	else
		data = pqueue->arr[pqueue->rear - 1];
	return data;
}
int isEmpty(pqueue_t pqueue) {
	if (pqueue->size == 0)
		return 1;
	return 0;
}
int isFull(pqueue_t pqueue) {
	if (pqueue->front == (pqueue->rear + 1) % MAX)
		return 1;
	return 0;
}
int getSize(pqueue_t pqueue) {
	return pqueue->size;
}
void printQueue(pqueue_t pqueue) {
	int cur = pqueue->front;
	while ((cur + 1) % MAX != pqueue->rear) {
		printf("%d ", pqueue->arr[cur]);
		cur++;
	}
	puts(" ");
}

//2、完成二叉树的层次建树
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef int elem_t;
typedef struct treenode {
	elem_t data;
	struct treenode* pleft;
	struct treenode* pright;
} treenode_t, * ptreenode_t;
void buildNewTree(ptreenode_t *pproot) {
	elem_t data;
	ptreenode_t queue[MAX];
	int rear = 0;
	int front = 0;
	ptreenode_t pcur;
	while (scanf("%d", &data) != EOF) {
		ptreenode_t pnew = (ptreenode_t)malloc(sizeof(treenode_t));
		pnew->data = data;
		queue[rear] = pnew;
		rear = (rear + 1) % MAX;
		if (*pproot == NULL) { //如果树为空
			*pproot = pnew;
			pcur = queue[front];
			front = (front + 1) % MAX;
		}
		else if(pcur->pleft == NULL){  //此时pcur没有左右孩子，将左孩子指向pnew；
			pcur->pleft = pnew; 

		}
		else { // 此时pcur->pright == NULL   pew作为pcur的右孩子， pcur两个孩子都不为空，将队头结点出队赋给pcur
			pcur->pright = pnew;      
			pcur = queue[front];
			front = (front + 1) % MAX;
		}

	}
}

//3、完成冒泡，选择，插入排序
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bubbleSort(int *arr, int size) {
	int i, j, temp;
	for(i = size - 1 ; i >= 0; i--)
		for (j = 0; j < i; j++) {
			if(arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
}
void selectSort(int* arr, int size) {
	int minpos;
	for (int i = 0; i < size; i++) {
		minpos = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[i] < arr[j])
				minpos = j;
			swap(&arr[minpos], &arr[i]);
		}
	}
}
void insertSort(int* arr, int size) {
	int i, j, temp, tempj;
	for (i = 1; i < size; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			arr[j + 1] = arr[j];
		arr[++j] = temp;
	}
}