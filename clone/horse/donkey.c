//Cracked by Roath
//xiao-ma.c 小毛驴
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
	set_name("小毛驴", ({ "donkey", "xiao maolu", "lu" }) );
        set("race", "家畜");
	set("age", 4);
	set("long", "这是一匹小毛驴，看来已经很健壮。\n");
	set("msg_fail", "$n不停地冲着$N摇晃著脑袋。");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 3);
	set("value", 10);
	set("ability", 2);

	set("ridable", 1);
	set("str", 40);
	set("con", 40);
	set("dex", 10);
	set("int", 15);
	set("max_qi", 400);
	set("qi", 400);
	set("max_jingli", 400);
	set("combat_exp", 500);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );
	set_weight(5000);

        setup();
}

int return_home(object home)
{
        return 1;
}
