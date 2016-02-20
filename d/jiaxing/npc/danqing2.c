//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("丹青生",({ "danqing sheng","sheng" }) );
        set("gender", "男性");
        set("age", 35);
	set("long",
		"他髯长及腹，左手一只酒杯，脸上醺醺然大有醉意。\n");
       // set("nickname","");
        set("title","梅庄四庄主");
        set("combat_exp", 78000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 80);
	set_skill("force",75);
        set_skill("parry", 70);
        set_skill("dodge", 80);
	set_skill("sword",70);

	set("max_neili",400);
	set("neili",400);
	set("jiali",40);


        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/hdjiudai");
}

#include "mzkill.h"

