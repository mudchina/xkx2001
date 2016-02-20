//Cracked by Roath
// houyuan.c
// qfy June 14, 1997.

#include <room.h>
inherit ROOM;

void reset();

void create()
{
    set("short", "后院");
    set("long", @LONG
这里是华山派的后院，里面是华山弟子的居室和练功房。华山派总所
倚山而建，地势险峻，往东便是悬崖。西面是另一个小花院，有假山小池，
景色怡人，颇有江南林园的特色。
LONG
    );

    set("exits", ([
	"east" : __DIR__"xuanya",
	"west" : __DIR__"huayuan2",
	"south" : __DIR__"zoulang1",
	"north" : __DIR__"huayuan",
    ]));

    set("objects", ([
	CLASS_D("huashan") + "/dayou" : 1,
    ]));

    set("no_clean_up", 0);

    set("cost", 0);

    setup();
    //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "华山派") && dir == "south" && !wizardp(me)
    && !me->query_temp("marks/bai_ning") && objectp(present("lu dayou", environment(me))) )
	return notify_fail("陆大有喝道：后面是华山派的内院，这位"+RANK_D->query_respect(me)+"请止步。\n");

    return ::valid_leave(me, dir);
}