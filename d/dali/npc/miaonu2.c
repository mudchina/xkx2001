//Cracked by Roath
// miaonu2.c 南国姑娘

inherit NPC;

void create()
{
	set_name("南国姑娘", ({ "girl" }));
	set("long", "　　南国的大姑娘颇带有当地优美秀丽山水的风韵，甜甜的笑，又有天真的\n浪漫。她穿着白色上衣，蓝色的宽裤，外面套着黑丝绒领褂，头上缠着彩色的头\n巾。\n");
	set("gender", "女性");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("combat_exp", 1000);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	setup();
	carry_object("/d/dali/obj/bai_cloth")->wear();
}
