//Cracked by Roath
// Npc: /kungfu/class/emei/jinghui.c 静慧师太
// Date: xbc 99/06/22
// Modified by xQin 8/00

inherit NPC;
inherit F_MASTER;

string ask_for_huansu();
string ask_for_join();
int auto_perform();

void create()
{
        set_name("静慧师太", ({
                "jinghui shitai",
                "jinghui",
                "shitai",
	}));
	set("long",
		"她是一位慈祥的中年师太，在千佛庵修行。\n"
		"她是灭绝师太的八大静字辈弟子之四，最擅长剑法与指法。\n"
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
	set("neili", 1300);
	set("max_neili", 1300);
	set("jiali", 70);
	set("combat_exp", 600000);
	set("score", 1000);

        set_skill("force", 100);
        set_skill("linji-zhuang", 100);
        set_skill("finger", 110);
        set_skill("tiangang-zhi", 110);
	set_skill("strike", 90);
	set_skill("jinding-zhang", 90);
        set_skill("sword", 110);
        set_skill("emei-jian", 110);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("zhutian-bu", 100);
        set_skill("persuading", 100);
        set_skill("mahayana", 100);
        set_skill("literate", 100);

        map_skill("force", "linji-zhuang");
        map_skill("finger", "tiangang-zhi");
        map_skill("strike", "jinding-zhang");
        map_skill("sword", "emei-jian");
        map_skill("parry", "tiangang-zhi");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("finger", "tiangang-zhi");
	prepare_skill("strike", "jinding-zhang");

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

	message("vision", "静慧师太对着"+me->name()+"讲了几句话。\n", environment(me), ({me}) );

        switch(random(2)) {
		case 0:
		write("静慧师太说：赵州从谂，乃是禅宗著名高师。
	    有一次一个官员曾问他：和尚还入地狱吗？　赵州从谂答：我马上就入。
	    那官员颇有些幸灾乐祸，说：大善知识为什么还入地狱呢？
	    赵州从谂是怎样回答他的呢？\n\n");

		if ((int)me->query_skill("mahayana", 1) > 60 +random(5)) {
			write("你忽然想起在一部经书里读到过这个故事。\n");
			write("你说：赵州从谂回答他道：我不入地狱，谁去教化你？\n\n");
			message("vision", me->name()+"想了一下，跟静慧师太说了几句话。\n",
				environment(me), ({me}) );

                	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
                	command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。\n");
                	command("recruit " + me->query("id"));
		}
		else {
			write("你想了许久，也不明白其中的道理。\n");
			command("say 阿弥陀佛，你多学些佛法后再来找我吧。\n");
		}
		break;

		case 1:
                write("静慧师太说：赵州从谂，乃是禅宗著名高师。
	    有一次一个僧人问他：狗子还有佛性没有？　赵州说：无。　
	    僧人说：上至诸佛，下至蝼蚁，都有佛性，为什么狗子却没有？
            赵州从谂是怎样回答他的呢？\n\n");

                if ((int)me->query_skill("mahayana", 1) > 60 +random(5)) {
                        write("你灵机一动，想起这个典故。\n");
                        write("你说：赵州从谂回答道：因为他有业识，即识神之业力在。\n\n");
                        message("vision", me->name()+"想了一下，跟静慧师太说了几句话。\n",
                                environment(me), ({me}) );

                        command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
                        command("say 希望你能以慈悲之心，以智慧之力，努力行善， 济度众生。\n");
                        command("recruit " + me->query("id"));
                }
		else {
                	write("你想了许久，也不明白其中的道理。\n");
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
	&& ob->query("family/master_id") == "jinghui shitai"
	&& ob->query("shen") < -100)  {
       	 	message_vision( "$n看着$N说道：你怎么在外边做坏事？\n", ob, this_object() );
		command("say 我峨嵋派乃是堂堂名门正派，" + "对弟子要求极严。我不能再收留你，你去吧。\n");
                command("expell " + ob->query("id"));
                return;
        }

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jinghui shitai"
        && ob->query("class") !=  "bonze" )                  {
		message_vision( "$n看着$N说道：你既然还了俗，还是去找你俗家师叔学艺吧。\n");
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
}
#include "/kungfu/class/emei/nun.h"
#include "/kungfu/class/emei/jing3.h"
#include "/kungfu/class/emei/auto_perform.h"
