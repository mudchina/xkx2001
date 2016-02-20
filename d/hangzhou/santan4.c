//Cracked by Roath
// 三潭映月
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "竹径通幽");
    set("long", @LONG
一截花窗短墙，横列在两段曲桥之间，墙的两端，了无衔接；墙
内竹叶绕径，佐静添幽。墙外假山隔水，一径横陈。南边是花岛亭，
北边过曲桥是一座小亭。
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
        "south" : __DIR__"santan5", 
        "north" : __DIR__"santan3", 
                 ])
       );
    setup();
    replace_program(ROOM);
}