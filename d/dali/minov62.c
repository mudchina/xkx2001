//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov62.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
一条贯通南北的大路，是由大理城往南边疆土的主要官道。沿路向南丛林愈
发茂密，大片雨林覆盖山岭，此间地势较平坦，大路笔直地连接着北边的大理城
和南边的喜州等城镇。
LONG);
	set("exits", ([
		"north" : __DIR__"shqiao",
		"south" : __DIR__"minov63",
		]));
	set("area", "喜州城");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
