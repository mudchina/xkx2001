//Cracked by Roath
// guimei_book.c
//Wzfeng@xkx 99 11
#include <ansi.h>
inherit ITEM;

int do_start(object me);


void create()
{
	set_name("鬼魅心法", ({ "guimei xinfa", "xinfa" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long", "这是一本残缺不全的小册子,上面记载着辟邪剑法失传已久的鬼魅心法。\n");
		set("material", "paper");
		set("no_drop","这样东西不能离开你。\n");
		set("no_get",1);
		set("no_steal",1);
		set("value", 300000);
	}
}
void init()
{
  add_action("do_lingwu","lingwu");
  
}
int do_lingwu(string arg)
{
	object me;
	int cost;
	me=this_player();
	if (me->is_busy()) return notify_fail("你正忙着呢!\n");
	if(arg!=this_object()->query("id")) return notify_fail("你要领悟什么?\n");
	if(me->query_skill("pixie-jian", 1) <120) return notify_fail("你的辟邪剑法不够娴熟，无法领悟心法中的奥妙。\n");
	if(this_object()->query("master")!=me->query("id"))
	{
		me->add("max_neili",-100);
		return notify_fail(HIR"你一读之下只觉浑身燥热，内力不聚，说不出的难受。\n"NOR);
	}
	if(this_player()->query_temp("linji/zhixin") || this_player()->query_temp("linji/fengyun"))
	{
		me->add("max_neili",-100);
		me->add("max_jingli",-100);
		return notify_fail(HIR"你突然发现浑身静脉不畅，说不出的难过，转眼间似乎要窒息。\n"NOR);
	}
	if(me->query("canuse_guimei")==1) return notify_fail("你已经领悟鬼魅心法的精要。\n");
	if(me->query("neili")<1500||me->query("jingli")<1500) return notify_fail("你精神不佳，无法领悟心法中的奥妙。\n");
	cost=me->query("int");
	if(cost>=30) cost=5;
	else cost=35-cost;
	me->set_temp("guimei_cost",cost);
	message_vision(HIB "$N从怀中摸出一本小册子,细细的看着,脸上露出诡异的神色。\n" NOR, me);
	me->start_busy((: do_start:));
	return 1;
}

int do_start(object me)
{
	if(me->query_temp("guimei_cost")<=0)
	{
		if(random(me->query("dex"))>19||random(me->query_dex())>40)	
		{
			me->add("pixie-guimei",1);
			message_vision(HIB "$N猛的凌空跃起,在空中幻化成几个身影，各自变换了几个邪异无比的姿势。\n" NOR, me);
			if(me->query("pixie-guimei")>=15)
			{
				tell_object  (me,HIY"你终于领悟出鬼魅心法的精要。\n"NOR);
				if(me->query("canuse_guimei")!=1)
				me->add("dex",1);
				me->set("canuse_guimei",1);
				me->delete("pixie-guimei");
				
			}
			me->set("neili",0);
			me->set("jingli",0);
		}
		else
		{
			
			message_vision(HIB "$N猛的凌空跃起,在空中幻化成几个身影，突然间双足一麻，重重摔了下来。\n" NOR, me);
		    me->unconcious();

		}
	return 0;
	}
	me->add_temp("guimei_cost",-1);
	return 1;
}
