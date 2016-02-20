//Cracked by Roath
// 始信峰
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "始信峰");
    set("long", @LONG
始信峰与上升、石笋峰鼎足而立，奇景天然。峰上多奇松巧石，
充满诗情画意。从这可眺望不远的石笋矸，矸上一根根石柱参差林立，
如同雨後春笋，它们被称为十八罗汉朝南海。“罗汉”高低大小不一，
形态各殊。
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"westdown" : __DIR__"mengbi",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
