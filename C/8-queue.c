//1����ɿ��ţ����ŵı�д
//(1)����
void quickSort(int *arr, int beg, int end){
	if (beg < end)
	{
		int ret = divide(arr, beg, end);
		quickSort(arr, beg, ret - 1);
		quickSort(arr, ret + 1, end);
	}
}
int divide(int* arr, int beg, int end){
		int i, j = beg, pivot = arr[end];
		int temp;
		for (i = beg; i < end; ++i){
			if (arr[i] < arr[end]) {
				temp = arr[j];
				arr[j++] = arr[i];
				arr[i] = temp;
			}
		}
		temp = arr[j];
		arr[j] = arr[end];
		arr[end] = temp;
		return j;
	}

//(2)����
#define SWAP(a, b) {int temp = a; a = b; b = temp;} //�����
void heapsort(int* arr, int size) {
	int i;
	for (i = (size - 2) / 2; i >= 0; --i) { //size-2����Ϊ���ĸ��ڵ��0��ʼ�����������һ��Ԫ��Ϊsize-1
		adjust(arr, i, size - 1);
	} //���ν��������
	for (int i = size - 1; i >= 1; --i) {//i = 0ʱ�����ٽ���
		SWAP(arr[0], arr[i]); //�õ����ֵ����������β
		adjust(arr, 0, i - 1); //��ʱ���ڵ���ˣ��ʴӸ��ڵ㿪ʼ���µ���
	}
}
void adjust(int* arr, int parent, int size) {
	int son = parent * 2 + 1;
	while (son <= size) {
		if (son + 1 <= size && arr[son] < arr[son + 1]) {
			son++; //�������Ⱥ����ֵܱȽ�
		}
		if (arr[parent] < arr[son]) {
			SWAP(arr[parent], arr[son]);
			parent = son;
			son = 2 * parent + 1; //��������ĺ��ӽ����Ϊ����㣬�������±Ƚ�
		}
		else     //���轻�������
			break;
	}
}

//2��ʹ��qsort����ṹ������ĵ�һ�⣨������һ��
#include <stdio.h> 
#include <stdlib.h> 
#define SWAP(a,b) {int tmp = a; a = b; b = tmp;} //�����
#define N 5
typedef int elem_t;
typedef struct student {
	int num;
	char name[20];
	float score1;
	float score2;
	float score3;
}stu, * pstu;
int myCompare(const void*, const void*);
int main() {
	stu student[N] = {
	05, "Ethan", 50, 51, 92,
	02, "Blcak", 70, 61, 52,
	03, "Candy", 70, 71, 72,
	01 ,"Alice", 80, 91, 82,
	04, "David", 90, 81, 62,
	};
	qsort(student, N, sizeof(stu), myCompare);
	for (int i = 0; i < N; i++)
		printf("%02d %s %5.1f %5.1f %5.1f\n", student[i].num, student[i].name, student[i].score1, student[i].score2, student[i].score3);
}
int myCompare(const void* left, const void* right) {
	pstu p1 = (pstu)left;
	pstu p2 = (pstu)right;
	return p1->num - p2->num;
}

//3��������Ĳ��루�������̫�ѣ����Լ�����ͼ��һ�����ɣ�
typedef struct RBTNode {
    unsigned char color;
    int key;
    struct RBTNode* pleft;
    struct RBTNode* pright;
    struct RBTNode* pparent;
}Node, * RBTree;
typedef struct rb_root {
    Node* node;
}RBTRoot;
void rbtree_left_rotate(RBTRoot* root, Node* x);   //����
void rbtree_right_rotate(RBTRoot* root, Node* x);  //����
void Insert(RBTRoot* root, Node* node);            //���루ͬ�����������Ĳ��룩
void Insert_fixup(RBTRoot* root, Node* node);      //��������Ϊ�����

void Insert(RBTRoot* root, Node* node) {
    if (!(root->node)) {
        root->node = node;
    }
    else {               //�����ֵС�ڵ�ǰ�ڵ㣬�������������������������������
        Node* par = NULL;
        Node* pcur = root->node;

        while (pcur != NULL) {
            par = pcur;
            if (node->key < pcur->key) {
                pcur = pcur->pleft;
            }
            else {
                pcur = pcur->pleft;
            }
        }
        node->pparent = par;
        if (node->key < par->key) {
            par->pleft = node;
        }
        else {
            par->pleft = node;
        }
    }
    node->color = 'r';
    Insert_fixup(root, node);
}

void Insert_fixup(RBTRoot* root, Node* node) { //����3���ж�����1
    Node* parent = node->pparent;
    Node* gparent = parent->pparent;
    Node* temp;
    while (parent->color == 'r') {   //P��Ϊ��ɫ����Ϊ����1������2
        if (parent->pleft = node) { //NΪP������
            if (gparent->pright->color == 'r') {//����Ϊ��ɫ����Ϊ���3
                gparent->color = 'r';
                parent->color = 'b';
                gparent->pright->color = 'b';
                continue;  //�����ݹ��ж�
            }
            if (parent->pright == node) { //P�Һ���ΪN���ж�Ϊ����4
                rbtree_left_rotate(root, parent);
                temp = parent;
                parent = node;
                node = temp;
                continue;             //�Խ������P�����ݹ��ж�
            }
            //ʣ��һ�������Ϊ����5
            parent->color = 'b';
            gparent->color = 'r';
            rbtree_right_rotate(root, gparent);  //��G����
        }
        else {  //NΪP���Һ��ӣ��������沽��
            if (gparent->pleft->color == 'r') {//����Ϊ��ɫ����Ϊ���3
                gparent->color = 'r';
                parent->color = 'b';
                gparent->pleft->color = 'b';
                continue;  //�����ݹ��ж�
            }
            if (parent->pleft == node) { //P�Һ���ΪN���ж�Ϊ����4
                rbtree_right_rotate(root, parent);
                temp = parent;
                parent = node;
                node = temp;
                continue;             //�Խ������P�����ݹ��ж�
            }
            //ʣ��һ�������Ϊ����5
            parent->color = 'b';
            gparent->color = 'r';
            rbtree_left_rotate(root, gparent);  //��G����
        }

    }
    root->node->color = 'b';          //���1
}

//4���Ƚ�������ͬѧ��ɾ��
