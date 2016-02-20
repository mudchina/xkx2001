//Cracked by Roath
// liu-ma.c 骝马
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"

int return_home(object home);
int condition_check();
void create()
{
	set_name("骝马", ({ "liu ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 8);
	set("long", "这是一匹黑鬃黑尾的红马， 善蹬山， 耐久力好， 多为陕西山区运输用。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，四蹄腾空，人立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边，低下头，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 3);
	set("value", 75);
	set("ability", 4);

	set("ridable", 1);
        set("str", 80);
	set("con", 30);
        set("dex", 40);
        set("int", 20);

	set("max_jingli", 770);
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

