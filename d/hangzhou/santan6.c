//Cracked by Roath
// 三潭映月
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "碑亭");
    set("long", @LONG
走在九曲石桥上，只见曲桥边睡莲竞绽，傍叠石鸢尾摇曳。曲桥
中是一座小亭。
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
        "north" : __DIR__"santan5", 
        "south" : __DIR__"santan1", 
                 ])
       );
    setup();
    replace_program(ROOM);
}