//Cracked by Roath
// shu-sheng.c
// Jay 6/1/97

inherit NPC;

void create()
{
	set_name("张朝唐", ({ "zhang chaotang", "zhang", "chaotang" }) );
	set("gender", "男性" );
	set("age", 22);
	set("int", 28);
	set("long",
		"这是个饱读诗书的南洋书生，他一直向往中土文化，特来赶考。\n");

        set("inquiry", ([
		"渤泥国" : "就是现在的文莱。\n",
	]));
	set("attitude", "peaceful");
        set("shen_type", 1);
	set("combat_exp", 40);
	set_skill("literate", 40);
	setup();
	carry_object("/clone/armor/cloth")->wear();
}

