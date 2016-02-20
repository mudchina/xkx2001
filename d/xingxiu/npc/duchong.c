//Cracked by Roath
// wsky, 22/7/00.
#include <ansi.h>

inherit NPC;

void create()
{
        switch( random(6) ){
        	case 0:
        	set_name(RED"星宿毒蛛"NOR, ({ "du zhu", "spider", "zhu" }) );
        	set("long", "一只形如拇指大小，颜色呈暗红色的蜘蛛，似乎体含剧毒。\n");
        	break;
        	case 1:
        	set_name(HIG"绿竹蝎"NOR, ({ "scorpion", "xie", "xie zi" }) );
        	set("long", "身如竹节，体成碧绿，星宿海独有。\n");
        	break;
        	case 2:
        	set_name(HIR"朱睛蛙"NOR, ({ "zhu wa", "wa", "frog" }) );
        	set("long", "一只活泼可爱的小蛙，两眼成朱红色。\n");
        	break;
        	case 3:
        	set_name(HIC"毒蛾"NOR, ({ "e", "du e"}) );
        	set("long", "一只体含剧毒的蛾子。\n");
        	break;
        	case 4:
        	set_name(HIR"七心甲虫"NOR, ({ "beetle", "jia chong", "chong" }) );
        	set("long", "一只体含剧毒的硬壳甲虫。\n");
        	break;
        	case 5:
        	set_name(YEL"野蜂"NOR, ({ "bee", "ye feng", "feng" }) );
        	set("long", "一只野山蜂，教蛰一下可是不好受的。\n");
        	break;
        	case 6:
        	set_name(HIB"蓝鼎蜘蛛"NOR, ({ "bee", "ye feng", "feng" }) );
        	break;
        }
        
        set("sub", "xx_job");
        set("race", "昆虫");
        set("subrace", "爬虫");
        set("age", 3);
        //set("limbs", ({ "头部", "身体", "触角", "前螯" }) );

        set("combat_exp", 100);
        //set_color("$HIY$");
        set_temp("apply/attack", 60);
        set_temp("apply/defense", 6);
        set_temp("apply/armor", 1);

        setup();
}

void init()
{
        object ob=this_object();
        object me=this_player();
        
        ::init();
        
        set("combat_exp", me->query("combat_exp"));
       
        call_out("kill_ob", 1, me);
        call_out("dest_bug",20,ob);
        
}

void die(object ob)
{
	this_player()->delete_temp("bug_out");
	::die();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("insect_poison", 50 +
                victim->query_condition("insect_poison"));
}

void dest_bug(object ob){
		
	message_vision (HIC+ob->query("name")+"突然钻到一片树叶下面，踪影全无。\n"NOR, this_player());
        this_player()->delete_temp("bug_out");
	destruct(ob);
	
}

