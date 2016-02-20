//Cracked by Roath
// Npc: /kungfu/class/emei/jingjia.c 静迦师太
// Date: shan 96/06/22
// Modified by xQin 8/00
inherit NPC;
inherit F_MASTER;

string ask_for_join();
string ask_for_huansu();
int auto_perform();

void create()
{
	set_name("静迦师太", ({ "jingjia shitai", "jingjia", "shitai",
	}));
	set("long",
		"她是一位慈祥的中年师太，睿智的面上带着和蔼的微笑。\n"
		"她是灭绝师太的八大静字辈弟子之六，最擅长刀法与掌法。\n"
	);

	set("gender", "女性");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "出家"  : (: ask_for_join :),
                "还俗" : (:ask_for_huansu:),
        ]));

	set("age", 32);
	set("shen_type", 1);

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1100);
	set("max_neili", 1100);
	set("jiali", 40);
	set("combat_exp", 300000);
	set("score", 1000);

        set_skill("force", 80);
        set_skill("linji-zhuang", 80);
        set_skill("strike", 90);
        set_skill("jinding-zhang", 90);
	set_skill("finger", 80);
	set_skill("tiangang-zhi", 80);
        set_skill("blade", 90);
        set_skill("yanxing-dao", 90);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("zhutian-bu", 80);
        set_skill("throwing", 80);
        set_skill("persuading", 90);
        set_skill("mahayana", 90);
        set_skill("literate", 100);

        map_skill("force", "linji-zhuang");
        map_skill("strike", "jinding-zhang");
        map_skill("finger", "tiangang-zhi");
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

void init()
{
        object ob;

	::init();
        add_action("do_kneel", "kneel");

        if (interactive(ob=this_player()) 
	&& ob->query("family/master_id") == "jingjia shitai"
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
	&& ob->query("family/master_id") == "jingjia shitai"
        && ob->query("class") !=  "bonze" )                 
	{
		message_vision(
                        "$n看着$N说道：你既然还了俗，还是去找你俗家师叔学艺吧。\n", ob, this_object());
                ob->delete("family/master_name");
                ob->delete("family/master_id");
                return;
        }
}
#include "/kungfu/class/emei/nun.h"
#include "/kungfu/class/emei/jing2.h"
#include "/kungfu/class/emei/auto_perform.h"
