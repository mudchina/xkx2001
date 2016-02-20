//Cracked by Roath
// Npc: 
// Date: 
#include "/d/beijing/autok.h"

inherit NPC;

void create()
{
	set_name("官兵", ({
		"guan bing",
		"bing",
	}));
//	set("title", "守门官兵");
	set("long",
		"这是一个看守城门的官兵，正盘查着过往的行人。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 35);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 300);
	set("max_neili", 300);
	set("combat_exp", 20000+random(5000));
	set("score", 100);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("cuff", 30);
	set_skill("parry", 30);
	set_skill("blade",30);

	setup();

        carry_object("/d/city/obj/junfu")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

void init ()
{
    auto_kill(this_player());
}
