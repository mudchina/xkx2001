//Cracked by Roath
// Room: /d/dali/garden5.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", MAG"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有蜜蜂采蜜其间。碎
石路边却长了一，两品异种茶花(flower)。
LONG);
	set("item_desc", ([
		"flower" : MAG"风尘三侠\n"
		"    风尘三侠，有正品和副品之分，凡是正品，三朵花中必须紫色者最大，那是\n"
		"虬髯可，白色者次之，那是李靖，红色者最小且最娇艳，那是红拂女。如果红花\n"
		"大过了紫花白花，那便是副品了，身份就差得多了。\n"NOR,]));
	set("exits", ([
		"southwest" : __DIR__"garden4",
		"southeast" : __DIR__"garden3",
		"north" : __DIR__"garden6",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
