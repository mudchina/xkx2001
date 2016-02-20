//Cracked by Roath
// Room: /d/dali/maze1.c

inherit ROOM;

int do_find(string);

void create()
{
	set("short", "树林外");
	set("long", @LONG
你来到了一片黑森森的树林面前，放眼望去，密密麻麻的都是树木，而且荆
棘丛生，隐约可见有些小路东盘西曲。你仔细观察，发现这显然是个人造的迷宫。
其中暗合五行八卦，奇门遁甲，端的非同小可，千万不要冒然进去。
LONG);
	set("exits", ([
		"north" : __DIR__"minov11",
		"south" : __DIR__"maze2.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir=="south") {
		me->set_temp("mark/maze金", 1);
		me->set_temp("mark/maze木", 1);
		me->set_temp("mark/maze水", 1);
		me->set_temp("mark/maze火", 1);
		me->set_temp("mark/maze土", 1);
	}

	return ::valid_leave(me, dir);
}
