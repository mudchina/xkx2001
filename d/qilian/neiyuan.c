//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "内院");
        set("long", @LONG
你眼前突然一亮，此处竟别有天地，不知光线从何透入，真是巧
夺天工。这是一个精致的院落，地面由鹅卵石铺成，四处种满了奇花
异草，许多是连皇宫中也少见的。正中央是一座假山，院落的西北角
有一口井（well），不时地飘来阵阵香气，令人陶醉不已。北面是日
月神教的议事堂。
LONG
        );
        set("exits", ([
                "out" : __DIR__"rukou1",
		"west" : __DIR__"zhengtang",
                "north" : __DIR__"datang",
        ]));
	set("item_desc", ([
                "well" : "上面写着：“流香泉”。\n"
        ]));
	set("resource/water", 1);
	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
