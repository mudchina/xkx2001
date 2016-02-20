//Cracked by Roath
// Room: xilang.c 西廊
// qfy July 7, 1996.

#include <room.h>
inherit ROOM;

void reset();

void create()
{
    set("short", "西廊");
    set("long", @LONG
走廊西边传来阵阵饭菜香气，不问可知那儿便是华山派的厨房。几个
华山弟子正兴高彩烈地谈论着自己的风光史及武林中的几件大事。另有几
个女弟子正忙着做饭烧菜。
LONG
    );

    set("exits", ([
	"east" : __DIR__"huayuan",
	"west" : __DIR__"chufang",
    ]));

    set("objects", ([
	CLASS_D("huashan") + "/lingshan" : 1,
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


    if (dir == "west" && objectp(present("yue lingshan", environment(me)))) {
	if ( !myfam || myfam["family_name"] != "华山派")
	   return notify_fail("岳灵姗拦身说道：后面是本派厨房，"+RANK_D->query_respect(me)+"请往前厅奉茶。\n");
    }

    return ::valid_leave(me, dir);
}
