//Cracked by Kafei
#include "room.h"

inherit ROOM;

int valid_leave();


void create()
{
        set("short", "天龙寺大门");
        set("long", @LONG
这里松柏幽幽，碧荫连天。你走在林间小径上只觉得心宁
神静。 前面有两颗菩提树在道路两旁，路的尽头有一堵高高
的砖墙，正中是一扇橡木门，门上一块黑匾(bian)。
LONG
        );


        set("outdoors", "dali");
          set("item_desc", ([
                "bian" : 			
"       \n"
"　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n"
"　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
"　　　　　　　　≌≌　  　天   龙   寺        ≌≌\n"
"　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
"　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n"
        ]));


        set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"tianls2.c",
  "southdown" : __DIR__"hongshengt.c",
]));
        
         set("cost", 2);
        setup();  
}
void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me = this_player();
if ( me->query("family/master_id") == "kurong dashi")   


{
write ("壮年僧人侧身让开，说道：师兄辛苦了，请进。\n");
me->move("/d/dali/tianls13.c");
}
if ( me->query( "family/master_name") != "枯荣大师" )
{
write("门后闪出两个壮年僧人，拦在你面前说道：这位" + 
RANK_D->query_respect(this_player()) 
+"，天龙寺内高僧不见俗人，还是请回吧。\n");
}
return 1;
}

 