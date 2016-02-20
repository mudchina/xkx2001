//Cracked by Roath
// chmiao.c 城隍庙
// qfy Nov 3, 1996

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "城隍庙");
	set("long", @LONG
这是一间年代久远的小庙，里面供放着观音菩萨和土地爷，是泉州乡间求
卜问卦的场所，据说这里的签卦特灵。旁边有扇小门。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"southwest" : __DIR__"houshan",
		"southeast" : __DIR__"chxiang",
	]));

        set("objects", ([ 
		__DIR__"npc/miaozhu" : 1,
        ]));

	create_door("southwest", "小门", "northeast", DOOR_CLOSED);

        set("no_clean_up", 0);

	set("cost", 0);
        setup();
}
