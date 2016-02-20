//Cracked by Roath
// 灵隐寺之天王
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "天王殿");
    set("long", @LONG
走进大殿，只见正面坐着袒胸露腹的弭勒佛，两旁是四大天王，
後面是神态威严的韦驮菩萨。天王殿後面便是大雄宝殿。
LONG);

    set("exits", 
          ([ /* sizeof() == 2 */ 
             "out" : __DIR__"lingyin0", 
             "north": __DIR__"lingyin2",
          ])
       );
	set("cost", 0);
    setup();
   replace_program(ROOM);
}