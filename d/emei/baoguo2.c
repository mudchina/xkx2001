//Cracked by Roath
// /d/emei/baoguo2.c 保国寺藏经楼
// Shan: 96/09/22

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "藏经楼");
	set("long", @LONG
这里是报国寺的藏经楼。阁楼上密密麻麻排了好多书架，架上摆满了经书。
有两个身穿白衣的小师太正在一角静静地读着经书。
LONG
	);
	set("exits", ([
		"south" : __DIR__"baoguo1",
	]));

        set("objects",([
                "d/emei/obj/yugajing0" : 1,
                "d/emei/obj/yugajing2" : 1,
		"d/emei/npc/daoming" :1,
        ]));


	set("cost", 0);
	setup();
}


int valid_leave(object me, string dir)
{
        if (  (dir == "south")
           && ( present("shu", this_player()) ) 
           && objectp(present("daoming", environment(me))) ) {
        message_vision("道明小师父见$N想把经书拿走，上前轻声说道：本阁经书不外借。\n", me);
        return notify_fail("\n");
        }

        return ::valid_leave(me, dir);
}

