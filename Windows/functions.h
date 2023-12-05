#include <time.h>
#include "character.h"
#include <unistd.h>
#define VERSION 3.0
void intinit(int*p, int length)
{
	for (int i = 0; i <= length - 1; i++)
	{
		p[i] = 0;
	}
}
void zselect(int *zselected, int *use, int *ban)
{
	time_t t;
	int upsizeu = 0, upsizeb = 0;
	for (int i = 0; i <= 15; i++)
	{
		if (use[i] <= 0)
		{
			upsizeu = i;
			break;
		}
	}
	for (int i = 0; i <= 999; i++)
	{
		if (ban[i] <= 0)
		{
			upsizeb = i;
			break;
		}
	}
	srand((unsigned)time(&t));
	for (int i = 0; i < upsizeu; i++)
	{
		zselected[i] = use[i];
	}
	for (int i = upsizeu; i <= 15; i++)
	{
		zselected[i] = rand() % 60 + 1;
		for (int j = 0; j < i; j++)
		{
			if (zselected[i] == zselected[j])
			{
				zselected[i] = 0;
				i--;
			}
		}
		for (int j = 0; j < upsizeb; j++)
		{
			if (zselected[i] == ban[j])
			{
				i--;
			}
		}
	}
}
void autoprint(int *zselected)
{
	for (int i = 0; i <= 15; i++)
	{
		int2zhprint(zselected[i]);
		if ((i + 1) % 4 == 0)
		{
			printf("\n");
		}
	}
}
void inputcvt(int *zselected, int *function, int functionloc)
{
	fflush(stdin);
	char input[7];
	scanf("%s", input);
	if (input[0] <= '9' && input[0] >= '1')
	{
		if (strlen(input) == 1)
		{
			if (zselected[input[0] - 49] != 0)
			{
				function[functionloc] = zselected[input[0] - 49];
				zselected[input[0] - 49] = 0;
				return;
			}
		}
		else if (zselected[10 * (input[0] - 48) + input[1] - 49] != 0)
		{
			function[functionloc] = zselected[10 * (input[0] - 48) + input[1] - 49];
			zselected[10 * (input[0] - 48) + input[1] - 49] = 0;
			return;
		}
	}
	else
	{
		for (int i = 0; i <= 15; i++)
		{
			if (zselected[i] == zhstr2int(input) && zselected[i] != 0)
			{
				zselected[i] = 0;
				function[functionloc] = zhstr2int(input);
				return;
			}
		}
	}
	printf("\n输入的角色不存在或已被禁用，请重新输入 ->");
	fflush(stdin);
	inputcvt(zselected, function, functionloc);
}
void outputcvt(int* banned, int usa, int usb, int usc, int usd, int *first, int firlen, int *second, int seclen)
{
	printf("\n先手已经禁用：");
	if (usa != 0)
	{
		int2zhprint(banned[0]);
	}
	if (usb != 0)
	{
		int2zhprint(banned[1]);
	}
	printf("\n后手已经禁用：");
	if (usc != 0)
	{
		int2zhprint(banned[2]);
	}
	if (usd != 0)
	{
		int2zhprint(banned[3]);
	}
	printf("\n先手已经选择：");
	for (int i = 0; i < firlen; i++)
	{
		int2zhprint(first[i]);
	}
	printf("\n后手已经选择：");
	for (int i = 0; i < seclen; i++)
	{
		int2zhprint(second[i]);
	}
	printf("\n");
}
void ask(int *zselected, int *banned, int *first, int *second, int step)
{
	system("cls");
	printf("Genshin TCG draft pick for Windows v%0.1f by hpszsp\n当前可用的角色池如下:\n\n", VERSION);
	autoprint(zselected);
	if (step == 1)
	{
		intinit(banned, 4);
		intinit(first, 5);
		intinit(second, 5);
		outputcvt(banned, 0, 0, 0, 0, first, 0, second, 0);
		printf("\n请先手禁用一个角色-> ");
		inputcvt(zselected, banned, 0);
	}
	if (step == 2)
	{
		outputcvt(banned, 1, 0, 0, 0, first, 0, second, 0);
		printf("\n请后手禁用一个角色-> ");
		inputcvt(zselected, banned, 2);
	}
	if (step == 3)
	{
		outputcvt(banned, 1, 0, 1, 0, first, 0, second, 0);
		printf("\n请先手选择一个角色-> ");
		inputcvt(zselected, first, 0);
	}
	if (step == 4)
	{
		outputcvt(banned, 1, 0, 1, 0, first, 1, second, 0);
		printf("\n请后手选择一个角色-> ");
		inputcvt(zselected, second, 0);
	}
	if (step == 5)
	{
		outputcvt(banned, 1, 0, 1, 0, first, 1, second, 1);
		printf("\n请后手选择一个角色-> ");
		inputcvt(zselected, second, 1);
	}
	if (step == 6)
	{
		outputcvt(banned, 1, 0, 1, 0, first, 1, second, 2);
		printf("\n请先手选择一个角色-> ");
		inputcvt(zselected, first, 1);
	}
	if (step == 7)
	{
		outputcvt(banned, 1, 0, 1, 0, first, 2, second, 2);
		printf("\n请先手选择一个角色-> ");
		inputcvt(zselected, first, 2);
	}
	if (step == 8)
	{
		outputcvt(banned, 1, 0, 1, 0, first, 3, second, 2);
		printf("\n请后手选择一个角色-> ");
		inputcvt(zselected, second, 2);
	}
	if (step == 9)
	{
		outputcvt(banned, 1, 0, 1, 0, first, 3, second, 3);
		printf("\n请后手禁用一个角色-> ");
		inputcvt(zselected, banned, 3);
	}
	if (step == 10)
	{
		outputcvt(banned, 1, 0, 1, 1, first, 3, second, 3);
		printf("\n请先手禁用一个角色-> ");
		inputcvt(zselected, banned, 1);
	}
	if (step == 11)
	{
		outputcvt(banned, 1, 1, 1, 1, first, 3, second, 3);
		printf("\n请先手选择一个角色-> ");
		inputcvt(zselected, first, 3);
	}
	if (step == 12)
	{
		outputcvt(banned, 1, 1, 1, 1, first, 4, second, 3);
		printf("\n请后手选择一个角色-> ");
		inputcvt(zselected, second, 3);
	}
	if (step == 13)
	{
		outputcvt(banned, 1, 1, 1, 1, first, 4, second, 4);
		printf("\n请后手选择一个角色-> ");
		inputcvt(zselected, second, 4);
	}
	if (step == 14)
	{
		outputcvt(banned, 1, 1, 1, 1, first, 4, second, 5);
		printf("\n请先手选择一个角色-> ");
		inputcvt(zselected, first, 4);
	}
	if (step == 15)
	{
		outputcvt(banned, 1, 1, 1, 1, first, 5, second, 5);
		printf("\n已经完成了对卡池的生成! ");
	}
	return;
}
void iniread(int *u, int *b)
{
	intinit(u, 16);
	intinit(b, 1000);
	char useini[600], banini[600], tmp[10] = "";
	if (!access("./use.ini", 0))
	{
		FILE *fu = fopen("./use.ini", "r+w+");
		fgets(useini, 600, fu);
		for (int i = 0; i <= 599; i++)
		{
			if (useini[i] == 10 || useini[i] == 13)
			{
				useini[i] = 0;
			}
		}
		for (int i = 4; useini[i] != 0 || useini[i + 1] != 0 || useini[i + 2] != 0; i = i + 6)
		{
			for (int j = 0; j <= 4; j++)
			{
				tmp[j] = useini[i + j];
			}
			u[(i - 4) / 6] = enstr2int(tmp);
		}
		fclose(fu);
	}
	if (!access("./ban.ini", 0))
	{
		FILE *fb = fopen("./ban.ini", "r+w+");
		fgets(banini, 600, fb);
		for (int i = 0; i <= 599; i++)
		{
			if (banini[i] == 10 || banini[i] == 13)
			{
				banini[i] = 0;
			}
		}
		for (int i = 4; banini[i] != 0 || banini[i + 1] != 0 || banini[i + 2] != 0; i = i + 6)
		{
			for (int j = 0; j <= 4; j++)
			{
				tmp[j] = banini[i + j];
			}
			b[(i - 4) / 6] = enstr2int(tmp);
		}
		fclose(fb);
	}

}
