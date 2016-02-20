//Cracked by Roath
// shicong2.c 侍从

inherit NPC;

void create()
{
	set_name("侍从", ({ "shi cong", "cong" }));
	set("long", "　　这位倒也打扮的利索，一身短打，白布包头，翘起的裤腿，一双洁白的布鞋，\n格外醒目。他正准备出去酬备白尼族一年一度的大会。\n");
	set("gender", "男性");
	set("age", 25+random(10));
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("combat_exp", 1000+random(500));
	set_skill("force", 10);
	set_skill("dodge", 25);
	set_skill("unarmed", 25);
	set_skill("parry", 25);
	setup();
	carry_object("/clone/armor/cloth")->wear();
}
