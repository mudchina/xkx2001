//Cracked by Roath
// 牛鼻峰
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "牛鼻峰");
    set("long", @LONG
牛鼻峰下的山路旁有一古松。这株古松的枝杆集中在顶部向四周伸
展，树冠平整，其形恰似蒲团，故得名蒲团松。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"westdown" : __DIR__"yanwang",
	"eastup" : __DIR__"wenshu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
