#include <stdio.h>
//1.打印九九乘法表
void multiplication99() {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			printf("%d*%d=%d\t", j, i, i * j);
		}
		printf("\n");
	}
}

//2.打印如下图形：
void printpic1() {
	int i, j;
	for (i = 4; i >= 0; i--) {
		j = i;
		while (j--) 
			printf(" ");
		for(j = 5 - i; j > 0; j--)
			printf("* ");
		printf("\n");
	}
	for (i = 1; i <= 4; i++) {
		j = i;
		while (j--)
			printf(" ");
		for (j = 5 - i; j > 0; j--)
			printf("* ");
		printf("\n");
	}
}

void printpic2() {
	int i, j;
	for (i = 4; i >= 0; i--) {
		j = i;
		while (j--)
			printf(" ");
			printf("*");
		for (j = 2*(4-i) - 1; j > 0; j--)
			printf(" ");
			if(i != 4)
				printf("*");
		printf("\n");
	}
	for (i = 1; i <= 4; i++) {
		j =i;
		while (j--)
			printf(" ");
		printf("*");
		for (j = 2 * (4 - i) - 1; j > 0; j--)
			printf(" ");
		if (i != 4)
			printf("*");
		printf("\n");
	}
}

void printpic3() {
	int i, j;
	for (i = 3; i >= 0; i--) {
		j = i;
		while(j--)
			printf(" ");
		j = 5 - i;
		while (j--)
			printf("* ");
		j = 2*i + 1;
		while (j--)
			printf(" ");
		j = 5 - i;
		while (j--)
			printf("* ");
		printf("\n");
	}
	for (i = 10; i >= 0; i--) {
		j = 10 - i;
		while(j--)
			printf(" ");
		j = i;
		while (j--)
			printf("* ");
		printf("\n");
	}
}

//4.(1）求两个有序数组的公共元素
int max(int a, int b) {
	if (a >= b)
		return a;
	else return b;
}
int* CommonElementsOfTwo(int a[], int b[], int lengtha, int lengthb) {
	int i = 0, j = 0, k = 0;
	int* ab= (int *)malloc(sizeof(int) * (max(lengtha, lengthb)+ 1));
	while (i < lengtha && j < lengthb) {
		if (a[i] == b[j]) {
			ab[k++] = a[i];
			i++;j++;
		}
		else if (a[i] > b[j])
			j++;
		else i++;
	}
		ab[k] = 65535;
		return ab;
	}

//（2）求三个有序数组的公共元素
void CommonElementsOfThree(int a[], int b[], int c[], int lengtha, int lengthb,int lengthc) {
	int* ab = CommonElementsOfTwo(a, b, lengtha, lengthb);
	int* abc = CommonElementsOfTwo(ab, c, lengtha, lengthb);
	printf("三个数组的公共元素为：");
	for(int i = 0; abc[i] != 65535; i++)
		printf("%d " ,abc[i]);
	printf("\n");
	
};

//(3）求n个有序数组的公共元素(n = 5)
//此函数运行时出现错误，多次调整后未能解决
void CommonElementsOfFive(int a[], int b[], int c[], int d[], int e[], int lengtha, int lengthb, int lengthc, int lengthd,int lengthe) {
	int* ab = CommonElementsOfTwo(a, b,  lengtha, lengthb);
	int* cd = CommonElementsOfTwo(c, d,  lengthc, lengthd);
	int* abe = CommonElementsOfTwo(ab, e, lengtha, lengthe);
	int* abcde = CommonElementsOfTwo(abe, cd, lengtha, lengthd);
	return *abcde;
	printf("五个有序数组的公共元素为：/n");
	for(int i = 0; abcde[i] != 65535; i++)
		printf("%d " ,abcde[i]);
	printf("/n");
}

//5.求数组的最大值和次大值
int FirstSecondMax(int a[], int length) {
	int fmax = -65535, smax = -65535;
	int i;
	for (i = 0; i < length; i++) {
		if (a[i] >= fmax)
			fmax = a[i];
		else if(a[i] > smax)
			smax = a[i];
	}
	printf("最大值：%d\n次大值：%d\n", fmax, smax);
}

//6. 给定一个n个整型元素的数组a，其中有一个元素出现次数超过n / 2，求这个元素
int quicksort(int* a, int left, int right) {  //先对数组排序，找有序序列的第n/2个数，即为所求
	if (left > right) return;
	int i = left - 1, j = right + 1, mid, temp;
	while (1) {
		mid = (left + right) / 2;
		while (a[++i] < a[mid]);
		while (a[--j] > a[mid]);
		if (i > j) break;
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	quicksort(a, left, mid - 1);
	quicksort(a, mid + 1, right);
}

int MostElem(int* a, int length) {
	int mid;
	quicksort(a, 0, length - 1);
	mid = a[length / 2 - 1];
	return mid;		
}

//7．给定一个含有n个元素的整型数组，找出数组中的两个元素x和y使得abs(x - y)值最小
int* absxsuby(int* a, int length) {
	int i = 0, j, min = 65535;
	int* b = (int*)malloc(sizeof(int) *2);
	quicksort(a, 0, length - 1);  //利用6题快排函数
	while (i < length - 1) {
		j = a[i] - a[i + 1];
		if (j < 0)
			j = -j;
		if (j < min) {
			min = j;
			b[0] = a[i];
			b[1] = a[i + 1];
		}
		i++;
	}
	return b;
}

//8. 给定含有1001个元素的数组，其中存放了1-1000之内的整数，只有一个整数是重复的，请找出这个数
//A1 + … + A1001 –(1 + … + 1000) 
int repeatedint(int n[]) {
	int i, a[1000];
	for (i = 0; i < 1000; i++) a[i] = 0;
	for (i = 0; i < 1001; i++) {
		a[n[i]]++;
		if (a[n[i]] == 2)
			break;
	}
	return n[i];   //重复的数 == A1 + … + A1001 –(1 + … + 1000)
}

int main() { //检验以上函数
	printf("1.打印九九乘法表\n");//1
	multiplication99();
	printf("\n2.打印如下图形：\n(1)\n");//2
	printpic1();printf("\n(2)\n");
	printpic2();printf("\n(3)\n");
	printpic3();printf("\n");
	//4
	printf("4.（1）对于数组a {1,2,3,4,7,8,9} 数组b { 2,4,6,8,9 }  数组c { 1,2,4,6,7,8 }\na, b的公共元素为：");
	int a[] = { 1,2,3,4,7,8,9 };
	int b[] = { 2,4,6,8,9 };
	int c[] = { 1,2,4,6,7,8 };
	int* ab = CommonElementsOfTwo(a, b, 7, 5);
	for (int i = 0; ab[i] != 65535; i++)
		printf("%d ", ab[i]);printf("\n");
	CommonElementsOfThree(a, b, c, 7, 5, 6);

	printf("对于数组{ 4, 7, 4, 9, 4, 2, 4, 8, 4, 4, 5, 4, 7, 4 }\n");
	int n[] = { 4, 7, 4, 9, 4, 2, 4, 8, 4, 4, 5, 4, 7, 4 };
	printf("5.");
	FirstSecondMax(n, 14);//5
	printf("6.出现次数超过n / 2的数字为：");
	printf("%d", MostElem(n, 14)); //6
	printf("\n7.使|x-y|最小的x, y值为：\n");
	int *xy;
	xy = absxsuby(n, 14); //7
	printf("x = %d, y = %d", xy[0], xy[1]);
	
	return 0;
}
