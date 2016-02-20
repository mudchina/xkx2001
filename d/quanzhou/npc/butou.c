//Cracked by Roath
// xunbu.c 捕头
// Fang 8/21/96
// Modified by Zhuang@XKX 960903 - disable hatred autofight

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("捕头", ({ "bu tou", "tou" }));
        set_color("$YEL$");
	set("age", 42);
	set("gender", "男性");
	set("long", "他是远近闻名的扬州第一捕头，一生侦破无数疑案。\n");
	set("attitude", "heroism");
//	set("vendetta_mark", "authority");
        set("pursuer", 1);

	set("str", 30);
	set("dex", 25);
	set("combat_exp", 100000);
	set("shen_type", 0);
        set("max_neili", 700);
        set("neili", 700);
        set("jiali", 20);
	set_skill("unarmed", 55 + random(10));
	set_skill("dodge", 55 + random(10));
	set_skill("parry", 55 + random(10));
	set_skill("blade", 55 + random(10));
	set_skill("force", 55 + random(10));
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 50);
        set("chat_chance", 5);
        set("chat_msg", ({
                "捕头大喊: 闪开！\n",
                (: random_move :)
        }) );

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"捕头喝道：大胆刁民，还不快快束手就擒！\n",
	}));
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/armor/junfu")->wear();
}

void init()
{
        if( strsrch(file_name(environment()), "/d/quanzhou/") == -1 ) {
                message_vision("$N快步走了过来。\n$N神色慌张地离开了。\n", this_object());
                this_object()->move("/d/quanzhou/zhongxin");
                message_vision("$N快步走了过来。\n", this_object());
        } else if( interactive(this_player())
	&& (int)this_player()->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, this_player());
	} else if( is_killing(this_player()->query("id")) )
		remove_killer(this_player());
}

int accept_fight(object me)
{
	command("say 小的有公务在身，不能与你过招。\n");
	return 0;
}

int accept_kill(object me)
{
        command("say 你这是太岁头上动土，活得不耐烦了！明年此时就是你的忌日！\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

