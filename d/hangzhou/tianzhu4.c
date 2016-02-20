//Cracked by Roath
// 天竺山路
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
小溪横过山路，跨溪有一座小石桥。溪边农家小孩在嬉戏玩乐。
南上便到了上天竺。北下就是中天竺。
LONG
        );

        set("exits", ([ /* sizeof() == 2 */ 
                "southup" : __DIR__"tianzhu5", 
                  "northdown" : __DIR__"tianzhu3", 
        ]));

	set("objects", ([
                "/d/village/npc/boy" : 1,
        ]));

	set("cost", 2);
        set("outdoors", "hangzhou");

        setup();

        replace_program(ROOM);
}
