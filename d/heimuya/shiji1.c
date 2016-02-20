//Cracked by Roath
// Room: /d/heimuya/shiji1.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", "石级");
        set("long", @LONG
这是上崖的石级，上面有一道铁门。铁闸之前，有
日月教教众把守，检查腰牌。
LONG
        );

        set("exits", ([
                "northup" : __DIR__"shiji2",
                "southwest" : __DIR__"zongtan",
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

