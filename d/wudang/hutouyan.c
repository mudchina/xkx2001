//Cracked by Roath
// hutouyan.c 虎头岩 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "虎头岩");
	set("long", @LONG
一块巨大的岩石看上去好象一个虎头正张大了血盆大口咆哮，虎身隐藏
在草木丛中。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"wulaofeng",
                "southup" : __DIR__"chaotian",
	]));
        set("objects", ([
                BEAST_D("laohu") : 1]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

