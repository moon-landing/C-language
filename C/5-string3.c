#include<stdio.h>
#include<string.h>
void big(char*, int, char**, char**);
int route(int, int);

int main() {
	//char *c[5] = { "lining","anta","nike","addias","qiaodan" };
	//char* big1 = c[0], * big2 = c[0];
	//big(c, 5, &big1, &big2);
	//puts(big1);
	//puts(big2);

	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d", route(m, n));
}

//1.求一个字符串数组的最大值和次大值  void big(char *arr[],int size ,char** big1,char** big2)
void big(char* arr[], int size, char** big1, char** big2){
	int i, j;
	int fbig, sbig;
	if (strcmp(arr[0], arr[1])) {
		fbig = 0;
		sbig = 1;
	}else {
		fbig = 1; 
		sbig = 0;
	}
	for (i = 2; i < size; i++) {
		if (strcmp(arr[i], arr[sbig]) == 1) {
			if (strcmp(arr[i], arr[fbig]) == 1) {
				sbig = fbig;
				fbig = i;
			}else {
				sbig = i;
			}
		}
	}
	*big1 = arr[fbig];
	*big2 = arr[sbig];
}

//2.从（0,0）到（m,n),每次走一步，只能向上或者向右走，有多少种路径走到(m,n)
int route(int m, int n) {
	if (m < 0 || n < 0)        //递归出口1，此时直接跳出
		return 0;
	else if (m == 0 || n == 0) //递归出口2，此时只有一种路线
		return 1;
	else                       //不满足出口，则递归执行
		return (route(m, n - 1) + route(m - 1, n));
}
