//Cracked by Roath
// Npc: /kungfu/class/emei/jingxuan.c 静玄师太
// Date: shan 96/09/24
// Modified by xQin 8/00
inherit NPC;
inherit F_MASTER;

string ask_for_huansu();
string ask_for_join();
string ask_for_job();
int auto_perform();

void create()
{
        set_name("静玄师太", ({
                "jingxuan shitai",
                "jingxuan",
                "shitai",
        }));
        set("long",
"她就是峨嵋派大弟子静玄师太，在八大静字辈弟子中排行第一，最擅剑法和刀法。\n"
"她身材高大，神态威猛，虽是女子，却比寻常男子还高了半个头。\n"
        );

	set("gender", "女性");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "出家"  : (: ask_for_join :),
                "还俗" : (:ask_for_huansu:),
                "渡世济人" : (:ask_for_job:),
        ]));

	set("age", 50);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 26);

	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 80);
	set("combat_exp", 700000);
	set("score", 5000);

        set_skill("force", 120);
        set_skill("linji-zhuang", 120);
        set_skill("strike", 100);
        set_skill("jinding-zhang", 100);
        set_skill("finger", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("sword", 120);
        set_skill("emei-jian", 120);
        set_skill("blade", 100);
        set_skill("yanxing-dao", 100);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("zhutian-bu", 120);
        set_skill("persuading", 120);
        set_skill("literate", 120);
        set_skill("mahayana", 120);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
        map_skill("sword", "emei-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");
	
	create_family("峨嵋派", 4, "弟子");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}


int do_nod(string arg)
{
        object me = this_player();

        if( !me->query_temp("pending/kao") )
                return 0;

	command("smile");
	command("say 我讲个故事你听：\n");

	message("vision", "静玄师太对着"+me->name()+"讲了几句话。\n",
                        environment(me), ({me}) );

        switch(random(2)) {
		case 0:
                write("静玄师太说：罗汉和尚曾住在峨嵋山延福院里。
            有僧人问他：什么是西来大意？　他说；井中红焰，日里浮沤。
            僧人问：这怎么领会？　罗汉和尚是怎样回答他的呢？\n\n");

		if ((int)me->query_skill("mahayana", 1) > 60 + random(10)) {
			write("你想起在一部书里读到过这个典故。\n");
			write("你说：遥指扶桑日那边。\n\n");
			message("vision", me->name()+"想了一下，跟静玄师太说了几句话。\n",
				environment(me), ({me}) );

                	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
                	command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。\n");
                	command("recruit " + me->query("id"));
		}
		else {
			write("你想了许久，也解不明白其中的禅理。\n");
			command("say 阿弥陀佛，你多学些佛法后再来找我吧。\n");
		}
		break;

		case 1:
                write("静玄师太说：密印安民曾在华藏寺开法。
            密印安民有一次请教名僧圆悟：什么是古帆未挂？
            圆悟说：庭前柏树子。密印安民大悟彻悟后说了什么？\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 + random(10)) {
                        write("你想起在一部经书里读到过这个典故。\n");
                        write("你答道：古人说“一滴投于巨壑”，殊不知大海也投于一滴！。\n\n");
                        message("vision", me->name()+"想了一下，跟静玄师太说了几句话。\n",
                                environment(me), ({me}) );

                        command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
                        command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。\n");
                        command("recruit " + me->query("id"));
                }
		else {
                        write("你想了许久，也解不明白其中的禅理。\n");
                	command("say 阿弥陀佛，你多学些佛法后在来找我吧。\n");
		}
               	break;
	}
        return 1;

} 
 
void init()
{
        object ob;

        add_action("do_kneel", "kneel");

        ::init();
        add_action("do_nod","nod");

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingxuan shitai"
	&& ob->query("shen") < -100) 
	{
       	 	message_vision(
                "$n看着$N说道：你怎么在外边做坏事？\n",
                ob, this_object() );
		command("say 我峨嵋派乃是堂堂名门正派，" +
                        "对弟子要求极严。我不能再收留你，你去吧。\n");
                command("expell " + ob->query("id"));
                return;
        }

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingxuan shitai"
        && ob->query("class") !=  "bonze" )                 
	{
		message_vision(
                        "$n看着$N说道：你既然还了俗，还是去找你俗家师叔学艺吧。\n");
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
}

#include "/kungfu/class/emei/jing3.h"
#include "/kungfu/class/emei/auto_perform.h"
#include "/kungfu/class/emei/nun.h"
#include "/kungfu/class/emei/pers_job.h"

