//Cracked by Roath
// 中天竺
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "法净寺");
   set("long", @LONG
法镜寺依山而立，寺前小溪流水。进香的游客不时的进进出出。
南上往上天竺。朝北是下山的路。
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "southup" : __DIR__"tianzhu4", 
                  "northdown" : __DIR__"tianzhu2", 
                ])
       );
	set("objects", ([
                "/d/wudang/npc/guest" : 1,
		"/d/shaolin/npc/xiao-ku" : 1,
        ]));
	set("cost", 1);
   setup();
   replace_program(ROOM);
}
