//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大广场");
        set("long", @LONG
这里是院前的大广场，是举行全寺性活动的场所，每年一度的辩经
大会就在这里举办。北面是前院，向南是山门。
LONG
        );
        set("exits", ([
                "north" : __DIR__"frontyard",
                "south" : __DIR__"shanmen",
        ]));
	set("objects", ([
                __DIR__"npc/gelun" : 1,
                "/kungfu/class/xueshan/gongcang" : 1,
 
        ]));
	set("valid_startroom",1);

        set("outdoors","qilian-shan");
	set("cost", 1);
        setup();
	"/clone/board/labuda_b"->foo();
}
void init()
{
	object me = this_player();
        int level;

/*        if ( this_player()->query_skill("xueshitiao",1) > 0 ) {
                level = me->query_skill("xueshitiao", 1);
                me->delete_skill("xueshitiao");
                me->set_skill("shenkongxing", level);
                me->map_skill("dodge", "shenkongxing");
        }
*/
	if (me->query("class") == "lama"){
        if (me->query_skill("lamaism", 1) < 30
	&& me->query("lama_butter") > 1
	&& me->query("lama_butter") < me->query("mud_age") - 86400){
        me->set("lama_wage",me->query("mud_age") * 2);
	}
        if (me->query_skill("lamaism", 1) > 30 && me->query_skill("lamaism", 1) < 60
	&& me->query("lama_butter") > 0
        && me->query("lama_butter") < me->query("mud_age")){
        me->set("lama_wage",me->query("mud_age") * 2);
        }
	else if (me->query("lama_butter") < 1)
	{me->set("lama_butter", me->query("mud_age") + 7200);}
   }
}
