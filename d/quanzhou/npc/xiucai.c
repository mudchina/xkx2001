//Cracked by Roath
// xiucai.c 老秀才

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIY"老秀才"NOR, ({ "lao xiucai", "xiucai", "lao" }));
	set("long", "一个老秀才，在这里开堂授课为生。\n");
	set("gender", "男性");
	set("age", 60);

	set_skill("literate", 40);

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	set("combat_exp", 2000);
	set("shen_type", 1);
	setup();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/朱"))
		return 0; 
	ob->add_temp("mark/朱", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	if (who->query_skill("literate", 1) > 30){
                message_vision("老秀才叹了口气对$N说道：阁下另请名师吧，我肚子里这点儿墨水已经教不了你了。\n", who);
                return 0;
        }
	if (!(int)who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);
	if (ob->query("money_id") && ob->value() >= 200) {
		message_vision("老秀才同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/朱", ob->value() / 50);
		return 1;
	}
	return 0;
}

int accept_kill(object me)
{
        command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
