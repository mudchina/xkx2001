//Cracked by Roath
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "长廊");
        set("long", @LONG
一条略显阴暗的长廊，长廊一侧是一溜排开的转经轮，另一侧
顺序点着一排酥油灯。昏黄的灯光在影子里摇弋，发出温暖的香气，
几个喇嘛来回逡迅着往灯里加着酥油，再往北走就是大殿了。
LONG
        );
        set("exits", ([
                "north" : __DIR__"dadian",
				"south" : __DIR__"dumudian",
        ]));

        set("objects", ([
                __DIR__"npc/jlseng" : 2,
        ]));

        set("cost", 1);
        setup();
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

   if (dir =="north" ) {

        if (present("jielv seng", environment(me))) {
            if (!myfam || myfam["family_name"] != "雪山派"
            && myfam["family_name"] != "血刀门" )
                return notify_fail("戒律僧挡住你说：后面乃本寺重地，请回吧！\n");
        }
   }
   if (dir =="south" ) {
        if (present("jielv seng", environment(me))) {
			if (present("juan na xiang", this_player())) {
                 if (myfam["family_name"] == "雪山派" ||
                     myfam["family_name"] == "血刀门") 
                        return notify_fail("戒律僧挡住你说：身为本门第子，竟敢拿捐纳箱，还不快放回去！\n");
				 else
                        return notify_fail("戒律僧嘿嘿干笑两声，说道：拿了我们佛爷的宝贝还想走？\n");
			}
		}
   }
   return ::valid_leave(me, dir);
}

