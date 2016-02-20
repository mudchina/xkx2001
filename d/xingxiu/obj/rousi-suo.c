//Cracked by Roath
// /d/xingxiu/obj/rss.c
// haowen mar 31st 1999
inherit ITEM;
//inherit F_AUTOLOAD;
#include <ansi.h>;
void create()
{
        set_name("柔丝索", ({"rousi suo", "rope", "suo"}));
        set_weight(80);
        set_max_encumbrance(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "这就是星宿三宝之一的柔丝索，以星宿海旁的雪蚕之丝制成。
那雪蚕野生于雪桑之上，形体远较冰蚕为小，也无毒性，吐出来的蚕丝却韧力大得异乎
寻常，一根单丝便已不易拉断。此宝物可以用来抓(catch),放(release)人物。\n");
                set("unit", "根");
                set("value",0);
                set("no_sell", 1);
                set("no_beg", 1);
                set("no_get", 1);
                set("no_steal", 1);
        }
}
void init()
{
	mapping myfam;
	myfam=this_player()->query("family");
	if(myfam["family_name"] == "星宿派"){
        	add_action("do_shou", "shou");
        	add_action("do_shou", "catch");
        	add_action("do_fang", "fang");
       		add_action("do_fang", "release");
        	add_action("do_look", "look");
        	add_action("do_look", "l");
//      	add_action("do_quit", "quit");
	}
}
/*int do_quit()
{
        if (!this_object()->query("catched"))
                {command("quit");
                return 1;}
        else    return notify_fail("你现在不能退出游戏！\n");
}*/

int do_shou(string arg)
{
        object env,*inv, ob,target,victim,me=this_player();
        int i;
        env=environment(me);
        inv=all_inventory(env);
        for (i=0;i<sizeof(inv);i++){
                if (inv[i]==me) continue; 
                if (!me->visible(inv[i])) continue;
                if (inv[i]->query("id")==arg)
                        target=inv[i];
                }
        ob=this_object();
        if (!target) 
                return notify_fail("你想收谁？\n");
        
        if(target==me)
                return notify_fail("你不能收自己！\n");

        if(!userp(target))
                return notify_fail("你只能收玩家！\n");
                
        if( environment(me)->query("no_fight") ) 
        	return notify_fail("你不能在这里用柔丝索。\n");
        /*
        if(!me->is_fighting() || !target->is_fighting() || !living(target))
                return notify_fail("你必须在战斗中才能使用柔丝索！\n");
        */
        
        if(ob->query_temp("catched"))
                {
                victim=find_player(ob->query_temp("catched"));
                if (victim && environment(victim)->query("short")=="柔丝索中")
                        return notify_fail("柔丝索已经收了人，恐怕收不下别人了！\n");

                else {ob->delete_temp("catched");
                        ob->delete("no_drop");}
                }
        if(me->is_busy())
                return notify_fail("你现在正忙着呢！\n");
                      
   
        message_vision( HIY "$N狂笑几声，手中似乎有什么东西向$n撒去。\n" NOR,me,target);
        if(random(me->query_skill("feixing-shu",1)+me->query("neili")+me->query("combat_exp")/1000) > random(target->query_skill("dodge",1)+target->query("neili")+target->query("combat_exp")/1000))
                {

			tell_object(target,HIR"你忽然觉得千百条细线缠住全身，手脚都已经不受控制！\n"NOR);

			tell_object(me,HIG"你手中一紧，心中暗喜，看来已经得手了！\n"NOR);
        		message_vision(HIY"$N闪避不及，忽然被无形的东西网住全身，动弹不得。\n" NOR, target);
                 	ob->set("no_drop",1);
                 	ob->set_temp("catched",target->query("id"));
                 	target->set_temp("current_catcher",me->query("id"));
                 	target->move("/d/xingxiu/rousiroom");
                }
        else {
                	message_vision(HIY "$n闪身一跃，避开了$N手中的东西！\n" NOR,me,target);
                	me->start_busy(random(5)+1);
        }          
        
        me->add("neili",-200);
        return 1;
}

int do_fang(string arg)
{
        object ob,target,victim,me=this_player();
        int i;
        string temp;
        ob=this_object();
        if(!ob->query_temp("catched"))
                return notify_fail("柔丝索并没有收住任何人！\n");

        victim=find_player(ob->query_temp("catched"));
        target=find_player(arg);
 
        if (!target) 
                return notify_fail("你想放谁？\n");
        
        if(target==me)
                return notify_fail("你不能放自己！\n");

        if(!userp(target))
                return notify_fail("你只能放玩家！\n");
                        
        
        if(!target->query_temp("current_catcher") || target->query_temp("current_catcher")!=me->query("id"))
                return notify_fail(target->query("name")+"没有被你收住！\n");

        if(!victim || environment(victim)->query("short")!="柔丝索中" )
                {
                 ob->delete_temp("catched");
                 ob->delete("no_drop");
                 return notify_fail("柔丝索并没有收住任何人！\n");
                }
        message_vision(HIR "$N举手一扬，似乎有一条白线回到$N的袖中。\n" NOR,me);
        message_vision(HIY "$N忽然间束缚全无，即刻活动起来。\n"NOR,target);

        tell_object(target,HIR"你左冲右突，忽然浑身一轻，已经摆脱了束缚！\n" NOR);
        target->delete_temp("current_catcher");
        ob->delete_temp("catched");
        ob->delete("no_drop");
        target->move(environment(me));
        return 1;
}
int do_look(string arg)
{
        object ob,victim;

        ob=this_object();
 
        if( !arg || arg == "" ) return 0;

        if( present(arg, this_player()) != ob ) return 0;

        if( ob->query_temp("catched")) 
                {
                victim=find_player(ob->query_temp("catched"));
                if(environment(victim)->query("short")=="柔丝索中")
                {
                tell_object(
this_player(),"这就是星宿三宝之一的柔丝索，以星宿海旁的雪蚕之丝制成。
那雪蚕野生于雪桑之上，形体远较冰蚕为小，也无毒性，吐出来的蚕丝却韧力大得异乎
寻常，一根单丝便已不易拉断。此宝物可以用来抓(catch),放(release)人物。\n"+"现在里面正束缚着"+
victim->query("name") +"\n");
                return 1;}
                else {ob->delete_temp("catched");
                        ob->delete("no_drop");}
                }               
                tell_object(
this_player(),"这就是星宿三宝之一的柔丝索，以星宿海旁的雪蚕之丝制成。
那雪蚕野生于雪桑之上，形体远较冰蚕为小，也无毒性，吐出来的蚕丝却韧力大得异乎
寻常，一根单丝便已不易拉断。此宝物可以用来抓(catch),放(release)人物。\n");
       return 1;
}
