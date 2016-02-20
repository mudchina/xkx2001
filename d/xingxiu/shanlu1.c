//Cracked by Roath
// shanlu1.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "山路");
	set("long", @LONG
这里山石渐多，道路曲折，西方一座白色山峰巍然耸立。
LONG
	);

	set("exits", ([
		"east" : __DIR__"caoyuan5",
		"west" : __DIR__"shanlu2",
	]));
	set("outdoors","xingxiu");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

