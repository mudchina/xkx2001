//Cracked by Roath
// maskman.c 蒙面人

inherit NPC;

void create()
{
	set_name("蒙面人", ({ "mengmian ren","ren","mengmian" }) );
	set("gender", "男性");
	set("age", 25+random(25));
	set("long",
		"这家伙黑巾蒙面，双眸均有杀气，时不时低沉地阴笑。\n");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "heroism");
	set("wimpy", 30);

	set("chat_chance", 5);
	set("chat_msg", ({
	}) );

	setup();

	carry_object("/clone/misc/cloth")->wear();
	if ( random(2) == 1 ) carry_object("/d/huashan/obj/lingpai");
	add_money("silver", random(10));
}

#include "/d/huashan/npc/maskman.h"
