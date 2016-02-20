//Cracked by Roath
// shicong3.c 侍从

inherit NPC;

void create()
{
	set_name("侍从", ({ "shi cong", "cong" }));
	set("long", "　　这是个白白胖胖的小伙子，也许是天生下来就少了块肉，他整天咧着个大嘴\n在傻笑。他也是一身短打，白布包头和一双洁白的布鞋。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("combat_exp", 1200+random(600));
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	setup();
	carry_object("/clone/armor/cloth")->wear();
}
