//Cracked by Roath
// kuli.c
// Jay 6/1/97

inherit NPC;

void create()
{
	set_name("张康", ({ "zhang kang", "zhang", "kang" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long",
		"这是个老实巴交的汉子，是张朝唐的从人。\n");
	set("shen_type", 1);
	set("combat_exp", 1200);
        set("str", 25);
        set("dex", 22);
        set("con", 20);
        set("int", 15);
	set("attitude", "friendly");

	setup();
	add_money("silver", 30);
        carry_object("clone/misc/cloth")->wear();

}

