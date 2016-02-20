//Cracked by Roath
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"秋菊斋"NOR);
	set("long", @LONG
这是一间地方颇为宽大的厢房，室中一派豪华富贵气派，珠翠环绕，让人
目不暇接。诸般器用均为寻常市面上所无，屋主之豪奢可见一斑。屋内香气扑
鼻．中人欲醉，四壁装饰以菊花图案为主，夹有不少浓词艳赋。
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
		"north" : __DIR__"lichun2",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}
 

