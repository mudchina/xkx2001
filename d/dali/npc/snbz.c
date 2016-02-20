//Cracked by Kafei
// snbz.c

inherit NPC;

void create()
{
	int i;

	set_name("神农帮弟子", ({ "shennong dizi","shennong","dizi" }) );
	set("gender", "男性");
	i = random(8);
	set("age", 35+i);
	if (i>4) 
	set("long",
		"这是一个神农帮的帮众，身穿黄衣，肩悬药囊，手持一柄短刀。\n");
	else
        set("long",
                "这是一个神农帮的帮众，身穿黄衣，肩悬药囊，手持一柄药锄。\n");
	set("combat_exp", 5000+i*4000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("blade", 30+i*5);
	set_skill("hammer",30+i*5);
	set_skill("unarmed", 30+i*5);
	set_skill("parry", 30+i*5);
	set_skill("dodge", 30+i*5);

	setup();

	if (i>4)
	carry_object("/d/dali/obj/duandao")->wield();
	else
	carry_object("clone/weapon/yaochu")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5+2*i);
}
