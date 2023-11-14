#include "functions.h"

int main()
{
	initcharacter();
	int selected[16], banned[4], first[5], second[5], mustuse[16], mustban[1000];
	iniread(mustuse, mustban);
	select(selected,mustuse,mustban);
	for (int i = 1; i <= 15; i++)
	{
		ask(selected, banned, first, second, i);
	}
	system("pause");
}
