//Cracked by Roath
// Room: /d/beijing/changanjie.c

#include "beijing_defs.h"
inherit ROOM;

void create()
{
	set("short", "长安街");
	set("long", @LONG
这是繁华热闹的长安街，大街北面就是守卫森严的紫禁城
南门天安门了。这里时常有巡逻的侍卫盘查过路的行人。大街
两边是各种店铺，你看的眼都花了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"zhengyangmen",
  "east"  : __DIR__"changanjie_e",
  "west"  : __DIR__"changanjie_w",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}

void init()
{
    if (random(5) == 1) 
	HELPER->clonehere_with_limit(this_object(), "/d/beijing/npc/randomnpc.c", 8);
}
