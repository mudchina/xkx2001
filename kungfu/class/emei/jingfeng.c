//Cracked by Roath
// Npc: /kungfu/class/emei/jingfeng.c 静风师太
// Date: xbc 96/09/22

inherit NPC;

string ask_me_1();
string ask_me_weapon(string);
string ask_for_join();
string ask_for_huansu();
int auto_perform();

void create()
{
        set_name("静风师太", ({
                "jingfeng shitai",
                "jingfeng",
                "shitai",
	}));
	set("long",
		"她是在华藏庵修行的师太，平时在储物间发放峨嵋派的练功武器及药品。\n"
	);

	set("gender", "女性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 600);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 1000);

        set_skill("force", 70);
        set_skill("linji-zhuang", 70);
        set_skill("finger", 70);
        set_skill("tiangang-zhi", 70);
        set_skill("strike", 70);
        set_skill("jinding-zhang", 60);
        set_skill("sword", 70);
        set_skill("emei-jian", 80);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("zhutian-bu", 70);
        set_skill("persuading", 60);
        set_skill("mahayana", 50);
        set_skill("literate", 70);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("sword", "emei-jian");
        map_skill("parry", "emei-jian");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
 
	create_family("峨嵋派", 4, "弟子");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	set_weight(1000000); 

        set("inquiry", ([
                "天香断续膏" :    (: ask_me_1 :),
                "柳叶刀" :    (: ask_me_weapon, "liuyedao" :),
                "软剑" :    (: ask_me_weapon, "ruanjian" :),
                "皮腰带" :    (: ask_me_weapon, "yaodai" :),
                "出家"  : (: ask_for_join :),
                "还俗" : (:ask_for_huansu:),
        ]));

	set("gao_count", 10);
	set("liuyedao_count", 4);
	set("ruanjian_count", 4);
	set("yaodai_count", 8);

	setup();

	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}

string ask_me_weapon(string name)
{
        mapping fam, log; 
        object ob, who = this_player();
	object room = load_object("/d/emei/chuwu");

        if (!(fam = who->query("family")) || fam["family_name"] != "峨嵋派")
                return RANK_D->query_respect(who) + 
                "与本派素无来往，不知此话从何谈起？";

        if (  ob=present(name, who) )
                return RANK_D->query_respect(who) + 
                "你现在身上不是有" + ob->query("name") + "吗，怎麽又来要了？ 真是贪得无餍！";

	log = room->query_temp(name);
	if ( mapp(log) && log[who->query("id")] ) 
		return "我不是刚给过你吗，怎麽又来要了？真是贪得无餍！";

        if ( mapp(log) && sizeof(log) > query(name+"_count"))
                return "抱歉，你来得不是时候，已经发完了。";

        if (name=="yaodai")
	ob = new("/d/emei/obj/yaodai");
	else ob = new("/clone/weapon/" + name);
        ob->move(who);

	room->set_temp(name+"/"+who->query("id"),1);

        message_vision("静风师太给$N一" + ob->query("unit") + ob->query("name") + "。\n", who);

        return "拿去吧。不过要记住，武器防具只可防身练武，不可凭此妨害他人。";
}


string ask_me_1()
{
        mapping fam, log; 
        object ob, who = this_player();
	object room = load_object("/d/emei/chuwu");

        if (!(fam = who->query("family")) || fam["family_name"] != "峨嵋派")
                return RANK_D->query_respect(who) + 
                "与本派素无来往，不知此话从何谈起？";

        if ( (int)who->query_condition("bonze_drug" ) > 0 )
                return RANK_D->query_respect(who) + 
                "你是不是刚敷过药，怎麽又来要了？ 灵药多敷有害无益，过段时间再来吧。";

        if (  present("tian xiang", who) )
                return RANK_D->query_respect(who) + 
                "你现在身上不是有一盒天香断续膏吗，怎麽又来要了？ 真是贪得无餍！";

	log = room->query_temp("tianxiang");

        if ( mapp(log) && log[who->query("id")])
                return "我不是刚给过你一盒天香断续膏吗，怎麽又来要了？ 真是贪得无餍！";

        if ( mapp(log) && sizeof(log) > query("gao_count")) return "对不起，天香断续膏已经发完了";

        ob = new(DRUG_D("tianxiang"));
        ob->move(who);

        room->set_temp("tianxiang/"+who->query("id"),1);

        message_vision("$N获得一盒天香断续膏。\n",this_player());
        return "好吧，记住，不到危急关头不要轻易使用此药。";

}

void init()
{
	::init();
        add_action("do_kneel", "kneel");

}

#include "/kungfu/class/emei/nun.h"
#include "/kungfu/class/emei/jing1.h"
#include "/kungfu/class/emei/auto_perform.h"
