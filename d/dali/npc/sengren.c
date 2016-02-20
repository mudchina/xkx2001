//Cracked by Roath
inherit NPC;

void create()
{
	set_name("僧人", ({ "seng ren", "seng" }));
	set("long", "这是一位僧人。\n");
	set("gender", "男性");
	set("dalivictim",1);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("age", 35);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 300);
	set("max_jing", 150);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 5000);
	set("score", 100);
	set("chat_chance", 5);
	set("chat_msg",({"僧人稽首说道：这位施主有请了！\n",}));
	set_skill("unarmed", 30);
	set_skill("staff", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);
	setup();
	carry_object("/clone/weapon/chanzhang")->wield();
	carry_object("/d/shaolin/obj/qing-cloth")->wear();
}
