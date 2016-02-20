//Cracked by Roath
// zhang.c 张三丰

inherit NPC;
inherit F_MASTER;

int auto_perform();
string ask_tjsg();
#define CANPIAN "/kungfu/class/wudang/obj/canpian"

void create()
{
	object zhenwu;

	set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "邋遢真人");
	set("long", 
		"他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
		"身穿一件污秽的灰色道袍，不修边幅。\n"
		"身材高大，年满百岁，满脸红光，须眉皆白。\n");
	set("gender", "男性");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 300);
	set("combat_exp", 2000000);
	set("score", 500000);

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

	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");
	set("chat_chance", 80);
	set("chat_msg", ({
		(: auto_perform :),
	}) );

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("inquries", ([
	    "太极神功" : (: ask_tjsg :),
	    "九阳神功" : (: ask_tjsg :)
	]));

	setup();
	zhenwu=carry_object("/clone/unique/zhenwu");
	if (objectp(zhenwu)) zhenwu->wield();
}

string ask_tjsg() {
    object obj, player=this_player();

    if (player->query("family/master_id") != "zhang sanfeng") {
	return 0;
    }
    switch (random(10)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
	return "先师觉远大师传授经文，我所学不全，至今虽闭关数次，"+
		"苦苦钻研，仍只能想通得三四成。\n";
    case 6:
    case 7:
    case 8:
    	return "先师觉远大师学得《九阳真经》，圆寂之前背诵经文，郭襄女侠、"+
	      "少林派无色大师和我三人各自记得一部分，\n"+
		"因而武当、峨嵋、少林三派武功大进，数十年来分庭抗礼，名震武林。\n";
    case 9:
	if (player->query_skill("taiji-shengong", 1) < 200) {
	    return "你的功力尚浅，好好学全了武当太极功再说吧。\n";
	}
	obj = find_object(CANPIAN);
	if (objectp(obj) && userp(environment(obj))) {
	    return "九阳神功残篇被你师兄弟借走了，你去问他们吧\n";
	}
	if (objectp(obj)) {
	    obj->move(player);
	}else {
	    obj = new(CANPIAN);
   	}
	message_vision("$N给$n一部九阳神功残篇。\n", this_object(), player);
        return "我将心中记得的一些九阳神功笔录在此，\n"+
		"你可找一位少林派高手与之共同参悟(canwu)，也好让这功夫不至于失传。\n";
    }
    return 0;
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "武当派" )
        {
                command ("say " + RANK_D->query_respect(this_player())
                        + "并非我门中人，习武还是先从各位道长起吧！");
                return;
        }

	if ((string)ob->query("family/family_name") == "丐帮" && ob->query("rank") > 1 ) {
		command("say " + RANK_D->query_respect(ob) + "是丐帮高手，恕我不能收你。");
                return;
        }

	if ((int)ob->query_skill("taiji-shengong", 1) < 100) {
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在太极神功上多下点功夫？");
		return;
	}
	if ((int)ob->query("shen") < 100000) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if (ob->query_int() < 30) {
		command("say 我武当派武功全从道藏悟出。");
		command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("chat 哈哈哈哈！！！！");
	command("chat 想不到老道在垂死之年，又觅得" + ob->name() + "这么一个可塑之才，真是可喜可贺。");
	command("recruit " + ob->query("id"));
}

int accept_kill(object obj)
{
	command("chat 唉……" + obj->name() + "……" );
       command("chat 贫道都已是半截子入土的人了，居然还想杀死我！拚着这副老骨头不要，只好陪" + RANK_D->query_respect(obj) + "过几招了。");
	return 1;
}


#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

void die()
{
	object corpse, killer;
	int i;
	string str, mykiller;

	if( !living(this_object()) ) revive(1);
        command("chat 贫道纵横江湖近百年，今日始信天外有天，人外有人！");
	// Clear all the conditions by death.
	this_object()->clear_condition();

	if( objectp(killer = query_temp("last_damage_from")) ) {
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
                command("chat " + killer->name() + "德配天地，威震寰宇，古今无比");
        	command("chat* " + "张三丰指着" + killer->name()
	 + "赞叹道：“" +  killer->name() + "是古往今来武林第一大宗师！”\n");
	} else 
		killer = this_object();
	corpse = new("/clone/misc/corpse");
	corpse->set("my_killer", killer->query("id"));
	corpse->set("victim_name", "张三丰");
	corpse->set("combat_exp", 2000000);
	corpse->set("name", "张三丰的尸体");
	corpse->set("gender", "男性");
	corpse->set("long",
                "他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "身穿一件污秽的灰色道袍，不修边幅。\n"
                "身材高大，年满百岁，满脸红光，须眉皆白。\n\n"
		"然而，他已经死了，只剩下一具尸体静静地躺在这里。\n" );

	corpse->move(environment(this_object()));

//	COMBAT_D->announce(this_object(), "dead");

//	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
//		corpse->move(environment());

//	this_object()->remove_all_killer();
//	all_inventory(environment())->remove_killer(this_object());

//	this_object()->dismiss_team();
	destruct(this_object());
}

#include "/kungfu/class/wudang/auto_perform.h"
void init()
{
        object ob;

        ::init();
        if (interactive(ob=this_player())) {
        if (ob->query("family/master_id") == "zhang sanfeng"
        && (ob->query("shen") < -100
          || time() < (int)ob->query("incharge") + 864000)) {
                command("say " + RANK_D->query_rude(ob) + "胆敢瞒着我在外胡作非为！");
                command("expell " + ob->query("id"));
        }
	}
}
