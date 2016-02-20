//Cracked by Roath
// Jay 5/10/9, modified from /kungfu/class/dali/gaoshengtai.c

inherit NPC;
void create()
{
	set_name("余鱼同", ({ "yu yutong", "yu"}));
    set("long","这是一位书生，长身玉立，脸上蒙着布。\n");
	set("title", "红花会十四当家");
	set("nickname","金笛秀才");
    set("gender", "男性");
    set("age", 21);
    set_skill("cuff", 100);
    set_skill("jinyu-quan", 100);
    set_skill("dodge", 100);
    set_skill("duanshi-shenfa", 110);
    set_skill("parry", 90);
    set_skill("force", 105);
    set_skill("kurong-changong", 90);
    set_skill("duanjia-jian",80);
    set_skill("sword",80);
	set_skill("finger",90);
    set_skill("buddhism",110);
    map_skill("cuff","jinyu-quan");
    map_skill("sword","duanjia-jian");
    map_skill("dodge","duanshi-shenfa");
    map_skill("parry", "duanjia-jian");
    map_skill("force","kurong-changong");
    prepare_skill("cuff","jinyu-quan");

    set("str", 23);
    set("int", 23);
    set("con", 24);
    set("dex", 28);
    set("max_qi", 800);
    set("max_jing", 600);
    set("neili", 800);
    set("max_neili", 800);
    set("jiali", 40);
    set("combat_exp", 500000);
	set("inquiry", ([
		"name" : "在下行不更名，坐不改姓，姓余名鱼同。余者，人未之余。"+
			"鱼者，混水摸鱼之鱼也。同者，君子和而不同之同，非破铜烂铁之铜也。\n",
		"红花会" : "怎么，你怕吗？\n" ,
		"李沅芷" :  "她是在下拙荆。\n",
		"骆冰" :  "“她是我四嫂。”说完余鱼同长叹一声。\n",
		]));

	set("attitude", "heroism");
    set("shen_type", 1);

    setup();
    carry_object("/d/dali/obj/tiedi")->wield();
    carry_object("/d/city/obj/cloth")->wear();
}
