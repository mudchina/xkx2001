//Cracked by Roath

inherit NPC_TRAINEE;
int condition_check();
int return_home(object home);
#include "/clone/horse/horse.h"
void create()
{
	set_name("骆驼", ({ "camel", "luo tuo", "luotuo" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", "这是一匹高大健壮的骆驼。它那大似蒲团的的软蹄，可以在流沙中安然行走；\n"
		    "它那有着密密睫毛的眼睛，可以在风沙中识途辩向；它那细长的绒毛，可以\n"
		    "在沙漠中抗寒御热。是人们到沙漠中旅行的必备之物。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，竖立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 6);
	set("value", 120);
	set("ability", 8);

	set("ridable", 1);
	set("str", 80);
        set("con", 40);
	set("dex", 50);
        set("int", 20);
	set("max_qi", 1000);
	set("qi", 1000);
	set("max_jingli", 3000);
	set("combat_exp", 20000);
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
