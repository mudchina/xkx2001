//Cracked by Roath
// Room: /d/dali/dalicheng11.c

inherit ROOM;

void create()
{
	set("short", "太和居二楼");
	set("long", @LONG
这里是太和居的二楼，楼梯边上坐了些手持云板，瑶琴的歌女。富商土豪在
这里边吃喝作乐，也有文人墨客在此饮酒清谈，从南面窗口望出，可以看道城外
五华楼前的一波碧水。
LONG);
	set("objects", ([ 
		__DIR__"npc/song" : 1,
		__DIR__"npc/genu" : 3,       
		]));
	set("exits", ([
		"down" : __DIR__"dalicheng10",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
	replace_program(ROOM);
}
