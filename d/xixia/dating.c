//Cracked by Roath
// Room: /d/xixia/dating.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "一品堂大厅");
	set("long", @LONG
大厅布置很简单，正北是两张太师椅围着一张八仙桌。房间的两侧
各放有四张椅子，北墙上挂着－副中堂，墙角摆着一些小巧玲珑的陈设
品。每当风吹入门，门口的风铃发出沙哑的低吟。地板由白玉石板铺成，
上面似乎还有条条暗青色的花纹。大厅西边有一扇月形的门洞。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dayuan",
  "west" : __DIR__"mishi",
]));
	create_door("west","木门","east",DOOR_CLOSED);
	set("objects", ([
		__DIR__"npc/tieshu" : 1,
		__DIR__"npc/ypshi" : 2,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir =="west" ) {
            if (present("wu shi", environment(me)))
                return notify_fail("一品堂武士一言不发地挡在你前面。\n"); 
        return 1;
    }
        return ::valid_leave(me, dir);
}
