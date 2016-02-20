//Cracked by Roath
// Jay 7/11/96

inherit NPC;

void create()
{
	set_name("花剑影", ({ "hua jianying","hua" }) );
	set("gender", "男性");
	set("age", 30);
	set("long",
		"他中等身材，白净脸皮，若不是一副牙齿向外突了一寸，一个鼻头低陷了半寸，倒算是一位相貌英俊的人物。\n");
	set("nickname","流星赶月");
	set("title","太岳四侠");
	set("combat_exp", 14000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  23);
	set("apply/defense", 23);

	set_skill("hammer", 35);
	set_skill("unarmed", 40);
	set_skill("parry", 30);
	set_skill("dodge", 40);

	setup();
        carry_object("/d/xingxiu/npc/obj/liuxing")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}
