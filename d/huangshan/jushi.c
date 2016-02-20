//Cracked by Roath
// 文殊石
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "文殊石");
    set("long", @LONG
一块巨石凌空向你扑头盖面般砸将下来，你不由得倒抽一口冷气，
正要闪开，那大石又不动了。原来那巨石被一道峡谷夹着，没落下来。
细看巨石上还刻着三个字“文殊石”，旁边石壁上又刻三个字“不可
皆”。巨石下又有一洞，看来又要钻(zuan)了。
LONG);

    set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"penglai",
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
   me->move(__DIR__"wenshu");
}
