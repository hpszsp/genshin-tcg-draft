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
		printf("\nuse.ini�涨�˱�����ֵĽ�ɫ\nban.ini�涨�˲��ܳ��ֵĽ�ɫ\nע�⣺use.ini�����ȼ�����ban.ini\n����ʹ��ָ����Ӣ����\n");
		printf("\nuse.iniʾ��: USE=Chuns Feixr Taozh\n��涨�˴�ˮ����л������ծ��һ��������ڿ�ѡ����\n");
		printf("\nban.iniʾ��: BAN=Chuns Feixr Taozh\n��涨�˴�ˮ����л������ծ��һ����������ڿ�ѡ����\n\n");
		printf("����pea�鿴��Ӣ�Ķ��ձ�\n����vi���㿪ʼ�༭��������������ļ������ʹ�ã�\n����read�Ķ����е������ļ�\n\n");
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
		printf("\nǿ�����õĽ�ɫ��: ");
		for (int i = 4; useini[i] != 0 || useini[i + 1] != 0 || useini[i + 2] != 0; i = i + 6)
		{
			for (int j = 0; j <= 4; j++)
			{
				tmp[j] = useini[i + j];
			}
			int2zhprint(enstr2int(tmp));
			printf(" ");
		}
		printf("\nǿ�ƽ��õĽ�ɫ��: ");
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
	printf("Genshin TCG draft pick for Windows v%0.1f by hpszsp\n����help�鿴����\n\n", VERSION);
	while (going)
	{
		cmdread(fu, fb);
	}
}
