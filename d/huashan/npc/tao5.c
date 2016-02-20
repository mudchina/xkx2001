//Cracked by Roath
// tao5.c 桃花仙
// qfy July 21, 1996

inherit NPC;
string ask_me();

void create()
{
	set_name("桃花仙", ({ "tao huaxian", "tao", "huaxian" }));
	set("nickname", "桃谷六仙老五");
	set("long", 
"桃花仙排行第五，常自诩其名为众兄弟中最好听的。\n");
	set("gender", "男性");
	set("age", 58);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 29);
	set("int", 22);
	set("con", 28);
	set("dex", 27);
	set("shen", 0);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1300);
	set("max_neili", 1300);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 5000);

	set_skill("force", 95);
	set_skill("dodge", 95);
	set_skill("parry", 95);
	set_skill("unarmed", 95);
	set_skill("ding-dodge", 95);
	set_skill("ding-force", 90);
	set_skill("ding-unarmed", 90);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("unarmed", "ding-unarmed");

	set("chat_chance", 5);

	set("chat_msg", ({
		"桃花仙兴高采烈地说道：我的名字是咱们桃谷六仙中最好听的。\n",
		"桃花仙说道：咱们常跟令狐冲斗酒，喝个十天八夜的也不算什么。\n",
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
