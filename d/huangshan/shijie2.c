//Cracked by Roath
// 石阶
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "石阶");
    set("long", @LONG
走在石阶上，起初还能看到黄山特有的奇松怪石，下了十八道弯
後，迎面是一座嶙峋奇特的山峰。它太像一只骆驼了，鼻子，眼睛，
嘴巴都和真的一样。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"shijie1",
	"down" : __DIR__"shijie3",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
