//Cracked by Roath
// 百步云梯
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "百步云梯");
    set("long", @LONG
这是一百多级石磴，像一列靠在峭壁上的长梯。四周云腾雾涌，
长梯仿佛架在云天之中。往上爬就到了鳖鱼峰。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"bieyu",
	"south" : __DIR__"lianhua",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
