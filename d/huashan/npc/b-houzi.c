//Cracked by Roath
// 华山大猴子
// qfy 27/7/96
//modified by xiaojian to prevent from using it to dig gold
inherit NPC;

void create()
{
        set_name("大马猴", ({"ma hou","hou","monkey"}));
        set("race", "野兽");
        set("age", 10);
        set("long", "一只硕大的马猴。见你看着它，也对你瞪视着。\n");
        set("attitude", "peaceful");
        set("limbs", ({ "头部", "身体",  "前肢", "后腿", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 2000);
        set_temp("apply/attack", 40);
        set_temp("apply/defense",40);
        set_temp("apply/armor", 30);
        set_temp("apply/damage",80);
        set("chat_chance", 12);
        set("chat_msg", ({
                "马猴性躁，跳上纵下，没半刻安宁。\n",
                "马猴摇摇尾巴，伸手扒痒。\n",
                "几只马猴互相追逐跑了过来，又跑开了。\n",
                "马猴抱起了小猴子。\n",
                "马猴高声地叫着。\n",
                (: random_move :)
        }) );
        setup();
}
private void go_home()
{
        if( !living(this_object()) ) return;
        message_vision("$N一蹦一跳地离开了。\n", this_object());
        this_object()->move("/d/huashan/husun");
        message_vision("$N蹦蹦跳跳的蹦了过来。\n", this_object());
}

void init()
{
        string file;

        ::init();
		file = base_name(environment());
        if( strsrch(file, "/d/huashan/") != 0 ) {

                remove_call_out("go_home");
                call_out("go_home", 1);
                }
}

int accept_object(object me, object obj)
{
        object obj2,ob;
		ob = this_object();
        if ( obj->query("food_supply") && obj->value() >= 0 ) {
           message_vision("马猴向$N躬身，咧咀高兴地笑着。\n", me);
           say("马猴狼吞虎咽地吃着,三两下便把"+(string)obj->query("name")+"吃得干干净净。\n");
           me->add("monkey", 1);

           if( (int)me->query("monkey")==15 || (int)me->query("monkey")==25
           || (int)me->query("monkey")==35 || (int)me->query("monkey")==45 ) {
                message_vision("大马猴拉扯$N的衣服，示意$N跟着它。\n", me);
                message("vision", me->name() + "随着大马猴走向深山，左拐右拐地一下子便看不见了。\n", environment(me), ({me}));
                message("vision", "另一只大马猴走了过来。\n", environment(me),({me}));
                write("你随着大马猴在山里走着，东转西转地搞得你迷失了方向。\n");
                write("走了良久，大马猴把你带到一个山洞前，指着洞口要你进去。\n");
                write("紧接着，大马猴便往野林里跑了。\n");
                me->move("/d/huashan/yelin1");
                message("vision",me->name()+"跟着大马猴走了过来。\n", environment(me), ({me}) );
           }

           if ( (int)me->query("monkey") == 50 ) {
                message_vision("大马猴拉扯$N的衣服，示意$N跟着它。\n", me);
                message("vision", me->name() + "随着大马猴走向深山，左拐右拐地一下子便看不见了。\n", environment(me), ({me}));
                message("vision", "另一只大马猴走了过来。\n", environment(me),({me}));
                write("你随着大马猴在山里走着，东转西转地搞得你迷失了方向。\n");
                write("你隐约觉得这次的路线和前几次走过的不同。走了良久，大马猴把你带到\n");
                write("一个山洞里。\n");
                me->delete("monkey");
                me->move("/d/huashan/shandong3");
                message("vision",me->name()+"跟着大马猴走了过来。\n", environment(me), ({me}) );
           }
           
           remove_call_out("destroy_it");
           call_out("destroy_it", 1, obj);
           return 1;
        }
        else {
           say("马猴将"+(string)obj->query("name")+"接了过来，玩弄了几下，似乎不懂有甚么用，便丢下了。\n");
           command("shake");
           if (obj->query("money_id")) {
              obj2 = new(base_name(obj));
              obj2->set_amount((int)obj->query_amount());
              obj2->move(environment(me));
              say("大马猴丢下一些"+(string)obj->query("name")+"。\n");
           }
           remove_call_out("drop_it");
           call_out("drop_it", 1, obj);

        }   
        return 1; 
}

void drop_it(object obj)
{
        command("drop all");
}

void destroy_it(object obj)
{
        destruct(obj);
}
        

