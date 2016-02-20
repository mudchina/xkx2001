//Cracked by Roath
// yayi.c  官府衙役
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("衙役", ({ "ya yi", "ya" }));
        set_color("$YEL$");
	set("gender", "男性");
	set("age", 25);

	set("long", "一个高大威猛的汉子，因为久在官府做事，脸上已经磨炼得毫无表情。\n");
	set("combat_exp", 7500);
	set("shen_type", 1);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
	setup();
	carry_object("/d/city/npc/obj/yayifu")->wear();
}
	
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                (int)ob->query_condition("xakiller")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
