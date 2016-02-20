//Cracked by Roath
// chuan-ma.c 川马

inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);
int condition_check();

void create()
{
	set_name("川马", ({ "chuan ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", "这是一匹体型矮小， 善蹬山， 耐长途跋涉的四川马。\n");
	set("msg_fail", "$n冲着$N一摆尾巴，人立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 3);
	set("value", 100);
	set("ability", 5);

	set("ridable", 1);
        set("str", 30);
	set("con", 30);
	set("dex", 30);
        set("int", 20);

	set("max_jingli", 670);
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

