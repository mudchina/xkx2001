//Cracked by Roath
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"丽春院"NOR);
	set("long", @LONG
这是丽春院二楼，不时有丫鬟从各房穿进穿出，端茶送水，递送菜肴。
有的厢房里不时传出打情骂俏之声，淫声浪语不一而足；有的厢房却门窗紧
闭，偶而有几缕销魂夺魄的呻吟声飘出。
LONG
	);

/*
	set("objects", ([
                __DIR__"npc/wei" : 1,
                __DIR__"npc/guinu" : 1,
	]));

	set("item_desc", ([
		"tu" :
"                                      Ο        Ο          Ο             
                                    ┌│        │          │
      ┌—Ο┌—  —┬——Ο        │┤      ┌┘          └┐
    —┘Ο—┘    ————Ο  Ο——┘│  Ο—┼┴—  Ο——┴┼


   Ο       Ο    ΟΟΟ                 Ο                  ○
   │       │    │├┼       ┌—Ο  ┌┼                  │
   ├ Ο┬┐┤    ├└┼┐   —┘Ο——┘┤          ○┬—┐┤
   │   ┘└│    │  │                 └            │  ││
	\n"]));
*/
	set("exits", ([
		"east" : __DIR__"lichun_e",
		"west" : __DIR__"lichun_w",
                "south" : __DIR__"lichun_s",
                "north" : __DIR__"lichun_n",
		"down" : __DIR__"lichunyuan",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    if (present("guinu",environment(me)) && 
                me->query("hooker")) {
       message_vision("龟奴一把揪住$N的裙边：你已经是丽春院的人了，不接客别想遛！\n",
                me);
       return notify_fail("\n");
    }
    else
        return :: valid_leave(me,dir);
}
 

