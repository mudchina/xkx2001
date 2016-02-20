//Cracked by Roath
// 石阶
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "石阶");
    set("long", @LONG
越往下走越清凉，正当你开始感到一丝冷意，迎面一股暖气扑面
而来。原来前面有一天然的温泉，泉水晶莹透明，无色无味，可饮可
浴。温泉四周长满了奇花异草。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"shijie4",
	"down" : __DIR__"songguan",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
