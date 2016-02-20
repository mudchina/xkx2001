//Cracked by Roath
// tianlang.c 天狼子
//#include "/kungfu/class/xingxiu/inter_killing.h"
inherit NPC;
inherit F_MASTER;
string ask_me();
//int inter_killing();
void create()
{
	set_name("天狼子", ({ "tianlang zi", "tianlang" }));
	set("nickname", "星宿派三师兄");
	set("long", 
		"他就是丁春秋的三弟子天狼子。\n"
		"他身形奇矮。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 100000);
	set("score", 30000);

	set_skill("force", 50);
	set_skill("huagong-dafa", 50);
	set_skill("dodge", 60);
	set_skill("zhaixinggong", 60);
	set_skill("strike", 50);
	set_skill("chousui-zhang", 60);
	set_skill("poison", 50);
	set_skill("parry", 50);
	set_skill("staff", 60);
  	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "chousui-zhang");

/*	set("chat_chance", 50);
        set("chat_msg", ({
			(: inter_killing :),
	}) );
*/
	create_family("星宿派", 2, "弟子");

	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
}

void attempt_apprentice(object me)
{
	if( me->query("family/family_name") == "丐帮"
        && me->query("combat_exp") >= 10000 ) {
		command ("say 我们老仙最恨叫化子，我可不敢收你。");
                return;
	}
	command("say 好吧，我就收下你了。");
	command("recruit " + me->query("id"));
}
