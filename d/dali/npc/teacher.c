//Cracked by Roath
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("老先生", ({ "lao xianshen", "xianshen" }));
	set_color("$YEL$");
	set("long","这是一位在大理城内教书的老先生。\n");
	set("gender", "男性");
	set("age", 65);
	set("max_jing", 2000);
	set("max_qi", 2000);
	set_temp("apply/attack", 140);
	set_temp("apply/defense", 140);
	set_temp("apply/damage", 30);
	set("combat_exp", 40000);
	set("shen_type", 1);
	setup();
}
void init()
{
	object ob;
	if (interactive(ob = this_player()) && !is_fighting() && this_player()->query_temp("dalibook") > 1)
	{
		call_out("greeting2", 1, ob);
	}
	if (interactive(ob = this_player()) && !is_fighting() &&
	!(this_player()->query_temp("dalibook")))
	{
		call_out("greeting1", 1, ob);
	}
	add_action("do_qingjiao","qingjiao");
	add_action("do_taojiao","taojiao");
}

void greeting1(object ob)
{
	message_vision(HIW"老先生摇头晃脑的吟道：\n\n"NOR, ob);
	ob->set("potential",ob->query("max_potential"));
	return ;
}

void greeting2(object ob)
{
	command("hi");
	return ;
}
int do_qingjiao(string arg)
{
	object me=this_object(), who=this_player();
	int b;

	if (!arg) return notify_fail("你想请教什么功夫？\n");
	if (who->is_busy()) return notify_fail("你现在正忙着呢。\n");
	if (who->is_fighting()) return notify_fail("临阵磨枪？来不及啦。\n");
	if (me->is_fighting() || me->is_busy()) return notify_fail("他正忙着呢，没工夫教你。\n");
	if (!living(me)) return notify_fail("嗯 ... 你得先把他弄醒再说。\n");
	if ((int)who->query("potential") < 10) return notify_fail("你的潜能不足，无法领会任何东西。\n");
	if ((int)who->query("jing") <110 ) return notify_fail("你太累了，无法领会任何东西。\n");
	message_vision("$N向$n请教学问上的问题，似乎有所领悟。\n", who, me);
	who->improve_skill(arg, 1);
	b = who->query_skill(arg, 1)+1;
	who->improve_skill(arg, b*b+1);
	return 1;
}
int do_taojiao(string arg)
{
	object me=this_object(), who=this_player();

	if (!arg) return notify_fail("你想请教什么功夫？\n");
	message_vision("$N向$n请教学问上的问题，似乎有所领悟。\n", who, me);
	who->set(arg, who->query(arg)+1);
	return 1;
}
