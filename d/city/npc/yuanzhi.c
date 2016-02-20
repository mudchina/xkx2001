//Cracked by Roath
// Jay 5/10/97 

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("李沅芷", ({ "li yuanzhi", "li", "yuanzhi" }));
        set_color("$YEL$");
	set("long", 
		"她就是李克秀的独生女儿。李克秀在湘西做参将任内所生，给女儿取这个名字，是纪念生地之意。\n"
		"她聪明伶俐，可有些任性。\n");
		
	set("gender", "女性");
	set("age", 18);
	set("shen_type", 1);

	set("inquiry", ([
		"余鱼同" : "他是我丈夫。\n",
		"李克秀" : "他是我爹。\n",
		"红花会" : "我嫁鸡随鸡，嫁狗随狗。怎么，你也要入会吗？\n",
	]));
	set("neili", 400);
	set("max_neili", 400);
	set("max_qi", 400);
	set("max_jing", 200);
	set("jiali", 10);

	set_skill("force", 50);
	set_skill("unarmed", 40);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 40);
	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);

	setup();
	carry_object(__DIR__"obj/goldring")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
}
int accept_kill(object me)
{
        command("say 你活得不耐烦了？看本小姐怎么收拾你！\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

