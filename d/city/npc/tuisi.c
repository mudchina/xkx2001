//Cracked by Roath
//Jay 2/4/97 
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("凌退思", ({ "ling tuisi", "ling" }));
        set_color("$YEL$");
	set("title","翰林");
	set("long","凌退思相貌清秀，面容很是慈祥。他虽然考中进士，做过翰林，\n"
	"其实是龙沙帮的大龙头。不但文才出众，武功也十分了得。\n");
	set("gender", "男性");
	set("age", 45);

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);

	set("combat_exp", 25000);
	set("shen_type", -1);
	setup();
	add_money("silver", 50);
	carry_object(__DIR__"obj/cloth")->wear();
}
	
int accept_kill(object me)
{
        command("say 光天化日之下竟敢在翰林府中行凶，没王法了吗？\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}


