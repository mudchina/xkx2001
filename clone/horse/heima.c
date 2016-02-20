//Cracked by Roath
// hei-ma.c 黑马
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);
int condition_check();
void create()
{
	set_name("黑马", ({ "hei ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", "这是一匹黑色的马，只在额角处有一大块白斑，看来是匹好马。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，竖立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 7);
        set("value", 70);
	set("ability", 4);

	set("ridable", 1);
        set("str", 80);
	set("con", 30);
	set("dex", 35);
        set("int", 20);

	set("max_jingli", 600);
	set("combat_exp", 8000);
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
