//Cracked by Roath
// 一线天
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "一线天");
    set("long", @LONG
一座高入云端的陡壁挡住了路。在陡壁旁边，几乎贴着它又竖起
一块摩天欲飞的岩石，和它齐肩并列，欲合未合，如想通过就只有钻
(zuan)进石缝。
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"xiaoxin",
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
