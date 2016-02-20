//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov30.c

inherit ROOM;

void create()
{
	set("short", "桑林");
	set("long", @LONG
一大片桑树林生长在低山的缓坡山腰上。养蚕、纺丝是摆夷族的重要副业，
摆夷妇女大都擅织丝，编织自己穿着的短裙，也用来和临近部落交换些其它物品。
一群摆夷姑娘正在林间忙着采摘桑叶。
LONG);
	set("objects", ([
		__DIR__"npc/bycaisang.c" : 3,
		]));
	set("exits", ([
		"northdown" : __DIR__"minov26",
		]));
	set("area", "阳宗镇");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
