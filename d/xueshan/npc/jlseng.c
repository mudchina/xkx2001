//Cracked by Roath
// snowbird 1/1999.

inherit NPC;

int auto_perform();
int auto_robot();
int get_help(int help_level);
int get_killer(object killer);
int perpare_fight (object target);

mapping HELP_STAT = ([]);

void create()
{
	set_name("戒律僧", ({ "jielv seng", "seng" }));
	set("long", 
"他是密宗的戒律僧，长得膀大腰圆，手中提着法器，身着黄袍，头戴黄帽，\n"
"满面肃杀之气。他是大轮明王亲自选来守护寺内宝物的。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "heroism");
	set("class","lama");
	set("shen_type", -1);

    set("str", 40);
    set("int", 25);
    set("con", 35);
    set("dex", 25);

	set("max_jing",2000);
	set("max_qi",1800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	set("score", 5000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("hammer", 200);
	set_skill("cuff", 200);
	set_skill("hand", 200);
    set_skill("literate", 120);

//	set_skill("hamagong", 200);
	set_skill("shenkongxing", 200);
	set_skill("riyue-lun", 200);
	set_skill("longxiang-banruo", 180);
	set_skill("yujiamu-quan", 200);
	set_skill("huoyan-dao", 200);
	set_skill("dashou-yin", 200);
    set_skill("necromancy", 150);
	set_skill("lamaism", 180);

	map_skill("cuff", "yujiamu-quan");
	map_skill("hand", "dashou-yin");
	map_skill("strike", "huoyan-dao");
	map_skill("hammer", "riyue-lun");
	map_skill("dodge", "shenkongxing");
    map_skill("force", "longxiang-banruo");
    map_skill("parry", "riyue-lun");

	prepare_skill("cuff", "yujiamu-quan");
	prepare_skill("hand", "dashou-yin");

    set("inquiry", ([
    ]) );

	set("chat_chance_combat", 60);
	set("chat_msg_combat", 
	({
		(: auto_perform :),
	}) );

	// no biaoju npc
	set("winner",1);
    setup();

    carry_object("/clone/weapon/falun")->set_amount(5);
    carry_object("/d/xueshan/obj/lamajiasha")->wear();
    carry_object("/d/xueshan/obj/rtlian")->wear();
    carry_object("/d/xueshan/obj/klguan")->wear();
    carry_object("/d/xueshan/obj/lubo");
	carry_object("/clone/drug/jinchuang")->set_amount(2);

    remove_call_out("auto_robot");
    call_out("auto_robot", 3+random(5) );

}


void init()
{
        object ob;
        mapping myfam;

        ::init();
        if (interactive(ob = this_player()) && 
			 present("juan na xiang", this_player())) {
             myfam = (mapping)ob->query("family");
             if (!myfam || myfam["family_name"] != "雪山派"
             && myfam["family_name"] != "血刀门" )
			 {
                remove_call_out("kill_target");
                call_out("kill_target", 1, ob);
			 }
        }
}

void kill_target(object ob)
{
    perpare_fight (ob);
    kill_ob(ob);
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	
//	if (ob->query_temp("mark/comin"))
//                say( "葛伦布双手合什笑咪咪地说道：这位" + RANK_D->query_respect(ob)
//                                + "，扎西德勒！\n");
//	else
//                say( "葛伦布双手合什笑咪咪地说道：这位" + RANK_D->query_respect(ob)
//                                + "，喀列别！\n");
}

int auto_robot()
{
    int point, i, add_exp, nei, new_qi, old_qi, flag1, poisoned, s;
	object me = this_object();
    mapping skill_status;
    string *sname;
	object drug1;

	flag1 = 0;
	poisoned = 0;
	point = 900;
	if ( !me->is_fighting() )
	{
/*        if ((int)me->query_condition("snake_poison") > 0) 
			  poisoned = 1;
        if ((int)me->query_condition("insect_poison") > 0) 
			  poisoned = 1;
        if ((int)me->query_condition("bt_poison") > 0) 
			  poisoned = 1;
        if ((int)me->query_condition("sl_poison") > 0) 
			  poisoned = 1;
        if ((int)me->query_condition("xx_poison") > 0) 
			  poisoned = 1;

		if(poisoned)
		{
            map_skill("force", "hamagong");
			me->reset_action();
			exert_function("qudu");
		}
		// help partner
		if (HELP_STAT["poison"] == 1){
            map_skill("force", "hamagong");
			me->reset_action();
			exert_function("xidu ygkent");
			HELP_STAT["poison"] = 0;
		}	   */

        map_skill("force", "longxiang-banruo");

		if ( me->query("eff_qi") < me->query("max_qi") ) {
			if ( me->query("eff_qi") < (me->query("max_qi")/2) ) {
				drug1=new("/clone/drug/jinchuang");
				drug1->move(me);
				command("apply jinchuang");
			}
			else
			    exert_function("heal");
		}
		else if (( me->query("neili") > me->query("max_neili")*7/4 ) && random(5))
		{
			skill_status = me->query_skills();
			i = random(8);
			switch (random(5))
			{
			case 0:
				command("wield lun");
				command("practice hammer 15");
				command("unwield lun");
				s = skill_status["riyue-lun"];
				if (i==0) {
				   if ((s*s*s/10) < me->query("combat_exp") ) 
	                 set_skill("riyue-lun", skill_status["riyue-lun"]+1);
				}
				break;
			case 1:
				command("unwield lun");
				command("practice cuff 15");    
				s = skill_status["yujiamu-quan"];
				if (i==0) {
				   if ((s*s*s/10) < me->query("combat_exp") ) 
	                 set_skill("yujiamu-quan", skill_status["yujiamu-quan"]+1);
				}
				break;
			case 2:
				command("unwield lun");
				command("practice hand 15");    
				s = skill_status["dashou-yin"];
				if (i==0) {
                   if ((s*s*s/10) < me->query("combat_exp") ) 
	                 set_skill("dashou-yin", skill_status["dashou-yin"]+1);
				}
				break;
			case 3:
				command("unwield lun");
				command("practice strike 15");    
				s = skill_status["huoyan-dao"];
				if (i==0) {
				   if ((s*s*s/10) < me->query("combat_exp") ) 
    	             set_skill("huoyan-dao", skill_status["huoyan-dao"]+1);
				}
				break;
			case 4:
				command("practice dodge 15");
				s = skill_status["shenkongxing"];
				if (i==0) {
				   if ((s*s*s/10) < me->query("combat_exp") ) 
	                 set_skill("shenkongxing", skill_status["shenkongxing"]+1);
				}
				break;
			}
			if (i==0) {
				 if (random(4) == 0) {
		 		     add_exp = 1000 + random(1000);
                     me->add("combat_exp", add_exp);
				 }
				 else 
		             me->add("max_neili", 1 );
			}
		}
		else {
		   flag1 = 1;
		   command("dazuo 300");
		}
        
		nei = me->query("max_neili") - 3000;
		new_qi = ((int)nei/2);
		old_qi = me->query("max_qi");
		me->set("max_qi",1800+new_qi);
	}
	remove_call_out("auto_robot");
	call_out("auto_robot", 1+flag1*20+random(10), me);

	return 1;

}

int accept_fight(object ob)
{

	return 0;

}

int accept_kill(object ob)
{
	object me = this_object();
	object *inv;
	int i;
     
	// get partner's help

   inv = all_inventory(environment(me));
   for( i=0; i<sizeof(inv); i++ )
   {
       	if ( (inv[i]->query("id") == "jielv seng") && (inv[i] != me) )
			    	inv[i]->get_killer(ob);
   }
   return perpare_fight(ob);
}

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");
	object *inv;
	string name1;
	int i;

	if ( !objectp(target) ) return 0;

	// get partner's help
    if ( me->query("eff_qi") < (me->query("max_qi")/5*4) ) {

    	inv = all_inventory(environment(me));
     	for( i=0; i<sizeof(inv); i++ )
     	{
	    	if ( (inv[i]->query("id") == "jielv seng") && (inv[i] != me) )
			    	inv[i]->get_killer(target);
		}
	}
	command ("bei none");
	me->prepare_skill("cuff", "yujiamu-quan");
	me->prepare_skill("hand", "dashou-yin");

    if ( me->query("neili") > 600 ) 
       exert_function("shield");

    if ( me->query("neili") > 1000 ) 
       exert_function("longxiang");

	if ( objectp(weapon) && weapon->query("skill_type") == "hammer")
	{
		me->map_skill("parry", "riyue-lun");
		me->set("jiali",0);
		me->reset_action();
		if (random(5) == 0) {
		   command("unwield lun");
		}
	}
	else if ( target->query("combat_exp") < me->query("combat_exp")	&& random(10) == 0 )
	{
		if ( me->query("neili") > 600 ) {
	       command("unwield lun");
		   command("wield lubo");
    	   exert_function("sing "+target->query("id"));
		   command("unwield lubo");
		   command("wield lun");
		}
	}
	else if (me->query("neili") < 1000) {
 		   command("wield lun");
    	   me->set("jiali",0);
	       me->reset_action();
	}
	else
	{
		me->map_skill("parry", "huoyan-dao");
		me->set("jiali",150);
		me->reset_action();
		// use fen only when my exp is close to targets'
		if ( !target->is_busy() && (me->query("neili")>1000) && target->query("combat_exp") < me->query("combat_exp")*1.2 )
		{
			command("bei none");
			me->prepare_skill("strike", "huoyan-dao");
			me->reset_action();
			return perform_action("strike.fen");
		}
	}
}

int get_help (int help_level) 
{
   switch(help_level) 
   {
      case 1:
         HELP_STAT["poison"] = 1;
		 break;
   }
   return 1;

}

int get_killer(object killer) {

	object me = this_object();

	if ( !me->is_fighting() ) {
       message_vision("$N大喝一声，竟敢谋害我师兄，拿命来！！！\n", this_object());
	   perpare_fight (killer);
	   kill_ob(killer);
	}
}

int perpare_fight (object ob) {

	object me = this_object();

	if ( me->query_temp("pending/exercise") )
		command("halt");

    if ( me->query("neili") > 600 ) 
       exert_function("shield");

    if ( me->query("neili") > 1000 ) 
       exert_function("longxiang");

	if ( ob->query("combat_exp") < (int)(me->query("combat_exp")*3/4) )
	{
		if ( me->query("neili") > 600 ) {
	       command("unwield lun");
		   command("wield lubo");
    	   exert_function("sing "+ob->query("id"));
		   command("unwield lubo");
		}
	}
	if (random(3)) {
		me->set("jiali",0);
	    command("wield lun");
	}

	return 1;
}

void destroy (object ob)
{
        destruct(ob);
        return;

}
