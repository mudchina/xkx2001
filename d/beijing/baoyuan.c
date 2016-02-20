//Cracked by Roath
//baoyuan.c 宝源钱庄
// ssy

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"宝源钱庄"NOR);
        set("long", @LONG
这是京城里最大的一家钱庄，它发行的银票信誉非常好，通行全国。墙上贴
着一张布告(bugao)。钱庄掌柜和伙计忙忙碌碌地工作着。
LONG
        );

        set("item_desc", ([
			   "bugao" : "
钱庄业务：存款(deposit)，取款(withdraw)，兑换(convert)。
\n",
        ]));
        set("objects", ([
	       __DIR__"npc/bankhuoji" : 1,
        ]));

        set("no_drop",1);
        set("exits", ([
               "west" : __DIR__"fuchengdajie_n",
        ]));

        set("day_shop", 1);
        set("cost", 0);
        setup();
}


