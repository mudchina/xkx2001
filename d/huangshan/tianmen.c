//Cracked by Roath
// 天门坎
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "天门坎");
    set("long", @LONG
天门坎高铺在天都峰与横云岩之间，两面奇峰入云，一条上山之
路就从天门中穿云而过。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"banshan",
	"up" : __DIR__"tiandu1",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
