#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define AllCharacters "00000 Ganyu Diona Kaiya Chony Lingh Youla Shenh Qiqii Babar Xingq Monaa Daday Xinhi Lingr Candy Nilou Diluk Xling Banit Amber Xiaog Kelee Hutao Yanfi Dixiy Feixr Leize Kqing Saino Beido Jtshl Ldjjn Bcshz Lisha Duori Shatg Qiinn Wendi Xiaoo Wanye Sanbg Ningg Noair Yidou Zhogl Abedo Kelai Tinal Naxid Yaoao Baizh Bingy Chuns Jingn Taozh Yuans Wuxnl Jiang Qqkin Grass aaaaa"
void readcharacter(char *p); //读取./character.cfg 的前1023字符并储存在*p中
void formatName(char *p);//预处理命令行
void readcharacter(char *p)
{
	FILE *fp = NULL;
	fp = fopen("./character.cfg", "r+w");
	fgets(p, 1023, fp);
	fclose(fp);
}
void formatName(char *p)
{
	if (!strcmp(p, "defconfig"))
	{
		FILE *fp = NULL;
		fp = fopen("./character.cfg", "w+");
		fprintf(fp, AllCharacters);
		fclose(fp);
	}
	if (!strcmp(p, "delconfig"))
	{
		system("del character.cfg");
	}
}
