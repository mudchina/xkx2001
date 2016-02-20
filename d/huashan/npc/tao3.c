//Cracked by Roath
// tao3.c 桃枝仙
// qfy July 21, 1996

inherit NPC;
string ask_me();

void create()
{
	set_name("桃枝仙", ({ "tao zhixian", "tao", "zhixian" }));
	set("nickname", "桃谷六仙不知是老三还是老四");
	set("long", 
"桃枝仙与桃叶仙不知谁是老三，谁是老四。但他常说自己是老三\n"
"，和桃叶仙常常为此争论。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 21);
	set("con", 29);
	set("dex", 29);
	set("shen", 0);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1400);
	set("max_neili", 1400);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 5000);

	set_skill("force", 95);
	set_skill("dodge", 100);
	set_skill("parry", 95);
	set_skill("unarmed", 100);
	set_skill("ding-dodge", 95);
	set_skill("ding-force", 95);
	set_skill("ding-unarmed", 95);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("unarmed", "ding-unarmed");

	set("chat_chance", 5);

	set("chat_msg", ({
		"桃枝仙指着桃叶仙说道：我是老三，他是老四。\n",
		"桃枝仙说道：我们父母本来记得谁是老三谁是老三，后来却忘了。\n",
	}) );

	set("inquiry", ([
		"令狐冲" : "令狐兄是我的好朋友，常说咱们六兄弟是江湖中的英雄好汉。\n",
		"风清扬" : (: ask_me :),
		"风前辈" : (: ask_me :),
		"风清扬前辈" : (: ask_me :),
	]));

	setup();
	carry_object("/d/city/obj/cloth")->wear();

}

#include "/d/huashan/npc/tao.h"
