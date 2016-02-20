//Cracked by Kafei
// Room: /d/dali/wlseast.c
// AceP

inherit ROOM;

int do_drop(object);

void create()
{
	set("short", "小山头");
	set("long", @LONG
你走在无量山中的树林中，这里树木较稀疏，前面不远有些烟火，
看来是有人烟的样子。
LONG );

	set("exits", ([
		"south" : __DIR__"wls5",
		"north" : __DIR__"wls4",
		"west"  : __DIR__"wls3",
		"east"  : __DIR__"wlseast1",
	]));

	set("cost", 3);
	set("outdoors", "dali");
	setup();
}
