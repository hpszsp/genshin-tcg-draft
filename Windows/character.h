//The upstream of this file is hpszsp/genshin-tcg-draft
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define characterMuch 61

char characteren[61][6] = {"Nouse",
                           "Ganyu", "Diona", "Kaiya", "Chony",
                           "Lingh", "Youla", "Shenh", "Qiqii",
                           "Babar", "Xingq", "Monaa", "Daday",
                           "Xinhi", "Lingr", "Candy", "Nilou",
                           "Diluk", "Xling", "Banit", "Amber",
                           "Xiaog", "Kelee", "Hutao", "Yanfi",
                           "Dixiy", "Feixr", "Leize", "Kqing",
                           "Saino", "Beido", "Jtshl", "Ldjjn",
                           "Bcshz", "Lisha", "Duori", "Shatg",
                           "Qiinn", "Wendi", "Xiaoo", "Wanye",
                           "Sanbg", "Ningg", "Noair", "Zhogl",
                           "Abedo", "Yidou", "Kelai", "Tinal",
                           "Naxid", "Yaoao", "Baizh", "Bingy",
                           "Chuns", "Jingn", "Taozh", "Yuans",
                           "Wuxnl", "Jiang", "Qqkin", "Grass",
                          };
char characterzh[61][8] = {"=====  ",
                           "����   ", "�ϰ��� ", "����   ", "����   ",
                           "类�   ", "��ǉ   ", "���   ", "����   ",
                           "�Ű��� ", "����   ", "Ī��   ", "����   ",
                           "�ĺ�   ", "���   ", "����˿ ", "��¶   ",
                           "��¬�� ", "����   ", "������ ", "����   ",
                           "����   ", "����   ", "����   ", "���   ",
                           "��ϣ�� ", "��л�� ", "����   ", "����   ",
                           "��ŵ   ", "����   ", "����   ", "����   ",
                           "����   ", "��ɯ   ", "����   ", "ɰ��   ",
                           "��     ", "�µ�   ", "��     ", "��Ҷ   ",
                           "ɢ��   ", "����   ", "ŵ���� ", "����   ",
                           "������ ", "һ��   ", "����   ", "������ ",
                           "����� ", "����   ", "����   ", "��ө   ",
                           "��ˮ   ", "��Ů   ", "��ծ�� ", "Ԩ��   ",
                           "������ ", "����   ", "������ ", "�ݼ�   ",
                          };
//tools
void int2enprint(int code)
{
	printf("%c%c%c%c%c", characteren[code][0], characteren[code][1], characteren[code][2], characteren[code][3], characteren[code][4]);
}
void int2zhprint(int code)
{
	printf("%c%c%c%c%c%c%c", characterzh[code][0], characterzh[code][1], characterzh[code][2], characterzh[code][3], characterzh[code][4], characterzh[code][5], characterzh[code][6]);
}
void int2enstr(int code, char* str)
{
	for (int i = 0; i <= 4; i++)
	{
		str[i] = characteren[code][i];
	}
}
void int2zhstr(int code, char* str)
{
	for (int i = 0; i <= 6; i++)
	{
		str[i] = characterzh[code][i];
	}
}
int zhstr2int(char *str)
{
	char tmp[7];
	for (int i = 0; i <= characterMuch - 1; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			tmp[j] = characterzh[i][j];
			if (tmp[j] == ' ')
			{
				tmp[j] = 0;
			}
		}
		if (!strcmp(tmp, str))
		{
			return i;
		}
	}
	return -1;
}
int enstr2int(char *str)
{
	char tmp[5];
	for (int i = 0; i <= characterMuch - 1; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			tmp[j] = characteren[i][j];
			if (tmp[j] == ' ')
			{
				tmp[j] = 0;
			}
		}
		if (tmp[0] == str[0] && tmp[1] == str[1] && tmp[2] == str[2] && tmp[3] == str[3] && tmp[4] == str[4])
		{
			return i;
		}
	}
	return -1;
}
