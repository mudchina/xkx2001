//Cracked by Roath
// xiaofei.c 萧飞
// qfy July 30, 1996
// modified by ryu, 10/4/97

inherit NPC;
int auto_throw();
void create()
{
	set_name("萧飞", ({ "xiao fei", "xiao", "fei" }));
	set("long", "萧飞是扬威武馆的暗器部教头，为人机警多谋。\n");
	set("nickname", "漫天花雨");
	set("gender", "男性");
	set("age", 32);

	set_skill("literate", 50);

	set_skill("finger", 55);
	set_skill("force", 55);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	//set_skill("throwing", 70);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_throw :),
        }) );
	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();

	carry_object("/clone/weapon/feibiao1");
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

	command("say 欢迎这位"+RANK_D->query_respect(ob)+"，你可向我学暗器(throwing)，指法(finger)，内功(force)，招架(parry)及轻功(dodge)。");
}


int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/马"))
		return 0; 
	return 1;
}
#include "/clone/npc/auto_throw.h";
