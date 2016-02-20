//Cracked by Roath
// shouwu.c 首乌精

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void init();


void create()
{
	set_name( GRN "首乌精" NOR , ({"shouwu jing", "shouwu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵成精的何首乌，至少生长了几百年了，早已成人形，有奇妙的药效。\n");
		set("value", 8000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jingli", (int)me->query("max_jingli"));
        
	message_vision(HIY "$N吃下一棵首乌精，药效立刻通彻肺腑，直达四肢。不仅精力大振，连伤痛也全都感觉不到了。\n" NOR, me);

	destruct(this_object());
	return 1;
}
