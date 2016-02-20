//Cracked by Roath
// wljian.c
// acep , mantian , mantian

#include <ansi.h>

inherit NPC;

void create()
{
        int i;
	i = random(8);
	set_name("无量剑弟子", ({ "wuliang dizi", "wuliang","dizi" }) );
	set("gender", "男性");
	set("age", 35+i);
	set("long",
		"这是无量剑派的一名弟子，腰挎一柄长剑，神情有些鬼祟，象是惧怕些什么。\n");
	set("combat_exp", 5000+i*4000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set("apply/attack",  35);
	set("apply/defense", 35);

	set_skill("sword", 30+i*5);
	set_skill("unarmed", 30+i*5);
	set_skill("parry", 30+i*5);
	set_skill("dodge", 30+i*5);

	setup();

	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 6+i);
}
