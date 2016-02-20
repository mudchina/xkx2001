//Cracked by Roath
// Room: /d/dali/garden8.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有蜜蜂采蜜其间。碎
石路边却长了一，两品异种茶花(flower)。
LONG);
	set("item_desc", ([
		"flower" : HIR"眼儿媚\n"
		"    一本白花，花瓣儿上有两个橄榄核儿状黑斑的，叫作“眼儿媚”，那两个黑\n"
		"斑，便好似美人儿的媚眼。\n"NOR,]));
	set("exits", ([
		"northeast" : __DIR__"garden9",
		"east" : __DIR__"garden6",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
