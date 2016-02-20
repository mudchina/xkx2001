//Cracked by Roath
// Room: /d/dali/hongshengt.c

inherit ROOM;

void create()
{
	set("short", "宏圣寺塔");
	set("long", @LONG
宏圣寺塔又名“一塔”，屹立于苍山之麓，面向洱海，为云南著名唐塔之一。
宏圣寺塔为四方形空心砖石塔，塔身各层之间用砖砌出跌涩椽，使其四角飞翘。
整个塔身轮廓呈抛物线，优美流畅。
LONG);
	set("exits", ([
		"west" : __DIR__"cangshan",
		"enter" : __DIR__"hongtj.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
