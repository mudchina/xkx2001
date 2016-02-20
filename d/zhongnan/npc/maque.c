// maque.c 麻雀
// Xuanyuan
#include <room.h>
#include <command.h>
inherit NPC;

void create()
{
        set_name("麻雀", ({ "ma que", "que", "bird" }) );
        set("race", "飞禽");
        set("age", 3);
        set("long", "一只叽叽喳喳，飞来飞去的小麻雀。\n");
        set("attitude", "peaceful");

        set("str", 10);
        set("dex", 100);
        set("combat_exp", 100);
        set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "小麻雀叽叽喳喳的欢叫着，在你头顶上飞来飞去。\n",
                "小麻雀忽而停在墙头，忽而飞上树梢，忙碌着找食吃。\n",
        }) );

        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "小麻雀叽叽叽地怒叫着，全身的羽毛都抖竖起来！\n",
        }) );

        setup();
}

void init()
{
        add_action("do_catch", "zhuo");
        add_action("do_catch", "zhua");
        add_action("do_catch", "catch");
        add_action("do_flee", "fang");
        add_action("do_flee", "throw");
}

int do_catch(string arg)
{
        object room, dest, me = this_player(), ob = this_object();
        string dir, *dirs;
        mapping exits;
        int ap;

        if( !living(me) ) return 0;

        if( !arg || !(arg == "ma que" || arg == "que" || arg == "bird") )
                return notify_fail("你要抓什么？\n");

        if( present(arg, environment(me)) != ob )
                return notify_fail("");

        if( !living(ob) )
                return notify_fail("还用得着抓吗?\n");

        if( environment(ob) == me )
                return notify_fail("你已经抓住它了。\n");

//      if( environment(ob) != find_object("/d/gumu/gmlg1") )
//              return notify_fail("这儿不是练抓麻雀的地方。\n");

	if( me->query("family/family_name") != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");

	if ( (int)me->query_skill("dodge", 1) > 101 )
		return notify_fail("你不用在这里浪费时间精力了。\n");

        if ( (int)me->query("qi") < 60 && (int)me->query("jing") < 40 )
                return notify_fail("你太累了, 先休息一下。\n");

	message("\n$N突然向$n扑去。\n", me, ob);

        me->receive_damage("jing", 10 + random(10), "精神透支过度死了");
        me->receive_damage("qi", 20 + random(10), "体力透支过度死了");

        ap = (int)me->query_skill("force") + (int)me->query_skill("dodge");
        if( ap < 1 ) ap = 1;
        ap = ap * me->query_dex() / 20;
        ap = random(ap);

        if( ap < 10 ) {
                message_vision("结果$N轻轻一展翅，飞到了半空。\n", ob);
                room = environment(me);
                if( !mapp(exits = room->query("exits")) )  return 1;

                dirs = keys(exits);
                for( int i = 0; i < sizeof(dirs); i ++ )
                        if( room->query_door(dirs[i], "status") & DOOR_CLOSED )
                          dirs -= ({dirs[i]});
                if( sizeof(dirs) < 1 ) return 1;
                dir = dirs[random(sizeof(dirs))];

                message_vision("$N一转眼便从你的视野中消失了。\n", ob);
                GO_CMD->main(ob, dir);

                dest = find_object(exits[dir]);
                message_vision("$N往" + dir + "方向飞走了。\n", ob);
                ob->move(dest);
                message_vision("$N叽叽喳喳地飞了过来。\n", ob);


        } else if( ap < 20 ) {
                message_vision("结果$N惊叫了一声，飞了开去。\n", ob);
        } else {
                message_vision("结果$N一下子便抓住了$n。\n", me, ob);
                ob->move(me);
                ob->set_temp("chat_msg", ob->query("chat_msg"));
                ob->delete("chat_msg");
                me->improve_skill("dodge", me->query("dex",1));

		if(me->query_skill("tianluo-diwang", 1) > 0) 
                	me->improve_skill("tianluo-diwang", me->query("dex",1)/2);

		me->add("combat_exp",1+random(2));
        }

        return 1;
}

int do_flee(string arg)
{
        object me = this_player();
        object ob = this_object();

        if( !living(me) ) return 0;

        if( !arg || !(arg == "ma que" || arg == "que" || arg == "bird") )
                return notify_fail("你要放什么？\n");

        if( present(arg, me) != ob )
                return notify_fail("");

        message_vision("$N将手一松，$n欢叫着飞开了。\n", me, ob);

        ob->move(environment(me));
        ob->set("chat_msg", ob->query_temp("chat_msg"));
        ob->delete_temp("chat_msg");

        return 1;
}