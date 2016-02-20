//Cracked by Roath
inherit NPC;

void create()
{
        set_name("蓝衣弟子", ({ "lanyi dizi", "lan yi", "dizi"}));
        set("long", "他是木岛主的一名弟子，专管传授岛上弟子的基本功夫。\n");
        set("gender", "男性");
        set("age", 34);

        set_skill("strike", 30);
        set_skill("force", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 20000);
        set("shen_type", 1);
        setup();
	  carry_object(__DIR__"obj/bluerobe")->wear();
        carry_object("/clone/weapon/stick")->wield();
}

void init()
{
        object ob;

        ::init();
        if ( interactive(ob=this_player()) ) 
	  {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	command("say 欢迎这位"+RANK_D->query_respect(ob)+
		"，你可向我学掌法(strike)，内功(force)，\n"+
                "招架(parry)及轻功(dodge)。");
}

int recognize_apprentice(object ob)
{
        return 1;
}
