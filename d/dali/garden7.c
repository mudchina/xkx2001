//Cracked by Roath
// Room: /d/dali/garden7.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有蜜蜂采蜜其间。碎
石路边却长了一，两品异种茶花(flower)。
LONG);
	set("item_desc", ([
		"flower" : HIG"满月\n"
		"    满月，是一本大白花而微有隐隐的黑斑的，大白花好似一轮明月，那些黑斑，n"
		"便是月中的桂枝了。\n"NOR,]));
	set("exits", ([
		"northwest" : __DIR__"garden9",
		"west" : __DIR__"garden6",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
