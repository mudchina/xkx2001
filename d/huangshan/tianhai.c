//Cracked by Roath
// 天海
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "天海");
    set("long", @LONG
天海在前、後、东、西四海的中间，地势比较平坦。突然间，云
雾从足底升起，云天一色，不愧为天海。
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"southdown" : __DIR__"bieyu",
	"northwest" : __DIR__"feilai",
	"northeast" : __DIR__"guangmin",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
