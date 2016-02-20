//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov67.c

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
一小片在山坡下的竹林里开垦出来的农田，临有溪流，种植着水稻。台夷生
活很大程度上依靠农业，从事农业的却基本上是妇女。男子大都专司狩猎和捕鱼。
LONG);
	set("objects", ([
		__DIR__"npc/tynong" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"minov66",
		]));
	set("area", "武定镇");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
