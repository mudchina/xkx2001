//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "金刚院");
        set("long", @LONG
这里是习武的葛伦布们常来的地方，护寺的萨木活佛就在这里授艺。
前方壁上有一钜形框，内刻梵文："十大自在相"，壁上还点缀得有山水、
楼台壁画。西方是时伦院，北面是后院。
LONG
        );
        set("exits", ([
                "west" : __DIR__"shilun",
                "north" : __DIR__"houyuan",
		"south" : __DIR__"zoulang",
        ]));
	set("objects", ([
                "/kungfu/class/xueshan/samu" : 1,
        ]));

	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (dir =="north" ) {
            if (present("samu huofo", environment(me))) 
            if (!myfam || myfam["family_name"] != "雪山派"
	    && myfam["family_name"] != "血刀门")
                return notify_fail("萨木活佛挡住你说道：後面是本寺高僧修行之地，施主请回。\n");
        
	return 1;
    }
        return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}
