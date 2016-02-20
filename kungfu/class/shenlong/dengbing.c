//Cracked by Roath
// deng bingchun µË±ş´º

inherit NPC;
// inherit F_MASTER;

void create()
{
	set_name("µË±ş´º", ({ "deng bingchun","deng" }));
//      set("nickname", "");
	set("long",
		"ÕÅµ­ÔÂµÄµÜ×Ó¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 25);
	set("con", 26);
	set("dex", 26);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 600);
	set("max_neili", 600);
	set("jingli", 600);
	set("max_jingli", 600);
	set("jiali", 30);
	set("combat_exp", 50000);
	set("score", 50000);
	set("shen", -8000);

	set_skill("force", 60);
	set_skill("dulong-dafa", 40);
	set_skill("dodge", 40);
	set_skill("lingshe-shenfa", 40);
	set_skill("strike", 50);
	set_skill("huagu-mianzhang", 30);
	set_skill("parry", 50);
	set_skill("blade", 50);
//      set_skill("magic", 30);
//      set_skill("shenlong-magic", 50);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
//      map_skill("magic", "shenlong-magic");

	prepare_skill("strike", "huagu-mianzhang");

	create_family("ÉñÁú½Ì", 3, "ºÚÁúÃÅµÜ×Ó");

//      set("inquiry", ([
//              "ÃØ¼®" : (: ask_me :),
//      ]));

//      set("book_count", 1);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();

}
