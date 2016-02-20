//Cracked by Roath
// hong-ma.c 红马
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);
int condition_check();
void create()
{
        set_name("红马", ({ "hong ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 8);
        set("long", "这是一匹红色的驽马，生得骠悍异常，是一种山地马。\n");
	set("msg_fail", "$n冲着$N摇晃著脑袋。");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 4);
	set("value", 62);
	set("ability", 4);

	set("ridable", 1);
        set("str", 80);
	set("con", 25);
	set("dex", 35);
        set("int", 20);

	set("max_jingli", 600);
        set("combat_exp", 10000);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );
        set_weight(100000);

        setup();
}

int return_home(object home)
{
        return 1;
}
