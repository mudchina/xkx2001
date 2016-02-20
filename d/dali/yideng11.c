//Cracked by Roath
// yideng quest room 11

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "庙内厢房");
	set("long", @LONG
这里是庙的东厢房，有小沙弥奉上香茶待客。庙宇看来虽小，里边却甚进深，
一条青石铺的小径穿进后面的一座竹林，竹林绿荫森森，幽静无比，令人烦俗尽
消。竹林中隐着三间石屋。
LONG);
	set("exits", ([
		"out" : __DIR__"yideng9",
		"north" : __DIR__"yideng12",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}
