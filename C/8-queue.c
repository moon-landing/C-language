//1、完成快排，堆排的编写
//(1)快排
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

//(2)堆排
#define SWAP(a, b) {int temp = a; a = b; b = temp;} //宏操作
void heapsort(int* arr, int size) {
	int i;
	for (i = (size - 2) / 2; i >= 0; --i) { //size-2是因为树的根节点从0开始，且树的最后一个元素为size-1
		adjust(arr, i, size - 1);
	} //初次建立大根堆
	for (int i = size - 1; i >= 1; --i) {//i = 0时无需再交换
		SWAP(arr[0], arr[i]); //得到最大值，放在数组尾
		adjust(arr, 0, i - 1); //此时根节点变了，故从根节点开始向下调整
	}
}
void adjust(int* arr, int parent, int size) {
	int son = parent * 2 + 1;
	while (son <= size) {
		if (son + 1 <= size && arr[son] < arr[son + 1]) {
			son++; //李世民先和他兄弟比较
		}
		if (arr[parent] < arr[son]) {
			SWAP(arr[parent], arr[son]);
			parent = son;
			son = 2 * parent + 1; //将交换后的孩子结点作为父结点，继续向下比较
		}
		else     //不需交换的情况
			break;
	}
}

//2、使用qsort解决结构体数组的第一题（这周周一）
#include <stdio.h> 
#include <stdlib.h> 
#define SWAP(a,b) {int tmp = a; a = b; b = tmp;} //宏操作
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

//3、红黑树的插入（如果觉的太难，就自己画画图看一看即可）
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
void rbtree_left_rotate(RBTRoot* root, Node* x);   //左旋
void rbtree_right_rotate(RBTRoot* root, Node* x);  //右旋
void Insert(RBTRoot* root, Node* node);            //插入（同二叉排序树的插入）
void Insert_fixup(RBTRoot* root, Node* node);      //插入后调整为红黑树

void Insert(RBTRoot* root, Node* node) {
    if (!(root->node)) {
        root->node = node;
    }
    else {               //插入的值小于当前节点，放入其左子树，大于则放入其右子树
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

void Insert_fixup(RBTRoot* root, Node* node) { //情形3中判断情形1
    Node* parent = node->pparent;
    Node* gparent = parent->pparent;
    Node* temp;
    while (parent->color == 'r') {   //P不为红色，则为情形1或情形2
        if (parent->pleft = node) { //N为P的左孩子
            if (gparent->pright->color == 'r') {//叔叔为红色，则为情况3
                gparent->color = 'r';
                parent->color = 'b';
                gparent->pright->color = 'b';
                continue;  //继续递归判断
            }
            if (parent->pright == node) { //P右孩子为N，判断为情形4
                rbtree_left_rotate(root, parent);
                temp = parent;
                parent = node;
                node = temp;
                continue;             //对交换后的P继续递归判断
            }
            //剩余一种情况则为情形5
            parent->color = 'b';
            gparent->color = 'r';
            rbtree_right_rotate(root, gparent);  //对G右旋
        }
        else {  //N为P的右孩子，则镜像上面步骤
            if (gparent->pleft->color == 'r') {//叔叔为红色，则为情况3
                gparent->color = 'r';
                parent->color = 'b';
                gparent->pleft->color = 'b';
                continue;  //继续递归判断
            }
            if (parent->pleft == node) { //P右孩子为N，判断为情形4
                rbtree_right_rotate(root, parent);
                temp = parent;
                parent = node;
                node = temp;
                continue;             //对交换后的P继续递归判断
            }
            //剩余一种情况则为情形5
            parent->color = 'b';
            gparent->color = 'r';
            rbtree_left_rotate(root, gparent);  //对G右旋
        }

    }
    root->node->color = 'b';          //情况1
}

//4、比较厉害的同学做删除
