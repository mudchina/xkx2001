//Cracked by Roath
// Room: /d/dali/shqiao.c

inherit ROOM;


void create()
{
	set("short", "双鹤桥");
	set("long", @LONG
这是一个岔路口，北边是座青石拱桥名叫双鹤桥，此桥跨在绿玉溪上，桥北
即是大理城，由此南去是通往南方的喜州、龙口等城镇的官道，东去的岔路通往
广西，沿绿玉溪南岸西行可达五华楼。
LONG);
	set("exits", ([
		"southeast" : __DIR__"tulu4",
		"north" : __DIR__"southgate.c",
		"south" : __DIR__"minov62",
		"west" : __DIR__"shanlu4",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
