//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "酒泉");
        set("long", @LONG
相传这里就是汉大将军霍去病大破楼兰后犒军之地，武帝赠御酒二十
瓶，霍不忍独享，尽倾于十泉内，与三军共饮。后闻以酒泉之水酿酒，香
馥可口。
LONG
        );
        set("exits", ([
                "northeast" : __DIR__"shalu1",
                "southwest" : __DIR__"loulan",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
