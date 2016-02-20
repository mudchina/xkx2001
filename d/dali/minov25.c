//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov25.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
道路在山林中蜿蜒继续，从西面的山岭通向东面的低洼地带。这里山势较为
平缓，山丛中偶有人烟，透过丛林的缝隙中向东望去，隐约可见一汪碧水和些许
人烟。
LONG);
	set("exits", ([
		"westdown" : __DIR__"minov24",
		"eastdown" : __DIR__"minov26",
		]));
	set("area", "阳宗镇");
	set("cost", 4);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
