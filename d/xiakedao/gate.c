//Cracked by Roath
// xiakedao/gate.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

#include <room.h>

void create()
{
        set("short", "石门");
        set("long", @LONG
这里已是甬道尽头，面前一道厚重的石门。门上刻着三个斗大的
古篆：「侠客行」。年深日久，那笔划的凹下之处都积满了青苔，越
发显得沧桑，你心中的敬意油然而生。
LONG );

        set("exits", ([
		"enter" : __DIR__"xiakexing1",
		"south" : __DIR__"yongdao10",
        ]));

        set("objects", ([
                __DIR__ +"npc/shaolin" : 1,
        ]));

	create_door("enter", "石门", "out", DOOR_CLOSED);
	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
