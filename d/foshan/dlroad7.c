//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "林间道");
        set("long", @LONG
这里是一条林间小道，在树丛中蜿蜒。这里向东是广西。向西北走
就是大理国的地界了。
LONG
        );
        set("exits", ([
		"east" : __DIR__"dlroad6",
		"northwest" : "/d/dali/tulu4",
	]));

	set("objects", ([
		"/d/city/obj/stone" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
