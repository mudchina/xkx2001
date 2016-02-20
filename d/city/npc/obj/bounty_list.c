//Cracked by Roath
#include <ansi.h>;

inherit ITEM;
inherit F_SSERVER;

string wanted();
int do_arrest(string);

void create()
{
	set_name(RED"海捕文书"NOR, ({ "haibu wenshu", "wenshu", }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("value", 0);
		set("material", "paper");
	}
	set("long", wanted());
	setup();
}

void init()
{
	add_action("do_arrest","arrest");
}

string wanted()
{
	int i;
	string msg;
	object *ob = users();

	msg = "";
	for (i = 0; i < sizeof(ob); i++)
		if ((int)ob[i]->query("PKS")>19 
		&& ob[i]->query("combat_exp")/ob[i]->query("PKS") < 10000
		&& environment(ob[i])->query("short") != "监狱") {
		msg += HIY"★★"NOR+ob[i]->query("title") + " ";
		if (ob[i]->query("nickname"))
			msg += "「" + ob[i]->query("nickname") + "」" ;
		msg += ob[i]->name() + HIY"★★\n"NOR;
		msg += (HIR"该犯犯下"+chinese_number(ob[i]->query("PKS"))+"桩命案。\n"NOR);
		if (ob[i]->query("long"))
			msg += ("该犯相貌特征如下：\n" + ob[i]->query("long"));
		else msg += ("该犯相貌不详。\n");
		msg += ("——————————————————————\n");
	}
	if (msg == "")
		return "本府治安良好。\n";
	else
		return "现在本府正在悬赏缉拿以下要犯：\n\n" + msg;
}

int do_arrest(string arg)
{
	object me=this_player(), victim, fighter;

	if (!me->query_temp("mark/巡捕"))
        return notify_fail("什么？\n");

	if (!arg)
        return notify_fail("你要拘捕谁？\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不准战斗。\n");

	victim = present(arg,environment(me));

	if (!victim)
        return notify_fail("这里并无此人！\n");

	if (victim == me) 
		return notify_fail("何必多此一举？\n");

	if (!living(victim))
		return notify_fail("这不是活物！\n");

	if (!(userp(victim)
		&& victim->query("PKS")>19
		&& victim->query("combat_exp")/victim->query("PKS") < 10000))
		return notify_fail("此人不是凶犯！\n");

	message_vision(HIW"$N对$n高喊一声："+RANK_D->query_rude(victim)+"作恶多端，今天可跑不了了！还不束手就擒？！\n"NOR, me, victim);

	if (victim->is_fighting()) 
		victim->remove_all_killer();

	victim->kill_ob(me);
	me->fight_ob(victim);
	return 1;
}
