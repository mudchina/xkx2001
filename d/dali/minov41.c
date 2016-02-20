//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov41.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条山路，四面皆是茂密的树林和延绵不绝的大山，道路两旁间或可见一些
夷族的村镇，西面一片高山高耸入云，山颠白雪皑皑终年不化。正路向西上山，
一条岔路向南蜿蜒着。
LONG);
	set("exits", ([
		"westup" : __DIR__"minov42",
		"eastdown" : __DIR__"shanlu",
		]));
	set("area", "碧罗雪山");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
