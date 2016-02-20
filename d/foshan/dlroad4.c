//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "林间道");
        set("long", @LONG
这里是一条林间小道，在树丛中蜿蜒。这里是广西了。岭南山林茂
密，多产毒虫，各位行路要十分小心。
LONG
        );
        set("exits", ([
		"southeast" : __DIR__"dlroad3",
		"southwest" : __DIR__"dlroad5",
	]));

	set("objects", ([
		__DIR__"npc/zsnake" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
