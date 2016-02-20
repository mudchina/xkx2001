//Cracked by Roath
// tao2.c 桃干仙
// qfy July 21, 1996

inherit NPC;
string ask_me();

void create()
{
	set_name("桃干仙", ({ "tao ganxian", "tao", "ganxian" }));
	set("nickname", "桃谷六仙老二");
	set("long", 
"桃根仙张着一张长长的马脸，尊容是令人不敢恭维的。与其五兄\n"
"弟行影不离，号称「桃谷六仙」。\n");
	set("gender", "男性");
	set("age", 63);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 21);
	set("con", 29);
	set("dex", 29);
	set("shen", 0);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("ding-dodge", 100);
	set_skill("ding-force", 100);
	set_skill("ding-unarmed", 100);

	map_skill("dodge", "ding-dodge");
	map_skill("force", "ding-force");
	map_skill("unarmed", "ding-unarmed");

	set("chat_chance", 5);

	set("chat_msg", ({
		"桃干仙神气地说道：咱们桃谷六仙在江湖上威名赫赫！\n",
		"桃干仙说道：你若是不认识咱们，那你一定是这个．．．这个．．孤陋寡闻。\n",
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
