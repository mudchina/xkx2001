//Cracked by Roath
// aijiao-ma.c 矮脚马
inherit NPC_TRAINEE;

#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
	set_name("矮脚马", ({ "aijiao ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", "这是一匹良种矮脚马，很耐长途。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，竖立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 4);
	set("value", 100);
	set("ability", 3);

	set("ridable", 1);
	set("str", 70);
	set("con", 20);
	set("dex", 20);
        set("int", 20);
	set("apply/attack", 50);

	set("max_jingli", 1200);
	set("combat_exp", 1000);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );
	set_weight(80000);

        setup();
}

int return_home(object home)
{
        return 1;
}
