//Cracked by Roath
// Ryu, 12/5/96

inherit ITEM;
#include <ansi.h>;

void init();
void wear(int);

int worn;

void create()
{
        set_name(HIR"一堆火焰"NOR,({"huo yan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR"火焰高约尺，"+GRN+"色作纯碧，"+BLU+"鬼气森森，"+HIR+"和寻常火焰大异。\n"NOR);
                set("unit", "堆");
                set("value", 10000);
                set("no_get", 1);
                set("no_drop", 1);
        }
        
        setup();
}

void init()
{
        worn = 0;
        call_out("wear", 100, 1); 
        add_action("do_kick","ti");
        add_action("do_kick","kick");
}


int do_kick(string arg){

	object ob, me, armor;
	mapping myfam;
	int exp1, exp2;
	me=this_player();
	if( !arg || me != this_player(1)) return 0;
	ob = present(arg, environment(me));  
	
	if(!ob) return notify_fail("这里没有这个生物。\n");
	
	exp1=me->query("combat_exp");
	exp2=ob->query("combat_exp");
	
	if(!ob->is_character() || !me->is_fighting(ob) )
                return notify_fail("只能对战斗中的对手使用。\n");
	
	if (me->is_busy()) return notify_fail("你正忙着呢。\n");
	
	if ((me->query_skill("feixing-shu",1)<150)){
		message_vision(HIR"$N嘻嘻一笑，提起脚来，向火焰踢去，结果一声惨叫，被火焰烧伤。\n"NOR,me);
		me->receive_wound("qi", random(500),"烧死了");
		destruct(this_object());
		me->start_busy(random(2)+2);
		return 1;
	} else {
		

                if( ob->query_temp("armor/cloth")){
			armor = ob->query_temp("armor/cloth");
                	if( armor->query("id") != "armor") {
                     		message_vision(HIY"只见$N身上的$n"+HIY+"被火焰烧得四散而飞。\n"NOR, ob, armor);
                     		armor->unequip();
                     		armor->move(environment(ob));
                     		armor->set("name", "烧焦的" + armor->query("name"));
                     		armor->set("value", 0);
                     		armor->set("armor_prop/armor", 0);
                     		ob->reset_action();
                	}
                }
		
		me->add("neili",-me->query_skill("feixing-shu",1));
		message_vision(RED"$N脸色一变，身形一晃，已经转到$n身后。举起右脚，微微一挑，将火焰向$n拨去。\n"NOR,me,ob);
		me->start_busy(random(2)+2);
		if(random(exp1)>random(exp2)){
			message_vision(HIR"只听见一声惨叫，$n躲闪不及，被火焰烧中。\n"NOR,me,ob);
			ob->receive_wound("qi", me->query_skill("feixing-shu",1),"烧死了");
			ob->start_busy(random(2)+1);
			destruct(this_object());
			return 1;
		} else {
			message_vision(HIY"$n大惊之下闪开，火光下只见$N微微冷笑。\n"NOR,me,ob);
			destruct(this_object());
			return 1;
		}
	}
	
}

void wear(int phase)
{
        worn = phase;
        switch(phase) {
        case 1:
                set("long", HIR"火焰熊熊燃烧着，"+GRN+"色作纯碧，"+BLU+"鬼气森森，"+HIR+"和寻常火焰大异。\n"NOR);
                call_out("wear", 100, phase+1); 
                break;
        case 2:
                set("long", RED"火势越来越弱，几乎快烧完了。\n"NOR);
                call_out("wear", 30, phase+1); 
                break;
        case 3:
                message_vision(RED"火焰渐渐地熄灭了。\n"NOR, this_object());
                destruct(this_object());
                break;
        }       
}

// End of File 
