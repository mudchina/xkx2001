//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "林间大道");
        set("long", @LONG
这里是一条林间大道。这里是湖南境内。南边通向南岭的一个
山口。路西有个小村子。
LONG
        );
        set("exits", ([
		"west" : __DIR__"cunkou",
		"southup" : __DIR__"nanling",
		"north" : __DIR__"road3",
	]));

	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
