//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "地下密室");
        set("long", @LONG
这是一间极其隐避的地下密室，是玄劫教的藏珍之所。室内从北
往南布满了兵器架，据传其中不少竟是大内藏珍，是真是假就不得而
知了，但是从一些能瞅见的刀鞘剑柄即能得知那是价值连城的宝物，
其中几个还叉着几柄木刀竹剑。最里面竟有一个丈高的白玉瓶，几个
力士也难以搬动。东边角上有一堵小小的石门（door）。
LONG
        );
	set("no_fight", "1");
        set("no_steal", "1");
        set("sleep_room",1);
        set("exits", ([
                "out" : __DIR__"zibai",
                "west" : __DIR__"houtin",
        ]));
        set("objects", ([
                __DIR__"obj/ping" : 1,
        ]));

	set("item_desc", ([
                "door" : "出了门就是紫柏坡。\n",
        ]));
        set("no_clean_up", 1);

	set("cost", 1);
        setup();
        replace_program(ROOM);
}
