//Cracked by Roath
// tao3.c 桃实仙
// qfy July 21, 1996

inherit NPC;
string ask_me();

void create()
{
	set_name("桃实仙", ({ "tao shixian", "tao", "shixian" }));
	set("nickname", "桃谷六仙老六");
	set("long", 
"桃实仙于桃谷六仙中年纪最小，同时胆子也最小。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 27);
	set("int", 20);
	set("con", 27);
	set("dex", 30);
	set("shen", 0);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 5000);

	set_skill("force", 95);
	set_skill("dodge", 95);
	set_skill("parry", 95);
	set_skill("unarmed", 95);
	set_skill("ding-dodge", 90);
	set_skill("ding-force", 90);
	set_skill("ding-unarmed", 90);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("unarmed", "ding-unarmed");

	set("chat_chance", 6);

	set("chat_msg", ({
		"桃实仙顾虑地道：他不是太利害吧？\n",
		"桃实仙对大伙说道：你们先上，我来殿后。\n",
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
