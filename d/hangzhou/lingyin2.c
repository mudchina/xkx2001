//Cracked by Roath
// 灵隐寺之大雄宝殿
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "大雄宝殿");
    set("long", @LONG
天王殿後是另一座高达三十几米的大殿。匾上写着“大雄宝殿”。
殿前有两座八角九层石塔。往南又进了天王殿。
LONG);

   set("exits", ([ /* sizeof() == 2 */ 
                  "enter" : __DIR__"lingyin3", 
		  "south": __DIR__"lingyin1",
                ])
      );
	set("cost", 0);
    setup();
    replace_program(ROOM);
}