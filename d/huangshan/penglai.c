//Cracked by Roath
// 蓬莱三岛
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "蓬莱三岛");
    set("long", @LONG
从这往南望，只见三座参差不起的小石峰，峰上奇松挺拔，白云
萦回其间，如海浪拍岸，故得名蓬莱三岛。南边石壁上有一条石缝，
如想通过就只有钻(zuan)进石缝。
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"jushi",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
void init()
{
   add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
   if ( arg )
      return notify_fail( "什么？\n");
   me->move(__DIR__"yixian2");
}
