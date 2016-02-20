//Cracked by Roath
// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("欧阳峰", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "他身形高大，高鼻深目，满脸雪白短须，根根似铁。\n"
		"他极善使毒，号称“西毒”。\n");
	set("nickname","老毒物");
        set("title", "白驼山庄主");
        set("gender", "男性");
        set("age", 65);

        set_skill("hand", 180);
	set_skill("shexing-diaoshou", 200);
	set_skill("strike", 180);
	set_skill("xingxiu-duzhang",180);
        set_skill("dodge", 150);
	set_skill("chanchubu", 150);
        set_skill("parry", 150);
        set_skill("force", 150);
	set_skill("hamagong", 150);
	set_skill("lingshe-zhang",200);
	set_skill("staff",200);
	set_skill("training",180);
	map_skill("hand","shexing-diaoshou");
	map_skill("strike","xingxiu-duzhang");
	map_skill("staff","lingshe-zhang");
        map_skill("dodge","chanchubu");
	map_skill("parry", "lingshe-zhang");
	map_skill("staff","lingshe-zhang");
	map_skill("force","hamagong");
	prepare_skill("hand","shexing-diaoshou");
	prepare_skill("strike","xingxiu-duzhang");

        set("str", 33);
        set("int", 28);
        set("con", 29);
        set("dex", 28);

        set("max_qi", 3000);
	set("qi",3000);
        set("max_jing", 800);
	set("jing",800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 300);
        set("combat_exp", 1500000);

        set("attitude", "peaceful");
        set("shen_type", -1);

        create_family("白驼山", 1 , "庄主");
	setup();
        carry_object("/d/xingxiu/npc/obj/shezhang")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        mapping fam;
	string son;

        if( !mapp(fam = ob->query("family")) || fam["family_name"] != "白驼山")
	{
		command ("say " + RANK_D->query_respect(ob) + 
			"先去敝山庄武师或账房先生手下打打杂吧。");
		return;
	}
	if ((int)ob->query_skill("hamagong", 1) < 100) {
                command("say 我们白驼山庄的绝技是我创的蛤蟆功。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在蛤蟆功上多下点功夫？");
                return;
        }
        if ((int)ob->query_skill("training", 1) < 100) {
                command("say 我们白驼山庄经常要训驭毒虫，"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "的驭兽术还不够好。");
                return;
        }
	if (ob->query("gender")=="女性") son = "义女";
	else son = "义子";
	command("我看你天资聪颖，有心认你做"+ son +"。你若肯拜我做义父，就给我"
		"磕个头(ketou)。");
	ob->set_temp("ouyangfeng",1);
	add_action("do_ketou","ketou");
	return;
}

int ketou(string arg)
{
	object ob = this_player();
	if (!ob->query_temp("ouyangfeng")) return 0;
	message_vision(
                "$N双膝跪倒，对着$n说道：“义父在上，请受孩儿一拜！”\n\n"
                "$n高兴得银须乱颤，，将$N从地上扶起。\n\n",
                ob, this_object() );

	command("say 孩子，你要给为父争光。");
        command("recruit " + ob->query("id"));
	ob->set("title","白驼山庄少庄主");
	return 1;
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	if (me->query("family/family_name") != "白驼山")
	me->apply_condition("snake_poison", 2 +
		me->query_condition("snake_poison"));
	return;
}
