//Cracked by Roath
// Write by Wzfeng 12-29
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"驿站"NOR);
        set("long", @LONG
这里是一家驿站，专门负责传递江湖人士的来往信件。里面摆着几张大红木
桌，供人写信之用。你如有什么信件需要送给你的亲朋好友，不妨交给这里的驿
丞。左边的墙上贴着一张告示。(gaoshi)
LONG
        );

                        set("exits", ([
                                         "north" : __DIR__"kedian",
                        ]));
	set("item_desc", ([
			"gaoshi":
		  "-------------------------寄信须知---------------------------\n\n\n"
			"\t一：请将要写的信在纸上写好。(write letter)。\n\n"
			"\t二：将信仔细的装在封套中，封好。(feng xin)。\n\n"
			"\t二：将封好的信件交给驿丞(send letter)。\n\n"

			 ]) );
	

        set("objects", ([
                __DIR__"npc/xinshi" : 1,
        ]));

                set("no_fight",1);
        set("no_sleep",1);
               setup();

}
