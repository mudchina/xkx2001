//Cracked by Roath
// 山道 /d/shenlong/shandao
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山道");
        set("long", @LONG
转过两个山坡，你已行走在一个山道之中，山道的北面是峰顶，向下是
山坡。抬头遥见峰顶建着几座大竹屋，耳边隐隐约约传来「锵锵」的刀剑撞
击声和有人高声喧哗的声音，看来离山顶不远了。山道狭窄，只能容一人通
过。
LONG
        );
	set("cost", 6);
        set("outdoors", "shenlong");

        set("exits", ([
		"northup" : __DIR__"fengding",
		"southdown" : __DIR__"shanpo2",
        ]));

        set("snaketype", ({"snake", "fushe"}));

        setup();
}

#include "/d/shenlong/snakeroom.h";
