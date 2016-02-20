//Cracked by Roath
// 狮石
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "狮石");
    set("long", @LONG
出了文殊院向左过狮石，可以看见玉屏峰下的天池。池水清碧，千
山倒映，人称它是万山中的一方明镜。一阵微风吹过，池水涟漪，山影
轻摇，使人山皆醉。
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"right" : __DIR__"wenshu",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
