//Cracked by Roath
// 保淑塔
// Dong  11/03/1996.

#include <ansi.h>
#include <room.h>

#define BANGZHU "/d/huanghe/npc/bangzhu"

inherit ROOM;

void create()
{
        set("short", "保淑塔");
        set("long", @LONG
保淑塔姿态秀丽挺拔，塔基极小，却负荷了极高的塔身。传说吴
越王钱弘淑奉召入京，久留未返，他大臣吴延爽为祝原其平安归来，
而建此塔，故名保淑塔。往南是下山的路。
LONG  );

        set("objects",([
		BANGZHU : 1,
        ]));

        set("exits", ([ /* sizeof() == 1 */ 
                  "southdown" : __DIR__"baoshi1", 
                ])
        );

	set("cost", 3);
        set("outdoors", "hangzhou");

        setup();

        replace_program(ROOM);
}
