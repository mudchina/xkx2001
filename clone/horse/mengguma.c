//Cracked by Roath
// menggu-ma.c 蒙古马
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);
int condition_check();
void create()
{
	set_name("蒙古马", ({ "menggu ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 12);
	set("long", "这是一匹体型高大， 蹄大尾长的大马， 善于平原奔驰， 多用为军马。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，嘴里呼呼地喷著白气。");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 6);
	set("value", 90);
	set("ability", 4);

	set("ridable", 1);
        set("str", 80);
	set("con", 30);
        set("dex", 40);
        set("int", 20);

	set("max_jingli", 780);
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
