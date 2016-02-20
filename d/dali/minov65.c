//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov65.c

inherit ROOM;

void create()
{
	set("short", "竹林小路");
	set("long", @LONG
一条小路穿竹林而过，西南方竹林深处是一片台夷人聚居的村镇，东北可遥
遥望见喜州城的城墙。道路两边竹林茂密，时有台夷人来砍伐。
LONG);
	set("exits", ([
		"northeast" : __DIR__"minov64",
		"southwest" : __DIR__"minov66",
		]));
	set("area", "喜州城");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
