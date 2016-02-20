//Cracked by Roath
// 飞来石
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "飞来石");
    set("long", @LONG
沿着山径，绕过西面的四座小山峰和三条幽谷，便来到仙桃峰，
峰上有一块大石，上尖下圆，形貌似桃。因为此石孤立在山峰之上，
大石下部和山峰是分开的，所以被称为飞来石。
LONG);

    set("exits", ([ /* sizeof() == 3 */
	"northwest" : __DIR__"paiyun",
	"northeast" : __DIR__"beihai",
	"southeast" : __DIR__"tianhai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
