//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov12.c

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条卵石铺成的小道，曲曲折折地通向前方。两边是密密的树林这里人
迹罕至，惟闻足底叩击路面，微风吹拂树叶，沙沙作响，西边直去可达大理城南
门。
LONG);
	set("exits", ([
		"southeast" : __DIR__"minov10",
		"westdown" : __DIR__"southgate",
		]));
	set("area", "黑龙岭");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
