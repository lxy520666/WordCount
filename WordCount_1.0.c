#include <stdio.h>
#include <stdlib.h>
#include<String.h>
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
int main(int argc, char* argv[])
{
	
	if (argc != 3)//检查参数个数是否正确
	{
		printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]);
		exit(1);
	}

	
	FILE* fp = fopen(argv[2], "r");//打开输入文件
	if (fp == NULL)
	{
		printf("Cannot open file %s\n", argv[2]);
		exit(2);
	}

	//根据参数选择统计模式
	if (strcmp(argv[1], "-c") == 0) //统计字符数
	{
		int count = 0; //记录字符数
		int ch; //存储读取的字符
		while ((ch = getc(fp)) != EOF) //循环读取文件中的每个字符，直到到达文件末尾
		{
			count++; //每读取一个字符，就增加一次计数
		}
		printf("Character count: %d\n", count); //输出结果
	}

	else if (strcmp(argv[1], "-w") == 0) //统计单词数
	{
		int count = 0; //记录单词数
		char word[100]; //存储读取的单词
		while (fscanf(fp, "%s", word) != EOF) //循环读取文件中的每个单词，直到到达文件末尾
		{
			count++; //每读取一个单词，就增加一次计数
		}
		printf("Word count: %d\n", count); //输出结果
	}
	else //无效的参数
	{
		printf("Invalid parameter: %s\n", argv[1]);
		exit(3);
	}

	//关闭输入文件
	fclose(fp);

	return 0;
}