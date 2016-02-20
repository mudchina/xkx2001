//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("黑白子",({ "heibai zi","zi","heibai" }) );
        set("gender", "男性");
        set("age", 55);
	set("long",
		"他眉目清秀，头发极黑而皮肤极白，"
		"似乎一具僵尸模样。\n");
       // set("nickname","");
        set("title","梅庄二庄主");
        set("combat_exp", 85000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 85);
	set_skill("force",85);
        set_skill("parry", 85);
        set_skill("dodge", 85);
	set_skill("hammer",85);

	set("max_neili",450);
	set("neili",450);
	set("jiali",45);


	set("mz/toy","棋谱");
	set("mz/set","heibai");
	set("mz/need","tubiweng");
	set("mz/needname","三庄主");
        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/qiping")->wield();
}

void fightwin(object who)
{
}
#include "mzfight.h"



