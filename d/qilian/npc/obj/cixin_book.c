//Cracked by Roath
// cixin_book.c
//Wzfeng@xkx 99 11
#include <ansi.h>
inherit ITEM;

int do_start(object me);


void create()
{
        set_name("刺心秘决", ({ "cixin yaojue", "yaojue" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本残缺不全的小册子,上面记载着辟邪剑法失传已久的刺心秘决。\n");
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
	 if (me->is_busy())
            return notify_fail("你正忙着呢!\n");

	
	if(arg!=this_object()->query("id")) return notify_fail("你要领悟什么?\n");
	if(me->query_skill("pixie-jian", 1) <180)
            return notify_fail("你的辟邪剑法不够娴熟，无法领悟要决中的奥妙。\n");
	if(this_object()->query("master")!=me->query("id"))
	{
		me->add("max_neili",-100);
		return notify_fail(HIR"你一读之下只觉浑身燥热，内力不聚，说不出的难受。\n"NOR);

	}
	if(this_player()->query_temp("linji/zhixin")
		||this_player()->query_temp("linji/fengyun"))
	{
		me->add("max_neili",-100);
		me->add("max_jingli",-100);
		return notify_fail(HIR"你突然发现浑身静脉不畅，说不出的难过，转眼间似乎要窒息。\n"NOR);

	}


	if(me->query("canuse_cixin")==1)
		    return notify_fail("你已经领悟刺心秘决的精要。\n");
	if(me->query("neili")<3000||me->query("jingli")<2000)
		return notify_fail("你精神不佳，无法领悟心法中的奥妙。\n");
	cost=me->query("int");
	if(cost>=30)
		cost=5;
	else
		cost=35-cost;
	me->set_temp("cixin_cost",cost);
	
	message_vision(HIB "$N从怀中摸出一本小册子,细细的看着,脸上露出诡异的神色。\n" NOR, me);
    me->start_busy((: do_start:));
	return 1;

}

int do_start(object me)
{


	if(me->query_temp("cixin_cost")<=0)
	{
		if(random(me->query("int"))>19||random(me->query_int())>40)	
		{
			me->add("pixie-cixin",1);
			tell_object  (me,HIY"你似乎对刺心要决有一丝领悟。\n"NOR);
			
			if(me->query("pixie-cixin")>=20)
			{
				tell_object  (me,HIY"你终于领悟出刺心秘决的精要。\n"NOR);
				if(me->query("canuse_cixin")!=1)
				me->add("str",1);
				me->set("canuse_cixin",1);
				me->delete("pixie-cixin");
				
			}
			me->set("neili",0);
			me->set("jingli",0);
	
		}
		else
		{
			
			tell_object  (me,HIR"你只觉心头一阵恶心，全身经脉逆转,“哇”的吐出一口鲜血。\n"NOR);
		    me->unconcious();

		}
	return 0;
	}
	me->add_temp("cixin_cost",-1);

	
	return 1;
}
