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

//1.将包含字符数字的字符串分开,使得分开后的字符串前一部分是数字后一部分是字母。（O(1)）
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

//2.将字符串中的空格替换成“%020” ，空间复杂度要求O(1)。
void test2() {
	char a[100];
	char b[100] = {0};
	char *c = "%020";
	char* i, * j, *end;
	int  bi, spacenums, k;
	for (int i = 0; i < 24; i++) {  //将b用%020填满
		strcat(b, c);
	}
	while (gets_s(a, sizeof(a)) != EOF) {
		i = j = a;
		end = a + strlen(a);
		while (*i != 0) {
			spacenums = 0;
			while (*i != ' ') {               //找到每个空格段起始位置
				i++;
			}
			j = i;
			while (*i == ' ') {               //统计空格
				i++;
				spacenums++;
			}
			for(k = end - a; k >= j - a;k--){ //将该空格段后的字符后移 空格数*3
				a[k + 3 * spacenums] = a[k];
			}
			end += 3 * spacenums;
			i += 3 * spacenums;
			for (bi = 0; j < i;) {            //填入%020
				*j= b[bi];
				j++, bi++;
			}
		}
		puts(a);
	}
}

//3.删除字符串中指定的字符。例如 “abcdaefaghiagkl“ 删除‘a’,以后： “bcdefghigkl”
void test3() {     //前移元素
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

//4.删除一个数组中重复的元素。例如 1 ,2, 2,2,3,3,3,4,4,5,5,5,6,6,6 -> 1,2,3,4,5,6
void test4() {     //前移元素
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

//5. 将字符串中的相邻的多余空格去掉
void test5() {     //前移元素
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

//6.附加题：大整数加法。实现任意范围的两个整数的加法(整数的范围用 int 型的变量无法表示,50位)
void test6() {
	char a[100];
	char b[100];
	while(1){
	printf("Please enter the two big number(Use enter to separate the two number):\n");
	gets_s(a, sizeof(a));
	gets_s(b, sizeof(b));
	int  c[100] = { 0 };
	int la, lb, mab, i, j, mab2;
	int carry = 0; //是否进位

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