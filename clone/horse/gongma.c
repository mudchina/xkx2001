//Cracked by Roath
// gong-ma.c 贡马
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);

void create()
{
	set_name("贡马", ({ "gong ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", "这是一匹贡马，多由大宛所进， 高大神骏， 通体雪白，
	 多用于皇室， 只有少数流入民间。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，全身毛发竖立，不怒自威！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边伏了下来，一付心满意足的样子！");
        set("attitude", "peaceful");

	set("wildness", 10);
	set("value", 220);
	set("ability", 6);

	set("ridable", 1);
        set("str", 30);
	set("con", 30);
        set("dex", 40);
        set("int", 20);

	set("max_jingli", 900);
	set("combat_exp", 10000);
        set_weight(100000);

        setup();
}

int return_home(object home)
{
        return 1;
}
