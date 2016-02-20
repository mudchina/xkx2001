//Cracked by Roath
// Summer 9/26/1996.

inherit NPC;
int do_huanyuan();
void create()
{
	set_name("葛伦布", ({ "ge lunbu", "ge", "lunbu" }));
	set_weight(3000000);
	set("long", 
"他是密宗的戒律僧，长得膀大腰，手中提着法器，身着黄袍，头戴黄帽，\n"
"满面肃杀之气。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "heroism");
	set("class","lama");
	set("shen_type", -1);
	
	set("max_qi", 500);
	set("max_jing", 450);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 40);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("dodge", 55);
	set_skill("parry", 60);
	set_skill("staff", 60);
	set_skill("cuff", 60);
	set_skill("hammer", 60);

        map_skill("parry", "jingang-chu");
        map_skill("staff", "jingang-chu");

        setup();
	switch( random(3) )
        {
                case 0:
       			 carry_object("/clone/weapon/falun")->wield();
                         break;
		case 1:
			 carry_object("/d/qilian/obj/fachu")->wield();
			 break;
		case 2:
		 	 carry_object("/d/qilian/obj/faling")->wield();
	}
        carry_object(__DIR__"obj/lamajiasha")->wear();
}


