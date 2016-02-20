//Cracked by Roath
#include <room.h>
inherit ROOM;

void kick();

void create()
{
	set("short", "竹林小道");
	set("long", @LONG
这是一条竹林小道，笔直的朝东面延伸。两旁尽是遮天蔽日的茂密的竹林，
南边隐隐有一座小破庙。
LONG
        );
        set("exits", ([
		"east" : __DIR__"zhulin2",
                "south" : __DIR__"pomiao",
        ]));

	set("objects",([
		CLASS_D("gaibang") + "/jian" : 1,
	]));

	create_door("south", "小门", "north", DOOR_CLOSED);

	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "丐帮") && dir == "east" &&
                objectp(present("jian zhanglao", environment(me))))
                return notify_fail("简长老一把揪住你的衣领说：“慢着！”\n");
        return ::valid_leave(me, dir);
}

