//Cracked by Roath
// zaohong-ma.c 枣红马
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
	set_name("枣红马", ({ "zaohong ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 8);
	set("long", "这是一匹体型偏小， 四蹄修长， 颈长尾短， 善于短途冲刺，
	 长途跋涉则非所长， 是长见的杂交马种。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，竖立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 4);
	set("value", 35);
	set("ability", 3);

	set("ridable", 1);
        set("str", 30);
	set("con", 30);
        set("dex", 40);
        set("int", 20);

	set("max_jingli", 550);
	set("combat_exp", 5000);
        set_weight(100000);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );

        setup();
}

int return_home(object home)
{
        return 1;
}

