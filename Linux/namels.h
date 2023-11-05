#include<string.h>
#include<stdio.h>
void zhprintf(char *p);
void see(int charMany, char *output, char *character); 
void zhprintf(char *p)
{
	if (!strcmp(p, "NNNNN"))
	{
		printf("=====  ");
		return;
	}
	if (!strcmp(p, "Ganyu"))
	{
		printf("甘雨   ");
		return;
	}
	if (!strcmp(p, "Diona"))
	{
		printf("迪奥娜 ");
		return;
	}
	if (!strcmp(p, "Kaiya"))
	{
		printf("凯亚   ");
		return;
	}
	if (!strcmp(p, "Chony"))
	{
		printf("重云   ");
		return;
	}
	if (!strcmp(p, "Lingh"))
	{
		printf("绫华   ");
		return;
	}
	if (!strcmp(p, "Youla"))
	{
		printf("优菈   ");
		return;
	}
	if (!strcmp(p, "Shenh"))
	{
		printf("申鹤   ");
		return;
	}
	if (!strcmp(p, "Qiqii"))
	{
		printf("七七   ");
		return;
	}
	if (!strcmp(p, "Babar"))
	{
		printf("芭芭拉 ");
		return;
	}
	if (!strcmp(p, "Xingq"))
	{
		printf("行秋   ");
		return;
	}
	if (!strcmp(p, "Monaa"))
	{
		printf("莫娜   ");
		return;
	}
	if (!strcmp(p, "Xinhi"))
	{
		printf("心海   ");
		return;
	}
	if (!strcmp(p, "Lingr"))
	{
		printf("绫人   ");
		return;
	}
	if (!strcmp(p, "Daday"))
	{
		printf("公子   ");
		return;
	}
	if (!strcmp(p, "Diluk"))
	{
		printf("迪卢克 ");
		return;
	}
	if (!strcmp(p, "Xling"))
	{
		printf("香菱   ");
		return;
	}
	if (!strcmp(p, "Banit"))
	{
		printf("班尼特 ");
		return;
	}
	if (!strcmp(p, "Xiaog"))
	{
		printf("宵宫   ");
		return;
	}
	if (!strcmp(p, "Kelee"))
	{
		printf("可莉   ");
		return;
	}
	if (!strcmp(p, "Amber"))
	{
		printf("安柏   ");
		return;
	}
	if (!strcmp(p, "Hutao"))
	{
		printf("胡桃   ");
		return;
	}
	if (!strcmp(p, "Dixiy"))
	{
		printf("迪希雅 ");
		return;
	}
	if (!strcmp(p, "Feixr"))
	{
		printf("奥兹   ");
		return;
	}
	if (!strcmp(p, "Leize"))
	{
		printf("雷泽   ");
		return;
	}
	if (!strcmp(p, "Kqing"))
	{
		printf("刻晴   ");
		return;
	}
	if (!strcmp(p, "Saino"))
	{
		printf("赛诺   ");
		return;
	}
	if (!strcmp(p, "Beido"))
	{
		printf("北斗   ");
		return;
	}
	if (!strcmp(p, "Jtshl"))
	{
		printf("九条   ");
		return;
	}
	if (!strcmp(p, "Ldjjn"))
	{
		printf("雷神   ");
		return;
	}
	if (!strcmp(p, "Bcshz"))
	{
		printf("八重   ");
		return;
	}
	if (!strcmp(p, "Lisha"))
	{
		printf("丽莎   ");
		return;
	}
	if (!strcmp(p, "Shatg"))
	{
		printf("砂糖   ");
		return;
	}
	if (!strcmp(p, "Qiinn"))
	{
		printf("琴     ");
		return;
	}
	if (!strcmp(p, "Wendi"))
	{
		printf("温迪   ");
		return;
	}
	if (!strcmp(p, "Xiaoo"))
	{
		printf("魈     ");
		return;
	}
	if (!strcmp(p, "Sanbg"))
	{
		printf("散兵   ");
		return;
	}
	if (!strcmp(p, "Ningg"))
	{
		printf("凝光   ");
		return;
	}
	if (!strcmp(p, "Noair"))
	{
		printf("诺艾尔 ");
		return;
	}
	if (!strcmp(p, "Yidou"))
	{
		printf("一斗   ");
		return;
	}
	if (!strcmp(p, "Zhogl"))
	{
		printf("钟离   ");
		return;
	}
	if (!strcmp(p, "Abedo"))
	{
		printf("阿贝多 ");
		return;
	}
	if (!strcmp(p, "Kelai"))
	{
		printf("柯莱   ");
		return;
	}
	if (!strcmp(p, "Tinal"))
	{
		printf("提那里 ");
		return;
	}
	if (!strcmp(p, "Naxid"))
	{
		printf("纳西妲 ");
		return;
	}
	if (!strcmp(p, "Yaoao"))
	{
		printf("瑶瑶   ");
		return;
	}
	if (!strcmp(p, "Bingy"))
	{
		printf("冰萤   ");
		return;
	}
	if (!strcmp(p, "Chuns"))
	{
		printf("纯水   ");
		return;
	}
	if (!strcmp(p, "Jingn"))
	{
		printf("镜女   ");
		return;
	}
	if (!strcmp(p, "Taozh"))
	{
		printf("讨债人 ");
		return;
	}
	if (!strcmp(p, "Yuans"))
	{
		printf("渊火   ");
		return;
	}
	if (!strcmp(p, "Wuxnl"))
	{
		printf("无相雷 ");
		return;
	}
	if (!strcmp(p, "Jiang"))
	{
		printf("剑鬼   ");
		return;
	}
	if (!strcmp(p, "Qqkin"))
	{
		printf("丘丘王 ");
		return;
	}
	if (!strcmp(p, "Grass"))
	{
		printf("草鸡   ");
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
		printf("\n%s：", output);
		zhprintf(output);
	}
}
