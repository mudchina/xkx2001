//Cracked by Roath
// pianting2.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "偏厅");
        set("long", @LONG
这是华山内院的偏厅。厅里摆设简单，只有一张桌子和几张椅子，墙
上挂着几幅图画。厅子的东西边各为练功房，是华山弟子静坐练功的地方。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"zoulang1",
            "south" : __DIR__"buwei2",
            "east" : __DIR__"liangong1",
            "west" : __DIR__"liangong2", 
        ]));

        set("objects", ([ 
            CLASS_D("huashan") + "/zhongze" : 1,
        ]));

        set("no_clean_up", 0);

        set("valid_startroom",1);

        set("cost", 0);
        setup();
}

void init()
{
        object ob, me=this_player();
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ( (!myfam || myfam["family_name"] != "华山派") && !me->query_temp("bai_ning")
           && ob=present("ning zhongze", environment(me)) ) {
                message_vision("$N怒斥道：你是何人？怎麽闯入这里来了？快走！\n", ob);
        }

        add_action("do_kill","kill");
        add_action("do_hit","hit");
	add_action("do_throw","throw");
}

int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;

        if ( ob->query("family/family_name") == "华山派" && me->query("family/family_name") != "华山派" ) {
           message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);    
        
           if ( ob1=present("ning zhongze", environment(me)) ) {
                message_vision("$N怒斥道：岂有此理！竟敢在华山上撒野，意图行凶杀人！\n", ob1);
                ob1->kill_ob(me);
                return 1;
           }

           return 0;
        }
        else if ( ob->query("family/family_name") == "华山派" && ob->query("id") != "yue buqun" 
        && ob->query("id") != "ning zhongze" && me->query("family/family_name") == "华山派" ) {
           message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);

           if ( ob1=present("ning zhongze", environment(me)) ) {
                message_vision("$N气极骂道：自己同门竟自相残杀！都给我到思过崖去好好面壁反省！\n", ob1);
                return 1;
           }

           return 0;
        }

        return 0;
}

int do_hit(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;

        if ( ob->query("family/family_name") == "华山派" && me->query("family/family_name") != "华山派" ) {
           message_vision("$n对著$N大喝一声：看招！\n",ob, me);

           if ( ob1=present("ning zhongze", environment(me)) ) {
                message_vision("$N怒斥道：岂有此理！竟敢在华山上撒野，意图行凶杀人！\n", ob1);
                ob1->kill_ob(me);
                return 1;
           }

           return 0;
        }
        else if ( ob->query("family/family_name") == "华山派" && ob->query("id") != "yue buqun"
        && ob->query("id") != "ning zhongze" && me->query("family/family_name") == "华山派" ) {
           message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", ob, me);

           if ( ob1=present("ning zhongze", environment(me)) ) {
                message_vision("$N气极骂道：自己同门竟自相残杀！都给我到思过崖去好好面壁反省！\n", ob1);
                return 1;
           }

           return 0;
        }

        return 0;
}

int do_throw(string arg)
{
	object victim, ob1, ob, me = this_player();
	string what, who;

	if( !arg
        ||      sscanf(arg, "%s at %s", what, who)!=2)
                return notify_fail("命令格式: throw <物品> at <某人>。\n");

	ob = present(what, me);
        if( !ob ) ob = present(arg, environment(me));
	if( !ob ) return notify_fail("你要扔什么？\n");

        if (ob->query("no_drop"))
                return notify_fail("这个东西不能离开你。\n");

        if (!(victim = present(who, environment(me))))
                return notify_fail("这里没有你的目标。\n");

        if (!victim)
                return notify_fail("这里并无此人！\n");

        if (!living(victim))
                return notify_fail("这不是活物！\n");
	
	if ( victim->query("family/family_name") == "华山派" && me->query("family/family_name") != "华山派" ) {
	   message_vision("$n对著$N大喝一声：看招！\n",victim, me);

	   if ( ob1=present("ning zhongze", environment(me)) ) {
		message_vision("$N一声冷笑：大胆狂徒！竟敢在华山上偷袭伤人，当我华山派好欺负么？\n", ob1);
		ob1->kill_ob(me);
		return 1;
	   }

	   return 0;
	}
	else if ( victim->query("family/family_name") == "华山派" && victim->query("id") != "yue buqun"
	&& victim->query("id") != "ning zhongze" && me->query("family/family_name") == "华山派" ) {
	   message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活！」\n", victim, me);

	   if ( ob1=present("ning zhongze", environment(me)) ) {
		message_vision("$N气得大骂：真是越来越有出息了！自己同门竟自相残杀！给我都到思过崖去面壁！\n", ob1);
		return 1;
	   }

	   return 0;
	}

	return 0;
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ( (!myfam || myfam["family_name"] != "华山派") && dir != "north" 
           && present("ning zhongze", environment(me)) ) {
                return notify_fail("宁中则拦在你身前斥道：外人不能随易出入本派重地！还不快给我离开？\n");
        }

        return ::valid_leave(me, dir);
}