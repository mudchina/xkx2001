//Cracked by Roath
// persuade.c
// xuy@xkx

#include <ansi.h>

inherit F_CLEAN_UP;

string *persuade_msg = ({
        "得饶人处且饶人，施主还是罢手不斗了吧！\n", 
        "别打了，有话好说，不要这般蛮横！\n",
        "两位休得伤了和气，不要再斗下去了吧！\n",
        "阿弥陀佛，大家江湖人士，怎地就动起粗来？两位还是住手吧！\n",
        "住手罢，大家无冤无仇，何必失了武林中的和气？\n",
        "多个朋友多条路, 两位何不化干戈为玉帛, 停手罢斗化敌为友呢？\n",
        "比武较量要点到为止，何必苦苦相斗，枉自伤了自家性命？\n",
});
string *succeed_msg = ({
        "良言相劝，暂且罢手。\n",
        "在此相劝，看在人家的面子上，这次就算了。\n",
});

int main(object me, string who)
{
	object target;
	mapping myfam;
	int age, pp, dp, myexp, yourexp;
	mixed busy;

	object where = environment(me);

	seteuid(getuid());

	if ( !(myfam = me->query("family")) || myfam["family_name"] != "峨嵋派")
		return notify_fail("你想劝人罢斗，可是人家不理睬你。\n");
//		return notify_fail("你非大乘佛教中人，不善劝人罢斗。\n");

	if ( !who ) return notify_fail("指令格式：persuade <人物>\n");

	target = present(who, environment(me));
	if ( !target || target == me || !living(target) || !objectp(target) ) 
		return notify_fail("你想劝服谁？\n");

	if ( busy = me->query_busy() ) {
		if (intp(busy)) me->start_busy(busy+1);
		return notify_fail("你现在正忙着！\n");
	}

	if ( target->query("race") != "人类" )
		return notify_fail(target->name() + "听不懂人话！\n");

	if ( target->query("winner"))
		return notify_fail("什么？\n");

	if ( me->query_temp("persuading") )
		return notify_fail("你正在劝服别人！\n");

	if ( !target->is_fighting() ) 
		return notify_fail(target->name() + "没在打架，不用你操心！\n");

        if ( target->query_temp("yield") )
		return notify_fail(target->name() + "打不还手，还是去劝劝" + 
			gender_pronoun(target->query("gender")) + "的对手吧。\n");

	if ( target->query_temp("persuading") == me->query("id")) 
		return notify_fail(target->name() + "正在开导你，想通了就自己先罢斗。\n" + NOR);

	if ( target->query_temp("last_persuader") == me->query("id") ) {
		me->start_busy(1);
		return notify_fail("你刚劝服过" + gender_pronoun(target->query("gender"))
				+ "，想必这次不会再听你劝了。\n");
	}

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 40 
	 || (int)me->query("jingli") * 100 / (int)me->query("max_jingli") < 40)
		return notify_fail("你太累了，休息一会儿再劝吧。\n");

	me->receive_damage("jing", 15);
	me->receive_damage("jingli", 15);

	age = (int)me->query("age");
	if( age > 50 ) age = 50;
	pp = ((int)me->query_skill("persuading",1)*2+(int)me->query_skill("mahayana"))*10
	    +age*(int)me->query_per();
	if ( pp < 1 ) pp = 1;
	myexp = me->query("combat_exp");
	pp *= myexp/1000+1;

	dp = ( (int)target->query("jing") + (int)target->query("max_jing") +
	       (int)target->query("qi") + (int)target->query("max_qi") +
	       (int)target->query("jingli") ) *2/3;
	if ( dp < 1 ) dp = 1;
	yourexp = target->query("combat_exp");
	dp *= (yourexp/2 + random(yourexp))/1500+1;

        tell_object(me, HIY + "你对" + EMOTE_D->normal_color(target->name())
              + "说道：" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR); 

        tell_object(target, HIY + me->name() + "对你说道：" +
                persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR);

        message("vision", HIY + me->name() + "对" + EMOTE_D->normal_color(target->name()) 
                + "说道：" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR,
                where, ({ me, target }) );

	me->set_temp("persuading", target->query("id"));
	call_out("complete_persuade", 1+random(4), me, target, pp, dp);
	return 1;
} 

private void complete_persuade(object me, object target, int pp, int dp)
{
	int t_shen, myexp, yourexp, exp_factor;
	int  bonus=2;

	if (objectp(me)) me->delete_temp("persuading");
	else return;
	if (!objectp(target)) return;

	if (environment(target) != environment(me)) {
		tell_object(me, "善哉，" + target->name() + "已经走了。\n"); 
		return;
	}

	if ( !living(target) ) {
		tell_object(me, target->name() + "已不能听取你的劝导了！\n");
		me->delete_temp("defensing");
		return;
	}

	if (!target->is_fighting()) {
		tell_object(me, "善哉，" + target->name() + "已经先行罢手了。\n");
		me->delete_temp("defensing");
		return;
	}

	t_shen =  - (int)target->query("shen");
	while ( t_shen > 10 ) {
		bonus += 1;
		t_shen = t_shen/32;
	}
	
	dp *= bonus;
	if (target->is_fighting(me) && !me->query_temp("defensing") ) {
		dp *= 1 + bonus;
		bonus = bonus/2;
	}
	if (target->is_killing(me->query("id"))
	    && !me->query_temp("defensing") ) dp *= 2;
	if (me->is_killing(target->query("id"))) dp *= 2;

if (wizardp(me) && (string)me->query("env/combat")=="verbose" )
	 tell_object(me, sprintf("pp = %d, dp = %d\n", pp, dp));

//  lower the exp get from persuading the same npc you are fighting.
if (me == target->select_opponent())
    exp_factor = 3;
else
    exp_factor = 1;

	if ( random(pp+dp) > dp ) {

		tell_object(target, HIG + "你受到" + me->name()
		  		  + "的感招，决定罢手不斗。\n" + NOR);
		tell_object(me, HIG + EMOTE_D->normal_color(target->name()) 
			      + "受到你佛法感招，决定罢手不斗。\n" + NOR);
                message("vision", CYN"只见" + EMOTE_D->normal_color(target->name()) 
                        + "往后一纵，说道：好！" + me->name() 
			+ succeed_msg[random(sizeof(succeed_msg))] + NOR, 
                        environment(target), ( {me, target} ) );

		target->remove_all_killer();
		target->start_busy(3);
		if (target->query("shen") < 0) 
			target->add("shen",-(int)target->query("shen")/20);
		me->remove_killer(target);
		me->start_busy(1);
		me->delete_temp("defensing");
		target->set_temp("last_persuader", me->query("id"));
		call_out("delete_last_persuader", 6+random(30), me, target);

// give exp and skills points
		myexp = me->query("combat_exp");
		yourexp = target->query("combat_exp");
		bonus += (yourexp/500)/(myexp/1000+1);
		if ( pp < 3*dp/2+random(dp*8) 
		  || myexp < yourexp 
		  || (int)random(yourexp) > 150000) {
			me->improve_skill("persuading", me->query_int()+(bonus-1)*random(me->query_int()));
			me->improve_skill("mahayana", random(me->query_int())/5);
                	if ( yourexp + random(myexp) > myexp )
       		        {
       	        	        me->query_skill("persuading", 1) < 144 ?
					me->add("combat_exp", 
						(me->query_skill("persuading",1)/12+2)*(1+bonus)/exp_factor )
				      : me->add("combat_exp",
						12*(1+bonus)/exp_factor );
				target->add("combat_exp", 1);
				if (target->query("potential") < target->query("max_potential"))
					target->add("potential", 1);
			}
		}
	}
	else if ( !target->is_fighting(me) || me->query_temp("defensing") ) {
		if ( random(pp) < dp/3 ) {
			tell_object(me, RED + EMOTE_D->normal_color(target->name()) + "冲你大喝一声：“"
				       + RANK_D->query_rude(me) 
				       + "多管闲事，看招！”\n" + NOR);
			tell_object(target, CYN + "你冲" + me->name() + "大喝一声：“"
				          + RANK_D->query_rude(me)
				          + "多管闲事，看招！”\n" + NOR);
			message("vision", CYN + "只见" + EMOTE_D->normal_color(target->name()) + "冲着"
					+ me->name() + "大喝一声：“"
					+ RANK_D->query_rude(me)
                                        + "多管闲事，看招！”\n" + NOR, environment(target),
					( {me, target} ) );
			if ( (int)target->query("shen") < 0 )
				target->kill_ob(me);
			else
				target->fight_ob(me);
			me->start_busy(1);
			COMBAT_D->do_attack(target, me, target->query_temp("weapon"));
                        me->add("combat_exp", 1);
			me->set_temp("defensing", 1);
		}
		else {
			tell_object(me, HIR + EMOTE_D->normal_color(target->name())
			 + "满脸不耐烦地冲你嚷道：哪凉快哪待着去，少管闲事！\n"+ NOR);
			tell_object(target, HIR "你对着" + EMOTE_D->normal_color(me->name())
			 + "不屑地撇撇嘴：哪凉快哪待着去，少管闲事！\n" + NOR);
			message("vision", HIR + "只见" + EMOTE_D->normal_color(target->name()) + "对着" 
					+ EMOTE_D->normal_color(me->name())
				+ "不屑地撇撇嘴：哪凉快哪待着去，少管闲事！\n" + NOR,
				environment(target), ( {me, target} ) );
			if (!target->is_fighting(me) ) me->delete_temp("defensing");
			me->start_busy(1+random(3));
		}
	}
	else if ( target->is_killing(me->query("id")) 
		|| me->is_killing(target->query("id")) ) {
		message_vision(CYN"$N对$n理也不理！\n"NOR, target, me);
		target->kill_ob(me);
		me->start_busy(2);
	} else if ( target->is_fighting(me) ) {
		tell_object(target, RED"你恶狠狠地对" + me->name() + "喝道："
			+ RANK_D->query_rude(me) + "，你我切搓武艺你还假惺惺瞎劝，拿命来吧！\n"NOR);
		tell_object(me, RED + target->name() + "恶狠狠地对你喝道："
			+ RANK_D->query_rude(me) + "，你我切搓武艺你还假惺惺瞎劝，拿命来吧！\n"NOR);
		message("vision", RED + target->name() + "恶狠狠地对"
			+ me->name() + "喝道：" + RANK_D->query_rude(me)
			+ "，你我切搓武艺你还假惺惺瞎劝，拿命来吧！\n"NOR,
			environment(target), ( {me, target} ) );
		target->kill_ob(me);
                me->add("combat_exp", 1);
		me->start_busy(1+random(5));
	}
}

private void delete_last_persuader(object me, object target)
{
	if (!target || !me) return;
	if (me->query("id") == (string)target->query_temp("last_persuader") )
		target->delete_temp("last_persuader");
}

int help(object me)
{
write(@HELP
指令格式 : persuade <某人>

峨嵋弟子可以高深佛法劝人向善，普渡众生。不过功力不够有时也会惹祸上身。
HELP
    );
    return 1;
}

