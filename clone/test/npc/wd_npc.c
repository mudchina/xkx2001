//Cracked by Roath
// modified from zhang.c 3/00

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "/kungfu/class/wudang/auto_perform.h"

int reset();
int auto_perform();
string ask_tjsg();
string ask_zhenwu();
#define CANPIAN "/kungfu/class/wudang/obj/canpian"

void create()
{

        set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
        set("nickname", "邋遢真人");
        set("long",
                "这就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
                "但见他身穿一袭污秽的灰布道袍，身形高大异常，须发如银，\n"
		"脸上红润光滑，笑眯眯的甚是可亲，此外也无特异情状。\n");
        set("gender", "男性");
        set("age", 100);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 14123);
        set("max_jing", 4000);
	set("eff_jingli", 5000);
	set("max_jingli", 5000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 300);
        set("combat_exp", 6400000);
        set("score", 640000);

        set_skill("force", 400);
        set_skill("taiji-shengong", 400);
        set_skill("dodge", 400);
        set_skill("tiyunzong", 400);
        set_skill("cuff", 400);
        set_skill("taiji-quan", 400);
        set_skill("parry", 400);
        set_skill("sword", 400);
        set_skill("taiji-jian", 400);
        set_skill("taoism", 400);
        set_skill("literate", 400);

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
                (: reset :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        set("inquiry", ([
		"真武剑" : (: ask_zhenwu : ),
		"太极神功" : (: ask_tjsg :),
		"九阳神功" : (: ask_tjsg :)
        ]));

	setup();
	if( clonep() )
	{
		carry_object("/clone/weapon/changjian")->wield();
		carry_object("/d/wudang/obj/greyrobe")->wear();
	}
}

string ask_zhenwu()
{
	object player = this_player();

	if( !player->query("wudang/zhenwu") )
		return "「真武剑」是贫道早年时所用的兵刃。";
}

string ask_tjsg() {
    object *obs, obj, player=this_player();

    if (player->query("family/master_id") != "zhang sanfeng") {
        return "太极神功是我武当派镇派之宝。\n";;
    }
    switch (random(10)) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return "先师觉远大师传授经文，我所学不全，至今虽闭关数次，"+
                "苦苦钻研，仍只能想通得三四成。\n";
    case 5:
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

        obj = 0;
        obs = filter_array(children(CANPIAN), (: clonep :));
        if (sizeof(obs) > 0) obj = obs[0];

        if (objectp(obj) && objectp(environment(obj)) &&
            userp(environment(obj))) {
            return "九阳神功残篇被你师兄弟借走了，你去问他们吧\n";
        }
        if (!objectp(obj)) obj = new(CANPIAN);
        obj->move(player);
        message_vision("$N给$n一部九阳神功残篇。\n", this_object(), player);
	command ("rumor "+this_player()->query("name")+"弄到了一部"NOR YEL"九阳神功残篇"HIM"。"NOR);
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
	object me = this_object();
	mapping skill_status;
	string *sname;
	int i, max = 200;

	command("chat 唉……" + obj->name() + "……" );
	command("chat 贫道都已是半截子入土的人了，居然还想杀死我！拚着这副老骨头不要，只好陪"
	 + RANK_D->query_respect(obj) + "过几招了。");

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
/*
	if( obj->query("combat_exp") > 2000000 )
	{
		me->set("combat_exp", obj->query("combat_exp"));

		if( mapp(skill_status = obj->query_skills()) )
		{
			skill_status = obj->query_skills();
			sname = keys(skill_status);

			for( i=0; i < sizeof(skill_status); i++ )
				if( skill_status[sname[i]] > max )
					max = skill_status[sname[i]];
		}
		if( mapp(skill_status = me->query_skills()) )
		{
			skill_status = me->query_skills();
			sname = keys(skill_status);
			for( i=0; i < sizeof(skill_status); i++ )
				me->set_skill(sname[i],max);
		}
		me->set_skill("taoism", 200);
		me->set_skill("literate", 200);
	}
*/
	return 1;
}

void die()
{
	object ob, me;
	me = this_object();

	if( !living(this_object()) ) revive(1);
	command("chat 贫道纵横江湖近百年，今日始信天外有天，人外有人！");
	if( objectp(ob = me->query_temp("last_damage_from")) )
	{
		command("chat " + ob->name() + "德配天地，威震寰宇，古今无比。");
		command("chat* " + "指着" + ob->name()
		 + "赞叹道：“" + ob->name() + "是古往今来武林第一大宗师！”\n");
	}
	::die();
}

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

int reset()
{
        object me = this_object();
/*
	if( me->query("combat_exp") > 4000000 )
	{
		me->set_skill("force", 400);
		me->set_skill("taiji-shengong", 400);
		me->set_skill("dodge", 400);
		me->set_skill("tiyunzong", 400);
		me->set_skill("cuff", 400);
		me->set_skill("taiji-quan", 400);
		me->set_skill("parry", 400);
		me->set_skill("sword", 400);
		me->set_skill("taiji-jian", 400);
		me->set("combat_exp", 4000000);
	}
*/
	if( me->query("eff_qi") < me->query("max_qi") )
		exert_function("heal");
	me->set("jiali", 300);
	command("wield sword");

	return 1;
}
