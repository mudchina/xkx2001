//Cracked by Roath
// train.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *training_msg = ({
	"全神贯注地凝视着",
	"伸出右手的食指和小指指着",
	"一边嘴里叽叽咕咕发出些奇怪的音节，一边慢慢走近",
	"做出一付若无其事的样子，不动声色地靠近"
});

int main(object me, string arg)
{
	string what, who;
	object victim, lord;
	int sp, dp, cost;


	if( me->query_temp("training") )
		return notify_fail("现在你正在试图驯服它！\n");

	if( !arg) return notify_fail("指令格式：train <动物>\n");

	victim = present(arg, environment(me));
	if( !victim || victim==me) return notify_fail("你想驯服的对象不在这里。\n");

	if(!living(victim)) return notify_fail("等它醒了再说吧。\n");

	if( !(victim->is_trainee()))
		return notify_fail("想驯服它？别做梦了！\n");

	if( objectp(lord = victim->query_lord()) 
	&& environment(lord) == environment(me) && lord != me)
		return notify_fail("当著主人面这么干？！不太好吧！\n");
	if (me == lord)
		return notify_fail("你已经是它的主人了。\n");

	if( environment(me)->query("short") == YEL"马厩"NOR)
                return notify_fail("在别人家里驯兽，这不太好吧。\n");

	if (victim->query_temp("prelord") == me->query("id")) {
		write("它好象认识你一样，凑了过来。\n");
		victim->train_it(me, victim,101);
		return 1;
	}	

	cost = me->query("max_jingli")/(2*(int)me->query_skill("training",1)/10 + 1) - 10;
	cost = 200/((int)me->query_skill("training",1)/5 + 1);

	if ( me->query("jingli") <= cost )
                return notify_fail("现在你太累了，小心反受其害！\n");

	me->add("jingli", - cost );
	if( me->query("jingli") <= 0 ) me->unconcious();

	sp = (int)me->query_skill("training", 1) + (int)me->query("kar")/4;

	if( sp < 1 ) sp = 1;

	if( me->is_fighting() ) {
		sp /= 2;
		me->start_busy(3);
	}
	dp = (int)victim->query("wildness");

	message_vision("$N" + training_msg[random(sizeof(training_msg))] +
		"$n。\n", me, victim);

	me->set_temp("training", 1);
	call_out( "compelete_train", 1, me, victim, sp, dp);

	return 1;
}

private void compelete_train(object me, object victim, int sp, int dp)
{
	int pts;
	string msg_fail, msg_succ;

	if( !me || !victim ) return;

	me->delete_temp("training");
	if(!(msg_fail = victim->query("msg_fail")))
		msg_fail = "$n看了$N一眼，转身背对着$N";
	if(!(msg_succ = victim->query("msg_succ")))
		msg_succ = "$n向后退了半步，似乎有些怕$N";

	if( environment(victim) != environment(me) ) {
		tell_object(me, "太可惜了，你想驯服的目标已经走了。\n");
		return;
	}

	pts = random(sp+dp);
	//tell_object(me, chinese_number(sp) + "！" + chinese_number(dp) +
		//"＝" + chinese_number(pts) + "\n");
	if( living(victim) && (pts > 2*dp) ) {
		//victim->train_it(me, victim);
		if( living(victim) ) {
			message_vision(msg_succ + "。\n", me, victim);
			me->improve_skill("training", random(me->query("int")));
			if (me->query("family/family_name")=="白驼山" ||
			    me->query("family/family_name")=="丐帮")
			if (me->query("combat_exp") < 100000 ){
			me->add("combat_exp",random((int)victim->query("wildness"))/2);
                        me->add("potential",random(2));
                        if (me->query("potential") > me->query("max_potential"))
                        me->set("potential", me->query("max_potential"));
			}
		}
		victim->train_it(me, victim, pts);

	} else {
		if( pts > dp/2 ) {
			message_vision(msg_fail + "。\n", me, victim);
			return;
		}
		//message_vision("$n想杀死$N。\n", me, victim);
		me->improve_skill("training", 1, 1);
		victim->kill_ob(me);
		me->fight_ob(victim);
		me->start_busy(3);
	}
}

int help(object me)
{
write(@HELP
指令格式 : train <动物>

此指令可用于驯化某动物。对于已经驯服的动物，可以进行下述指令：

基本指令：
	gen(come) <动物名>: 		让动物跟随主人行动;
	ting(stay): 			停止动物的跟随状态;
	yao(attack <某人>): 		让动物攻击敌人;
	zhi(stop) <动物名>:		让动物停止对人的攻击;
	fang(release): 			结束主奴状态，将动物放离。

特殊指令：（只对某些动物适用）
	qi(ride) <动物名>:		骑，如骑马，虎，雕，鲨等。
	xia(unride) <动物名>:		下，离开坐骑。
	wei(feed) <动物名>:		替动物喂食。
	yin <动物名>:			给动物饮水。

HELP
    );
    return 1;
}
