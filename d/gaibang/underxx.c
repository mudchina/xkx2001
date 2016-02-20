//Cracked by Roath
// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "沙丘小洞");
	set("long", @LONG
这里是沙丘石碑下的一个密洞。里面破破烂烂的，丢满了各种
杂物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通
道。
LONG
	);

	set("exits", ([
		"west" : "d/xingxiu/silk4",
		"east":__DIR__"xxandao2",
	]));

	set("objects",([
		CLASS_D("gaibang") + "/yu-hongxing" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



