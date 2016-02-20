//Cracked by Roath
// wyshang.c ÎÚÒÄÉÌ··

inherit NPC;

void create()
{
	set_name("ÎÚÒÄÉÌ··", ({ "shang fan", "shang", "fan" }) );
	set("long", "Ò»Î»ÎÚÒÄ×åµÄÉÌ··£¬Ìô×ÅÒ»µ£Æ¤Ã«Ò°Î¶ÔÚ··Âô¡£\n");

	set("age", 25);
	set("gender", "ÄĞĞÔ");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 1000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/d/dali/npc/obj/wyhui.c")->wear();
}
