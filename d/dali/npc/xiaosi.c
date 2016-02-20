//Cracked by Roath
// xiaosi.c 小厮子

inherit NPC;

void create()
{
	set_name("小厮子", ({ "xiao si" }));
	set("long", "　　一个小厮儿，生得眉清目秀，伶俐乖觉。他头上戴一顶新盔的玄罗帽儿，身\n上穿一件半新不旧的天青夹绉纱褶子。\n");
	set("gender", "男性");
	set("age", 18+random(5));
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 21+random(2));
	set("int", 21+random(2));
	set("con", 22+random(2));
	set("dex", 24+random(2));
	set("max_qi", 110+random(60));
	set("max_jing", 100+random(50));
	set("combat_exp", 2200+random(200));
	set("score", 1200+random(200));
	set_skill("force", 26+random(5));
	set_skill("dodge", 21+random(4));
	set_skill("unarmed", 19+random(2));
	set_skill("parry", 19+random(3));
	set_temp("apply/attack", 16+random(2));
	set_temp("apply/defense", 16+random(2));
	set_temp("apply/damage", 5+random(3));
	setup();
	carry_object("/d/dali/obj/tqcloth")->wear();
}
