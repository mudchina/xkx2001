//Cracked by Roath
 // 烟霞洞
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", MAG"烟霞洞"NOR);
    set("long", @LONG
据说站在山头，清晨观看山村缭绕炊烟，傍晚仰望蓝天彩霞，景
色优美，故称“烟霞”。洞口两旁有精美的“观音”和“大势至菩萨”
洞内两壁的天然岩穴里有各代的石刻。往东是下山的路。西边是去龙
井。
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                  "west" : __DIR__"road62", 
                  "eastdown" : __DIR__"road64", 
                ])
       );
	set("cost", 3);
    setup();
    replace_program(ROOM);
}
