//Cracked by Roath
// Room: /d/shaolin/shijie1.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "石阶");
	set("long", @LONG
这里是嵩山南麓的少室山山脚。一条长长的石阶如同巨龙般
蜿蜒而上，直没云端。嵩山群峰壁立，翠色满山，令人俯仰间顿
生渺小之意。边上有几个叫卖的小贩和挑夫，似乎在嚷嚷着争吵
些什么。
LONG
	);

	set("exits", ([
		"east" : __DIR__"ruzhou",
		"west" : __DIR__"xiaojing1",
		"northup" : __DIR__"shijie2",
	]));

	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
		__DIR__"npc/tiao-fu" : 2,
	]));

	set("outdoors", "shaolin");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



