//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("秃笔翁",({ "tubi weng","weng" }) );
        set("gender", "男性");
        set("age", 45);
	set("long",
		"他矮矮胖胖，头顶秃得油光滑亮，"
		"一根头发也没有，衣衫上都是墨迹。\n");
       // set("nickname","");
        set("title","梅庄三庄主");
        set("combat_exp", 80000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 80);
	set_skill("force",80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
	set_skill("club",80);

	set("max_neili",450);
	set("neili",450);
	set("jiali",40);


	set("mz/toy","率意帖");
	set("mz/set","tubiweng");
	set("mz/need","danqing");
	set("mz/needname","四庄主");
        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/panguanbi")->wield();
}


void fightwin(object who)
{
}
#include "mzfight.h"

