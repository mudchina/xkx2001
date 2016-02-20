//Cracked by Roath
// 排云亭
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "排云亭");
    set("long", @LONG
西海边上有一石亭，叫排云亭。亭前有铁锁石栏，游客都会来此
观赏日落和深山幽谷的奇景。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"southeast" : __DIR__"feilai",
	"east" : __DIR__"beihai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
