#include<string.h>
#include<stdio.h>
void zhprintf(char *p);
void see(int charMany, char *output, char *character); 
void zhprintf(char *p)
{
	//printf("%s",p);
	if (!strcmp(p, "NNNNN"))
	{
		printf("=====  ");
		return;
	}
	if (!strcmp(p, "Ganyu"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Diona"))
	{
		printf("�ϰ��� ");
		return;
	}
	if (!strcmp(p, "Kaiya"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Chony"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Lingh"))
	{
		printf("类�   ");
		return;
	}
	if (!strcmp(p, "Youla"))
	{
		printf("��ǉ   ");
		return;
	}
	if (!strcmp(p, "Shenh"))
	{
		printf("���   ");
		return;
	}
	if (!strcmp(p, "Qiqii"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Babar"))
	{
		printf("�Ű��� ");
		return;
	}
	if (!strcmp(p, "Xingq"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Monaa"))
	{
		printf("Ī��   ");
		return;
	}
	if (!strcmp(p, "Xinhi"))
	{
		printf("�ĺ�   ");
		return;
	}
	if (!strcmp(p, "Lingr"))
	{
		printf("���   ");
		return;
	}
	if (!strcmp(p, "Daday"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Diluk"))
	{
		printf("��¬�� ");
		return;
	}
	if (!strcmp(p, "Xling"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Banit"))
	{
		printf("������ ");
		return;
	}
	if (!strcmp(p, "Xiaog"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Kelee"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Amber"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Hutao"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Dixiy"))
	{
		printf("��ϣ�� ");
		return;
	}
	if (!strcmp(p, "Feixr"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Leize"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Kqing"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Saino"))
	{
		printf("��ŵ   ");
		return;
	}
	if (!strcmp(p, "Beido"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Jtshl"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Ldjjn"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Bcshz"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Lisha"))
	{
		printf("��ɯ   ");
		return;
	}
	if (!strcmp(p, "Shatg"))
	{
		printf("ɰ��   ");
		return;
	}
	if (!strcmp(p, "Qiinn"))
	{
		printf("��     ");
		return;
	}
	if (!strcmp(p, "Wendi"))
	{
		printf("�µ�   ");
		return;
	}
	if (!strcmp(p, "Xiaoo"))
	{
		printf("��     ");
		return;
	}
	if (!strcmp(p, "Sanbg"))
	{
		printf("ɢ��   ");
		return;
	}
	if (!strcmp(p, "Ningg"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Noair"))
	{
		printf("ŵ���� ");
		return;
	}
	if (!strcmp(p, "Yidou"))
	{
		printf("һ��   ");
		return;
	}
	if (!strcmp(p, "Zhogl"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Abedo"))
	{
		printf("������ ");
		return;
	}
	if (!strcmp(p, "Kelai"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Tinal"))
	{
		printf("������ ");
		return;
	}
	if (!strcmp(p, "Naxid"))
	{
		printf("����� ");
		return;
	}
	if (!strcmp(p, "Yaoao"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Bingy"))
	{
		printf("��ө   ");
		return;
	}
	if (!strcmp(p, "Chuns"))
	{
		printf("��ˮ   ");
		return;
	}
	if (!strcmp(p, "Jingn"))
	{
		printf("��Ů   ");
		return;
	}
	if (!strcmp(p, "Taozh"))
	{
		printf("��ծ�� ");
		return;
	}
	if (!strcmp(p, "Yuans"))
	{
		printf("Ԩ��   ");
		return;
	}
	if (!strcmp(p, "Wuxnl"))
	{
		printf("������ ");
		return;
	}
	if (!strcmp(p, "Jiang"))
	{
		printf("����   ");
		return;
	}
	if (!strcmp(p, "Qqkin"))
	{
		printf("������ ");
		return;
	}
	if (!strcmp(p, "Grass"))
	{
		printf("�ݼ�   ");
		return;
	}
	printf("%s  ", p);
}

void see(int charMany, char *output, char *character)
{
	for (int i = 1; i <= charMany; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			output[j] = character[6 * i + j];
		}
		for (int j = 5; j <= 1023; j++)
		{
			output[j] = 0;
		}
		printf("\n%s��", output);
		zhprintf(output);
	}
}
