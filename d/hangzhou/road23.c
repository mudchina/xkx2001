//Cracked by Roath
// 青石大道
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "青石大道");
    set("long", @LONG
沿湖大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，
一片太平热闹景象。街东边是一古朴书院，书院里不时传来朗朗的笑声。
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
                   "north" : __DIR__"road22", 
                   "south" : __DIR__"road24", 
                   "east" : __DIR__"shuyuan", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}