//Cracked by Roath
// 鲫鱼背
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "鲫鱼背");
    set("long", @LONG
鲫鱼背就是深渊中连结两峰的一快薄薄石壁，溜平光滑如同鱼脊，
走在上面不由自主地要心惊胆战，头晕目眩。脚下万丈深渊中乱云飞
渡，犹如江海怒涛。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"down" : __DIR__"tiandu1",
	"up" : __DIR__"tiandu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
