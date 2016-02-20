// Change by Server
// regban.c
// Created by Dts@XKX, 1997-04-15
// cf ban.c

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
		REGBAN_D->print();
	else if (sscanf(arg, "+ %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能禁以 *, +, ? 结尾的地址。\n");
		else
			REGBAN_D->add(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
		REGBAN_D->remove(site);
	else if (sscanf(arg, "? %s", site) == 1)
		REGBAN_D->check(site);
	else write("指令格式：regban [+|-|? hostname|user@hostname]\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
指令格式：regban [+|-|? hostname_pettern|user@hostname_pattern]

禁止别人注册新的人物，以防有人蓄意捣乱。
例： regban + smart@.*hacker.com
     regban - smart@.*hacker.com
     regban ? smart@attack.hacker.com
例： regban + hacker.com
     regban - hacker.com
     regban ? attack.hacker.com
HELP
	);
	return 1;
}
