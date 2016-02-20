//Cracked by Kafei
// Room: /dali/jb1.c
// AceP

inherit ROOM;

void create()
{
	set("short", "江边");
	set("long", @LONG
你站在澜沧江边，江岸山石壁立，嶙峋巍峨，你身后的洞口处离江面有十余丈
高，江水再涨，也不会淹进洞去。这里并无人迹，更无道路。
LONG );

	set("exits", ([
                "west"    : __DIR__"jb2",
		"enter" : __DIR__"shishi2",
	]));

	set("cost", 2);
        set("outdoors", "dali");
	setup();
}
