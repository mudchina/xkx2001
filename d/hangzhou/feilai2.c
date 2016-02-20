//Cracked by Roath
// 飞来峰
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "射旭洞");
    set("long", @LONG
洞後侧穹顶上的石罅间可仰见一束天光，故又名“一线天”。东
南边是下山的路。
LONG);
    set("exits", ([ /* sizeof() == 1 */ 
        "southeast" : __DIR__"feilai1",
        ])
       );
	set("cost", 3);
    setup();
    replace_program(ROOM);
}