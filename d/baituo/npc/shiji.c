//Cracked by Roath
// shinu.c 白驼山庄侍姬
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("侍姬", ({ "shi ji","ji"}));
        set("long", "白驼山少主的一名姬妾，体态婀娜，笑容冶艳。\n");
        set("gender", "女性");
        set("age", 20);

        set_skill("hand", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("force", 40);

        set("str", 19);
        set("int", 20);
        set("con", 18);
        set("dex", 20);

        set("max_neili", 500);
        set("combat_exp", 30000);

        set("attitude", "peaceful");

	setup();
	carry_object("/d/xingxiu/obj/wcloth")->wear();
}
