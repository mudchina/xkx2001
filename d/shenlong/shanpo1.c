//Cracked by Roath
// 山坡1 /d/shenlong/shanpo1
// ALN 9 / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山坡");
        set("long", @LONG
这是一个山坡，通向北方的一座山峰，坡很陡，轻功不好的人爬起来就
更加费力。突然间，你看见树上、草上、路上，东一条，西一条全是毒蛇，
可怕极了！北面是另一个山坡，往南是一条山路。
LONG
        );
	set("cost", 6);
        set("outdoors", "shenlong");

        set("exits", ([
		"northup" : __DIR__"shanpo2",
		"southdown" : __DIR__"shanlu2",
        ]));

        set("snaketype", ({"jinhuan", "fushe"}));

        setup();
}

#include "/d/shenlong/snakeroom.h";
