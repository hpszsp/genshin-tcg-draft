#include "functions.h"

int main()
{
	initcharacter();
	int selected[16], banned[4], first[5], second[5], mustuse[16], mustban[1000];
	char shell;
	iniread(mustuse, mustban);
	select(selected, mustuse, mustban);
	for (int i = 1; i <= 15; i++)
	{
		ask(selected, banned, first, second, i);
	}
	printf("输入r再来一局，输入q退出\n\n");
	while (1)
	{
		fflush(stdin);
		printf("-> ");
		scanf("%c", &shell);
		if (shell == 'r')
		{
			main();
			return 0;
		}
		if (shell == 'q')
		{
			return 0;
		}
	}
}
