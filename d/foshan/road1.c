//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "林间道");
        set("long", @LONG
这里是一条林间小道，在树丛中蜿蜒。西北方连着一条黄土路，南
面的道路要宽一些。
LONG
        );
        set("exits", ([
		"south" : __DIR__"road2",
		"northwest" : "/d/wudang/wdroad6",
	]));

	set("objects", ([
		"/d/city/obj/branch" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
