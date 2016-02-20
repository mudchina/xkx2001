//Cracked by Roath
// Room: /d/mingjiao/luanshidui.c
#include <ansi.h>
inherit ROOM;


void create()
{
        set("short",HIC "迷宫" NOR);
        set("long", HIW @LONG
这是一个迷宫。
LONG NOR
);      
/*	set("exits", ([ 
 "east" : __DIR__"shanlu23",
  "west" : __DIR__"shanlu23",
  
]));
*/
set("no_clean_up", 1);
        setup();

}
