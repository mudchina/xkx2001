//Cracked by Roath
// yingying.c 崔莺莺

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("崔莺莺", ({ "cui yingying", "cui", "ying" }));
        set_color("$YEL$");
	set("long", "她长得极美，尤其是那对眼睛，媚得直可以勾人魂魄。\n");
	set("title", "财主女儿");
	set("gender", "女性");
	set("age", 17);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/necklace")->wear();
}
	
int accept_kill(object me)
{
        command("say 爹爹救命啊！" + me->name() + "这个" + RANK_D->query_rude(me) + "要强暴我！\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

