//Cracked by Roath
// Jay 5/7/97
inherit NPC;

void create()
{
	set_name("谢烟客", ({ "xie yanke", "xie" }));
	set("title", "摩天居士");
	set("long", 
	"他是个身形高大，相貌清矍的老者。一袭青袍在内力激荡下鼓鼓做响。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "heroism");
	set("shen_type", 0);
	set("str", 37);
	set("int", 37);
	set("con", 40);
	set("dex", 35);
	
	set("max_qi", 1800);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 1500000);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
        set_skill("qimen-dunjia", 150);
	set_skill("strike", 150);
	set_skill("hand",150);
	set_skill("finger", 150);
	set_skill("yuxiao-jian", 150);
	set_skill("tianji-xuangong", 150);
	set_skill("luoying-shenjian",150);
	set_skill("luoying-shenfa", 150);
	set_skill("kick", 150);
	set_skill("xuanfeng-saoye", 150);
	set_skill("lanhua-fuxue", 150);
	set_skill("tanzhi-shentong", 150);

	map_skill("force", "tianji-xuangong");
	map_skill("parry", "yuxiao-jian");
	map_skill("finger", "tanzhi-shentong");
	map_skill("strike", "luoying-shenjian");
	map_skill("dodge", "luoying-shenfa");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("hand", "lanhua-fuxue");
	
	prepare_skill("kick", "xuanfeng-saoye");

	setup();
	carry_object("/d/xixia/obj/robe")->wear();
}
