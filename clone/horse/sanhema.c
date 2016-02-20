//Cracked by Roath
// sanhe-ma.c 三河马
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
	set_name("三河马", ({ "sanhe ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", "这马产於蒙古三河地区， 多为拉车载货用途。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，竖立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 2);
	set("value", 80);
	set("ability", 3);

	set("ridable", 1);
        set("str", 80);
	set("con", 30);
	set("dex", 30);
        set("int", 20);

	set("max_jingli", 1000);
	set("combat_exp", 10000);
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

