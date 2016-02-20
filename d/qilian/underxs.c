//Cracked by Roath
// /d/gaibang/underxs.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "雪坑");
        set("long", @LONG
这是大雪山脚下的一个雪坑。丢满了各种杂物， 还有丐帮弟
子收集的破铜烂铁等。坑边上有一个小洞。
LONG
        );
	 switch(random(3)){
	case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        }
	set("exits", ([
		"up" : "d/xueshan/shanlu7",
		"enter":__DIR__"xsandao2",
	]));


	set("cost", 2);
	setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (dir =="enter" ) {
            if (!myfam || myfam["family_name"] != "丐帮")
                return notify_fail("那麽小的洞你专得进去吗？\n");

        return 1;
    }
        return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}



