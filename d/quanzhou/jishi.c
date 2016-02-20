//Cracked by Roath
// jishi.c 集市
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "集市");
	set("long", @LONG
这里是居民购买日常生活用品和商贩的场所，各种商品应有尽有，琳琅满
目。同时这里也进行着与外国商人的买卖交易。香料、石等是本地商家最抢手
的需求品，因为他们都知道一旦将其运到中原，将会获得极丰厚的利润。不难
想象为何这里长年累月人来人往，川流不息，吵吵嚷嚷尽是讨价还价的声音。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"tumen",
		"west" : __DIR__"xinmen",
		"south" : __DIR__"hjting",
	]));

	set("objects", ([ 
                __DIR__"npc/butou" : 1,
		__DIR__"npc/xiao-fan" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
