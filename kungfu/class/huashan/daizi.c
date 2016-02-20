//Cracked by Roath
// daizi.c 施戴子

inherit NPC;

void create()
{
	set_name("施戴子", ({ "shi daizi", "shi", "daizi" }));
	set("long", 
"施戴子在华山弟子中排行第四。\n");
	set("gender", "男性");
	set("age", 27);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 22);
	set("con", 24);
	set("dex", 22);
	
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 730);
	set("max_neili", 730);
	set("jiali", 22);
	set("combat_exp", 49000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("zixia-gong", 50);
	set_skill("dodge", 55);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("huashan-jianfa", 60);
	set_skill("strike", 55);
	set_skill("hunyuan-zhang", 55);
	set_skill("huashan-shenfa", 55);
	set_skill("cuff", 50);
        set_skill("pishi-poyu", 50);
	set_skill("ziyin-yin", 40);
        set_skill("zhengqi-jue", 40);

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
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}
