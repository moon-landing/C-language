#include <stdio.h>
#define N 11

void test1();             //1
int* test2_1();           //2(1)
						  //2(2)没做
void test3_1();           //3(1)
void test3_2();           //3(2)
void test3_3();           //3(3)
void test3_4();           //3(4)
void test4();             //4
void test5_1(int[], int); //5(1)
void test5_2(int[], int); //5(2)
void findThreeNum(int[]); //5(3)
void findThreeNum(int a[]);// 5(3)
void test6_1();           //6(1)
void test6_2();           //6(2)
void test6_3();           //6(3)
void test6_4();           //6(4)
void test6_5();           //6(5)
int weekForDate(int, int, int);


int ten(int);
int convertDECtoBIN(int);
int DateOfYear(int, int, int);
int runnian(int);

int main() {
	//test1();                                        
	//int* nums;
	//nums = test2_1();
	//for (int i = 0; i < 3; i++)
	//	printf("%d", nums[i]);                         
	//test3_1();                                        
	//test3_2();                                       
	//test3_3();                                        
	//test3_4();                                      
	//test4();
	//int a[11] = { 1, 2, 3, 4, 2, 3, 1, 6, 4, 8, 6 };   
	//test5_1(a, 11); 
	//int b[12] = { 1, 2, 3, 4, 2, 3, 1, 6, 4, 8, 6, 7 }; 
	//test5_2(b, 12);
	//int c[13] = { 1, 2, 3, 4, 2, 3, 1, 6, 4, 8, 6, 7, 9};
	//test5_2(c, 13);
	int a[N] = { 20,9,7,11,9,13,20,11,4, 4, 26 };
	findThreeNum(a);  //5(3)
    //test6_1();
	//test6_2();
	//test6_3();
	//test6_4();
	test6_5();
}


//1.从键盘上输入字符，将小写字母转换成大写字母。输入“ctl + z” 结束 。	
void test1(){
	char c;
	printf("Please enter the lowercase:");
	while (scanf("%c", &c) !=EOF) {  
		if (c == '\n') {
			printf("\n");
		}else if (c >= 97 && c <= 122) {
			printf("%c", c - 32);
		}	
	}
}

//2.从键盘上输入字符，
//（1）分别统计一下其中字母，数字，其他字符的个数
//（2）将统计的字母，数字，其他字符的个数以柱状图的形式打印

int* test2_1() {
	char c;
	int* nums = (int*)malloc(sizeof(int) * 3);
	for (int i = 0; i < 3; i++)
		nums[i] = 0;
	printf("Please enter the characters:");
	while (scanf("%c", &c) != EOF) {
		if (c >= 49 && c <= 57) {   // 字母81-106 97-122 //数字49-57
			nums[0]++;
		}else if ((c >= 81 && c <= 106) || (c >= 97 && c <= 122)){
			nums[1]++;
		}else if(c != '\n'){
			nums[2]++;
		}
	}
	return nums;
}

//3.进制转换。
//（1）将十进制数转换成二进制数。输入十进制数输出对应的二进制数，输入“ctl + z”结束。
void test3_1() {
	int d, b;
	while (scanf("%d", &d) != EOF) {
		b = convertDECtoBIN(d);
		printf("The Binary number of Decimal number(%d) is : %d", d, b);
	}
}

int convertDECtoBIN(int d) {
	int i = 1, j, b = 0,negative = 0;
	if (d < 0) {
		d = -d;
		negative = 1;
	}

	while(d != 0) {
		j = d % 2;
		if (j == 1) {
			b += ten(i);
		}
		d = d / 2;
		i++;
	}
	if (negative == 1)
		b = -b;
	return b;
}

int ten(int j) {
	int num = 1;
	while (--j) {
		num *= 10;
	}
	return num;
}

//（2）将二进制转换成十进制数。输入二进制数输出对应的十进制数，输入“ctl + z”结束。
void test3_2(){
	int b, d = 0;
	while (scanf("%d", &b) != EOF) {
		int i = 0, j, num = 0;
		while (b != 0) {
			num = b % 2;
			for (j = i; j > 0; j--) {
				num *= 2;
			}
			d += num;
			b = b / 10;
			i++;
		}
		printf("The Decimal number of Binary number(%d) is : %d", b, d);
	}
}

//（3）将十进制数转换成十六进制数。输入十进制数输出对应的十六进制数。输入“ctl + z” 结束。
void test3_3() {
	int d;
	while (scanf("%d", &d) != EOF) {
		int i = 0, j, num = d; 
		int h[20];
		for (i = 0; num > 0; num /= 16, i++) {
			j = num % 16;
			if (j < 10) {
				h[i] = 48 + j;
			}else {
				h[i] = 65 + j - 10;
			}
		}
		printf("The Decimal number of Binary number(%d) is : ", d);
		for (i--; i >=0; i--) {
			printf("%c", h[i]);
		}
	}

}

//（4）将十六进制数转换成十进制数。输入十六进制数输出对应的十进制数。输入“ctl +  z” 结束。
void test3_4() {
	int h, d = 0;
	while (scanf("%x", &h) != EOF) {
		int i = 0, j, num = 0;
		while (h != 0) {
			num = h % 16;
			for (j = i; j > 0; j--) {
				num *= 16;
			}
			d += num;
			h = h / 16;
			i++;
		}
		printf("The Decimal number of Binary number(%d) is : %d", h, d);
	}
}

//4.统计一个整数对应的二进制数的1的个数。输入一个整数（可正可负）， 输出该整数的二进制包含1的个数， “ctl+ z” 结束。
void test4() {
	int d, b;
	while (scanf("%d", &d) != EOF) {
		int i = 0, j = 0, num = 0;
		b = convertDECtoBIN(d);
		if (b < 0){
			num = -b;
		}else {
			num = b;
		}
		for (; num> 0; num /= 10) {
			i = num % 2;
			if (i == 1)
				j++;
		}
		printf("the \"1\" numbers of the binary number %d is:%d\n", b, j);
	}
}

//5.（1）.有101个整数，其中有50个数出现了两次，1个数出现了一次， 找出出现了一次的那个数。
void test5_1(int a[], int length) {
	int i, num = 0;
	for (i = 0; i < length; i++) {
		num ^= a[i];	
	}
	printf("The repeated, number is :%d", num);
}

//（2）有102个整数，其中有50个数出现了两次，2个数出现了一次， 找出出现了一次的那2个数。
void test5_2(int a[], int length) {
	int i , j, res = 0, res1 = 0, res2 = 0, splice;
	for (int i = 0; i < length; i++) {
		res ^= a[i];
	}
	splice = res & (-res);
	for (i = 0; i < length; i++) {
		if (a[i] & splice) {
			res1 ^= a[i];
		}else {
			res2 ^= a[i];
		}
	}
	printf("The repeated number is :%d %d", res1, res2);

}

//（3）有103个整数，其中有50个数出现了两次，3个数出现了一次， 找出出现了一次的那3个数。
//#define N 11
void findTwoNum(int a[], int res, int result2) {
	int i, j, splice, secondNum, thirdNum;
	secondNum = thirdNum = 0;
	splice = res & (-res);
	for (i = 0; i < N; i++) {
		if (a[i] & splice) {
			secondNum ^= a[i];
		}
		else {
			thirdNum ^= a[i];
		}
	}
	if (splice & result2)   //secondNum是在a[i] & splice 成立的情况下 若splice & result2 则说明result2在secondNum这组中
		secondNum ^= result2;
	else
		thirdNum ^= result2;
	printf("The second number is :%d \n The third number is :%d", secondNum, thirdNum);
}

void findThreeNum(int a[]) {
	int i, j, split, count1, count2, result1, result2;
	split = 1;
	for (i = 0; i < 32; i++, split = split << 1) {
		count1 = count2 = result1 = result2 = 0;
		for (j = 0; j < N; j++) {
			if (split & a[j]) {
				count1++;
				result1 ^= a[j];
			}
			else {
				count2++;
				result2 ^= a[j];
			}
		}
		if (count1 % 2 == 0 && result1 != 0) {
			printf("The first number is :%d\n", result2);
			findTwoNum(a, result1, result2);
			break;
		}
		if (count2 % 2 == 0 && result2 != 0) {
			printf("The first number is :%d\n", result1);
			findTwoNum(a, result2, result1);
			break;
		}
	}
}

//6.（1）输入年月日，输出该日期是当年的第几天。
void test6_1() {
	int year, mon, day;
	while ((scanf("%d%d%d", &year, &mon, &day) != EOF)) {
		if (day >= 32 || day <= 0) {
			printf("The day you entered is wrong.\n");
			continue;
		}
		printf("%d-%02d-%02d is %dth\n", year, mon, day, DateOfYear(year, mon, day));
	}
}

int DateOfYear(int year, int mon, int day) {
	int total = 0;
	int date12[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < mon - 1; i++) {
		total += date12[i];
	}
	if (mon > 2) {
		total += (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	}
	total += day;
	return total;
}

int runnian(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}

//6.（2）输入两个日期（年 月 日 年 月 日）， 输出这两个日期之间差多少天。
void test6_2() {
	int year1, mon1, day1, year2, mon2, day2, th1, th2, yeari, tday;
	while ((scanf("%d%d%d%d%d%d", &year1, &mon1, &day1, &year2, &mon2, &day2) != EOF)) {
		tday = 0;
		if (day1 >= 32 || day1 <= 0 || day2 >= 32 || day2 <= 0) {
			printf("The day you entered is wrong.\n");
			continue;
		}
		th1 = DateOfYear(year1, mon1, day1);
		th2 = DateOfYear(year2, mon2, day2);
		for (yeari = (year1 < year2 ? year1 : year2); yeari < (year1 > year2 ? year1 : year2); yeari++) {
			tday += 365 + runnian(yeari);
		}
		if (year1 != year2) {
			tday = tday - (year1 < year2 ? th1 : th2) + (year1 > year2 ? th1 : th2);
		}
		else {
			tday = tday - (th1 < th2 ? th1 : th2) + (th1 > th2 ? th1 : th2);
		}
		printf("The number of days between these two dates is： %d.\n", tday);
	}
}

//3）输入一个日期，输出该日期是星期几。
void test6_3() { //AD 0001/01/01 is Monday.
	int year1, mon1, day1, th1, yeari, tday, week;
	int year2 = 1, mon2 = 1, day2 = 1, th2 = 1;
	while ((scanf("%d%d%d", &year1, &mon1, &day1) != EOF)) {
		tday = 0;
		if (day1 >= 32 || day1 <= 0) {
			printf("The day you entered is wrong.\n");
			continue;
		}
		th1 = DateOfYear(year1, mon1, day1);
		for (yeari = (year1 < year2 ? year1 : year2); yeari < (year1 > year2 ? year1 : year2); yeari++) {
			tday += 365 + runnian(yeari);
		}
		if (year1 != year2) {
			tday = tday - (year1 < year2 ? th1 : th2) + (year1 > year2 ? th1 : th2) +1;
		}else {
			tday = tday - (th1 < th2 ? th1 : th2) + (th1 > th2 ? th1 : th2) + 1;
		}
		printf("%d-%d-%d is ", year1, mon1, day1);
		switch (tday % 7){
			case 0: puts("Sunday.");break;
			case 1: puts("Monday.");break;
			case 2: puts("Tuseday.");break;
			case 3: puts("Wednesday.");break;
			case 4: puts("Thursday.");break;
			case 5: puts("Friday.");break;
			case 6: puts("Saturday.");break;
		}
	}
}

//（4）输入 一个日期 和一个整数 n，输出从该日期起经过n天以后的日期。
void test6_4() {
	int year, mon, day, year1, mon1 ,day1,n, n1, yeari, moni, lostDay;
	while ((scanf("%d%d%d%d", &year, &mon, &day, &n) != EOF)) {
		int date12[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (day >= 32 || day <= 0) {
			printf("The day you entered is wrong.\n");
		}else{
			year1 = year, mon1 = mon, day1 = day, n1 = n;
			n1 += DateOfYear(year, mon, day);
			for (yeari = year; n1 > 365 + runnian(yeari); n1 -= (365 + runnian(year)), yeari++);
			year1 = yeari;
			if (runnian(year)) {
				date12[2] = 29;
			}
			for (moni = 1, lostDay = 31; n1 >= lostDay; lostDay += date12[++moni]);
			mon1 = moni;
			for (; moni > 1; moni--) {
				n1 -= date12[moni];
			}
			day1 = n1;
			printf("%d-%d-%d plus %d is %d-%d-%d\n", year, mon, day, n ,year1, mon1, day1);
		}
	}	
}

//（5）输入一个年份,月份，输出该月份的日历。
void test6_5() {
	int year, mon, day, i, j, k, dayf, days, firstDayMonf = 0, firstDayMons = 0, plusdayf, plusdays, blankf, blanks;
	int first, second;
	int date[13] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	printf("Please enter a year:\n");
	scanf("%d", &year);
	if (runnian(year))
		date[2] += 1;
	printf("║==================== The Calender of Year %d ===================║\n", year);
	for (mon = 1; mon <= 6; mon++) {
		first = mon;
		second = 6 + first;
		//if (runnian(year) && i == 2) {
		//	dayi = date[2] + 1;
		//}
		//dayj = date[j];
		firstDayMonf = weekForDate(year, first, 1);
		firstDayMons = weekForDate(year, second, 1);
		plusdayf = plusdays = 1;
		printf("║ %2d  SUN MON TUE WED TUR FRI SAT  %2d  SUN MON TUE WED TUR FRI SAT ║\n", first, second);

		for (int i = 1; i <= 5; i++) {
			printf("║    ");
			if (i == 1){//打印每月空的前几天
				blankf = firstDayMonf;
				for (int k = blankf; k > 0; k--)
					printf("    ");
				for (int k = 7 - blankf; k > 0 && plusdayf <= date[first]; k--, plusdayf++)
					printf("  %02d", plusdayf);
			}
			if (i > 1){
				for (int k = 7; k > 0 && plusdayf <= date[first]; k--, plusdayf++)
					printf("  %02d", plusdayf);
				if (i == 5) {
					for (int i = 35 - date[first] - blankf - 1; i >= 0; i--)
						printf("    ");
				}
			}
			printf("     ");
			if (i == 1) { //打印每月空的前几天
				blanks = firstDayMons;
				for (int k = blanks; k > 0; k--) {
					printf("    ");
				}
				for (int k = 7 - blanks; k > 0 && plusdays <= date[second]; k--, plusdays++) {
					printf("  %02d", plusdays);
				}
			}
			if (i > 1){
				for (int k = 7; k > 0 && plusdays <= date[second]; k--, plusdays++)
					printf("  %02d", plusdays);
				if (i == 5){
					for (int i = 35 - date[second] - blanks - 1; i >= 0; i--)
						printf("    ");
				}
			}
			printf(" ║\n");
		}
		//}
	}
	printf("║==================================================================║\n");
}

int weekForDate(int year1, int mon1, int day1) {
	int  th1, yeari, tday, week;
	int year2 = 1, mon2 = 1, day2 = 1, th2 = 1;
		tday = 0;
		th1 = DateOfYear(year1, mon1, day1);
		for (yeari = (year1 < year2 ? year1 : year2); yeari < (year1 > year2 ? year1 : year2); yeari++) {
			tday += 365 + runnian(yeari);
		}
		if (year1 != year2) {
			tday = tday - (year1 < year2 ? th1 : th2) + (year1 > year2 ? th1 : th2) + 1;
		}
		else {
			tday = tday - (th1 < th2 ? th1 : th2) + (th1 > th2 ? th1 : th2) + 1;
		}
		return (tday % 7);
}

