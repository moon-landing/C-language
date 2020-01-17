#include<stdio.h>
#include<string.h>
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main() {
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
}

//1.�������ַ����ֵ��ַ����ֿ�,ʹ�÷ֿ�����ַ���ǰһ���������ֺ�һ��������ĸ����O(1)��
void test1(){     //simillar to insert sort 
	char a[100];
	char* i, * j;
	char temp;
	int  k , s;
		while (gets_s(a, sizeof(a)) != EOF) {
		i = j = a;
		k = 0, s = 0;
		while (*i != 0) {
			while ((*i < 48 || *i > 57) && *i != 0) {
				i++;
			}
			if (0 == *i)
				break;
			temp = *i;
			for (k = i - a ; k > s; k--)
				a[k] = a[k - 1];
			a[s] = temp;
			s++;
		}
		puts(a);
	}
}

//2.���ַ����еĿո��滻�ɡ�%020�� ���ռ临�Ӷ�Ҫ��O(1)��
void test2() {
	char a[100];
	char b[100] = {0};
	char *c = "%020";
	char* i, * j, *end;
	int  bi, spacenums, k;
	for (int i = 0; i < 24; i++) {  //��b��%020����
		strcat(b, c);
	}
	while (gets_s(a, sizeof(a)) != EOF) {
		i = j = a;
		end = a + strlen(a);
		while (*i != 0) {
			spacenums = 0;
			while (*i != ' ') {               //�ҵ�ÿ���ո����ʼλ��
				i++;
			}
			j = i;
			while (*i == ' ') {               //ͳ�ƿո�
				i++;
				spacenums++;
			}
			for(k = end - a; k >= j - a;k--){ //���ÿո�κ���ַ����� �ո���*3
				a[k + 3 * spacenums] = a[k];
			}
			end += 3 * spacenums;
			i += 3 * spacenums;
			for (bi = 0; j < i;) {            //����%020
				*j= b[bi];
				j++, bi++;
			}
		}
		puts(a);
	}
}

//3.ɾ���ַ�����ָ�����ַ������� ��abcdaefaghiagkl�� ɾ����a��,�Ժ� ��bcdefghigkl��
void test3() {     //ǰ��Ԫ��
	char a[100];
	char* i, * end;
	int  k;
	while (gets_s(a, sizeof(a)) != EOF) {
		i = a;
		k = 0;
		end = strlen(a);
		while (*i != 0) {
			while (*i != 'a'&& *i != 0) {
				i++;
			}
			if (0 == *i)
				break;
			for (k = i - a; k <= end; k++)
				a[k] = a[k + 1];
		}
		puts(a);
	}
}

//4.ɾ��һ���������ظ���Ԫ�ء����� 1 ,2, 2,2,3,3,3,4,4,5,5,5,6,6,6 -> 1,2,3,4,5,6
void test4() {     //ǰ��Ԫ��
	char a[100];
	char* i, * end, *iplace;
	int  k, repeatNum;
	while (gets_s(a, sizeof(a)) != EOF) {
		i = a, k = 0, repeatNum = 0;
		end = strlen(a);
		while (*i != 0 && (i - a < strlen(a))) {
			while (*i != *(i + 1)) {
				i++;
			}
			repeatNum = 1;
			iplace = i;
			while (*(++iplace) == *(iplace + 1))
				repeatNum++;
			for (k = i - a; k <= end; k++)
					a[k] = a[k + repeatNum];
			
		}
		puts(a);
	}
}

//5. ���ַ����е����ڵĶ���ո�ȥ��
void test5() {     //ǰ��Ԫ��
	char a[100];
	char* i, * end;
	int  k;
	while (gets_s(a, sizeof(a)) != EOF) {
		i = a;
		k = 0;
		end = strlen(a);
		while (*i != 0) {
			while (*i != ' ' && *i != 0) {
				i++;
			}
			if (0 == *i)
				break;
			while(' ' == *(i)){
				for (k = i - a; k <= end; k++)
					a[k] = a[k + 1];
			}
		}
		puts(a);
	}
}

//6.�����⣺�������ӷ���ʵ�����ⷶΧ�����������ļӷ�(�����ķ�Χ�� int �͵ı����޷���ʾ,50λ)
void test6() {
	char a[100];
	char b[100];
	while(1){
	printf("Please enter the two big number(Use enter to separate the two number):\n");
	gets_s(a, sizeof(a));
	gets_s(b, sizeof(b));
	int  c[100] = { 0 };
	int la, lb, mab, i, j, mab2;
	int carry = 0; //�Ƿ��λ

	la = strlen(a) - 1;
	lb = strlen(b) - 1;
	mab = la > lb ? la : lb;
	for (i = mab; la >= 0 && lb >= 0; i--, la--, lb--) {
		if (carry == 1) {
			c[i]++;
			carry = 0;
		}
		if (a[la] + b[lb] - '0' + c[i] > '9') {
			carry = 1;
			c[i] = a[la] + b[lb] + c[i] - '9' - 1;
		}
		else {
			c[i] = a[la] + b[lb] + c[i] - '0';
		}

	}
	if (la > lb) {
		for (j = la;j >= 0; j--) {
			if (carry == 1) {
				c[j]++;
				carry = 0;
			}
			c[j] = c[j] + a[j] ;
		}
	}else {
		for (j = lb;j >= 0; j--) {
			if (carry == 1) {
				c[j]++;
				carry = 0;
			}
			if (c[j] + b[j] - '0' > '9') {
				carry = 1;
				c[j] = c[j] + b[j] - '9' - 1;
			}else {
				c[j] = c[j] + b[j];
			}
		}
	}
	printf("The answer is :\n");
	if (carry == 1) {
		printf("1");
	}
	for (int i = 0; i <= mab; i++) {
		printf("%d", c[i] - '0');
	}
	printf("\n");
	}
}