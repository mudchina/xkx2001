//Cracked by Roath
// dayou.c 岳灵姗
// qfy July 7, 1996

inherit NPC;

void create()
{
	set_name("岳灵姗", ({ "yue lingshan", "yue", "lingshan", "shan" }));
	//set("nickname", "");
	set("long", 
"岳灵姗是华山派掌门岳不群的女儿，是华山的小师妹。长得十分\n"
"娇美可爱，为人善良。\n");
	set("gender", "女性");
	set("age", 18);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 22);
	set("int", 26);
	set("con", 26);
	set("dex", 29);
	
	set("max_qi", 750);
	set("max_jing", 500);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 20);
	set("combat_exp", 45000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("zixia-gong", 50);
	set_skill("dodge", 60);
	set_skill("parry", 55);
	set_skill("sword", 50);
	set_skill("huashan-jianfa", 50);
	set_skill("strike", 45);
	set_skill("hunyuan-zhang", 45);
	set_skill("huashan-shenfa", 60);
	set_skill("cuff", 45);
        set_skill("pishi-poyu", 45);
	set_skill("ziyin-yin", 35);
        set_skill("zhengqi-jue", 35);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("华山派", 14, "弟子");

	setup();
	if (clonep()) 
	carry_object("/clone/weapon/bishui-jian", "/clone/weapon/gangjian")->wield();
	carry_object("/d/city/obj/pink_cloth")->wear();
	carry_object("/d/city/obj/necklace")->wear();
}
