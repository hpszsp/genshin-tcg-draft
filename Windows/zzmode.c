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
		printf("û�м�⵽�����ļ����Ѿ�����Ĭ�������Զ�����\n\n");
		IFGEN = 1;
	}
	else
	{
		printf("��⵽�����ļ������ڶ�ȡ��\n\n");
	}
	for (int i = 0; i < 30; i++)
	{
		printf("��");
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
		printf("���棺character.cfg������00000��ͷ������ܵ�����Ĳ��ֽ�ɫ������ȡ�����߳�������\n");
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
			printf("�����˴��󣬿���������Ľ�ɫ������300����Ҳ������character.cfg�м��лس����߲�����aaaaa��β\n");
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
	//�������������Ľ�ɫ���ɺͽ��ù���
	gen(selectMany, output, character, selected);
	printf("\n�Ѿ�Ϊ���������16����ɫ\n�����ң����ϵ�����1��16��");
	printf("\n\n�����ֽ���һ����ɫ����������� -> ");
	scanf("%d", &ban);
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	printf("\n\n����ֽ���һ����ɫ����������� -> ");
	scanf("%d", &ban);
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	printf("\n\n������ѡ��һ����ɫ����������� -> ");
	scanf("%d", &ban);
	std1[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	printf("\n\n�����ѡ��һ����ɫ����������� -> ");
	scanf("%d", &ban);
	std2[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n�����ѡ��һ����ɫ����������� -> ");
	scanf("%d", &ban);
	std2[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n������ѡ��һ����ɫ����������� -> ");
	scanf("%d", &ban);
	std1[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n������ѡ��һ����ɫ����������� -> ");
	scanf("%d", &ban);
	std1[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n�����ѡ��һ����ɫ����������� -> ");
	scanf("%d", &ban);
	std2[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n����ֽ���һ����ɫ����������� -> ");
	scanf("%d", &ban);
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n�����ֽ���һ����ɫ����������� -> ");
	scanf("%d", &ban);
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n������ѡ��һ����ɫ����������� -> ");
	scanf("%d", &ban);
	std1[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n�����ѡ��һ����ɫ����������� -> ");
	scanf("%d", &ban);
	std2[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n�����ѡ��һ����ɫ����������� -> ");
	scanf("%d", &ban);
	std2[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	printf("\n\n������ѡ��һ����ɫ����������� -> ");
	scanf("%d", &ban);
	std1[ban - 1] = selected[ban - 1];
	selected[ban - 1] = 0;
	system("cls");
	gen(selectMany, output, character, selected);
	nextgen1(selectMany, output, character, std1);
	nextgen2(selectMany, output, character, std2);
	//�����������Ľ�ɫ���ɺͽ��ù���
	printf("\n\nȫ����ɣ�\n����yɾ�������ļ�������r�������ɣ�����h�鿴����\n\n");
	reask(charMany, output, character);
	return 0;
}

void nextgen1(int selectMany, char *output, char *character, int *std1)
{
	printf("\n�����Ѿ�ѡ��");
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
	printf("\n�����Ѿ�ѡ��");
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
	printf("����ǰ���õĽ�ɫ�����£�\n\n");
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
		printf("ע�⣺�������ļ��ĵ������´�����ʱ�Ż���Ч\n");
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
		printf("\ncharacter.cfg��һ����00000��ͷ��aaaaa��β���ı��ļ��������������г�����Ϊ���õĽ�ɫ��\n");
		printf("��Щ��ɫ�����Ʊ����������Ӣ����ĸ��ɣ��м���һ���ո�ֿ���\n");
		printf("���������������ʽ��дcharacter.cfg��������������\n\n");
		printf("�����в�����defconfig����Ĭ�����ã�delconfigɾ������\n\n");
		if (IFGEN)
		{
			printf("��¼����ɫ��Ӣ�Ķ��ձ�");
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
