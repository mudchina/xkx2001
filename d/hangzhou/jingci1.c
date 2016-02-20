//Cracked by Roath
// 净慈寺
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   
   set("short", "净慈寺");
   set("long", @LONG
净慈寺，原名慧日永明院，又叫兴教寺。净慈寺面向西湖，後拥
苍然挺秀的南屏山。往北就回到大道上。
LONG        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "north" : __DIR__"road72", 
                  "enter" : __DIR__"jingci2", 		  
                ])
       );

	set("cost", 1);
   setup();
   replace_program(ROOM);
}
