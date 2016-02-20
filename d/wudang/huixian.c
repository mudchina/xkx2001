//Cracked by Roath
// huixian.c 会仙桥 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "会仙桥");
	set("long", @LONG
这里地势稍平，一道山涧缓缓流过，一座窄窄的木桥横在涧上，只溶一人
经过。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"chaotian",
                "south" : __DIR__"toutian",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

