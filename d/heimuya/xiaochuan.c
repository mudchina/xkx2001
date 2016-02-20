//Cracked by Roath
// Room: /d/heimuya/xiaochuan.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", "小船");
        set("long", @LONG
这是一艘小船，最多也就能载三、四个人。一名六
十多岁的老艄公手持长竹篙，正在船尾吃力地撑着船。
LONG
        );


        set("outdoors", "heimuya");
        set("cost", 2);
        set("invalid_startroom", 1);
        setup();
        replace_program(ROOM);
}



