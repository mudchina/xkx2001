//Cracked by Roath

inherit NPC_TRAINEE;

int return_home(object home);
#include "/clone/horse/horse.h"
void create()
{
	set_name("伊犁马", ({ "yili ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", "这是一匹良种伊犁马，骑上它可驰骋八百里。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，竖立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 6);
	set("value", 140);
	set("ability", 4);

	set("ridable", 1);
	set("str", 80);
        set("con", 40);
	set("dex", 50);
        set("int", 20);
	set("max_qi", 800);
	set("qi", 800);
	set("max_jingli", 700);
	set("combat_exp", 15000);
        set_weight(100000);
	//call_out("checking", 1, this_object() );

        setup();
}

int return_home(object home)
{
        return 1;
}
