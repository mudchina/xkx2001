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
一片太平热闹景象。西边有一花园，游人进进出出，十分热闹。东边
是名医胡庆余开的药铺。
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                   "northeast" : __DIR__"road24", 
                   "southwest" : __DIR__"road71", 
                   "west" : __DIR__"jujing1", 
                   "east" : __DIR__"yaodian", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}