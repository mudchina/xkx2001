//Cracked by Roath
// Room: donglang.c 东廊
// qfy July 7, 1996.

#include <room.h>
inherit ROOM;

void reset();
int valid_leave(object, string);

void create()
{
    set("short", "东廊");
    set("long", @LONG
东边是华山派的藏书室，专供华山弟子读书写字。存有一些剑谱和经
书。西面连着花园，北边是个偏厅。
LONG
    );

    set("exits", ([
	"east" : __DIR__"shuyuan",
	"west" : __DIR__"huayuan",
	"north" : __DIR__"pianting",
    ]));

    set("objects", ([
	CLASS_D("huashan") + "/liangfa" : 1,
    ]));

    set("no_clean_up", 0);

    set("cost", 0);
    setup();
    //replace_program(ROOM);
}

void init()
{
	this_player()->delete_temp("possbooks");
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if (dir == "east" && objectp(present("liang fa", environment(me)))) {
	if ( !myfam || myfam["family_name"] != "华山派" )
	   return notify_fail("梁发挡住你说道：后面是本派书院，这位"+RANK_D->query_respect(me)+"请留步。\n");

	if ( (int)me->query_temp("huashan/书") )
	   return notify_fail("梁发挡住你说道：你已拿了书，得先还我才让你再拿！\n");    
    }

    return ::valid_leave(me, dir);
}
