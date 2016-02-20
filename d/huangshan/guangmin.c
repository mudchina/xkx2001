//Cracked by Roath
// 光明顶
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "光明顶");
    set("long", @LONG
这里地势高旷，是看日出好地方。四周云雾缭绕，阳光斜射在
云霓上形成一条彩虹，你背着太阳看那彩虹，只见白云间有你自己
的身影，身影上镶饰着光环，四周映射出五颜六色的霞光，那彩色
斑斓的光晕更史人心旷神怡。
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"north" : __DIR__"beihai",
	"southwest" : __DIR__"tianhai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
