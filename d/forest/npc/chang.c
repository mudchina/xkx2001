//Cracked by Roath
// Jay 7/11/96

inherit NPC;

void create()
{
	set_name("常长风", ({ "chang changfeng","chang" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"他又高又肥，便如是一座铁塔摆在地下。\n");
	set("nickname","双掌开碑");
	set("title","太岳四侠");
	set("combat_exp", 15000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  28);
	set("apply/defense", 28);

	set_skill("hammer", 44);
	set_skill("unarmed", 44);
	set_skill("parry", 30);
	set_skill("dodge", 30);

	setup();
        carry_object(__DIR__"obj/mubei")->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 1);
}
