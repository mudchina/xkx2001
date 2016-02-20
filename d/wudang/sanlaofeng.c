//Cracked by Roath
// sanlaofeng.c 三老峰 
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "三老峰");
	set("long", @LONG
只见三座奇峰突兀，惊险无比，行人多不敢放胆在此玩赏风景。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"wuyaling",
                "southup" : __DIR__"wulaofeng",
	]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

