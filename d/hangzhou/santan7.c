//Cracked by Roath
// 三潭映月
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "沿堤石路");
    set("long", @LONG
石堤旁处处垂柳拂波，湖面波光粼粼，山色空朦。不少游客都在
此停步小歇。石路沿伸向东南和东北两边。
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
	"northeast" : __DIR__"santan3",
	"southeast" : __DIR__"santan1",
                 ])
       );
    setup();
    replace_program(ROOM);
}