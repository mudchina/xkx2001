//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "朱提山");
        set("long", @LONG
此山通山由赤土构成，远望尤如红玛瑙帽顶，所以叫朱提。其山为祈连诸山中
最矮的一座，大概因为土质不好，少有生迹，唯山顶有几处黑草丛生之处。但听说
常有剧毒长虫出没，令人颇感费解。东边一条小路，路旁一个木牌(mupai)。
LONG
        );
        set("exits", ([
                "southwest" : __DIR__"datong-ling",
                "north" : __DIR__"yongchang",
		"east" : __DIR__"xiaolu",
        ]));

        set("item_desc", ([
                "mupai": "东向入山，九死一生。\n",
	]));

	set("objects", ([
		"/d/wudang/npc/snake" : 1,
	]));
	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
