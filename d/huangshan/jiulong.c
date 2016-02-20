//Cracked by Roath
// 九龙瀑
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "九龙瀑");
    set("long", @LONG
流泉自香炉和罗汉两峰间倾泻而下，喷珠飞玉，犹如九龙腾空而
将。瀑九迭，每迭一潭，亦称九龙潭。前人有诗赞美“飞泉不让匡庐
瀑，峭壁撑天挂九龙。”
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"northwest" : __DIR__"yungu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
