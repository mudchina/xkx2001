//Cracked by Roath
// langren.c 日本浪人

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("日本浪人", ({ "lang ren", "wu shi", "lang", "ren" }) );
	set("gender", "男性");
	set("age", 20+random(30));
	set("long",
		"这是个神态倨傲的东洋武士，头戴斗笠，身着灰黑色的和服，腰里挎着把长长的武士刀。\n");
	set("combat_exp", 150000+random(5000));
        set("shen_type", -1);
	set("attitude", "heroism");

	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("str", 28);
	set("con", 30);
	set("int", 15);
	set("dex", 27);

	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);

	set_skill("blade",   60+random(60));
	set_skill("unarmed", 60+random(40));
	set_skill("parry",   60+random(60));
	set_skill("dodge",   60+random(60));

	setup();

        carry_object("/d/quanzhou/obj/wushidao")->wield();
        carry_object("/d/quanzhou/obj/wushifu")->wear();
}

void init()
{
	::init();
	if( this_player()->query("combat_exp") <= 5000 & random(5) == 0) {
		message_vision("日本浪人轻蔑地瞪了$N一眼，说道：中国人都象你这般没用吧，哈哈哈！\n", 
		this_player());
	}	
	else if( this_player()->query("combat_exp") <= 10000 & random(5) == 0) {
		message_vision("日本浪人对著$N冷笑道：看你这麽差劲，拿你的血来洗我的刀都不配！\n", 
		this_player());
	}	
}
