//Cracked by Roath
// Room: /d/dali/garden9.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有蜜蜂采蜜其间。碎
石路边却长了一，两品异种茶花(flower)。
LONG);
	set("item_desc", ([
		"flower" : RED"抓破美人脸\n"
		"    白瓣而洒红斑的，叫作“红妆素裹”，百瓣而有一抹绿晕，一丝红条的叫作\n"
		"“抓破美人脸”。但红丝多了，便是“倚榄娇”了。\n"NOR,]));
	set("exits", ([
		"southwest" : __DIR__"garden8",
		"southeast" : __DIR__"garden7",
		"south" : __DIR__"garden6",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
