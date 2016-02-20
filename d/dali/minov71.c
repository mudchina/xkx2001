//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov71.c

inherit ROOM;

void create()
{
	set("short", "妃丽湖畔");
	set("long", @LONG
你站在妃丽湖的北岸，北边不远就是喜州城。此湖不大，但湖水清澈，鱼鳖
皆有，不少台夷村民划着竹筏在湖上捕鱼。湖之南和东边半山上都有台夷村镇，
有道路绕湖东而过通向南边。
LONG);
	set("exits", ([
		"southeast" : __DIR__"minov72",
		"eastup"  : __DIR__"minov78",
		"north" : __DIR__"minov64",
		]));
	set("area", "妃丽湖");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
