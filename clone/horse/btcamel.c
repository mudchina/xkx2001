//Cracked by Roath

inherit NPC_TRAINEE;

int return_home(object home);
#include "/clone/horse/horse.h"
int condition_check();
void create()
{
	set_name("白骆驼", ({ "camel", "luo tuo", "luotuo" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", "这是一匹产於西域，全身雪白的骆驼。\n");
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
	set("baituo", 1);
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
