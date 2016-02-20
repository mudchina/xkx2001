//Cracked by Roath
// Jay 7/11/96

inherit NPC;

void create()
{
	set_name("逍遥子", ({ "xiaoyao zi","xiaoyao","zi" }) );
	set("gender", "男性");
	set("age", 45);
	set("long",
		"他是个病夫模样的中年人，衣衫褴褛，咬著一根旱烟管，双目似睁似闭，嘴里慢慢喷出烟雾。\n");
	set("nickname","烟霞神龙");
	set("title","太岳四侠");
	set("combat_exp", 20000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("chat_chance", 5);
	set("chat_msg", ({
		"逍遥子左手按胸，咳嗽起来。\n",
	}) );

	set_skill("club", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();
        carry_object(__DIR__"obj/yanguan")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/village/npc/obj/shoes")->wear();
	carry_object(__DIR__"obj/jinchai");
	add_money("silver", 3);
}
