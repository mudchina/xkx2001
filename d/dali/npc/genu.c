//Cracked by Roath
// genu.c 歌女

inherit NPC;

void create()
{
	set_name("歌女", ({ "ge nu", "nu", "girl" }));
	set("long", "　　她是一个卖唱为生的歌女，长的颇有几分资色。\n");
	set("gender", "女性");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 10);
	set("combat_exp", 3000);
	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set("chat_chance", 8);
	set("chat_msg", ({
		"歌女柔声唱道，“今宵酒醒何处，杨柳岸晓风残月”。\n",
		"歌女拨动着瑶琴低声唱道，“恨春去，不与人期，弄月色，空遗满地梨花雪”。\n",
		"歌女垂首唱道，“农华如梦水东流，人间所事堪惆怅。莫向横塘问旧游”。\n",
		"歌女引吭高歌，“相逢一醉是前缘，风雨散，飘然何处?”。\n",
		"歌女低声轻吟，“衣上酒痕诗里字，点点行行，总是凄凉意”。\n",
		"歌女低声悲歌，“惜起残红泪满衣，他生莫作有情疑。人天无地著相思”。\n",
		}) );
	setup();
	carry_object("/d/city/obj/jin_ao.c")->wear();
	carry_object("/d/jiaxing/obj/yaoqin")->wield();
}
