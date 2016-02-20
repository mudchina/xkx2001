//Cracked by Kafei
// lifeheal.c

#include <ansi.h>
void over(object,object);
void over1(object,object);
void over2(object,object);
void over3(object,object);
void over4(object,object);
void over5(object,object);
void over6(object,object);
void over7(object,object);
void over8(object,object);
int exert(object me, object target)
{
	object obj, old_target;
        object *ob;
        mapping myfam;

	if( !target )
		return notify_fail("你要用真气为运阴进？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运阴进，你找死么！\n");

	if( !living(target) )
		return notify_fail(target->name() + "已经无法和你运功练功了。\n"); 

	if( !userp(target) )
		return notify_fail("只能在玩家之间互相修炼玉女心经。\n");

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "古墓派") )
                  return notify_fail("只有古墓弟子之间才能运用玉女心经合修。\n");

//	if( me->query_temp("gumu/yinjin") )
//		return notify_fail("你已经在运功练功了。\n");

        if( me->query("gender") =="无性" )
                return notify_fail("你已经领悟不了玉女心经中的种种阴阳变化了。\n");

	if( (int)me->query_skill("yunu-xinjing", 1) < 20 )
		return notify_fail("你的玉女心经火候太低，无法相助他人练功。\n");

	if( (int)me->query_skill("yunu-xinjing", 1) > (int)target->query_skill("yunu-xinjing", 1) * 2 )
		return notify_fail("对方的玉女心经火候太低，无法相助你练功。\n");

        if ( me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("你没有激发玉女心经到内功上！\n"); 

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的真气不够。\n");

        if( target->query_condition("huaiyun") > 0)
                return notify_fail("对方在怀孕中，强行运功练习会伤及胎儿！\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi")  )
		return notify_fail( target->name() +"已经受伤，经受不起你的真气震荡！\n");

	if(target==me)	return notify_fail("你不能为自己运功练功。\n");

	if( userp(target) && (object)target->query_temp("pending/yunu-xinjing")!=me ) {
		message_vision("\n$N对著$n说道：我已经准备好运功修习玉女心经。\n\n", me, target);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "取消了和你练功的念头。\n" NOR);
		me->set_temp("pending/yunu-xinjing", target);
		tell_object(target, YEL "如果你愿意和对方同时运功修练，请你对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 yun yangtui 指令。\n" NOR);
		write(YEL "由于对方是由玩家控制的人物，你必须等对方同意才能开始练功。\n" NOR);
		return 1;
	}

	else {
		message_vision("\n$N把修习玉女心经的口诀法门说了一段，$n听了点点头盘膝坐定准备运功。\n\n", me, target);
		target->delete_temp("pending/yunu-xinjing");
		me->set_temp("gumu/yinjin", 1);
		me->start_busy(10);
		call_out("over", 1, target,me);
	} 
	return 1;
}
void over(object me,object obj)
{
        message_vision(WHT"$N气运丹田，左臂伸出，于$n右掌相抵。\n"NOR,me,obj);

	if(me->query("qi")<99||me->query("jing")<99) {
                        message_vision(HIR "$N突然口吐鲜血，晕倒在地。看来是体力透支过度了。\n"NOR,me);
			me->receive_damage("qi", 60, "体力透支过度死了");
                        me->unconcious();
	}
	if(obj->query("qi")<99||obj->query("jing")<99) {
                        message_vision(HIR "$N突然口吐鲜血，晕倒在地。看来是体力透支过度了。\n"NOR,obj);
			obj->receive_damage("qi", 60, "体力透支过度死了");
                        obj->unconcious();
	}
				me->start_busy(3);
				obj->start_busy(3);
                                call_out("over1", 3, me,obj);
}
void over1(object me,object obj)
{
                message_vision(HIY "$N运起阳退内力，将$n的阴进耐力引入自身，阴进内力在$N
的体内运行了一个周天，渐渐开始返回$n。\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over2", 30, me,obj);
}

void over2(object me,object obj)
{
                message_vision(HIY "$N的阳退内力在阴进内力返还的同时也自行导入$n体内，这股
真气在$n体内过紫宫，走泥丸，穿十二重楼，循环于全身诸穴。\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(03);
                call_out("over3", 30, me,obj);
}

void over3(object me,object obj)
{
                message_vision(HIR "$N于$n的真气在对方的体内游走不定，自转不息，约摸一顿饭
的功夫，$N于$n具是燥热无比，气血沸腾，汉如雨下。\n"NOR,me,obj);

/*
		if( objectp(cloth = present(arg, me)) || cloth->query("equipped")){
                message_vision(HIR "$N只觉得浑身燥热不安，原来是身上还穿有衣衫，热气不能立时发散郁积体内。\n"NOR,me);
                message_vision(HIR "$N突然口吐鲜血，晕倒在地。\n"NOR,me);
		me->receive_damage("qi", 1000, "练功走火入魔死了");
		me->receive_damage("jing", 1000, "练功走火入魔死了");
		return 1;
		}

		if( objectp(cloth = present(arg, obj)) || cloth->query("equipped")){
                message_vision(HIR "$N只觉得浑身燥热不安，原来是身上还穿有衣衫，热气不能立时发散郁积体内。\n"NOR,obj);
                message_vision(HIR "$N突然口吐鲜血，晕倒在地。\n"NOR,obj);
		obj->receive_damage("qi", 1000, "练功走火入魔死了");
		obj->receive_damage("jing", 1000, "练功走火入魔死了");
		return 1;
		}
*/
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over4", 30, me,obj);
}

void over4(object me,object obj)
{
                message_vision(HIW "又过了一会儿，只见二人全身热气蒸腾，头上升出丝丝白气。
二人练功至此以是高潮，周围雾气缭绕。\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over5", 30, me,obj);
}
void over5(object me,object obj)
{
                message_vision(HIM "再过一会儿，两人周身蒸汽渐散，$N的阳退内力缓缓流回自
身，散入任督脉络之中。\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over6", 30, me,obj);
}
void over6(object me,object obj)
{
                message_vision(MAG "$n仍然继续运功调整，虽不如刚才那般大汉淋漓，但依旧是
眉头紧锁，其时半点马虎不得。\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over7", 30, me,obj);
}
void over7(object me,object obj)
{
                message_vision(YEL "又是一盏茶的功夫，$n嘴脚微抬，口中吐出一口白气，混合
了阳退内力的真气慢慢贮于丹田之中，运功将止。\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over8", 30, me,obj);
}
void over8(object me,object obj)
{
                message_vision("这时两人周身的热气已尽数散去，$n缓缓睁开眼，对$N会心一笑。\n",me,obj);
		me->improve_skill("force", me->query_con()+random(me->query_skill("yunu-xinjing", 1))*50);
		me->improve_skill("yunu-xinjing", me->query_con()+random(me->query_skill("force", 1))*50);
                me->add("max_neili",  random(2));
                me->add("max_jingli",  random(2));
		me->start_busy(30);
		obj->start_busy(30);
		me->delete_temp("gumu/yinjin");

		if (obj->query_skill("yunu-xinjing", 1) < 61)
		obj->set("request/yunu",obj->query_skill("yunu-xinjing", 1)/20+1);

		if (me->query_skill("yunu-xinjing", 1) < 120 && obj->query_skill("yunu-xinjing", 1) > 61)
		obj->set("request/yunu",obj->query_skill("yunu-xinjing", 1)/10+1);

		if (me->query_skill("yunu-xinjing", 1) > 120)
		obj->set("request/yunu", obj->query_skill("yunu-xinjing", 1)/5+1);
}