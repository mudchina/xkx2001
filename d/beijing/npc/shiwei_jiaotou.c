//Cracked by Roath
// Npc: shiwei jiaotou
// chu

inherit NPC;

void create()
{
	set_name("侍卫教头", ({
		"shiwei jiaotou",
		"jiaotou",
	}));
	set("long", 
	"这是京城侍卫的总教头，听说他原来曾在丐帮混，\n"
	"后来不知怎么的就来了京城，打败了三十六名禁军侍卫，\n"
	"多总管就让他当了个教头。\n");

	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 39);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 300000);
	set("score", 100);
	

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("cuff", 120);
	set_skill("strike",120);
	set_skill("finger", 120);
	set_skill("claw",120);
	set_skill("hand", 120);
	set_skill("sword",120);
	set_skill("blade",120);
	set_skill("staff",120);
	set_skill("stick",120);

  	set_skill("taixuan-gong", 120);
  	set_skill("liuxing-bu", 120);
  	set_skill("wuyu-zhangfa", 120);
  	set_skill("wuxing-quan", 120);
  	set_skill("wugou-jianfa", 120);
  	set_skill("wuhu-duanmen", 120);

	map_skill("force", "taixuan-gong");
	map_skill("dodge", "liuxing-bu");
	map_skill("cuff", "wuxing-quan");
	map_skill("strike", "wuyu-zhangfa");
	map_skill("parry", "wuhu-duanmen");
	map_skill("blade", "wuhu-duanmen");
	map_skill("sword", "wugou-jianfa");

	prepare_skill("strike", "wuyu-zhangfa");

	setup();

	carry_object("/d/beijing/obj/shiweicloth")->wear();
}

#include "/d/beijing/autok.h"
