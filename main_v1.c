#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BINARY_SIZE 32

typedef enum{ FALSE = 0, TRUE } Bool;

/* function interface */
int my_pow(int x, int y);
void binary_print(int data);
int _2to10(char* data);
void my_add(Bool* iswork);
void my_sub(Bool* iswork);
void my_mul(Bool* iswork);
void my_div(Bool* iswork);
void MainLoop();

/* test case */
int main(){
	MainLoop();
	return 0;
}

/* function realize */
void MainLoop(){
	printf("--- 二进制整数运算器 ---\n");
	printf("-----------------------\n");
	Bool IsWork = TRUE;
	char option;
	while (IsWork){
		printf("选择要进行的运算/操作：\n  [1.加法 | 2.减法 | 3.乘法 | 4.除法 | 5.清屏 | 6.退出]\n");
		printf(">>>");
		scanf("%[^\n]%*c", &option);
		switch (option){
		case '1': my_add(&IsWork);
			break;
		case '2': my_sub(&IsWork);
			break;
		case '3': my_mul(&IsWork);
			break;
		case '4': my_div(&IsWork);
			break;
		case '5': system("clear");
			break;
		case '6':
			IsWork = FALSE;
      printf("bye bye!\n");
			break;
		default:
			printf("请在本软件支持范围内选择！\n\n");
      break;
		}
	}
}

void my_add(Bool* iswork){
	char binary_num1[BINARY_SIZE] = { 0 };
	char binary_num2[BINARY_SIZE] = { 0 };
	printf("输入第一个加数：");
	scanf("%[^\n]%*c", binary_num1);
	int num1 = _2to10(binary_num1);
	printf("输入第二个加数：");
	scanf("%[^\n]%*c", binary_num2);
	int num2 = _2to10(binary_num2);

	int result = num1 + num2;

	printf("运算结果为：");
	binary_print(result);
	printf("\n\n");

	*iswork = TRUE;
}

void my_sub(Bool* iswork){
	char binary_num1[BINARY_SIZE] = { 0 };
	char binary_num2[BINARY_SIZE] = { 0 };
	printf("输入被减数：");
	scanf("%[^\n]%*c", binary_num1);
	int num1 = _2to10(binary_num1);
	printf("输入减数：");
	scanf("%[^\n]%*c", binary_num2);
	int num2 = _2to10(binary_num2);

	int result = num1 - num2;
	printf("运算结果为：");
	binary_print(result);
	printf("\n\n");

	*iswork = TRUE;
}
void my_mul(Bool* iswork){
	char binary_num1[BINARY_SIZE] = { 0 };
	char binary_num2[BINARY_SIZE] = { 0 };
	printf("输入第一个因数：");
	scanf("%[^\n]%*c", binary_num1);
	int num1 = _2to10(binary_num1);
	printf("输入第二个因数：");
	scanf("%[^\n]%*c", binary_num2);
	int num2 = _2to10(binary_num2);

	int result = num1 * num2;

	printf("运算结果为：");
	binary_print(result);
	printf("\n\n");

	*iswork = TRUE;

}
void my_div(Bool* iswork){
	char binary_num1[BINARY_SIZE] = { 0 };
	char binary_num2[BINARY_SIZE] = { 0 };
	printf("输入被除数：");
	scanf("%[^\n]%*c", binary_num1);
	int num1 = _2to10(binary_num1);
	printf("输入除数：");
	scanf("%[^\n]%*c", binary_num2);
	int num2 = _2to10(binary_num2);
	if (!num2){ //如果除数为0，则退出运算
		printf("除数有误！！！\n");
		*iswork = FALSE;
		return;
	}

	int result = num1 / num2;
	printf("运算结果为：");
	binary_print(result);
	printf("\n\n");

	*iswork = TRUE;
}

int my_pow(int x, int y){
	int result = 1;
	while (y){
		if (y & 1){
			result *= x;
		}
		y >>= 1;
		x *= x;
	}
	return result;
}

/* core function */
int _2to10(char* data){
	int size = (int)strlen(data) - 1;
	int conversion_result = 0;
	for (int i = size; i >= 0; --i){
		int tmp = data[i] - 48;
		conversion_result += tmp * my_pow(2, size - i);
	}
	return conversion_result;
}

void binary_print(int data){
	char tmp[BINARY_SIZE] = { 0 };
	if (data > 0){
		for (int i = 0; data; ++i){
			if (data % 2 == 0)
				tmp[i] = '0';
			else
				tmp[i] = '1';
			data >>= 1;
		}
		for (int i = strlen(tmp) - 1; i >= 0; --i)
			printf("%c", tmp[i]);
		return;
	}
	else if (data < 0){
		//这里用int用32位表示
		data = -data; //将data变成正数
		data = ~data + 1; //将data变成data的补码
		//用位运算获取data的每一位，赋给数组
		for (int i = 31, j = 0; i >= 0; --i, ++j){
			tmp[j] = ((data >> i) & 1) ? '1' : '0';
		}
		//正序打印数组即可
		for (int i = 0; i < 32; ++i)
			printf("%c", tmp[i]);
		return;
	}
	printf("0");
}
