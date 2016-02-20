//Cracked by Roath
// /d/gaibang/underem.c
// Xbc: 96/10/01

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "井底密洞");
        set("long", @LONG
这是峨嵋山脚下草棚后的井底密洞。里面破破烂烂的，丢满了各种杂物，
还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG
        );

	set("exits", ([
		"up" : "d/emei/shack",
		"east":__DIR__"emandao2",
	]));

	set("objects",([
                CLASS_D("gaibang") + "/mo-bushou" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



