//Cracked by Roath
// shanlu3.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "山路");
	set("long", @LONG
道路不知已有多少年无人行走，有些地方长草比人还高，有
些地方又全被沙堆阻塞。路径愈走愈狭，两旁山石壁立，这条路
显是人工凿出来的。
LONG
	);

	set("exits", ([
		"east" : __DIR__"chalu"+(6+random(4)),
		"west" : __DIR__"shanlu4",
	]));
	set("outdoors","xingxiu");
	set("cost", 6);
	setup();
	replace_program(ROOM);
}

