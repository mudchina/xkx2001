//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "林间大道");
        set("long", @LONG
这里是一条林间大道，在树丛中蜿蜒。这里是湖南境内。北边是
湖北。路边有可供路人休息的小茶亭。
LONG
        );
        set("exits", ([
		"south" : __DIR__"road4",
		"north" : __DIR__"road2",
		"east" : __DIR__"chating",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
