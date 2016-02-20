//Cracked by Roath
// Room: /d/taishan/baihe.c
// Date: CSWORD 96/03/25
// Modified by qfy August 24, 96.

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "白鹤泉");
	set("long", @LONG
相传从前这里有一个白鹤泉，它的水清凉甘甜，为泰山之最。这泉水长年涌
流不断，喷出的水像仙鹤扑扇着翅膀洗澡一样，因以为名。可惜后来有一个自私
自利的小官，独霸了泉水，后来更因迷信风水之说，把泉眼堵塞，白鹤泉从此便
干涸了。现在只剩下一座刻着「白鹤泉」三字的石坊以为纪念。从这里继续北上，
便是上山之路。
LONG
	);

	set("exits", ([
		"northup" : __DIR__"yitian",
		"southdown" : __DIR__"daizong",
	]));

	set("resource/water",1);
	set("outdoors", "taishan");
	set("cost", 4);
	setup();
//	replace_program(ROOM);
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

        if ( interactive(ob=this_player()) && ob->query_temp("biao/ma")
        && present("hong biao", ob) && random(3)==1
        || me->query_temp("rob_victim") && random(5)==1) {
                message_vision(HIR"突然一个大汉从石坊后闪了出来拦住$N，竟是一个山贼！\n"NOR, ob);
		robber = new(__DIR__"npc/shanzei");
                robber->move(environment(ob));
        }
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("biao/ma") && present("shan zei", environment(me) )
        || me->query_temp("rob_victim") && present("shan zei", environment(me)))
		return notify_fail("山贼大吼道：赶快将宝贝交出来，不然你就别指望活着离开！\n");
	else { me->delete_temp("rob_victim"); }

	return ::valid_leave(me, dir);
}
