//Cracked by Roath
// Npc: /kungfu/class/emei/jingkong.c 静空师太
// Date: xbc 99/09/24
// Modified by xQin 8/00
inherit NPC;
inherit F_MASTER;
string ask_for_huansu();
string ask_for_join();
int auto_perform();

void create()
{
        set_name("静空师太", ({
                "jingkong shitai",
                "jingkong",
                "shitai",
	}));
	set("long",
		"她是一位慈祥的中年师太，在万年庵修行。\n"
		"她是灭绝师太的八大静字辈弟子之四，最擅刀法与掌法。\n"
	);

	set("gender", "女性");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "出家"  : (: ask_for_join :),
                "还俗" : (:ask_for_huansu:),
        ]));

	set("age", 38);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 70);
	set("combat_exp", 600000);
	set("score", 1000);

        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
	set_skill("finger", 110);
	set_skill("tiangang-zhi", 110);
        set_skill("strike", 100);
        set_skill("jinding-zhang", 100);
        set_skill("blade", 110);
        set_skill("yanxing-dao", 110);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("zhutian-bu", 90);
        set_skill("persuading", 110);
        set_skill("mahayana", 110);
        set_skill("literate", 120);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
//        map_skill("sword", "emei-jian");
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

        carry_object("/clone/weapon/gangdao")->wield();
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

	message("vision", "静空师太对着"+me->name()+"讲了几句话。\n",
                        environment(me), ({me}) );

        switch(random(3)) {
		case 0:
                write("静空师太说：白水禅师曾住在我们万年庵，那时叫白水寺。
            有个僧人问他：什么是祖师西来意？　白水禅师是怎样回答他的呢？\n\n");

		if ((int)me->query_skill("mahayana", 1) > 60 + random(5)) {
			write("你想起在一部经书里读到过这个故事。\n");
			write("你说：四溟无窑宅，一滴润乾坤。\n\n");
			message("vision", me->name()+"想了一下，跟静空师太说了几句话。\n",
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
                write("静空师太说：白水禅师曾住在我们万年庵，那时叫白水寺。
            有个僧人问他：禅宗六祖一路，应谈何事？　白水禅师是怎样回答他的呢？\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 + random(5)) {
                        write("你想起在一部经书里读到过这个故事。\n");
                        write("你答道：涧松千载鹤来聚，月中香桂凤凰归。\n\n");
                        message("vision", me->name()+"想了一下，跟静空师太说了几句话。\n",
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

		case 2:
                write("静空师太说：白水禅师曾住在我们万年庵，那时叫白水寺。
            有个僧人问他：什么是此经，即佛性？　白水禅师是怎样回答他的呢？\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 ) {
                        write("你想起在一部经书里读到过这个故事。\n");
                        write("你答道：抛梭石女辽空响，海底泥牛夜叫频。\n\n");
                        message("vision", me->name()+"想了一下，跟静空师太说了几句话。\n",
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
	&& ob->query("family/master_id") == "jingkong shitai"
	&& ob->query("shen") < -100) 
	{
       	 	message_vision(
                "$n看着$N说道：你怎么在外边做坏事？\n",
                ob, this_object() );
		command("say 我峨嵋派乃是堂堂名门正派，" +
                        "对弟子要求极严。我不能再收留你，你去吧。\n");
                command("expell " + ob->query("id"));
		ob->delete("emei_shen");
                return;
        }

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingkong shitai"
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

