//Cracked by Roath
//huangbiao-ma.c 黄膘马
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
	set_name("黄膘马", ({ "huangbiao ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", "这是一匹黄色的高头大马，生得全身黄色，无一根杂毛。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，伸出前蹄，作势欲踢");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n就地打了一个滚，走到$N身边，温顺地低下了头");
        set("attitude", "peaceful");

        set("wildness", 5);
	set("value", 43);
	set("ability", 4);

	set("ridable", 1);
        set("str", 80);
        set("con", 40);
        set("dex", 40);
        set("int", 20);

	set("max_jingli", 450);
	set("combat_exp", 12000);
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
