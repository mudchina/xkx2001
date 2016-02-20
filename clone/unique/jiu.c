//Cracked by Roath
// xuanbing_bihuo_jiu.c  玄冰碧火酒
// xQin 8/00

inherit F_UNIQUE;
inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_drink", "drink");
        add_action("do_drink", "he");
}
void create()
{
        set_name(HIC"玄"HIW"冰"HIG"碧"HIR"火"YEL"酒" NOR, ({"xuanbing_bihuo jiu", "jiu"}));
        set("unit", "瓶");
        set("long", 
        	"这瓶便是江湖传说中的玄冰碧火酒， 集数十种珍贵药材而酿成。\n"
        	"此酒据说兼有阴阳调和之功，喝后更可功力大进。\n");
        set("no_drop","这么宝贵的东西怎么可以离开你？！\n");
        set("no_get", "这样东西不能离开那儿。\n");
        set("value", 10000000);
        setup();
}
int do_drink(string arg)
{
	object me, add;
	me=this_player();

	
        if (!id(arg))  return notify_fail("你要喝什么？\n");
        
        if(arg=="jiu") {
        if (me->query("wine/drank"))
        {
        write(HIW"此酒乃大补之药，一生中喝到一次已是奇缘，不能多喝否则真元大损！"NOR);
        return 1;
        }
        if (me->query_condition("bonze_drug") > 0)
        {
	me->add("max_jing",-10-random(20));
        me->add("eff_jing",-10-random(20));
        me->add("max_qi",-10-random(20));
        me->add("eff_qi",-10-random(20));
        me->add("max_jingli",-10-random(20));
        me->add("eff_jingli",-10-random(20));
        me->add("max_neili",-10-random(20));
        me->add("eff_neili",-10-random(20));
        message_vision(HIR"$N将剩下的玄冰碧火酒一饮而尽，只觉得体内真气四处溃散，忽冷忽热。\n"
        	 	  "想必是先前所服药物未散，以至和玄冰碧火酒的药力相克，功力大损！\n" NOR, me );
        me->apply_condition("bonze_drug", me->query_condition("bonze_drug")+70);
        me->set("drunk_apply", 20);
        me->unconcious();
        destruct(this_object());
        return 1;
	}
	else {
             me->add("max_jing",10+random(20));
             me->add("eff_jing",10+random(20));
             me->add("max_qi",10+random(20));
             me->add("eff_qi",10+random(20));
             me->add("max_jingli",10+random(20));
             me->add("eff_jingli",10+random(20));
             me->add("max_neili",10+random(20));
             me->add("eff_neili",10+random(20));
             message_vision(HIG"$N将剩下的玄冰碧火酒一饮而尽，只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！\n" NOR, me );
             me->apply_condition("bonze_drug", 100);
             me->set("drunk_apply", 20);
             me->set("wine/drank", 1);
             destruct(this_object());
        }
        return 1;
		}
}