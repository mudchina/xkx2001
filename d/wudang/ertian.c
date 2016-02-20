//Cracked by Roath
// ertian.c 二天门 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "二天门");
	set("long", @LONG
这里是“二天门”，金光灿灿的金顶就在眼前了。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"toutian",
                "southup" : __DIR__"santian",
	]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

