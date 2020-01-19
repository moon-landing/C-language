#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//1. ����The_Holy_Bible.txt���еı������滻�ɿո� ��д��ĸת����Сд��ĸ�������� �����ı����浽 ��The_Holy_Bible_Res.txt���С� 
int main(int argc, char *argv[]){
	FILE* fp1 = fopen(argv[1], "r+");   //argv[1] = "The_Holy_Bible.txt"
	FILE* fp2 = fopen(argv[2], "r+");   //argv[2] = "The_Holy_Bible_Res.txt"
	char str[200];
	char c;
	int i;
	while (fgets(str, sizeof(str), fp1)) {
		for (i = 0; (str[i] != '\n') && (str[i] != 0) ; i++) {
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			else if (str[i] >= 33 && str[i] <= 47 || str[i] >= 58 && str[i] <= 63 || str[i] >= 91 && str[i] <= 96) {
				str[i] = ' ';
			}
		}
		fputs(str, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}

//2. ͳ�ơ� The_Holy_Bible_Res.txt �� ���ַ��ĸ��������������ʵĸ�����ͳ�Ƶ��ʵĴ�Ƶ����ӡ�����Ƶ��ߵ�ǰ 10 �����ʼ����Ƶ�� 
#define MAXKEY 5000
int hash(char* key);
int find(char* input, char** arr);
typedef struct wordNum {  //���浥��+���ִ���
	char word[20];
	int num;
}wnum_t, * pwnum_t;
int myCompare(const void*, const void*);
int main(int argc, char *argv[]){
	FILE* fp1 = fopen(argv[1], "r+");   //argv[1] = "The_Holy_Bible_Res.txt"
	FILE* fp2 = fopen(argv[2], "r+");   //argv[2] = "NoNum.txt"
	char str[200];
	char word[20];
	int charNum = 0, lineNum = 1, wordNum = 0;
	int pos; //hash
	pwnum_t words = (pwnum_t)malloc(sizeof(wnum_t) * MAXKEY);
	for (int i = 0; i < MAXKEY; i++) {
		words[i].num = 0;
	}
	while (fgets(str, sizeof(str), fp1)) {			//���ļ��е������滻Ϊ�ո񣬱�����"NoNum.txt"��
		++lineNum;
		for (int i = 0; (str[i] != '\n') && (str[i] != 0); i++) {
			
			if (str[i] >= 0 && str[i] <= 127)
				++charNum;
			if (str[i] >= 48 && str[i] <= 57) {
				str[i] = ' ';
			}
		}
		fputs(str, fp2);
	}
	fclose(fp1);
	rewind(fp2);
	while (fscanf(fp2, "%s", word) != EOF) {  //��hash�ҵ����ʶ�Ӧ�Ľṹ��
		pos = hash(word);
		find(word, &words);
		wordNum++;
	}
	qsort(words, MAXKEY, sizeof(wnum_t), myCompare);   //���ÿ���
	printf("Total char number :%d\nTotal line number :%d\nTotal word number :%d\n", charNum, lineNum, wordNum);
	puts("\n|     Top 10 words     |\n|----------------------|\n|word         |number  |\n|-------------|--------|");
	for (int i = 0; i < 10; i++) {
		printf("| %-10s  |%6d  |\n", words[i].word,words[i].num);
	}
	fclose(fp2);
}
int myCompare(const void* left, const void* right) {
	pwnum_t p1 = (pwnum_t)left;
	pwnum_t p2 = (pwnum_t)right;
	return p2->num - p1->num;
}
int hash(char* key)
{
	int h = 0, g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
			h ^= g >> 24;
		h &= ~g;
	}
	return h % MAXKEY;
}
int find(char* word, pwnum_t* words)
{
	int pos = hash(word);
	if (0 == (*words)[pos].num)
	{	
		strcpy((*words)[pos].word, word);
		++(*words)[pos].num;
	}
	else
	{
		++(*words)[pos].num;
	}
}

//3. ʹ�ü��������1�ڸ������򡣲�������ʱ�� 
#include<stdio.h>
#include<string.h>
#include <time.h>
#define SWAP(a,b) {int tmp = a; a = b; b = tmp;} 
#define SIZE 100000000
#define MAX 200000000
int main(){
	int* arr = (int*)malloc(sizeof(int) * SIZE);
	int* num = (int*)malloc(sizeof(int) * MAX);
	for (int i = 0; i < SIZE; ++i){
		arr[i] = rand() % MAX;
	}
	for (int i = 0; i < MAX; ++i) {
		num[i] = 0;
	}
	for (int i = 0; i < SIZE; ++i) {
		++num[arr[i]];
	}
	for (int i = 0, j = 0; j < SIZE; ++j) {
		if (num[i] > 0) {
			arr[j] = i;
			--num[i];
		}
		else {
			while (num[++i] == 0);
			arr[j] = i;
			--num[i];
		}
	}
}

//4. ��һ����¼ѧ����Ϣ���ļ���ÿһ�м�¼һ��ѧ������Ϣ����ʽ���� 
//ѧ��\t ����\t �Ա�\t ���� 1\t ���� 2\t ���� 3\n.  
#include<stdio.h>
#include<string.h>
#define MAX 5
typedef struct student {
	int num;
	char name[10];
	char sex;
	int score1, score2, score3, totalScore;
	struct student* next;
}stu_t, * pstu_t;
int myCompare(const void* left, const void* right);
int main(int argc, char* argv[]) {
	int i = 0;
	pstu_t totalStu = (pstu_t)malloc(sizeof(stu_t) * MAX);
	FILE* fp = fopen(argv[1], "r+");   //argv[1] = "student.txt"
	while (fscanf(fp, "%d%s %c%d%d%d",
		&((totalStu + i)->num),
		&((totalStu + i)->name),
		&((totalStu + i)->sex),
		&((totalStu + i)->score1),
		&((totalStu + i)->score2),
		&((totalStu + i)->score3)) != EOF) {
		i++;
	}
//Ҫ�󣺣�1����ȡ�ļ������ݣ�����һ������   
	for (i = 0; i < MAX - 1; i++) {
		totalStu[i].next = &(totalStu[i + 1]);
		totalStu[i].totalScore = totalStu[i].score1 + totalStu[i].score2 + totalStu[i].score3;
	}
	totalStu[i].next = NULL;
	totalStu[i].totalScore = totalStu[i].score1 + totalStu[i].score2 + totalStu[i].score3;
	pstu_t aa = totalStu;
	while (aa != NULL) {
		printf("%d\t%s\t%c\t%d\t%d\t%d\t%d\n", aa->num, aa->name, aa->sex, aa->score1, aa->score2, aa->score3, aa->totalScore);
		aa = aa->next;
	}
//��2�������ֵܷݼ����򽫽�����浽ԭ�ļ��� 
	qsort(totalStu, MAX, sizeof(stu_t), myCompare);
	rewind(fp);
	for (i = 0; i < MAX  ; i++) {
		fprintf(fp, "%d\t%s\t%c\t%d\t%d\t%d\n", totalStu[i].num, totalStu[i].name, totalStu[i].sex, totalStu[i].score1, totalStu[i].score2, totalStu[i].score3);
	}
	fclose(fp);
}
int myCompare(const void* left, const void* right) {
	pstu_t p1 = (pstu_t)left;
	pstu_t p2 = (pstu_t)right;
	return p1->totalScore - p2->totalScore;
}