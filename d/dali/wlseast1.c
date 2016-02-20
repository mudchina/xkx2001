//Cracked by Kafei
// Room: /d/dali/wlseast1.c
// AceP

inherit ROOM;

int do_drop(object);

void create()
{
	set("short", "山坡");
	set("long", @LONG
这里是一个小山坡，几个神农帮帮众在守卫，不远处的青烟，
是神农帮在煮炼毒药。
LONG );

	set("exits", ([
		"up"   : __DIR__"wlseast2",
		"west" : __DIR__"wlseast",
	]));

	set("objects", ([
		__DIR__"npc/snbz": 2,
		]));

	set("cost", 3);
	set("outdoors", "dali");
	setup();
}
