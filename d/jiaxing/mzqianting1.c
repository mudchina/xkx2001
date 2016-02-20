//Cracked by Roath
// Jay 8/9/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "梅庄前厅");
        set("long", @LONG
厅外的天井中种着一棵老梅，枝干如铁，极是苍劲。大厅正中悬挂
一幅中堂(zhongtang)。南面大门(door)外是一片梅林。
LONG
        );
        set("exits", ([
		"south" : __DIR__"mzgate1"
	]));

        set("item_desc", ([
		"door" : "门上似乎并未上锁。\n", 
                "zhongtang" : "画中所绘是一个仙人的背面，墨意淋漓，笔力雄健，"
			"上题「丹青生大醉後泼墨」八字，笔法森严，一笔笔如长"
			"剑的刺划。\n",
        ]));
        create_door("south","大门","north", DOOR_CLOSED);
	set("objects", ([
		__DIR__"npc/huang2" : 1,
		__DIR__"npc/danqing2" : 1,
		__DIR__"npc/tubiweng2" : 1,
	]));
        set("no_clean_up", 0);

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
   if (dir =="south" ) {
        if (objectp(present("huangzhong gong", environment(me))))
                return notify_fail("黄钟公挥琴挡住了你的去路。\n");
        if (objectp(present("tubi weng", environment(me))))
                return notify_fail("秃笔翁挥笔挡住了你的去路。\n");
        if (objectp(present("huangzhong gong", environment(me))))
                return notify_fail("丹青生挥剑挡住了你的去路。\n");
   }
   return::valid_leave(me, dir);
}



