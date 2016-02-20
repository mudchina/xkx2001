//Cracked by Roath
// /d/bwdh/sjsz/npc/weishi.c

inherit NPC;

#include <ansi.h>
#include "/kungfu/class/wudang/auto_perform.h"

int reset();
int auto_perform();

#define CANPIAN "/kungfu/class/wudang/obj/canpian"
#define BOARD "/clone/board/bwboard"
string ask_me_huqi();
string ask_me_heal();


void create()
{
		  object zhenwu;

		  set_name("武士", ({ "wu shi", "shi" }));
		  set("long","这是位武士，身披钢甲，手执长剑，双目精光炯炯，警惕地巡视着四周的情形。\n");
		  set("gender", "男性");
		  set("age", 50);
		  set("attitude", "heroism");
		  set("shen_type", 0);
		  set("str", 30);
		  set("int", 30);
		  set("con", 30);
		  set("dex", 30);

		  set("max_qi", 1123);
		  set("max_jing", 3000);
		  set("eff_jingli", 3000);
		  set("max_jingli", 3000);
		  set("neili", 3000);
		  set("max_neili", 3000);
		  set("jiali", 300);
		  set("combat_exp", 6400000);

		  set_skill("force", 200);
		  set_skill("taiji-shengong", 200);
		  set_skill("dodge", 200);
		  set_skill("tiyunzong", 200);
		  set_skill("cuff", 200);
		  set_skill("taiji-quan", 200);
		  set_skill("parry", 200);
		  set_skill("sword", 200);
		  set_skill("taiji-jian", 200);
		  set_skill("taoism", 200);
		  set_skill("literate", 200);

		  map_skill("force", "taiji-shengong");
		  map_skill("dodge", "tiyunzong");
		  map_skill("cuff", "taiji-quan");
		  map_skill("parry", "taiji-jian");
		  map_skill("sword", "taiji-jian");

		  prepare_skill("cuff", "taiji-quan");

		  create_family("武当派", 2, "");
		  set("chat_chance", 80);
		  set("chat_msg", ({
					 (: reset :),
		  }) );

		  set("chat_chance_combat", 50);
		  set("chat_msg_combat", ({
					 (: auto_perform :),
		  }) );

	set("inquiry", ([
		"heal" : (: ask_me_heal :),
		"疗伤" : (: ask_me_heal :),
		"护旗": (: ask_me_huqi :),
		"huqi": (: ask_me_huqi :),
		"试剑山庄": "试剑山庄是闻名遐迩的武林圣地。各路英雄都争相来这里比武。",
		"sjsz": "试剑山庄是闻名遐迩的武林圣地。各路英雄都争相来这里比武。",
	]));


	setup();
	if( clonep() )
	{
		  carry_object("/d/city/obj/gangjian")->wield();
		  carry_object("/d/city/obj/tiejia")->wear();
	}
}


void attempt_apprentice(object ob)
{
		 return;
}

int accept_kill(object obj)
{
	object me = this_object();
	mapping skill_status;
	string *sname;
	int i, max = 200;

	command("say "+RANK_D->query_rude(obj)+"居然还想杀死我！看招！");

	if( !objectp(obj->query_temp("weapon")) || !objectp(me->query_temp("weapon")) )
	{
		command("unwield sword");
		command("enable parry taiji-quan");
	}
	else if( objectp(obj->query_temp("weapon")) )
	{
		command("wield sword");
		command("enable parry taiji-jian");
	}
	command("exert taiji");
	return 1;
}

void die()
{
	object ob, me;
	object board;
	mapping entryA, entryB;
	int i, scoreA,scoreB;

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return ;
	 }
	 entryA = board->query("team/" + board->query("east"));
	 entryB = board->query("team/" + board->query("west"));

	 if( !entryA || !entryB ){ ::die(); return; }

	 scoreA = entryA["this_score"];
	 scoreB = entryB["this_score"];

	me = this_object();

	if( objectp(ob = me->query_temp("last_damage_from")) &&
		 userp(ob) &&
		ob->query("sjsz/team_name") != me->query("sjsz/team_name") )
	{
		ob->add("sjsz/exp",me->query("combat_exp")/20000);
		ob->add("sjsz/this_exp",me->query("combat_exp")/20000);
		ob->add("sjsz/bw_score",me->query("combat_exp")/20000);
		ob->add("sjsz/this_score",me->query("combat_exp")/20000);
		if( ob->query("sjsz/white") )scoreA += me->query("combat_exp")/20000;
		else if( ob->query("sjsz/red") )scoreB += me->query("combat_exp")/20000;
	}

	 entryA["this_score"]=scoreA;
	 entryB["this_score"]=scoreB;

	 board->set("team/" + board->query("east"),entryA);
	 board->set("team/" + board->query("west"),entryB);

	 board->save();

	::die();
}

void init()
{
		  object ob;
		  ::init();
}

int reset()
{
	object me = this_object();
	if( me->query("eff_qi") < me->query("max_qi") )
		exert_function("heal");
	me->set("jiali", 50);
	command("wield sword");

	return 1;
}


string ask_me_heal()
{
	object ob = this_player();
	object me = this_object();

	if( ob->query("sjsz/team_name") != query("sjsz/team_name") )
	{
		me->kill_ob(ob);
		return RANK_D->query_rude(this_player()) + "非本队人马，莫非想来诳我？看招！\n";
	}

	if( ob->query("eff_qi") < ob->query("max_qi") )
		message_vision(HIG"$N看了看$n，痛快地说道：“没问题！”\n"NOR,me,ob);
	else return "你无伤无痕，开我玩笑？";
	command("halt");
	command("exert heal "+ob->query("id"));

	return "好些了吗？";
}

string ask_me_huqi()
{
	object ob = this_player();
	object me = this_object();

	if( ob->query("sjsz/team_name") != query("sjsz/team_name") )
	{
		me->kill_ob(ob);
		return RANK_D->query_rude(this_player()) + "非本队人马，莫非想来诳我？看招！\n";
	}

	if( !environment(me)->query("flag") )
	{
		message_vision(HIG"$N疑惑地四下望望，说道：“可是这里没有旗可护！”\n"NOR,me);
		return "别搞错了！";
    }
	else
	{
		message_vision(HIG"$N看了看$n，痛快地说道：“好吧！我就留下来护旗。”\n"NOR,me,ob);
		command("halt");
		command("follow none");
	}

	return "大家加油干！";
}






