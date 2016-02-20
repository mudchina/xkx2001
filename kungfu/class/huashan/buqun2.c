//Cracked by Roath
// buqun.c 岳不群
// qfy July 4, 1996.

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int auto_perform();

void create() 
{
	set_name("岳不群", ({ "yue buqun", "yue", "buqun" }));
	set("nickname", "君子剑");
	set("long",
"这便是华山当代掌门「君子剑」岳不群。他在江湖中侠名远播，\n"
"疾恶如仇，甚得人心。他看起来文绉绉地似个书生，武功却是深\n"
"不可测。\n");
	set("gender", "无性");
	set("age", 46);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 49);
	set("int", 20);
	set("con", 20);
	set("dex", 49);
	set_temp("apply/armor", 120);
	set_temp("apply/damage", 50);
	set_temp("apply/dodge", 120);
	set_temp("apply/attack", 50);
	set("env/wimpy",60);

	set("max_qi", 2000);
	set("qi", 2500);
	set("max_jing", 1800);
	set("neili", 3800);
	set("max_neili", 3800);
	set("jiali", 120);
	set("combat_exp", 950000);
	set("score", 5000);

	set_skill("force", 150);
	set_skill("dodge", 170);
	set_skill("parry", 140);
	set_skill("sword", 145);
	set_skill("strike", 140);
	set_skill("huashan-jianfa", 145);
	set_skill("hunyuan-zhang",140);
	set_skill("zixia-gong", 150);
	set_skill("huashan-shenfa", 170);
	set_skill("pixie-jian", 180);
	set_skill("cuff", 140);
	set_skill("pishi-poyu", 140);
	set_skill("ziyin-yin", 110);
	set_skill("zhengqi-jue", 110);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "pixie-jian");
	map_skill("sword", "pixie-jian");
	map_skill("strike","hunyuan-zhang");
	map_skill("dodge","pixie-jian");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("华山派", 13, "掌门");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	setup();
	carry_object("/d/quanzhou/obj/xiuhua")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	object ob, me = this_object();

	::init();

	set_heart_beat(1);

	if ( interactive(ob = this_player()) ) {
	  if ( ob->query("family/family_name") != "华山派" )
		me->kill_ob(ob);

		remove_call_out("checking");
		call_out("checking", 1, me, ob);
	}
}

int checking(object me, object ob)
{
	object obj;

	if ( !me->is_fighting() ) {
		obj = new(__DIR__"buqun");
		obj->move(environment(me));
		obj->set("eff_qi", me->query("eff_qi"));
		obj->set("qi", me->query("qi"));
		obj->set("neili", me->query("neili"));
		obj->set("eff_jing", me->query("eff_jing"));
		obj->set("jing", me->query("jing"));
		destruct(me);
	}

	if ( present(ob, environment()) ) call_out("checking", 1, me, ob);

	return 1;
}

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

		  if ( objectp(weapon) ) {
					 if ( weapon->query("skill_type") == "sword" )
								return perform_action("sword.cimu");
		  }
		  else if ( !me->query_temp("leidong") ) {
								return perform_action("cuff.leidong");
		  }
		  else if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
								return perform_action("strike.wuji");
		  }
}
