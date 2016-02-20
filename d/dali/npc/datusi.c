//Cracked by Roath
// datusi.c 大土司
inherit NPC;

void create()
{
	set_name("大土司", ({ "da tusi" ,"offical"}));
	set("long", "　　大土司是摆夷族人氏，是苍山纳苏系的。他倒是长的肥头大耳的，每说一句\n话，每有一点表情，满脸的肉纹便象是洱海里的波浪一样。他身着彩绸，头带凤\n羽，脚踩藤鞋，满身挂着不同色彩的贝壳。只见他傲气凛然地高居上座，不把来\n人看在眼里。\n");
	set("gender", "男性");
	set("age", 47);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("max_qi", 300);
	set("max_jing", 300);
	set("jiali", 10);
	set("combat_exp", 8000);
	set_skill("force", 30+random(10));
	set_skill("dodge", 30+random(10));
	set_skill("unarmed", 30+random(10));
	set_skill("parry", 30+random(10));
	setup();
	carry_object("/d/dali/obj/shelllace")->wear();
}
