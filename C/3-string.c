#include<stdio.h>
#include<string.h>
char* mystrcat(char *, const char *);
char* mystrcpy(char* , const char*);
int mystrcmp(const char*, const char*);
size_t mystrlen(char*);

void test2();
int ifCharacter(char);
void test3();
void test4_1();
void test4_2();
void reverse(char *, char *);

int main() {
	//char a[10] = "a214";
	//char b[] = "vd";
	//puts(mystrcat(a, b));
	//puts(mystrcpy(a, b));
	//printf("%d", mystrlen(a));
	//printf("%d", mystrcmp(a, b));
	//test2();
	test3();
	//test4_1();
	//test4_2();
}

//1.实现 mystrcpy(), mystrcmp(), mystrcat(), mystrlen()
char* mystrcat(char *str1, const char *str2) {
	char* ps = str1 + strlen(str1);
	char *pf = str2;
	int i = 0;
	while (i <= strlen(str2)) {
		*ps = *pf;
		ps++;
		pf++;
		i++;
	}
	return str1;
}

char* mystrcpy(char* to, const char* from) {
	char* ps = to;
	char* pf = from;
	int i = 0;
	while (i <= strlen(from)) {
		*ps = *pf;
		ps++;
		pf++;
		i++;
	}
	return to;
}

int mystrcmp(const char* str1, const char* str2) {
	char* p1 = str1, * p2 = str2;
	while (*p1 == *p2) {
		p1++;
		p2++;
	}
	if (*p1 > * p2)
		return 1;
	else if (*p1 < *p2)
		return -1;
	else
		return 0;
}

size_t mystrlen(char* str) {
	int i = 0;
	char* p = str;
	while (*p != '\0') {
		p++;
		i++;
	}
	return i;
}

//2.输入一行字符串（单词和若干空格），输出该行单词个数。
int ifCharacter(char c) {
	if ((c >= 81 && c <= 106) || (c >= 97 && c <= 122))
		return 1;
	else return 0;
}

void test2() {
	char a[100];
	char* p;
	int i;
	while (gets_s(a, sizeof(a)) != EOF) {
		p = a;
		for (i = 0; *p != 0; i++) {
			while (!ifCharacter(*p) && *p != 0)
				p++;
			while (ifCharacter(*p) && *p != 0)
				p++;
		}
		printf("The number of words is: %d", i);
	}

}

//3.输入一行字符串（单词和若干空格），输出该行单词（每个单词一行）
void test3() {
	char a[100];
	char* ps, * pf;
	char* i;
	while (gets_s(a, sizeof(a)) != EOF) {
		ps = pf = a;
		for (i = 0; *ps != 0; i++) {
			while (!ifCharacter(*ps) && *ps != 0)
				ps++;
			pf = ps;
			while (ifCharacter(*ps) && *ps != 0)
				ps++;
			for (i = pf; i <= ps; i++)
				printf("%c", *i);
			printf("\n");
		}
	}
}

//4:输入一行字符串，把字符串翻转。
//(1)直接翻转一下
void test4_1() {
	char a[100];
	while (gets_s(a, sizeof(a)) != EOF) {
		reverse(a, a + strlen(a) - 1);
		puts(a);
	}
}

//(2)把每个单词找出来，原地自身翻转
void test4_2() {
	char a[100];
	while (gets_s(a, sizeof(a)) != EOF) {
	char *pf ,*ps;
	pf = ps = a;
	while ('\0' != *ps) {
		while (*ps == ' ')
			ps++;
		pf = ps;
		while (*ps != ' ' && *ps != '\0')
			ps++;
		reverse(pf, ps -1);
	}
	puts(a);
	}
}

void reverse(char* pf, char* ps) {
	char* i = pf, * j = ps;
	char temp;
	while (i < j) {
		temp = *i;
		*i = *j;
		*j = temp;
		i++;
		j--;
	}
}
