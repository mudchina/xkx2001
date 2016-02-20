//Cracked by Roath
// Room: /d/dali/garden6.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有蜜蜂采蜜其间。碎
石路边却长了一，两品异种茶花(flower)。
LONG);
	set("item_desc", ([
		"flower" : GRN"落第秀才\n"
		"    落第秀才，虽有十七朵不同色的茶花生于一株，但论颜色，比十八学士少了\n"
		"一色，偏又是驳而不纯，开起来或迟或早，花朵有大有小。处处东施效颦，学那\n"
		"十八学士却又学不象，于是就被叫做了“落第秀才”。\n"NOR,]));
	set("exits", ([
		"north" : __DIR__"garden9",
		"south" : __DIR__"garden5",
		"west" : __DIR__"garden8",
		"east" : __DIR__"garden7",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
