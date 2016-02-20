//Cracked by Roath
// 慈光阁
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "慈光阁");
    set("long", @LONG
走过听涛亭，绿荫深处露出一幢古刹，那就是慈光阁。阁四周群
山环抱，茂林修竹掩映，环境十分幽静。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"wengquan",
	"northup" : __DIR__"lima",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
