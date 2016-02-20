//Cracked by Roath
//wzfeng 99 11/29
#include <ansi.h>
inherit ITEM;

void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
        set_name(HIW"补阴丸"NOR, ({"buyin wan","wan"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "粒");
                set("long","这是一粒补阴丸，滋补阴柔之气有奇效，不过常人服食恐有异常 。\n");
                set("value", 0);
		set("no_drop","这样东西不能离开你。\n");
                set("value", 300000);
		set("medicine", 1);

        }
        setup();
}
 
int do_eat(string arg)
{

	object me;
	int skill;
	me=this_player();
	skill=me->query_skill("pixie-jian", 1);

	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	if(skill<200)
	{
	message_vision(HIR"$N吃下一粒补阴丸，只觉得浑身一阵冰凉，一股阴寒之气之丹田串向全身，刹那间心神失首，经脉受损!\n"NOR, this_player());
	if(me->query("max_jingli")>50)
	{
	me->add("eff_jingli",-20);
	me->add("max_jingli",-20);
	}
	me->unconcious();
	}
	else
	{
		if(me->query("drug_list/1")==query("drug_list/1")
			&&me->query("drug_list/2")==query("drug_list/2")
			&&me->query("drug_list/3")==query("drug_list/3")
			&&me->query("drug_list/4")==query("drug_list/4")
			&&me->query("drug_list/5")==query("drug_list/5")
			)
		
		
		{

			if(me->query("pixie/buyin-wan/lvl")>=skill&&me->query("pixie/buyin-wan/lvl")>0)

			{
				message_vision(HIG"$N吃下一粒补阴丸，只觉得浑身一阵冰凉，一股阴寒之气之丹田串向全身，刹那间阳气锐减，阴气陡增。\n"NOR, this_player());
				message_vision(HIR"不料以前的药力似乎并未消失，连续服用效果适的其反。$N刹那间心神失首，经脉受损。\n"NOR, this_player());
	if(me->query("max_jingli")>50)
	{
	me->add("eff_jingli",-20);
	me->add("max_jingli",-20);
	}

			}
			else
			{
			
				message_vision(HIG"$N吃下一粒补阴丸，只觉得浑身一阵冰凉，一股阴寒之气之丹田串向全身，刹那间阳气锐减，阴气陡增。\n"NOR, this_player());
				me->add("eff_jingli",5+random(2));
				me->add("max_jingli",5+random(2));
				me->set("pixie/buyin-wan/lvl",skill);
			}
		
		}
		else
		{
		message_vision(HIG"$N吃下一粒补阴丸，只觉得浑身一阵冰凉，一股阴寒之气之丹田串向全身，刹那间阳气锐减，阴气陡增。\n"NOR, this_player());
		message_vision(HIR"不料此药剂量与你身体不符，刹那间$N心神失首，经脉受损。\n"NOR, this_player());
		me->add("max_jingli",-20);
		me->unconcious();
	
		}

	}
	
	
	destruct(this_object());
	return 1;
}

