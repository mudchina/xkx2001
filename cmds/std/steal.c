//Cracked by Roath
// steal.c
// 04/16/97: xbc modified this file.  The exp and pot rewards depends on
// relative exp of me and victim, but same for both gb and non-gb dizi.  
//changed by wzfeng 99 12 3
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止行窃。\n");

	if( me->query_temp("stealing") )
		return notify_fail("你已经在找机会下手了！\n");

	if( me->is_busy() )
		return notify_fail("你正忙着呢！\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("指令格式：steal <物品> from <人物>\n");

	if( what == "all" ) return notify_fail("别着急，还是一样一样来吧。\n");
	victim = present(who, environment(me));
	if( !victim || victim==me) return notify_fail("你想行窃的对象不在这里。\n");
	if( !victim->is_character() ) return notify_fail("偷"+victim->name()+"？！你有毛病啊？\n");
	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("玩家不能偷巫师身上的东西。\n");
		//////////////////////////////////////////////add by wzfeng
	if(victim->query("id")=="tang nan" 
	|| victim->query("id")=="lao chaofeng"
	|| victim->query("dealer"))
		return notify_fail("想偷他的东西？下辈子吧。\n");
/////////////////////////////////////////////////////////////


	ob = present(what, victim);

	if( !ob ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) || (sizeof(inv)==1 && inv[0]->query("no_steal")) )
			return notify_fail( victim->name() + "身上看起来没有什麽值钱的东西好偷。\n");
		ob = inv[random(sizeof(inv))];
	}

	if( ob->query("no_steal") || ob->query("no_get")) 
	return notify_fail("这东西不能偷。\n");

	sp = (int)me->query("jing")/10 + (int)me->query("kar") + (int)me->query_dex();
	sp *= (int)me->query_skill("stealing", 1)/10;

	if ( (myfam = me->query("family")) && myfam["family_name"] == "丐帮" )
	sp *= 2;

	if( sp < 1 ) sp = 1;

	if( me->is_fighting() ) {
		sp /= 2;
		me->start_busy(3);
	}
	dp = (int)victim->query("jing") + (int)ob->weight()/25 + victim->query("combat_exp")/700;
	if( victim->is_fighting() ) dp *= 10;
	if( ob->query("equipped") ) dp *= 10;

	write("你不动声色地慢慢靠近" + victim->name() + "，等待机会下手 ...\n\n");

	me->set_temp("stealing", 1);
	me->start_busy(3);
	call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
	mapping myfam, vtfam;

	me->delete_temp("stealing");

	if( !me || !victim || !ob) return;

	if( environment(victim) != environment(me) ) {
		tell_object(me, "太可惜了，你下手的目标已经走了。\n");
		return;
	}

	if( !living(victim) || (random(sp+dp) > dp) ) {
		if( !ob->move(me) ) {
			tell_object(me, "你摸到一" + ob->query("unit") + ob->name() 
				+ "，可是对你而言太重了，不得不放弃。\n");
			return;
		}
		if ( ob->query("money_id") ) victim->save();
		tell_object(me, HIW "得手了！\n\n" NOR);
		tell_object(me, "你成功地偷到一" + ob->query("unit") + ob->name() + "！\n");

		if( living(victim) ) {
			if (me->query("combat_exp") <= (int)victim->query("combat_exp")*3/2) {
				me->add("potential",random(2));
				me->add("combat_exp",random(2));
				me->improve_skill("stealing", random(me->query("int")));
			if (me->query("potential") > me->query("max_potential"))
			me->set("potential", me->query("max_potential"));
			}
		}

		if( random(sp) > dp/2 )
			message("vision", "你看到" + me->name() + "鬼鬼祟祟地从"
				+ victim->name() + "身上偷走了一" + ob->query("unit")
				+ ob->name() + "！\n", environment(me), ({ me, victim }) );
	} else {
		if( random(sp) > dp/3 ) {
			tell_object(me, victim->name() + "不经意地一转头，你急忙将手缩了回去！\n"
				"还好，没有被发现。\n");
			return;
		}
		tell_object(me, HIR "糟糕！你失手了！\n\n" NOR);
//	      message_vision("$N一回头，正好发现$n的手正抓着$P身上的" + ob->name() + "！\n\n"
//		      + "$N喝道：「干什么！」\n\n", victim, me);

		if ( victim->query("race") == "人类" ) 
			message_vision("$N一回头，正好发现$n的手正抓着$P身上，喝道：「干什么！」\n\n", victim, me);
		else
			message_vision("$N一回头，正好发现$n的手正抓着$P身上，显得十分愤怒！\n\n", victim, me);

		me->improve_skill("stealing", 1, 1);
		if( userp(victim) ) victim->fight_ob(me);
		else victim->kill_ob(me);
		me->fight_ob(victim);
		me->start_busy(2);
		me->add("thief", 1);
	}
}

int help(object me)
{
write(@HELP
指令格式 : steal <某物> from <某人>

这个指令让你有机会偷到他人身上的东西。成功了, 当然你就能获得
该样物品。可是, 马有失蹄, 人总有失风的时候, 当你失败时当然就
得付出代价, 至於是什么代价......靠你自己去发掘罗。
HELP
    );
    return 1;
}
