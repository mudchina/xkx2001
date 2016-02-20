//Cracked by Roath
// longquan.c 龙铨
// qfy July 30, 1996
inherit NPC;

void create()
{
	set_name("龙铨", ({ "long quan", "long", "quan" }));
	set("long", "龙铨是扬威武馆的刀刃部教头，为人耿直豪爽。\n");
	set("nickname", "一刀平南");
	set("gender", "男性");
	set("age", 35);

	set_skill("literate", 50);

	set_skill("claw", 50);
	set_skill("force", 50);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
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

	command("say 欢迎这位"+RANK_D->query_respect(ob)+"，你可向我学刀法(blade)，爪法(claw)，内功(force)，招架(parry)及轻功(dodge)。");
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/马"))
		return 0; 
	return 1;
}
