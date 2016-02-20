//Cracked by Roath
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"春桃阁"NOR);
	set("long", @LONG
这是一间地方不大的小厢房，屋中陈设颇为雅致，屋中装饰以真树真花为
主，枝干横斜，花叶疏密有致，淡雅天然，真如一幅名家水墨山水一般。屋角
一张小几，一张牙床，罗帷低垂，空气中有一阵淡淡幽香。
LONG
	);

/*
	set("objects", ([
	]));

	set("item_desc", ([
		"tu" :
	"\n"
	]));
*/
	set("exits", ([
		"west" : __DIR__"lichun2",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}
 

