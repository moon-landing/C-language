#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 5
typedef int elem_t;
typedef struct student {
	int num;
	char name[20];
	float score1;
	float score2;
	float score3;
}stu, *pstu;
typedef struct node {
	elem_t data;
	struct node* pnext;
}node_t, * pnode_t;

void test1_1_totalMessage(pstu stu);
void test1_2_highest3(pstu student);
void test1_3_averageScore(pstu student);
void test1_4_rank(pstu student);
void test2_tailInsert(pnode_t* pphead, pnode_t* pptail, elem_t data);
void test3_headInsert(pnode_t* pphead, pnode_t* pptail, elem_t data);
void test4_sortInsert(pnode_t* pphead, pnode_t* pptail, elem_t data);
void test5_deleteList(pnode_t* pphead, pnode_t* pptail, int num);
pnode_t test6_combineTwo(pnode_t phead1, pnode_t phead2);
void test7_reverse(pnode_t* phead);
void test8_findLast4th(pnode_t phead);
void test9_findMidElem(pnode_t phead);
void test10_ifCircle(pnode_t phead);
pnode_t test11_ifCross(pnode_t phead1, pnode_t phead2);
void test12_deleteRepeated(pnode_t* phead);
void test13_splitList(pnode_t* phead, pnode_t* phead2);
void printList(pnode_t phead);
void test14_longNumPlus(pnode_t phead1, pnode_t phead2);    //没写完

int main() {
	//stu student[N] = {
	//01 ,"alice", 80, 91, 82,
	//02, "blcak", 70, 61, 52,
	//03, "candy", 70, 71, 72,
	//04, "david", 90, 81, 62,
	//05, "elige", 50, 51 ,92};
	//totalMessage(student);
	//averageScore(student);
	//highest3(student);
	//rank(student);
	elem_t data;
	pnode_t phead, ptail;
	pnode_t phead1, ptail1, phead2, ptail2;
	phead = ptail = NULL;
	phead1 = phead2 = ptail1 = ptail2 = NULL;
	//while (scanf("%d", &data) != EOF) {
	//	tailInsert(&phead, &ptail, data);
	//}
	//deleteList(&phead, &ptail, 3);
	//findLast4th(phead);
	//reverse(&phead);
	//findMidElem(phead);
	//ptail->pnext = phead;
	//ifCircle(phead);
	//phead = combineTwo(phead1, phead2);
	//printList(phead);
	//while (scanf("%d", &data) != EOF) {
	//	sortInsert(&phead, &ptail, data);
	//}
	//deleteRepeated(&phead);
	//splitList(&phead, &phead2);
	//printList(phead);
	//printList(phead1);
	//printList(phead2);
	test14_longNumPlus(phead1, phead2); 
}

void printList(pnode_t phead) {
	pnode_t pcur = phead;
	while (pcur) {
		printf("%d ", pcur->data);
		pcur = pcur->pnext;
	}
	printf("\n");
}

//1. 有一个学生结构体，其数据成员有： 学号， 姓名，3门课程。从键盘上输入5个学生的信息。要求输出:
//(1)  按照学号递增输出全部学生信息，每个学生的信息一行。（格式： 学号 姓名 分数 1 分数 2 分数 3 总分） 
void test1_1_totalMessage(pstu student) {
	int i;
	for (i = 0; i < 4; i++) {
		printf("%02d %s %5.1f %5.1f %5.1f\n", student[i].num, student[i].name, student[i].score1, student[i].score2, student[i].score3);
	}
}

//(2)  输出每门课程最高分的学生的信息 
void test1_2_highest3(pstu student) {
	int i, num1, num2, num3;
	float max1, max2, max3;
	max1 = student[0].score1;
	max2 = student[0].score2;
	max3 = student[0].score3;
	num1 = num2 = num3 = 0;
	for (i = 1; i < N; i++) {
		if (max1 < student[i].score1) {
			max1 = student[i].score1;
			num1 = i;
		}
		if (max2 < student[i].score2) {
			max2 = student[i].score2;
			num2 = i;
		}
		if (max3 < student[i].score3) {
			max3 = student[i].score3;
			num3 = i;
		}
	}
	printf("The highest of 3 subject are:\n");
	printf("%02d %s %5.1f %5.1f %5.1f\n", student[num1].num, student[num1].name, student[num1].score1, student[num1].score2, student[num1].score3);
	printf("%02d %s %5.1f %5.1f %5.1f\n", student[num2].num, student[num2].name, student[num2].score1, student[num2].score2, student[num2].score3);
	printf("%02d %s %5.1f %5.1f %5.1f\n", student[num3].num, student[num3].name, student[num3].score1, student[num3].score2, student[num3].score3);
}

//(3) 输出每门课程的平均分
void test1_3_averageScore(pstu student) {
	int i;
	float sumScore1, sumScore2, sumScore3;
	sumScore1 = sumScore2 = sumScore3 = 0;
	for (i = 0; i < N; i++) {
		sumScore1 += student[i].score1;
		sumScore2 += student[i].score2;
		sumScore3 += student[i].score3;
	}
	printf("The average scores of 3 subjects are: %5.1f, %5.1f, %5.1f\n", sumScore1 /= N, sumScore2 /= N, sumScore3 /= N);
}

//(4) 按照总分输出学生排名
void test1_4_rank(pstu student) {
	float total[N] = { 0 };
	int i, j;
	int tempt;
	stu temps;
	for (i = 0; i < N; i++) {
		total[i] = student[i].score1 + student[i].score2 + student[i].score3;
	}
	for (i = 0; i < N; i++)
		for (j = N - 1; j > i; j--) {
			if (total[j] > total[j - 1]) {
				tempt = total[j];
				total[j] = total[j - 1];
				total[j - 1] = tempt;
				temps = student[j];
				student[j] = student[j - 1];
				student[j - 1] = temps;
			}
		}
	printf("The rank of this test is: \n");
	for (i = 0; i < N; i++) {
		printf("%02d %s %5.1f\n", student[i].num, student[i].name, total[i]);
	}
}

//2. 用尾插法建立链表。
void test2_tailInsert(pnode_t* pphead, pnode_t* pptail, elem_t data) {
	pnode_t pcur = (pnode_t)malloc(sizeof(node_t));
	memset(pcur, 0, sizeof(node_t));
	pcur->data = data;
	if (*pphead == NULL) {
		*pphead = pcur;
		*pptail = pcur;
	}
	else {
		(*pptail)->pnext = pcur;
		*pptail = pcur;
	}
}

//3. 用头插法建立链表。 
void test3_headInsert(pnode_t* pphead, pnode_t* pptail, elem_t data) {
	pnode_t pcur = (pnode_t)malloc(sizeof(node_t));
	memset(pcur, 0, sizeof(node_t));
	pcur->data = data;
	if (*pphead == NULL) {
		*pphead = pcur;
		*pptail = pcur;
	}
	else {
		pcur->pnext = *pphead;
		*pphead = pcur;
	}
}

//4. 用有序插入建立链表。
void test4_sortInsert(pnode_t* pphead, pnode_t* pptail, elem_t data) {
	pnode_t pcur = (pnode_t)malloc(sizeof(node_t));
	memset(pcur, 0, sizeof(node_t));
	pcur->data = data;
	if (*pphead == NULL) {
		*pphead = *pptail = pcur;
	}
	else if (data < (*pphead)->data) {
		pcur->pnext = *pphead;
		*pphead = pcur;
	}
	else if (data > (*pptail)->data) {
		(*pptail)->pnext = pcur;
		*pptail = pcur;
	}
	else {
		pnode_t p1 = *pphead;
		pnode_t p2 = p1->pnext;
		while (p2 != NULL) {
			if (p1->data < data && p2->data >= data) {
				pcur->pnext = p2;
				p1->pnext = pcur;
				break;
			}
			p1 = p1->pnext;
			p2 = p2->pnext;
		}
		if (p2 == NULL)
			printf("Error\n");
	}
}

//5. 删除指定的某个结点。 
void test5_deleteList(pnode_t* pphead, pnode_t* pptail, int num) {
	pnode_t pcur = *pphead;
	pnode_t ppre = pcur;
	while (pcur->data != num) {
		ppre = pcur;
		pcur = pcur->pnext;
	}
	if (pcur == NULL) {
		printf("Finding is failed.\n");
	}
	if (pcur == *pphead) {
		if (*pptail == *pphead) {
			*pptail == NULL;
		}
		*pphead = (*pphead)->pnext;
		free(pcur);
		pcur = NULL;
	}
	else {
		if (pcur == *pptail) {
			*pptail = ppre;
		}
		ppre->pnext = pcur->pnext;
		free(pcur);
		pcur = NULL;
	}
}
	
//6. 将两个有序链表合并成一个有序链表。
pnode_t test6_combineTwo(pnode_t phead1, pnode_t phead2) {
	pnode_t pcur1, pcur2, pcur, phead;
	pcur1 = phead1;
	pcur2 = phead2;
	if (pcur1->data <= pcur2->data) {
		pcur = pcur1;
		phead = pcur;
		pcur1 = pcur1->pnext;
	}
	else {
		pcur = pcur2;
		phead = pcur;
		pcur2 = pcur2->pnext;
	}
	while (pcur1 && pcur2) {
		if (pcur1->data <= pcur2->data) {
			pcur->pnext = pcur1;
			pcur1 = pcur1->pnext;
			pcur = pcur->pnext;
		}
		else{
			pcur->pnext = pcur2;
			pcur2 = pcur2->pnext;
			pcur = pcur->pnext;
		}
	}
	if (pcur1) {
		pcur->pnext = pcur1;
	}
	else if (pcur2) {
		pcur->pnext = pcur2;
	}
	return phead;
}

//7. 将一个链表逆置  如：1->2 ->3 ->4 ->5 ->NULL， 输出: 5 -> 4 -> 3 ->2 ->1 -> NULL ； 
void test7_reverse(pnode_t *phead) {
	pnode_t pcur, pcur_next, ptmphead;
	ptmphead = pcur = *phead;
	pcur = (*phead)->pnext;
	ptmphead->pnext = NULL;
	while (pcur) {
		pcur_next = pcur->pnext;
		pcur->pnext = ptmphead;
		ptmphead = pcur;
		*phead = pcur;
		pcur = pcur_next;
	}
}

//8. 找出链表的倒数第四个节点 
void test8_findLast4th(pnode_t phead) {
	pnode_t pcur = phead;
	pnode_t pcur_4 = phead;
	int i;
	for (i = 0; i < 4; i++) {
		pcur = pcur->pnext;
	}
	if (!pcur)
		printf("Error!\n");
	while (pcur) {
		pcur = pcur->pnext;
		pcur_4 = pcur_4->pnext;
	}
	printf("The fourth elememt from bottom is :%d\n", pcur_4->data);
}

//9. 找出链表的中间节点 
void test9_findMidElem(pnode_t phead) {
	pnode_t pcur1 = phead;
	pnode_t pcur2 = phead;
	while (pcur2) {
		pcur2 = pcur2->pnext;
		pcur2 = pcur2->pnext;
		pcur1 = pcur1->pnext;
	}
	printf("The mid element is :%d \n", pcur1->data);
}

//10. 判断单链表是否有环 
void test10_ifCircle(pnode_t phead) {
	pnode_t pcur1 = phead;
	pnode_t pcur2 = phead;
	int i = 0;
	while (pcur2->pnext != pcur1) {
		pcur2 = pcur2->pnext;
		pcur2 = pcur2->pnext;
		pcur1 = pcur1->pnext;
		i++;
		if (i >= 1000) {
			printf("The list is not a circle.\n");
			break;
		}
	}
	if (pcur2->pnext == pcur1)
		printf("The list is a circle.\n");
}

//11. 判断两个链表是否相交, 如果相交, 计算交点 
pnode_t test11_ifCross(pnode_t phead1, pnode_t phead2) {
	int length1, length2, minus;
	length1 = length2 = 0;
	pnode_t pcur1, pcur2;
	pcur1 = phead1;
	pcur2 = phead2;
	while (pcur1) {
		pcur1 = pcur1->pnext;
		++length1;
	}
	while (pcur2) {
		pcur2 = pcur2->pnext;
		++length2;
	}
	pcur1 = phead1;
	pcur2 = phead2;
	if (length1 >= length2) {
		minus = length1 - length2;
		while (minus) {
			pcur1 = pcur1->pnext;
			--minus;
		}
	}
	else {
		minus = length2 - length1;
		while (minus) {
			pcur2 = pcur2->pnext;
			--minus;

		}
	}
		while (pcur1 != pcur2 && pcur1) {
			pcur1 = pcur1->pnext;
			pcur2 = pcur2->pnext;
		}
		if (!pcur1)
			return pcur1;
		return NULL;
	}

//12. 删除单链表中重复的元素 
void test12_deleteRepeated(pnode_t* phead) {
	//调用此函数前采用有序插入，保证链表有序
	pnode_t pcur;
	pcur = *phead;
	while (pcur->pnext && pcur) {
		if (pcur->data == pcur->pnext->data) {
			pcur->pnext = pcur->pnext->pnext;
		}
		else {
			pcur = pcur->pnext;
		}
	}
}

//13. 将一个链表拆分（将链表奇数位置上的节点构成一个链表，偶数位置上的节点构成另一 个链表）
//例如：L：1 -> 2 -> 3 ->4 ->5 ->6 ->7 ->8 ->9->NULL L1 : 1 ->3 ->5 ->7 ->9->NULL; L2: 2 ->4 ->6 ->8->NULL
void test13_splitList(pnode_t* phead, pnode_t *phead2) {
	pnode_t pcur1, pcur2;
	pnode_t pcur = *phead;
	*phead2 = pcur->pnext;
	pcur = (*phead2)->pnext;
	pcur1 = *phead;
	pcur2 = *phead2;
	int i = 3;
	while (pcur) {
		if (i % 2 == 1) {
			pcur1->pnext = pcur;
			pcur1 = pcur1->pnext;
			pcur = pcur->pnext;
		}
		else {
			pcur2->pnext = pcur;
			pcur2 = pcur2->pnext;
			pcur = pcur->pnext;
		}
		i++;
	}
	pcur1->pnext = NULL;
	pcur2->pnext = NULL;
}

//14．大整数加法。（计算两个整数（该整数的值可能超过一个整型变量所能表示的范围）的 加法）
void test14_longNumPlus(pnode_t phead1, pnode_t phead2) {
	pnode_t pnum1, pnum2, pcur1, pcur2;
	int n;
	pcur1 = phead1;
	pcur2 = phead2;
	printf("Please enter num1:\n");
	while (scanf("%c", &n) != EOF) {
		pcur1->data = n;
		pcur1 = pcur1->pnext;
	}
	pcur1->pnext = NULL;
	printf("Please enter num2:\n");
	while (scanf("%d", &n) != EOF) {
		pcur2->data = n;
		pcur2 = pcur2->pnext;
	}
	pcur2->pnext = NULL;
}