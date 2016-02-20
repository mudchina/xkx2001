//Cracked by Roath

inherit NPC;

void create()
{
	seteuid(getuid());

	set_name("仆人", ({"puren",}));
	set("gender", "男性");
	set("age", 20);
	set("long", "这是一名仆人");
	set("attitude","heroism");
	set("generation",0);
	set("winner","none");

	set("str",20);
	set("con",20);
	set("int",20);
	set("dex",20);
	set("max_qi",200);
	set("eff_qi",200);
	set("qi",80);
	set("max_jing",200);
	set("jing",200);
	set("neili",0);
	set("max_neili",0);
	set("shen_type",1);
	set("no_clean_up",1);
	set("combat_exp",1000);

	set_skill("force",20);
	set_skill("unarmed",20);
	set_skill("dodge",20);
	set_skill("parry",20);

	setup();
}
