//Cracked by Roath
// emroad2.c 小路
// Shan: 96/06/22

inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", "小路");
        set("long", @LONG
这是四川与湖北的交界。一条静悄悄的小土路，两旁有疏疏落落的农舍耕
田，但路上行人很少，都匆匆赶路。
LONG
        );
        set("exits", ([
		"northeast" : __DIR__"emroad3",
                "west" : __DIR__"emroad1",
        ]));

/*        set("objects", ([
                __DIR__"npc/xiao_tufei": 1,
        ]) );
*/
        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 1);
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
	&& me->query_temp("rob_victim") && random(5)==1) {

                message_vision(HIR"突然一个大汉由西边的树林跳了出来，拦住了$N。\n"NOR, me);
                robber = new(__DIR__"npc/rob_tufei");
                robber->move(environment(ob));
        }
}
int valid_leave(object me, string dir)
{
        if ( me->query_temp("rob_victim") && present("tu fei", environment(me) ))
                return notify_fail("土匪凶巴巴地叫道：放聪明点，快将宝贝交出来！\n");
        else { me->delete_temp("rob_victim"); }

        return ::valid_leave(me, dir);
}
