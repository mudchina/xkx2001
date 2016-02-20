//Cracked by Roath
// xuetu.c 武馆学徒
// qfy July 30, 1996
inherit NPC;

void create()
{
	set_name("武馆学徒", ({ "xue tu", "tu" }));
	set("long", "他是城中的子弟，正勤奋地练功。\n");
	set("gender", "男性");
	set("age", 25);

	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("stick", 30);
	set_skill("staff", 30);
	set_skill("sword", 30);
	set_skill("blade", 30);	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 5);

	set("combat_exp", 10000);
	set("shen_type", 1);
	setup();

	switch( random(4) )
        {
                case 0:
                       carry_object("/d/city/obj/gangjian")->wield();
                       break;
                case 1:
                       carry_object("/d/city/obj/gangdao")->wield();
                       break;
                case 2:
                       carry_object("/d/xingxiu/obj/gangzhang")->wield();
                       break;
                case 3:
                       carry_object("/d/city/obj/zhubang")->wield();
		       break;		
	}
}
