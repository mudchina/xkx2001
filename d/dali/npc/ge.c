//Cracked by Kafei
// NPC gan.c
// AceP

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("葛光佩", ({ "Ge guangpei","ge" }) );
	set("gender", "女性");
	set("age", 25);
	set("long", "这位是无量剑西宗掌门双清的弟子，名叫葛光佩。\n");
	set("combat_exp", 30000);
	set("shen_type", -1);

	set("apply/attack",  50);
	set("apply/defense", 50);

	set_skill("sword", 70);
	set_skill("unarmed", 65);
	set_skill("parry", 65);
	set_skill("dodge", 65);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}
