//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov4.c

inherit ROOM;

void create()
{
	set("short", "金汁河畔");
	set("long", @LONG
这里位处金汁河畔，原本建有一座地藏寺，如今寺院早废。唯有一座石刻经
幢半埋土中。
LONG);
	set("exits", ([
		"eastup" : __DIR__"minov13",
		"north" : __DIR__"minov5",
		"west" : __DIR__"minov2",
		]));
	set("area", "大叠水瀑布");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
