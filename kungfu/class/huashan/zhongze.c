//Cracked by Roath

// zezhong.c 宁中则
// qfy July 4, 1996.

inherit NPC;
inherit F_MASTER;

int auto_perform();
string ask_me();

void create()
{
	set_name("宁中则", ({ "ning zhongze", "ning", "zhongze" }));
	//set("nickname", "君子剑");
	set("long", 
"这便是华山当代掌门夫人。她在江湖中侠名不下于岳不群，是个\n"
"不让须眉的女中豪杰。武功与岳不群不相上下。\n");
	set("gender", "女性");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 37);
	set("int", 20);
	set("con", 20);
	set("dex", 37);

	set("max_qi", 2000);
	set("max_jing", 1850);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 120);
	set("combat_exp", 900000);
	set("score", 5000);
	set("env/wimpy",60);

	set_skill("force", 140);
	set_skill("dodge", 145);
	set_skill("parry", 140);
	set_skill("sword", 145);
	set_skill("strike", 140);
	set_skill("huashan-jianfa", 145);
	set_skill("hunyuan-zhang",140);
	set_skill("huashan-shenfa", 145);
	set_skill("zixia-gong", 140);
	set_skill("cuff", 140);
	set_skill("pishi-poyu", 140);
	set_skill("ziyin-yin", 110);
	set_skill("zhengqi-jue", 110);
	set_skill("literate", 140);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("华山派", 13, "掌门夫人");

	set("inquiry", ([
		 "剑宗" : (: ask_me :),
		 "气宗" : (: ask_me :),
	    "岳不群" : "他是我外子。\n",
	    "岳灵姗" : "她是我女儿。\n",
	    "紫霞功" : "那是本门至高无上的内功心法。\n",
	    "紫霞神功" : "那是本门至高无上的内功心法。\n",
	    "思过崖" : "那是本派弟子修行思过之处。\n",
	    "风清扬" : "他是我师叔，不过你还是问我外子吧。\n",
	]));

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/pink_cloth")->wear();
}

void init()
{
	object ob;

	::init();

	set_heart_beat(1);

	if (interactive(ob=this_player()) && ob->query("family/master_id") == "ning zhongze"
	&& ob->query("shen") < -100 ) {
		command("say " + RANK_D->query_rude(ob) + "胆敢瞒着我在外胡作非为！" );
		command( "expell " + ob->query("id"));
	if ( this_object()->query("qi") < 2200 ) {
		exert_function("heal");
		exert_function("heal");
		exert_function("heal");
		exert_function("recover");
		return 0;
	}

	}
}

void attempt_apprentice(object ob)
{

	if (ob->query("class")=="bonze") {
		command ("say 华山派一向不收出家人为徒，你请回吧。");
		return;
	}

	if ((string)ob->query("gender") == "男性") {
		command("say 我不收男徒，" + RANK_D->query_respect(ob) + "还是拜入我外子门下吧。");
		return;
	} 

	if ((string)ob->query("gender") == "无性") {
		command("say " + RANK_D->query_respect(ob) + "是东厂中人，恕我不能收你。");
		return;
	}

	if ((string)ob->query("family/family_name") == "丐帮" && ob->query("rank") > 1 ) {
		command("say " + RANK_D->query_respect(ob) + "是丐帮高手，恕我不能收你。");
		return;
	}

	if( ob->query("family/family_name") != "华山派" && ob->query("combat_exp") >= 10000 ) {
		command ("say " + RANK_D->query_respect(this_player()) + "是"
			+ob->query("family/family_name")+"高手，本派可不敢收留！");
		return;
	}

	if ((int)ob->query("huashan/ning") == 1 && (int)ob->query("betrayer") > 10) {
		command("say " + RANK_D->query_respect(ob) + "是个出名的反覆之人，叫我如何信得过你？");
		return;
	}

	if ((int)ob->query("shen") < 0) {
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say "+RANK_D->query_respect(ob)+"非我辈中人，恕我不能收你。");
		return;
	}
       
	command("say 好吧，我就收下你了。希望你能为华山争光，造福武林。");
	ob->set("huashan/ning", 1);
	ob->set("betrayer", 0);
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	object me = this_player();
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( !myfam || myfam["family_name"] != "华山派" )
		return "咱们豪无渊源，你问这事干嘛？\n";

	say("宁则中长长地叹了一气，语重心长地说道：“华山不幸曾分为气剑二宗。咱\n");
	say("们气宗奉气为主，以剑为辅，以气运剑，无坚不摧。而剑宗则倒行逆施重剑\n");
	say("轻气。二宗各持己见，终于水火不容，同门操戈！华山因此式微。你即入我\n");
	say("门，盼你能洁身自爱，重振华山！记得当年匾额上写的是「剑气冲霄」，结\n");
	say("果剑宗虽剑路纵横，变化无方，可仍然败在我宗「紫霞神功」之下，数十年\n");
	say("来不复再现，实异不胜正也。”\n");
	return "切记！切记！\n";
}


int accept_fight(object ob)
{
	object me = this_object();
	int my_max_qi; 
	
	my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
		me->command("say 我身体不适，恕不奉陪！");
		me->set("qi",me->query("eff_qi",1)+20);
		return 0;
	}

	if ( me->query("neili")<1500 ) {
		return 0;
	}

	auto_perform();

	return 1;
}

int accept_kill(object ob)
{
	object me = this_object();
	object ob1 = this_player();

	// if unconcious then do nothing
	if( me->query("qi",1) <= 0 || me->query("jing",1) <= 0 || me->query("jingli",1) <= 0) return 1;

	// if qi low, escape
	if ( me->query("eff_qi",1) < 1300 || me->query("neili",1) < 500) {
		me->command("halt");
		me->random_move();
		return 1;
	}

	me->command("say 原来你是个奸诈之徒，今天就让我为民除害！");
	me->command("follow " + ob1->query("id") );
	ob1->set_temp("kill_ning",1);
	me->set_leader(ob1);
	me->kill_ob(ob1);

	if ( me->query("eff_qi") < 1500 ) {
		me->set("eff_qi",1500);
	}

	me->set_temp("apply/armor", 120);
	me->set_temp("apply/damage", 50);
	me->set_temp("apply/dodge", 120);
	me->set_temp("apply/attack", 50);
	//me->setup();
	me->auto_perform();
	return 1;
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 100);

					 return 1;
		  }

		  if ( objectp(weapon) ) {
					 if ( weapon->query("skill_type") == "sword" )
								return perform_action("sword.jianzhang");
		  }
		  else if ( !me->query_temp("leidong") ) {
			return perform_action("cuff.leidong");
	}
	else if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
			return  perform_action("strike.wuji");
	}
}
