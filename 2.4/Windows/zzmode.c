#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <io.h>
#include "zfile.h"
#include "namels.h"

float VERSION = 2.4;
int IFGEN = 0;

void reask(int charMany, char *output, char *character);
void gen(int selectMany, char *output, char *character, int *selected);
void nextgen1(int selectMany, char *output, char *character, int *std1);
void nextgen2(int selectMany, char *output, char *character, int *std2);

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		formatName(argv[1]);
		return 0;
	}
	printf("zzmode for Windows v%0.1f by hpszsp\n", VERSION);
	if (access("./character.cfg", 0))
	{
		formatName("defconfig");
		printf("没有检测到配置文件，已经按照默认配置自动生成\n\n");
		IFGEN = 1;
	}
	else
	{
		printf("检测到配置文件，正在读取中\n\n");
	}
	for (int i = 0; i < 30; i++)
	{
		printf("●");
		Sleep(10);
	}
	system("cls");
	char character[1023];
	char output[1023];
	int selected[16], ban;
	int charMany = -1;
	int std1[16], std2[16];
	for (int i = 0; i <= 15; i++)
	{
		std1[i] = 0;
		std2[i] = 0;
	}
	time_t t;
	readcharacter(character);
	if (!(character[0] == '0' && character[1] == '0' && character[2] == '0' && character[3] == '0' && character[4] == '0' && character[5] == ' '))
	{
		system("color 1F");
		printf("警告：character.cfg不是以00000开头，这可能导致你的部分角色不被读取，或者出现乱码\n");
		Sleep(3000);
		system("color 07");
		system("cls");
	}
	const int selectMany = 15;
	for (int i = 0;; i = i + 6)
	{
		if (character[i] == 'a' && character[i + 1] == 'a' && character[i + 2] == 'a' && character[i + 3] == 'a' && character[i + 4] == 'a')
		{
			break;
		}
		charMany++;
		if (i >= 2000)
		{
			system("color 4F");
			printf("遇到了错误，可能是输入的角色数多于300个，也可能是character.cfg中间有回车或者不是以aaaaa结尾\n");
			Sleep(3000);
			return 0;
		}
	}
	srand((unsigned) time(&t));
	for (int i = 0; i <= selectMany; i++)
	{
		selected[i] = rand() % charMany + 1;
		for (int j = 0; j < i; j++)
		{
			if (selected[j] == selected[i])
			{
				i--;
			}
		}
	}
	//接下来是漫长的角色生成和禁用过程
	gen(selectMany, output, character, selected);
	printf("\n已经为您随机生成16个角色\n从左到右，从上到下是1到16号");
	printf("\n\n请先手禁用一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	printf("\n\n请后手禁用一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	printf("\n\n请先手选择一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	std1[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	printf("\n\n请后手选择一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	std2[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n请后手选择一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	std2[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n请先手选择一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	std1[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n请先手选择一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	std1[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n请后手选择一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	std2[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n请后手禁用一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n请先手禁用一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n请先手选择一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	std1[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n请后手选择一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	std2[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n请后手选择一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	std2[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n请先手选择一个角色，输入其号码 -> ");
	scanf("%d", &ban);
	std1[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	//以上是漫长的角色生成和禁用过程
	printf("\n\n全部完成！\n输入y删除配置文件，输入r重新生成，输入h查看帮助\n\n");
	reask(charMany, output, character);
	return 0;
}

void nextgen1(int selectMany, char *output, char *character, int *std1)
{
	printf("\n先手已经选择：");
	for (int i = 0; i <= selectMany; i++)
	{
		if (std1[i] != 0)
		{
			for (int j = 0; j <= 4; j++)
			{
				output[j] = character[6 * std1[i] + j];
			}
			for (int j = 5; j <= 1023; j++)
			{
				output[j] = 0;
			}
			zhprintf(output);
		}
	}
}
void nextgen2(int selectMany, char *output, char *character, int *std2)
{
	printf("\n后手已经选择：");
	for (int i = 0; i <= selectMany; i++)
	{
		if (std2[i] != 0)
		{
			for (int j = 0; j <= 4; j++)
			{
				output[j] = character[6 * std2[i] + j];
			}
			for (int j = 5; j <= 1023; j++)
			{
				output[j] = 0;
			}
			zhprintf(output);
		}
	}
}

void gen(int selectMany, char *output, char *character, int *selected)
{
	printf("zzmode for Windows v%0.1f by hpszsp\n", VERSION);
	printf("您当前可用的角色池如下：\n\n");
	for (int i = 0; i <= selectMany; i++)
	{
		if (selected[i] == 0)
		{
			zhprintf("NNNNN");
		}
		else
		{
			for (int j = 0; j <= 4; j++)
			{
				output[j] = character[6 * selected[i] + j];
			}
			for (int j = 5; j <= 1023; j++)
			{
				output[j] = 0;
			}
			zhprintf(output);
		}

		if ((i + 1) % 4 == 0 && i != 0)
		{
			printf("\n");
		}
	}
}

void reask(int charMany, char *output, char *character)
{
	fflush(stdin);
	char a = 0;
	printf("-> ");
	scanf("%c", &a);
	if (a == 'y')
	{
		system("del character.cfg");
		printf("注意：对配置文件的调整在下次启动时才会生效\n");
		reask(charMany, output, character);
	}
	else if (a == 'r')
	{
		system("cls");
		system("zzmode.exe");
		return;
	}
	else if (a == 'h')
	{
		printf("\ncharacter.cfg是一个以00000开头，aaaaa结尾的文本文件，它包含了所有程序认为可用的角色。\n");
		printf("这些角色的名称必须是由五个英文字母组成，中间用一个空格分开。\n");
		printf("如果不按照上述方式编写character.cfg，程序将遇到错误。\n\n");
		printf("命令行参数：defconfig生成默认配置，delconfig删除配置\n\n");
		if (IFGEN)
		{
			printf("附录：角色中英文对照表");
			see(charMany, output, character);
			printf("\n\n");
		}
		reask(charMany, output, character);
	}
	else
	{
		reask(charMany,  output, character);
	}
}
