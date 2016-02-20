//Cracked by Roath
//gaibang npc
//by fear
inherit NPC;
int use_bang();
int use_unarmed();

int auto_perform();

void create()
{
        set_name("萧峰", ({ "xiao feng", "xiao", "feng", "gb_npc", "gaibang", "gb", "bangzhu", "npc"}));
        set_color("$HIG$");
        set("long", 
"这人身材甚是魁伟，三十来岁年纪，身穿灰色旧布袍，已微有破烂，浓眉大眼，\n"
"高鼻阔口，一张四方的国字脸，颇有风霜之色，顾盼之际，极有威势。\n");
        set("gender", "男性");
        set("age", 60);
        set("attitude", "heroism");
        set("shen_type", 1);
		set("rank",10);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

	set("neili", 8000);
        set("eff_neili", 8000);
        set("max_neili", 8000);
        set("jingli", 5000);
        set("max_jingli", 5000);
        set("eff_jingli", 5000);
        set("jiali", 200);
        set("jiajin",30);

        set("combat_exp", 6400000);
        set("score", 500000);
        set("death_count", 250);
        set("death_times", 250);

        set_skill("force", 400);
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("blade", 400);
        set_skill("stick", 400);
        set_skill("hand", 400);
        set_skill("strike",400);
        set_skill("literate", 400);
        set_skill("dagou-bang",400);
        set_skill("liuhe-dao", 400);
        set_skill("xianglong-zhang",400);
        set_skill("shexing-diaoshou",400);
        set_skill("xiaoyaoyou", 400);
        set_skill("huntian-qigong", 400);
        set_skill("begging", 400);
        set_skill("checking",400);
        set_skill("digging", 400);
        set_skill("training", 400);
        map_skill("hand", "shexing-diaoshou");
        map_skill("force", "huntian-qigong");
        map_skill("parry", "dagou-bang");
        map_skill("blade", "liuhe-dao");
        map_skill("stick", "dagou-bang");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        
        prepare_skill("strike", "xianglong-zhang");

        create_family("丐帮", 13, "帮主");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        setup();
        carry_object("/d/gaibang/obj/budai")->set_amount(9);
        carry_object("/d/gaibang/obj/budai")->wear();
        carry_object("/d/gaibang/obj/yellowbang");
}
// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
        object me=this_object();
        object weapon=me->query_temp("weapon");
        object opp=me->select_opponent();

        if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 50);

                return 1;
        }

        if ( !me->query_temp("powerup") ) {
                return exert_function("powerup");
        }

        if ( objectp(weapon) ) {
                switch (weapon->query("skill_type")) {
                case "blade" :
                    me->map_skill("parry", "liuhe-dao");           
                return perform_action("blade.lianhuan");
                break ;
      
                case "stick" :
                     me->map_skill("parry", "dagou-bang");           
                if ( !me->query_temp("shengang") )
                        return exert_function("shengang");

                if ( weapon->query("skill_type") == "stick" )
                                        if( objectp(opp->query_temp("weapon")) ) {
                                command("perform duo");
                                        }
/*                                      if( objectp(opp->query("jingli")<2500) ) {
                                command("perform ban");
                                        }
                                        if( objectp(opp->query("combat_exp")<me->query("combat_exp")) ) {
                                command("perform chan");
                                        } */
                                        else
                                        {
                        return perform_action("stick.sansha");
                                }                      
        }
        }
        else {
			command("exert powerup");
            me->map_skill("parry", "xianglong-zhang");           
			if(me->query_temp("sanhui") )
			{
			   return perform_action("strike.leiting");
			}
			else 
			{
				return perform_action("strike.sanhui");
			}
        }
                
}

int use_unarmed()
{
	command("nod");
	command("unwield bang");
	this_object()->map_skill("parry", "xianglong-zhang");
	return 1;
}

int use_bang()
{
	this_object()->command("wield bang");
	this_object()->map_skill("parry","xianglong-zhang");
	return 1;
}
