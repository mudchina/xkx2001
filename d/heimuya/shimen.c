//Cracked by Roath
// Room: /d/heimuya/shimen.c
// Date: fear 1999/12/18
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", HIR"石门"NOR);
        set("long", @LONG
这里是一道大石门，只见两旁刻着两行大字，右首
是“文成武得”，左首是“仁义英明”，横额上刻着“
日月光明”四个大红字。
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"shiji3",
                "north" : __DIR__"cliff",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

