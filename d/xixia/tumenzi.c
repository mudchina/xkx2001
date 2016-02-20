//Cracked by Roath
// Room: /d/xixia/tumenzi.c

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "土门子");
	set("long", @LONG
土门子也是以前驻军的地方，周围全是沙漠，中间一块小小的绿洲，本来这
里有当地的牧民居住，可是前不就来了一伙马贼占据了这里以这里为大本营四出
劫掠，无恶不做。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"shixiazi",
  "south" : __DIR__"weiwu",
]));
	setup();
}
void init()
{
        object ob, robber, *inv, me=this_player();
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("value") >= 10000
                && !inv[i]->query("money_id")) j++;
        }
        if (j>0) me->set_temp("rob_victim", 1);

        if ( interactive(ob=this_player())
        && me->query_temp("rob_victim") && random(3)==1) {

                message_vision(HIR"突然一个大汉由西边的树林跳了出来，拦住了$N。\n"NOR, me);
	 robber = new(__DIR__"npc/mazei");
                robber->move(environment(ob));
        }
}
int valid_leave(object me, string dir)
{
        if ( me->query_temp("rob_victim") && present("ma zei", environment(me) ))
                return notify_fail("马贼凶巴巴地叫道：放聪明点，快将宝贝交出来！ \n");
        else { me->delete_temp("rob_victim"); }

        return ::valid_leave(me, dir);
}
