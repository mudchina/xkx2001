//Cracked by Roath
// 石阶
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "石阶");
    set("long", @LONG
又走了一会儿，四周怪石嶙立。你边走边看，那一块好像“老虎
驮羊”，那一块又好像“关公挡曹”，这一块是“三尊大佛”，还有
前面是“太白醉酒”。。。无不维妙维肖，如雕似塑。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"shijie2",
	"down" : __DIR__"shijie4",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
