//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "洞口");
        set("long", @LONG
这是一个小小的山洞，血刀老祖的藏身之地。由於此地
比较隐秘，仇家很难寻到这来。洞底有一张供桌，上面供了
什麽东西，你看不清。
LONG
        );
        set("exits", ([
                "out" : __DIR__"cave1",
        ]));
	set("objects", ([
		"/d/qilian/npc/xlama" : 1,
                "/kungfu/class/xuedao/laozu" : 1,
        ]));

	set("cost", 2);
        setup();
}
/*int valid_leave(object me, string dir)
{
        if (dir =="out" ) {
        if (present("liu chengfeng", environment(me))
        ||present("liu chengfeng", me) ) 		
                return notify_fail("血刀老祖向你大声喝道：刘承风不杀，留着干什麽？\n");
        return 1;
    }
        return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}
*/
int valid_leave(object me, string dir)
{
        if (dir =="out" && this_player()->query_temp("jidao", 1) > 0)
        return
notify_fail("血刀老祖发出一阵阴笑：人还没替我杀完，你就想走？\n");
return ::valid_leave(me, dir);
set("no_clean_up", 0);

}

