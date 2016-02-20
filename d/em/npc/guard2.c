//Cracked by Roath
// /kungfu/class/emei/guard2.c 守墓弟子
// shan: 96/08/22

#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("守墓弟子", ({ "guard", "shoumu dizi", "dizi"}));
        set("long", 
		"她是在峨眉后山守墓的弟子。\n");
	set("gender", "女性");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 22);
	set("int", 18);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 900);
	set("max_jing", 900);
	set("neili", 1000);
	set("jiali", 40);
	set("max_neili", 1000);

	set("combat_exp", 200000);
	set("score", 1000);

        set_skill("force", 60);
        set_skill("linji-zhuang", 70);
        set_skill("strike", 70);
        set_skill("sword", 80);
        set_skill("huifeng-jian", 80);
        set_skill("parry", 70);
        set_skill("dodge", 80);
        set_skill("zhutian-bu", 80);
        set_skill("throwing", 40);

        map_skill("force", "linji-zhuang");
        map_skill("sword", "huifeng-jian");
        map_skill("parry", "huifeng-jian");
        map_skill("dodge", "zhutian-bu");

	create_family("峨嵋派", 4, "弟子");

        set("inquiry", ([
		"出家" : "你去本山的庵堂里找我静字辈师姐吧。她们在福寿庵、千佛庵、\n万年庵、万行庵和卧云庵修行。\n",
            "灭绝师太" : "她是本派掌门人，在华藏庵修行。\n",
//Add more here:
        ]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/npc/obj/hui-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();

}

void init()
{
	object ob = this_object();
        object me = this_player();
	string myname = (string)me->query("id");

	::init();
        if (interactive(me) && ob->query_temp("digger/myname")) {
        	message_vision("$n冲$N叫道：又是你！看剑！\n", me, ob);
        	command("kill " + me->query("id"));
		return;
        }
        if (interactive(me) && present("ruanwei-jia", me)) {
        	message_vision(
                	"$n看着$N说道：你如何偷了祖师墓中的宝物？看剑！\n",
        		me, ob);
        	command("kill " + me->query("id"));
		return;
	}
}

