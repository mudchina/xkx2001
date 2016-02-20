//Cracked by Roath
// hou-tonghai.c 侯通海

inherit NPC;

void create()
{
	set_name("侯通海", ({ "hou tonghai", "hou" }));
	set("nickname", "三头蛟");
	set("long", 
"侯通海是个青脸瘦子，面颊极长，额角上肿起了三个大肉瘤，非常难看。\n");
//	set("title", "");
	set("gender", "男性");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 21);
	set("int", 17);
	set("con", 21);
	set("dex", 19);
	
	set("max_qi", 600);
	set("max_jing", 350);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 30);
	set("combat_exp", 70000);

	set_skill("force", 60);
	set_skill("dodge", 70);
	set_skill("parry", 65);
	set_skill("liuhe-qiang", 70);
	set_skill("wuxingbu", 70);
	set_skill("pike", 70);
	set_skill("ding-force", 60);
	set_skill("unarmed", 70);

	map_skill("dodge", "wuxingbu");
	map_skill("pike", "liuhe-qiang");
	map_skill("parry", "liuhe-qiang");
	map_skill("force", "ding-force");

	setup();
	carry_object("/clone/weapon/sangucha")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}
