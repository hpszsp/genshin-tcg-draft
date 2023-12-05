#include "character.h"
#define VERSION 3.0
#define characterMuch 61

int going = 1;
void cmdread(FILE* fu, FILE* fb)
{
	char cmdin[20] = "";
	printf("draft-ini -> ");
	scanf("%s", cmdin);
	if (!strcmp(cmdin, "help"))
	{
		printf("\nuse.ini规定了必须出现的角色\nban.ini规定了不能出现的角色\n注意：use.ini的优先级高于ban.ini\n必须使用指定的英文名\n");
		printf("\nuse.ini示例: USE=Chuns Feixr Taozh\n这规定了纯水，菲谢尔，讨债人一定会出现在可选池中\n");
		printf("\nban.ini示例: BAN=Chuns Feixr Taozh\n这规定了纯水，菲谢尔，讨债人一定不会出现在可选池中\n\n");
		printf("输入pea查看中英文对照表\n输入vi从零开始编辑（如果已有配置文件请谨慎使用）\n输入read阅读已有的配置文件\n\n");
		cmdread(fu, fb);
	}
	if (!strcmp(cmdin, "pea"))
	{
		printf("\n");
		for (int i = 1; i <= characterMuch - 1; i++)
		{
			int2enprint(i);
			printf(":");
			int2zhprint(i);
			if (i % 6 == 0 || i == characterMuch - 1)
			{
				printf("\n");
			}
		}
		printf("\n");
		cmdread(fu, fb);
	}
	if (!strcmp(cmdin, "vi"))
	{
		fclose(fu);
		fclose(fb);
		system("echo USE=> ./use.ini");
		system("notepad.exe use.ini");
		system("echo BAN=> ./ban.ini");
		system("notepad.exe ban.ini");
		fu = fopen("./use.ini", "r+w+");
		fb = fopen("./ban.ini", "r+w+");
		cmdread(fu, fb);
	}
	if (!strcmp(cmdin, "read"))
	{
		char useini[600];
		char banini[600];
		char tmp[10] = "";
		fgets(useini, 600, fu);
		fgets(banini, 600, fb);
		for (int i = 0; i <= 599; i++)
		{
			if (useini[i] == 13 || useini[i] == 10)
			{
				useini[i] = 0;
			}
			if (banini[i] == 13 || banini[i] == 10)
			{
				banini[i] = 0;
			}
		}
		printf("\n强制启用的角色有: ");
		for (int i = 4; useini[i] != 0 || useini[i + 1] != 0 || useini[i + 2] != 0; i = i + 6)
		{
			for (int j = 0; j <= 4; j++)
			{
				tmp[j] = useini[i + j];
			}
			int2zhprint(enstr2int(tmp));
			printf(" ");
		}
		printf("\n强制禁用的角色有: ");
		for (int i = 4; banini[i] != 0 || banini[i + 1] != 0 || banini[i + 2] != 0; i = i + 6)
		{
			for (int j = 0; j <= 4; j++)
			{
				tmp[j] = banini[i + j];
			}
			int2zhprint(enstr2int(tmp));
			printf(" ");
		}
		printf("\n\n");
		fclose(fu);
		fclose(fb);
		fu = fopen("./use.ini", "r+w+");
		fb = fopen("./ban.ini", "r+w+");
		cmdread(fu, fb);
	}
}

int main()
{
	initcharacter();
	FILE *fu = fopen("./use.ini", "r+w+");
	FILE *fb = fopen("./ban.ini", "r+w+");
	printf("Genshin TCG draft pick for Windows v%0.1f by hpszsp\n输入help查看帮助\n\n", VERSION);
	while (going)
	{
		cmdread(fu, fb);
	}
}
