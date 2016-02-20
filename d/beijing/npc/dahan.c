//Cracked by Roath

inherit NPC;

void create()
{
	seteuid(getuid());

	set_name("大汉", ({"dahan",
			     "han"}));
	set("gender", "男性");
	set("age", 35);
	set("long", "这是一名身材壮实的蒙古大汉");
	set("attitude","heroism");
	set("generation",0);
	set("winner","none");

	set("str",30);
	set("con",29);
	set("int",25);
	set("dex",20);
	set("max_qi",300);
	set("eff_qi",300);
	set("qi",300);
	set("max_jing",300);
	set("jing",300);
	set("neili",0);
	set("max_neili",0);
	set("shen_type",0);
	set("no_clean_up",1);
	set("combat_exp",5000);

	set_skill("force",40);
	set_skill("unarmed",60);
	set_skill("dodge",30);
	set_skill("parry",30);

	setup();
}
