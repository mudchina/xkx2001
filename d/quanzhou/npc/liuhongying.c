//Cracked by Roath
// liuhongying.c 刘虹瑛
// qfy July 30, 1996
inherit NPC;

void create()
{
	set_name("刘虹瑛", ({ "liu hongying", "liu", "hongying" }));
	set("long", "刘虹瑛是扬威武馆的剑部教头，当年曾凭一把长剑独挑黑血帮。\n");
	set("nickname", "绝情剑");
	set("gender", "女性");
	set("age", 34);

	set_skill("literate", 60);

	set_skill("strike", 50);
	set_skill("force", 60);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("sword", 70);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();

	carry_object("/clone/weapon/gangjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if ( interactive(ob=this_player()) && (int)ob->query_temp("mark/马") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        command("say 欢迎这位"+RANK_D->query_respect(ob)+"，你可向我学剑法(sword)，掌法(strike)，内功(force)，招架(parry)及轻功(dodge)。");
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/马"))
		return 0; 
	return 1;
}
