//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov32.c

inherit ROOM;

void create()
{
	set("short", "林中山涧");
	set("long", @LONG
密林深处豁然开朗，一道激流从上上飞溅下来，山涧并不宽，更谈不上深，
行人尽可徒步通过。涧水清凉干净，路人往往停下来用竹筒装水解渴。四面皆是
青竹林，竹叶随山风沙沙作响。有些摆夷村民不远数里上山来采新鲜竹笋为食。
LONG);
	set("objects", ([
		__DIR__"npc/byshanren.c" : 1,
		]));
	set("exits", ([
		"northdown" : __DIR__"minov31",
		"southdown" : __DIR__"minov33",
		]));
	set("area", "阳宗镇");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("resource/water",1);
	setup();
	replace_program(ROOM);
}
