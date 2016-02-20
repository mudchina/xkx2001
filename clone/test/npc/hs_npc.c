//Cracked by Roath
//hs npc
//by xiaojian
inherit NPC;

int auto_perform();
int use_dgjj();
int use_unarmed();
int use_hsjf();
int use_lyd();
void create()
{
        set_name("穆人清", ({ "hs_npc", "mu","mu renqing"}));
	set_color("$HIC$");
        set("long", 
"此老身躯高大，而且气度非凡，令人不敢小窥。据传闻他\n"
"闭关已久，江湖上鲜闻其名。武功之高，却令人震惊。\n");
        set("gender", "男性");
        set("age", 70);
        set("attitude", "heroism");
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
        set("score", 5000);

        set_skill("force", 400);
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("blade", 400);
        set_skill("sword", 400);
        set_skill("strike",400);
	set_skill("literate", 400);
	set_skill("dugu-jiujian",400);
        set_skill("liangyi-dao", 400);
        set_skill("huashan-jianfa", 400);
        set_skill("hunyuan-zhang",400);
        set_skill("huashan-shenfa", 400);
        set_skill("zixia-gong", 400);
        set_skill("cuff", 400);
        set_skill("pishi-poyu",400);
        set_skill("ziyin-yin", 400);
        set_skill("zhengqi-jue", 400);
        map_skill("cuff", "pishi-poyu");
        map_skill("force", "zixia-gong");
        map_skill("force", "zixia-gong");
        map_skill("parry", "huashan-jianfa");
        map_skill("blade", "liangyi-dao");
        map_skill("sword", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "huashan-shenfa");
        
        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "pishi-poyu");

        create_family("华山派", 1, "掌门人");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	  set("inquiry", ([ 
                                "dugu-jiujian"   : (: use_dgjj :),
                                "huashan-jianfa"    : (: use_hsjf :),
				"unarmed"  : (: use_unarmed :),
				"blade" : (: use_lyd:),

        ]) );
        setup();
        carry_object("/clone/weapon/gangdao");
	  carry_object("/clone/weapon/changjian");
        carry_object("/d/city/obj/cloth")->wear();
}
int auto_perform()
{
        object me=this_object();
        object weapon=me->query_temp("weapon");
        object opp=me->select_opponent();
	object ob=me->select_opponent();
        object my_weapon;
        string action;

	if( me->query("qi",1) < 10 || me->query("jing",1) < 10 || me->query("jingli",1) < 10) return;

        if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 200);
                return 1;
        }

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "blade" )
				{
				me->map_skill("parry", "liangyi-dao");
                		return perform_action("blade.sanshen");
				}
		else if ( weapon->query("skill_type") == "sword" )
		{
		    if (me->query_skill_mapped("sword") == "huashan-jianfa")	
			{
                	me->map_skill("parry", "huashan-jianfa");
                  return perform_action("sword.jianzhang"); 
		 	}
		     else if (me->query_skill_mapped("sword") == "dugu-jiujian")
			{
			me->map_skill("parry", "dugu-jiujian"); 
			if (objectp(my_weapon=me->query_temp("weapon")) ) 
			{
           if ( !weapon = ob->query_temp("weapon") ) {
              switch (random(3)) {
              case 0:
		perform_action("sword.po"); 
                //action = "sword.po";
                break;
              case 1:
		perform_action("sword.poqi"); 
                //action = "sword.poqi";
                break;
              case 2:
		perform_action("sword.pozhang"); 
                //action = "sword.pozhang";
                break;
              }
           }
           else if ( (string)weapon->query("skill_type") == "sword" ) {
              switch (random(3)) {
              case 0:
		perform_action("sword.po"); 
                //action = "sword.po";
                break;
              case 1:
		perform_action("sword.poqi"); 
                //action = "sword.poqi";
                break;
              case 2:
		perform_action("sword.jian"); 
                //action = "sword.pojian";
                break;
              }
           }
           else if ( (string)weapon->query("skill_type") == "blade" ) {
              switch (random(3)) {
              case 0:
		perform_action("sword.po"); 
                //action = "sword.po";
                break;
              case 1:
		perform_action("sword.poqi"); 
                //action = "sword.poqi";
                break;
              case 2:
		perform_action("sword.podao"); 
                //action = "sword.podao";
                break;
              }
           }
           else if ( (string)weapon->query("skill_type") == "staff"
           || (string)weapon->query("skill_type") == "stick"
           || (string)weapon->query("skill_type") == "club" ) {
              switch (random(3)) {
              case 0:	
		perform_action("sword.po"); 
                //action = "sword.po";
                break;
              case 1:
		perform_action("sword.poqi"); 
                //action = "sword.poqi";
                break;
              case 2:
		perform_action("sword.poqiang"); 
                //action = "sword.poqiang";
                break;
              }    
           }
           else if ( (string)weapon->query("skill_type") == "hammer" ) {
              switch (random(3)) {
              case 0:
		perform_action("sword.po"); 
                //action = "sword.po";
                break;
              case 1:
		perform_action("sword.poqi"); 
                //action = "sword.poqi";
                break;
              case 2:
		perform_action("sword.pobian"); 
                //action = "sword.pobian";
                break;
              }
           }
           else if ( (string)weapon->query("skill_type") == "whip" ) {
              switch (random(3)) {
              case 0:
		perform_action("sword.po"); 
                //action = "sword.po";
                break;
              case 1:
		perform_action("sword.poqi"); 
                //action = "sword.poqi";
                break;
              case 2:
		perform_action("sword.posuon"); 
                //action = "sword.posuon";
                break;
              }
           }
           else {
                switch (random(2)) {
              case 0:
		perform_action("sword.po"); 
                //action = "sword.po";
                break;
              case 1:
		perform_action("sword.poqi"); 
                //action = "sword.poqi";
                break;
              }
	}
 		}
		}
		}
		}
	  else if ( !me->query_temp("leidong") ) {	
			me->map_skill("parry", "pishi-poyu");
			me->reset_action();
			return perform_action("cuff.leidong");
		}
	     else return perform_action("strike.wuji");
			

       /* else if ( !me->query_temp("leidong") ) {	
     	                  me->reset_action();
                        return perform_action("cuff.leidong");
        }
        else if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
      	            n();
                        return perform_action("strike.wuji");
        }*/
}
int use_dgjj()
{	
	command("nod");
 	command("unwield blade");
     	command("wield jian");
	 map_skill("sword", "dugu-jiujian");
	 map_skill("parry", "dugu-jiujian");        
	return 1;
}
int use_hsjf()
{
	map_skill("sword", "huashan-jianfa");
	command("nod");
 	command("unwield blade");
     	command("wield jian");
	 map_skill("parry", "huashan-jianfa");        
	return 1;
}
int use_unarmed()
{
	command("nod");
	command("unwield blade");
	command("unwield jian");
	map_skill("parry", "pishi-poyu");
	return 1;
}
int use_lyd()
{
	command("nod");
	command("unwield jian");
	command("wield blade");
	map_skill("parry", "liangyi-dao");
	return 1;
}