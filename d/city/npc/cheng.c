//Cracked by Roath
// cheng.c 程药发

#include <ansi.h>
inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("程药发", ({ "cheng yaofa", "cheng" }));
        set_color("$YEL$");
	set("title", "扬州知府");
	set("gender", "男性");
	set("age", 43);
	set("str", 20);
	set("dex", 20);
	set("long", "他就是程药发，扬州现任知府。\n");
	set("combat_exp", 30000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
}

int accept_kill(object me)
{
        command("say 来人啊，有刺客！\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

int accept_fight(object me)
{
        command("say 本官这点三脚猫手艺怎敢跟人过招？");
        return 0;
}

