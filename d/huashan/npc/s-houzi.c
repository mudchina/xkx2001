//Cracked by Roath
// 华山小猴子
// qfy 27/7/96
//modified by xiaojian to prevent using it to dig gold 09/9/00
inherit NPC;

void create()
{
        set_name("小猴子", ({"hou zi","hou","monkey"}));
        set("race", "野兽");
        set("age", 2);
        set("long", "一只可爱的小猴子，见你望着它，逃开离你远些向你回望。\n");
        set("attitude", "peaceful");
        set("limbs", ({ "头部", "身体",  "前肢", "后腿", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 500);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 8);
        set_temp("apply/damage", 4);
        set_temp("apply/armor", 3);
        set("chat_chance", 10);
        set("chat_msg", ({
                "一只小猴子忽然跑过来，向你作了个揖。\n",
                "小猴子摇了摇尾巴。\n",
                "几只小猴子蹦蹦跳跳地跑过来，又互相追逐离去。\n",
                "小猴子在你的脚边挨挨擦擦，想跟你玩。\n",
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
        object obj2;
                
        if ( obj->query("food_supply") && obj->value() >= 0 ) {
           command("drop"+obj->query("id"));
           message_vision("小猴子高兴地绕着$N蹦蹦跳跳。\n", me);
           set_leader(me);
           say("小猴子三两下便把"+(string)obj->query("name")+"吃得干干净净。\n");
           me->add("monkey", 1);

           if( (int)me->query("monkey")==15 || (int)me->query("monkey")==25 
           || (int)me->query("monkey")==35 || (int)me->query("monkey")==45 ) {
                message_vision("小猴子拉扯$N的衣服，示意$N跟着它。\n", me);
                message("vision", me->name() + "随着小猴子走向深山，左拐右拐地一下子便看不见了。\n", environment(me), ({me}));
                message("vision", "另一只小猴子跑了过来。\n", environment(me), ({me}));
                write("你随着小猴子在山里走着，东转西转地搞得你迷失了方向。\n");
                write("走了良久，小猴子把你带到一个山洞前，指着洞口要你进去。\n");
                write("紧接着，小猴子便往野林里跑了。\n");
                me->move("/d/huashan/yelin1");
                message("vision",me->name()+"跟着小猴子走了过来。\n", environment(me), ({me}) );
           }    


           if ( (int)me->query("monkey") == 50 ) {
                message_vision("小猴子拉扯$N的衣服，示意$N跟着它。\n", me);
                message("vision", me->name() + "随着小猴子走向深山，左拐右拐地一下子便看不见了。\n", environment(me), ({me}));
                message("vision", "另一只小猴子跑了过来。\n", environment(me), ({me}));
                write("你随着小猴子在山里走着，东转西转地搞得你迷失了方向。\n");
                write("你隐约觉得这次的路线和前几次走过的不同。走了良久，小猴子把你带到\n");
                write("一个山洞里。\n");
                me->delete("monkey");
                me->move("/d/huashan/shandong3");
                message("vision",me->name()+"跟着小猴子走了过来。\n", environment(me), ({me}) );
           }

           remove_call_out("destroy_it");
           call_out("destroy_it", 1, obj);              
           return 1;
        }
        else {
           say("小猴子将"+(string)obj->query("name")+"接了过来，玩弄了几下，似乎不懂有甚么用。\n");
           command("shake");
           if (obj->query("money_id")) {
              obj2 = new(base_name(obj));
              obj2->set_amount((int)obj->query_amount());
              obj2->move(environment(me));
              say("小猴子丢下一些"+(string)obj->query("name")+"。\n");
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
