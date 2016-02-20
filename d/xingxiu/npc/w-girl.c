//Cracked by Roath
// girl.c

inherit NPC;

void create()
{
	set_name("小克孜", ({ "xiao kezi", "kezi", "girl" }) );
	set("gender", "女性");
	set("age", 14);
	set("long", "一个活泼可爱的回族小女孩。小克孜是维吾尔语，意思就是小姑娘。\n");
	set("shen_type", 1);
	set("combat_exp", 1000);
	set("str", 13);
	set("dex", 20);
	set("con", 14);
	set("int", 25);
	set("attitude", "peaceful");
	setup();
	carry_object("/d/city/obj/cloth")->wear();

}
