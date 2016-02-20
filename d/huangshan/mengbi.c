//Cracked by Roath
// 梦笔生花
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "梦笔生花");
    set("long", @LONG
山路旁有一根石柱矗立在松海里，一株古松从石缝中盘旋而出，
石柱是“笔杆”，古松是“笔头”，这一奇景被叫作“梦笔生花”。
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"eastup" : __DIR__"shixin",
	"southdown" : __DIR__"xianrenz",
	"northeast" : __DIR__"beihai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
