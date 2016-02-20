//Cracked by Roath
//By haowen  1/15/1999 

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name("雪蚕丝", ({"xuecan si", "can si","cansi"}));
        set_weight(80);
        set_max_encumbrance(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "这是一根雪蚕丝，是星宿海旁的雪蚕所吐之丝。雪蚕形体远较冰蚕为小，也无毒性，
吐出来的蚕丝却韧力大得异乎寻常，一根单丝便已不易拉断。\n");
                set("unit", "根");
                set("value", 0);
                set("busy_source", random(5)+1);
        }
}
void init()
{
        add_action("do_shou", "shou");
        add_action("do_shou", "catch");
//        add_action("do_fang", "fang");
//	add_action("do_fang", "release");
}
int do_shou(string arg)
{
        object  env,*inv,target,ob,me=this_player();
	int i;
	ob=this_object();
	env=environment(me);
	inv=all_inventory(env);
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]==me) continue;
		if(!me->visible(inv[i])) continue;
		if (inv[i]->query("id")==arg)
			target=inv[i];
		}
        if (!target) 
		return notify_fail("你想收谁？\n");
        
	if(target==me)
		return notify_fail("你不能收自己！\n");

//	if(!userp(target))
//		return notify_fail("你只能收玩家！\n");
	
        if(!me->is_fighting() || !target->is_fighting() || !living(target))
                return notify_fail("你必须在战斗中才能使用雪蚕丝！\n");

        if(me->query_skill("feixing-shu",1)<30)
		return notify_fail("以你现在的暗器功力恐怕用不了雪蚕丝！\n");

	if(me->is_busy())
		return notify_fail("你现在无法做任何动作！\n");

	if(target->is_busy())
		return notify_fail(target->query("name")+"正自顾不暇，放手攻击吧！\n");
   
        message_vision( HIY "$N狂笑几声，手中似乎有什么东西向$n撒去。\n" NOR,me,target);
        if(random(me->query_skill("feixing-shu",1)) > random(target->query_skill("dodge",1)))
		{
		 tell_object(target,HIR "你忽然觉得一条细线缠上全身，手脚都已经不受控制！\n" NOR);
		 tell_object(me,HIG "你手中一紧，心中暗喜，看来已经得手了！\n" NOR);
		 target->start_busy(ob->query("busy_source"));
//                 me->start_busy(1);
                }
	else {
		message_vision(HIY "$n闪身一跃，避开了$N手中的东西！\n" NOR,me,target);
                tell_object(me,HIG "你赶紧反手一扣，收回了雪蚕丝。\n" NOR);
                me->start_busy(2);
	     }		
	me->add("neili",-50);
	return 1;
}

