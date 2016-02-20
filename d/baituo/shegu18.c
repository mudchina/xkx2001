//Cracked by Roath
// shegu.c 蛇谷
// maco 7/15/2000

#include <ansi.h>
inherit ROOM;
string look_crack();

void create()
{
	set("short", "蛇谷树林");
	set("long", @LONG
这是白驼山蛇谷中的一处密林，杂草丛生，树木枝桠茂密，幽暗
阴森，古木盘根错节，有些树根间的裂缝(crack)中响着细碎的声音。
东北方地势略高，是一处坡地。西南方是大片荒地，是蛇谷中最危险
的地带。
LONG
	);

	set("exits", ([ 
	    "east" : __DIR__"shegu17",
	    "northeast" : __DIR__"shegu19",
	    "southwest" : __DIR__"shegu_maze1",
	]));

	set("item_desc", ([
	"crack" : (: look_crack :),
	]));

	set("objects", ([
	    "/d/baituo/npc/bt_snake" : 1,
	]));

	set("hide_snake", 1+random(3));
	set("grass", 1);
	set("crack", 1);

	set("cost", 2);
	set("outdoors","baituo");
	set("shegu", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "southwest") {
		if ( me->query("family/family_name") == "白驼山" 
		&& !me->query_temp("shegu/warning_18") ) {
			me->set_temp("shegu/warning_18", 1);
			return notify_fail( HIR"西南边是蛇谷中大型蛇类出没的荒地，你心里暗自警惕，必需小心谨慎。\n"NOR+"做好心理准备的话，就再次前进吧。\n");
		}
	}
	return ::valid_leave(me,dir);
}


#include "snake_room.h"
