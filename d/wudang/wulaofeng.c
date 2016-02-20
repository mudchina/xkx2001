//Cracked by Roath
// wulaofeng.c 五老峰 
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "五老峰");
	set("long", @LONG
只见五座奇峰突兀，惊险无比，行人多不敢放胆在此玩赏风景。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"sanlaofeng",
                "southup" : __DIR__"hutouyan",
	]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

