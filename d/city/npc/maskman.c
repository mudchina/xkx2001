//Cracked by Roath
// maskman.c 蒙面人

inherit NPC;

void create()
{
	set_name("日月神教使者", ({ "rysj shizhe","shizhe","shi" }) );
	set("gender", "男性");
	set("age", 25+random(25));
	set("long",
		"这家伙黑巾蒙面，胸口绣有火焰标记，双眸均有杀气，时不时低沉地阴笑。\n");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "heroism");
	set("wimpy", 30);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		"蒙面使者大声说道：神教一统江湖指日可待，你可别不识时务，到时后悔莫及！\n",
		"蒙面使者桀笑说道：神教东方教主天下无敌，你简直是膛臂挡车，自取灭亡！\n",
		"蒙面使者低沉说道：神教东方教主乃千古第一人，识相的赶快向本神教投诚！\n",
		"蒙面使者高声呐喊：日出东方、唯我不败、文成武德、泽被苍生！\n",
		"蒙面使者高声呐喊：熊熊圣火、光耀神州、一统江湖、天下归诚！\n",
	}) );


	setup();

	carry_object("/clone/misc/cloth")->wear();
//	if ( random(2) == 1 ) carry_object("/d/huashan/obj/lingpai");
	add_money("silver", random(10));
}

#include "/d/city/npc/maskman.h"
