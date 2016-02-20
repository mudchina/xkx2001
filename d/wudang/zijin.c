//Cracked by Roath
// zijin.c 紫金城 
// by Fang 8/20/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"紫金城"NOR);
	set("long", @LONG
这是守护金殿的紫金城墙，周长三里，城墙由花岗石依山势砌成，东西北
城门均面临绝壁，南门为上下路口，气势壮观。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"jinding",
		"south" : __DIR__"jindian",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

