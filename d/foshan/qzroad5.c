//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "林间道");
        set("long", @LONG
这里是一条林间小道，在树丛中蜿蜒。岭南山林茂
密，多产毒虫，各位行路要十分小心。
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"qzroad6",
		"southwest" : __DIR__"qzroad3",
	]));

	set("objects", ([
            "/d/city/obj/stone" : 2,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
