//Cracked by Roath
// Room: /d/dali/garden3.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。一个老花匠穿梭其间整理花茶花，
花丛中时时有蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG);
	set("item_desc", ([
		"flower" : RED"十八学士\n"
		"    十八学士，是天下的极品，一株上共开十八朵花，朵朵颜色颜色不同，红的\n"
		"就是全红，紫的便是全紫，决无半分混杂。而且十八朵花形状业朵朵不同，各有\n"
		"各的妙处，开时齐开谢时齐谢。\n"NOR,]));
	set("objects", ([
		__DIR__"npc/huajiang": 1,
		]));                                                                  
	set("exits", ([
		"northwest" : __DIR__"garden5",
		"southwest" : __DIR__"garden2",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
}
int valid_leave(object me, string dir)
{
	if (me->query_temp("garden_working")) return notify_fail("没干完活儿就想溜，没门儿！\n");  
	return ::valid_leave(me, dir);
}                                                                             
