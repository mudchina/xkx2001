//Cracked by Roath
// 半山寺
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "半山寺");
    set("long", @LONG
一座小小的寺庙建在老人峰与朱砂峰之间。庙旁有一茶室，上下
山的游客大多在此稍作停留，一边休息一边观赏周围风境。
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"southdown" : __DIR__"lima",
	"northeast" : __DIR__"tianmen",
	"northwest" : __DIR__"xiaoxin",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
