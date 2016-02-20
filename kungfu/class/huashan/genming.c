//Cracked by Roath
// genming.c 高根明

inherit NPC;

void create()
{
	set_name("高根明", ({ "gao genming", "gao", "ming" }));
	set("long", 
"高根明在华山弟子中排行第五。\n");
	set("gender", "男性");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 20);
	set("con", 24);
	set("dex", 22);
	
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 20);
	set("combat_exp", 48000);
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
	set_skill("cuff", 55);
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
