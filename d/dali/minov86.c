//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov86.c

inherit ROOM;

void create()
{
	set("short", "剑川镇");
	set("long", @LONG
这里是剑川的镇中心，镇子不大，居民大部分是乌夷族，几乎全都以狩猎为
生。由于山高地寒，附近山林的野兽大多皮粗毛厚，有不少皮货商在这里和当地
猎人交易。北出山口则属大理北疆，也是入蜀之途，南穿苍山则可抵大理内陆。
LONG);
	set("objects", ([
		__DIR__"npc/wylieren1.c" : 1,
		__DIR__"npc/phshang.c" : 1,
		]));
	set("exits", ([
		"southup" : __DIR__"minov84",
		"north" : __DIR__"minov87",
		]));
	set("area", "剑川镇");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
