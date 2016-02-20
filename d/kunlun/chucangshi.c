//Cracked by Roath
// Room: /d/mingjiao/chucangshi.c 储藏室
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

int do_check();
int f_set_jingtie(int num);
string word_string();

void create()
{
	set("short", "储藏室");
	set("long", @LONG
这是用来储藏精铁的房间。墙上面有一行小字(word)。
LONG
	);

	set("item_desc", ([
		"word": (: word_string :),
	]) );
	set("jingtie", 0);
	set("no_clean_up", 0);

	setup();
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}

void init()
{
	add_action("do_check","check_jingtie");
	add_action("f_set_jingtie","set_jingtie");
}

int do_check()
{
	write("现有"+query("jingtie")+"块精铁\n");
	return 1;
}

int f_set_jingtie(int num)
{
	set("jingtie",num);
	write("OK!\n");
	return 1;
}

string word_string()
{
	return HIC"查精铁储藏量:	check_jingtie\n"+
		"设置精铁储藏量	set_jingtie\n"NOR;
}