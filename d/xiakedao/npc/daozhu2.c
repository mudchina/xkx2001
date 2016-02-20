//Cracked by Roath
// daozhu1.c 侠客岛木岛主
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();

void create()
{
	set_name("木岛主", ({ "mu daozhu", "mu", "daozhu"}));
	set("long", "他长鬓稀稀落落，却还黑多白少，但一张脸却满是皱纹。\n");
	set("gender", "男性");
	set("age", 70);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 35);
	set("con", 25);
	set("dex", 25);
	set("race", "人类");	
	set("max_qi", 2000);
	set("eff_qi", 2000);
	set("qi", 2000);
	set("max_jing", 2000);
	set("eff_jing", 2000);
	set("jing", 2000);
	set("max_neili", 3000);
	set("eff_neili", 3000);
	set("neili", 3000);
	set("max_jingli", 2000);
	set("eff_jingli", 2000);
	set("jingli", 2000);
	set("combat_exp", 2000000);
	set("score", 100000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("cuff", 200);
	set_skill("sword", 200);
	
	set("inquiry", ([
			"中原"   : 	(: ask_leave :),
			"离岛"   : 	(: ask_leave :),
			
		]));
	setup();
}

void init()
{
        object me = this_player();        

        ::init();

}

int ask_leave()
{	
	say("木岛主对你不理不睬，只是凝望着石壁出神。\n");
	return 1;
}
