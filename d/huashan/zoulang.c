//Cracked by Roath
// Room: zoulang.c 走廊
// qfy July 7, 1996.

#include <room.h>
inherit ROOM;

void reset();

void create()
{
    set("short", "走廊");
    set("long", @LONG
走廊东边木门后连着华山男弟子的休息室，西边门后是女弟子的休息
室。南边是华山掌门的寝室，弟子皆不准进去。北边则是客厅。
LONG
    );

    set("exits", ([
	"east" : __DIR__"nanshi",
	"west" : __DIR__"nushi",
	"south" : __DIR__"buwei2",
	"north" : __DIR__"zoulang1",
    ]));

    set("objects", ([
	CLASS_D("huashan") + "/dayou" : 1,
    ]));

    create_door("east", "木门", "west", DOOR_CLOSED);
    create_door("west", "木门", "east", DOOR_CLOSED);   

    set("no_clean_up", 0);

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "华山派") && dir != "south" ) {
	if ( (!myfam || myfam["family_name"] != "华山派") && dir != "north" )
	   return notify_fail("华山不留外客，你不能住在这里！\n");
    }

    if ( me->query("gender") == "男性" && dir == "west" && !wizardp(me) )
	return notify_fail("看清楚点，男弟子休息室在东边！\n");

    if ( me->query("gender") == "女性" && dir == "east" && !wizardp(me) )
	return notify_fail("看清楚点，女弟子休息室在西边！\n");

    if ( me->query("gender") == "无性" && (dir=="east" || dir=="west") )
	return notify_fail("你不能住在这里！\n");

    if (dir == "south" && objectp(present("lu dayou", environment(me))))
	return notify_fail("陆大有喝道：后面是师父的寝室，这位"+RANK_D->query_respect(me)+"请止步。\n");

    return ::valid_leave(me, dir);
}
