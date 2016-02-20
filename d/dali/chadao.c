//Cracked by Kafei
// Room: /dali/chadao.c
// AceP

inherit ROOM;

void create()
{
	set("short", "岔道");
	set("long", @LONG
这里是从中原到大理官道上的一条岔道，行走在密林当中。往东是官道
的正路，向西就进入云南大理的无量山区了，但地形崎岖，道路难辨，对此
地区不熟悉的人，是根本找不到路的。
LONG
	);

	set("exits", ([
		"west"  : __DIR__"wls1",
		"east"  : __DIR__"guandao",
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
