//Cracked by Roath
// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

int auto_perform();
string ask_baicao();
string ask_xhwan();

void create()
{
	set_name("梁长老", ({"liang zhanglao", "liang", "zhanglao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "传功长老");
	set("gender", "男性");
	set("age", 55);
	set("long", 
		"梁长老是丐帮出道最久，武功最高的长老，在武林中享名已久。\n"
		"丐帮武功向来较强，近来梁长老一力整顿，更是蒸蒸日上。\n");

	set("attitude", "peaceful");
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("rank", 9);

	set("qi", 1200);
	set("max_qi", 1200);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 120);
	
	set("combat_exp", 700000);
	
	set_skill("force", 140); 
	set_skill("huntian-qigong", 145); 
	set_skill("strike", 110); 
	set_skill("xianglong-zhang", 110); 
	set_skill("hand", 140); 
	set_skill("shexing-diaoshou", 145); 
	set_skill("dodge", 130); 
	set_skill("xiaoyaoyou", 130); 
	set_skill("parry", 140); 
	set_skill("blade", 150); 
	set_skill("liuhe-dao", 150); 
	set_skill("begging", 100); 
	set_skill("checking", 120);
	
	map_skill("force", "huntian-qigong");
	map_skill("strike","xianglong-zhang");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("blade", "liuhe-dao");
	map_skill("dodge", "xiaoyaoyou");
	
	prepare_skill("strike", "xianglong-zhang");

	set("baicao", 10);
	set("xhwan", 10);
	set("chat_chance", 3);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	create_family("丐帮", 18, "九袋长老");

	set("inquiry", ([
	    "雄黄丸" : (: ask_xhwan :),
	    "百草丹" : (: ask_baicao :),
//          "job" : (: ask_job :),
	]));

	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(8);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object ob;
	mapping myfam;
	
	::init();
	set_heart_beat(1);
	if (interactive(ob = this_player()) && !is_fighting()) 
	{
		myfam = (mapping)ob->query("family");
		if (!wizardp(ob) && (!myfam || myfam["family_name"] != "丐帮")
		&& environment(this_object())->query("short") =="树洞下")
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	message_vision("\n粱长老看到$N闯进来，大喝一声：你不是丐帮弟子，给我滚出去！\n\n", ob);
	call_out("kicking", 3, ob);     
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/gaibang/inhole");
	message("vision","只听“乒”地一声，" + ob->query("name") +
		"从小门里飞了出来。\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
/*
	if (ob->query("class")=="bonze") {
		if (ob->query("gender")=="女性")
			command ("say 师太是是出家人，怎么能在本帮做叫化子呢？");
		return;
	}
*/
	if ((int)ob->query_str() < 28) {
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "臂力太弱，似乎不宜学丐帮的功夫？");
		return;
	}

	if( ob->query("family/family_name") != "丐帮" )
	{
		if( ob->query("rank") > 1 ) {
			command("say 本帮以忠义为先，可容不下你这种无信无义的家伙！\n");
			return;
		}

		command("say 好吧，希望" + RANK_D->query_respect(ob) +
		"能好好学习本门武功，将来在江湖中闯出一番作为。");
		ob->set("rank", 1); 
		command("recruit " + ob->query("id"));
		ob->set("title", "丐帮一袋弟子");
	} 
	else
	{
		ob->set_temp("title", ob->query("title"));
		command("recruit " + ob->query("id"));
		ob->set("title", ob->query_temp("title"));
		ob->delete_temp("title");
	}
}

string ask_xhwan()
{
	object me = this_object(), ob = this_player(), wan;

	if ( !ob->query("family") || ob->query("family/family_name") != "丐帮" ) {
		return "你非本帮弟子，怎能索取本帮灵药？\n\n";
	}

	if ( !ob->query_condition("xx_poison") || !ob->query_condition("snake_poison")
	|| !ob->query_condition("insect_poison") ) {
		message_vision("$N向$n脸上仔细地打量了一阵，便皱起眉头。\n", me, ob);
		return "你并未中毒，要雄黄丸干吗？\n\n";
	}

	message_vision("$N向$n脸上仔细地打量了一阵，抓起$n手腕打脉。\n", me, ob);

	if ( me->query("xhwan") < 1 ) {
		message_vision("然後$N伸手入怀，但摸索良久，似乎没找着。\n", me);
		return "我身上此刻没有雄黄丸，你还是快到城里去找大夫吧！\n\n";
	}

	me->add("xhwan", -1);
	wan = new(DRUG_D("xh-wan"));
	wan->move(ob);

	message_vision("然後$N伸手入怀，取出一颗雄黄丸给$n。\n", me, ob);
	return "快把雄黄丸吃下，别要让毒素入侵内腑！\n\n";
}

string ask_baicao()
{
	object me = this_object(), ob = this_player(), wan;

	if ( !ob->query("family") || ob->query("family/family_name") != "丐帮" ) {
		return "你非本帮弟子，怎能索取本帮灵药？\n\n";
	}

	if ( (int)ob->query("eff_qi")==(int)ob->query("max_qi")
	&& (int)ob->query("eff_jing")==(int)ob->query("max_jing") ) {
		message_vision("$N向$n脸上仔细地打量了一阵，便皱起眉头。\n", me, ob);
		return "你并未受伤，要百草丹干吗？\n\n";
	}

	message_vision("$N向$n脸上仔细地打量了一阵，抓起$n手腕打脉。\n", me, ob);

	if ( me->query("baicao") < 1 ) {
		message_vision("然後$N伸手入怀，但摸索良久，似乎没找着。\n", me);
		return "我身上此刻没有百草丹，你还是快到城里去找大夫吧！\n\n";
	}

	me->add("baicao", -1);
	wan = new(DRUG_D("baicao-dan"));
	wan->move(ob);

	message_vision("然後$N伸手入怀，取出一颗百草丹给$n。\n", me, ob);
	return "快把百草丹吃下，别要让伤势继续加重！\n\n";
}

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 100);

                return 1;
        }

	if ( !me->query_temp("powerup") ) {
		return exert_function("powerup");
	}

	if ( !me->query_temp("shengang") ) {
		return exert_function("shengang");
	}

	if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "blade" )
			return perform_action("blade.lianhuan");
	}
	else
		return perform_action("strike.leiting");
}       

#include "/kungfu/class/gaibang/promote.h"
