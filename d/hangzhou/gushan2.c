//Cracked by Roath
// 平台
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "孤山平台");
    set("long", @LONG
平台北面有“西湖天下景”亭阁，亭柱两旁有一对联(duilian)。
这里还有曲桥水池，临池有叠石假山，布置得高低参差，疏密有致。
北边是下山的路。
LONG);

    set("exits", ([ /* sizeof() == 1 */ 
        "northdown" : __DIR__"gushan1", 
                 ])
       );
   set("item_desc", 
      ([
      "duilian" : 
	"水		晴\n"
	"山		雨\n"
	"处		时\n"
        "处              时\n"
	"明		好\n"
	"秀		奇\n"
      ])
      );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
