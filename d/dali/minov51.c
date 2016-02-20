//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov51.c

inherit ROOM;

void create()
{
	set("short", "高黎山密林");
	set("long", @LONG
高黎山上地势险恶、树大林深，附近几乎毫无人烟。地处高山四季皆寒，熊
虎等猛兽时常出没，只有勇敢的猎人才敢上这里来。东面下山即是泸水谷地。
LONG);
	set("objects", ([
		BEAST_D("laohu") : 1
		]));
	set("exits", ([
		"east" : __DIR__"minov50",
		]));
	set("area", "泸水沿岸");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
