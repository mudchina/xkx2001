//Cracked by Roath
//shaolin test npc
//by xiaojian
inherit NPC;
inherit F_MASTER;
int auto_perform();
int use_whip();
int use_unarmed();
int use_zuigun();
// int use_jg();
// int use_jzz();
void create()
{
        set_name("达摩祖师", ({
                "sl_npc",
                "damo",
		"zushi",
		"da-mo",
   }));
        set_color("$HIG$");
        set("long",
                "他他就是少林派开山鼻祖、当今武林的隐世高僧达摩祖师。\n"
		"看上去他是一位白须白眉的老僧，身穿一袭金丝绣红袈裟。\n"
                "他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。\n"
        );

        set("gender", "男性");
        set("attitude", "heroism");
        set("class", "bonze");

        set("age", 70);
        set("shen_type", 1);
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

        set_skill("force", 400);
        set_skill("hunyuan-yiqi", 400);
        set_skill("dodge", 400);
        set_skill("shaolin-shenfa", 400);
        set_skill("cuff", 400);
        set_skill("jingang-quan", 400);
        set_skill("club", 400);
        set_skill("zui-gun", 400);
        set_skill("strike", 400);
        set_skill("sanhua-zhang", 400);
        set_skill("finger", 400);
        set_skill("nianhua-zhi", 400);
        set_skill("parry", 400);
        set_skill("buddhism", 400);
        set_skill("literate", 400);
	set_skill("whip",400);
	set_skill("riyue-bian",400);
	set_skill("yizhi-chan",400);
	set_skill("banruo-zhang",400);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
	map_skill("club", "zui-gun");
	map_skill("sword", "damo-jian");
        map_skill("finger", "yizhi-chan");
        map_skill("strike", "banruo-zhang");
        map_skill("claw", "longzhua-gong");
        map_skill("parry", "yizhi-chan");
	map_skill("whip", "riyue-bian");
	map_skill("cuff", "jingang-quan");

        prepare_skill("finger", "yizhi-chan");
        prepare_skill("strike", "banruo-zhang");
        create_family("少林派", 1, "弟子");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: auto_perform :), }));

	set("inquiry", ([ 
                                "whip"   : (: use_whip :),
                                "unarmed"    : (: use_unarmed :),
				"zui-gun"  : (: use_zuigun :),
				/*"use jingang" : (: use_jg :),
				"use jzz" : (: use_jzz :),*/
									     
        ]) );        
        
        setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
	carry_object("/d/shaolin/obj/changbian");
	carry_object("d/shaolin/obj/qimeigun");
}
int auto_perform()
{  	
	object me = this_object();
        object target = me->select_opponent();
        object weapon = me->query_temp("weapon");
        
        
        if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                exert_function("heal");
                me->set("jiali", 200);
                return 1;
        }

        if ( !objectp(target)
                || !random( (int)me->query("combat_exp") * 2
                / (int)target->query("combat_exp") + 1) ) return 0;

        if ( objectp(weapon) ) {
                switch (weapon->query("skill_type")) {
                case "whip" :
		    me->map_skill("parry", "riyue-bian");           
                return perform_action("whip.chanrao");
                break ;
        
                case "club" :
                if (me->query_skill_mapped("club") == "zui-gun")
                        {me->map_skill("parry", "zui-gun");
                        if (me->query_condition("drunk", 1) < 40)
                        {       
                        me->apply_condition("drunk", 40);
                        return perform_action("club.zuida");
                        }
                else 
                        return perform_action("club.zuida");
                        }
                else
                        
                        return 0;
                        
                break;

                case "sword" :
                if (me->query_skill_mapped("sword") == "damo-jian")
                {me->map_skill("parry", "yizhi-chan");
                return perform_action("sword.sanjue");
                }
		    else 
                return 0;
                break;  
                }       
        }
        else
        {       
		//if (jingang == 1);
                command("exert jingang");
		//else {command("exert jinzhongzhao");}
		if (me->query_skill_prepared("finger") == "yizhi-chan")
                {
                me->map_skill("parry", "yizhi-chan");
                me->reset_action();
                return perform_action("finger.jingmo");
                }
		else if (me->query_skill_prepared("strike") == "banruo-zhang" && random(3) == 0)
                {
                me->reset_action();
                return perform_action("strike.san");
                }
		else if (me->query_skill_prepared("finger") == "nianhua-zhi")
                {
                me->map_skill("parry", "nianhua-zhi");
                me->reset_action();
                return perform_action("finger.fuxue");
                }               
	}


}

int use_whip()
{
	command("nod");
	command("unwield gun");
	command("wield bian");
	map_skill("parry", "riyue-bian");
	return 1;
}
int use_unarmed()
{
	command("nod");
	command("unwield bian");
	command("unwield gun");
	map_skill("parry", "yizhi-chan");
	return 1;
}
int use_zuigun()
{
	command("nod");
	command("unwield bian");
	command("wield gun");
	map_skill("parry", "zui-gun");
	return 1;
}
/*int use_jzz()
{
	set("jingang", 0);
	return 1;
}
int use_jg()
{
	set("jingang", 1);
	return 1;
}*/
