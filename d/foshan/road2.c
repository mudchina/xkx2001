//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "林间大道");
        set("long", @LONG
这里是一条林间大道，在树丛中蜿蜒。这里是湖北境内。南边是
湖南。
LONG
        );
        set("exits", ([
		"south" : __DIR__"road3",
		"north" : __DIR__"road1",
	]));

	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
