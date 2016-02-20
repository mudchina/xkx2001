//Cracked by Roath
// Room: /d/heimuya/zongtan.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", HIR"日月神教总坛"NOR);
        set("long", @LONG
这里是日月神教的总坛，总坛的广场上面有很多日
月神教教众站立在那里，情景极是严肃。
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"shiji1",
                "south" : __DIR__"hillroad4",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

