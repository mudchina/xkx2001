//Cracked by Roath
// 石阶
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "石阶");
    set("long", @LONG
山谷越下越深，光线越来越暗，山高蔽日，林幽苔滑。四面的松
树渐渐少，取而代之的是各种其他的树木。每株树上都挂着密密的苔
藓，岩壁上、石阶上也铺着苔藓。沿途石缝中长出终年常绿的龙絮草
从悬涯上垂下来，好像绿色的瀑布。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"up" : __DIR__"shijie3",
	"down" : __DIR__"shijie5",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
