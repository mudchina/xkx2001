//Cracked by Roath
// Jay 8/9/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "梅庄大门");
        set("long", @LONG
穿过一大片梅林，走上一条青石板大道，来到一座朱门白墙的大庄
院外，行至近处，见大门(door)外写着「梅庄」两个大字，旁边署着
「虞允文公题」四字。
LONG
        );
        set("exits", ([
		"west" : __DIR__"changdi",
		"north" : __DIR__"mzqianting1"
	]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
	]));

        set("item_desc", ([
                "door" : "门上似乎并未上锁。\n",
        ]));
        create_door("north","大门","south", DOOR_CLOSED);
        set("no_clean_up", 0);

	set("cost", 1);
	setup();
	set("outdoors","quanzhou");
        replace_program(ROOM);
}
