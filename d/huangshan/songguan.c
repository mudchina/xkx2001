//Cracked by Roath
// 松谷庵
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "松谷庵");
    set("long", @LONG
松谷庵在迭障峰下，庵前有流水汇成池沼，周围翠竹如海，环境
幽静，庵前散落着青龙、白龙、乌龙和老龙诸潭景。这些水潭深浅不
同加上峰峦倒影，石色有异，把水映成各种色彩，奇美悦目。
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"up" : __DIR__"shijie5",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
