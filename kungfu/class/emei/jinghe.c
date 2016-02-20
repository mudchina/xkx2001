//Cracked by Roath
// Npc: /kungfu/class/emei/jinghe.c 静和师太
// Date: xbc 96/09/22
// Modified by xQin 8/00

inherit NPC;

string ask_for_join();
string ask_for_huansu();
int auto_perform();

void my_move();

void create()
{
        set_name("静和师太", ({
                "jinghe shitai",
                "jinghe",
                "shitai",
	}));
	set("long",
		"她是在华藏庵修行的师太，常见在侧殿里与年轻峨嵋弟子讨论问题。\n"
	);

	set("gender", "女性");
	set("attitude", "friendly");
	set("class", "bonze");

        set("inquiry",([
                "出家"  : (: ask_for_join :),
                "还俗" : (:ask_for_huansu:),
        ]));

	set("age", 40);
	set("shen_type", 1);

        set("startroom","/d/emei/hz_east");

	set("str", 26);
	set("int", 20);
	set("con", 20);
	set("dex", 25);

	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 40);
	set("combat_exp", 88000);
	set("score", 1000);

        set_skill("force", 50);
        set_skill("linji-zhuang", 50);
        set_skill("strike", 65);
        set_skill("jinding-zhang", 65);
        set_skill("finger", 65);
        set_skill("tiangang-zhi", 65);
        set_skill("parry", 65);
        set_skill("dodge", 60);
        set_skill("zhutian-bu", 60);
        set_skill("persuading", 60);
        set_skill("literate", 60);
        set_skill("mahayana", 50);

        map_skill("force", "linji-zhuang");
        map_skill("finger", "tiangang-zhi");
        map_skill("strike", "jinding-zhang");
        map_skill("parry", "jinding-zhang");
        map_skill("dodge", "zhutian-bu");

	prepare_skill("finger", "tiangang-zhi");

	create_family("峨嵋派", 4, "弟子");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

//        set("chat_chance", 2);
        set("chat_msg", ({
                "静和师太道：从菩提心所起愿行，及身口意三业，皆遍一切处，纯一妙善，备尽众德。\n",
        	(: this_object(), "my_move" :),
        }) );


	setup();

        carry_object("/d/emei/npc/obj/nun-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
}
void init()
{
	::init();
        add_action("do_kneel", "kneel");

}

void my_move()
{
        int value;

        value = random(10);

        if (value > 6)
        {
		command("say 普贤菩萨者，普是遍一切处，贤是最妙善义。\n");
                command("west");
        }
        else if (value < 4)
        {
                command("say 静和师太道：普贤之学得于行，行之谨审重莫若象，故好象。\n");
                command("east");
        }
}

#include "/kungfu/class/emei/nun.h"
#include "/kungfu/class/emei/jing1.h"
#include "/kungfu/class/emei/auto_perform.h"
