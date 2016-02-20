//Cracked by Roath
// 阎王壁
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "阎王壁");
    set("long", @LONG
这一段山路奇险无比，故得此名。爬阎王壁的游客面对着这险坡
都不禁有点儿心惊。爬上阎王壁就可到莲花峰了。往东上是玉屏峰。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"lianhua",
	"eastup" : __DIR__"niubi",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
