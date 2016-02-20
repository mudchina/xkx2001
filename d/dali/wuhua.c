//Cracked by Roath
// Room: /d/dali/wuhua.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"五华楼大门"NOR);
	set("long","这里是五华楼的大门，两扇红木门上雕满了各种南疆的珍禽异兽。这里是南
诏大王接待西南各族首领的地方，门上一块乌木大牌，有三丈来长，一丈八尺高，
上面用金粉漆了三个大字"HIY"「五华楼」"NOR"。据闻是南诏王劝丰佑的手迹。\n"
);
	set("objects", ([
		__DIR__"npc/weishi4" : 2,
		]));
	set("exits", ([
		"south" : __DIR__"shanlu3.c",
		"enter" : __DIR__"wuhua1.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
