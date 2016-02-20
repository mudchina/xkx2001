//Cracked by Roath
// bailin.c 武当柏林
// by Fang 8/19/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"武当柏林"NOR);
	set("long", @LONG
	你穿行在一片茂密的柏林中，阴森郁翠，怪石嶙峋，草深没人。不时地
有兔子从你的身边飞跑而过。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southup" : __DIR__"haohanpo",
		"northdown" : __DIR__"yuzhen",
	]));
        set("objects", ([
                __DIR__"npc/yetu" : 2]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

