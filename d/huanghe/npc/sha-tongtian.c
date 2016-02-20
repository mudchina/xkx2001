//Cracked by Roath
// sha-tongtian 沙通天

inherit NPC;

void create()
{
	set_name("沙通天", ({ "sha tongtian", "sha" }));
	set("nickname", "鬼门龙王");
	set("long", 
"沙通天是个秃子，头上油光光地没半根头发，双目布满红丝，眼\n"
"珠突出，生就一副异相。性子暴躁，武功却是出奇地高，江湖上\n"
"无人不晓。\n");
	set("title", "黄河帮帮主");
	set("gender", "男性");
	set("age", 48);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 25);
	set("int", 22);
	set("con", 21);
	set("dex", 22);
	
	set("max_qi", 900);
	set("max_jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 40);
	set("combat_exp", 320000);

	set_skill("force", 95);
	set_skill("dodge", 90);
	set_skill("parry", 95);
	set_skill("cuff", 90);
	set_skill("wuxingbu", 100);
	set_skill("wuxing-quan", 120);
	set_skill("wuhu-gun", 120);
	set_skill("staff", 100);
	set_skill("ding-force", 100);

	map_skill("dodge", "wuxingbu");
	map_skill("staff", "wuhu-gun");
	map_skill("parry", "wuhu-gun");
	map_skill("cuff", "wuxing-quan");
	map_skill("force", "ding-force");

	prepare_skill("cuff", "wuxing-quan");

	setup();
	carry_object("/clone/weapon/tiejiang")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}

/*void unconcious()
{
        command("say 众兄弟，点子爪子太硬，风紧扯呼！");
	message_vision("\n$N伸手在墙上一按，纵身闪入现出的暗门里。\n", this_object());
	destruct(this_object());
}
*/
