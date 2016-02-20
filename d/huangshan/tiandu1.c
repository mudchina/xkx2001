//Cracked by Roath
// 天都峰
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "天都峰");
    set("long", @LONG
你手脚并用爬这垂直的绝壁，不时要膝盖贴腮，鼻子靠壁。爬了
一会儿，你不得不停下来歇歇。看看四周的景色，发现到处奇石异态
，有那松鼠跳天都，仙人下桥，还有那姜子牙钓鱼，个个维妙维肖。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"down" : __DIR__"tianmen",
	"up" : __DIR__"jiyubei",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
