//Cracked by Roath
// haidao_s.c 老海盗


#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老海盗", ({ "lao haidao", "haidao" }));
	set("long", 
	        "一个年老的海盗，虽然胡子一大把了，但还是凶巴巴的。\n");
	set("gender", "男性");
	set("age", 74);
	set("attitude", "heroism");
        set("shen_type", -1);

        set("chat_chance", 5);
        set("chat_msg", ({
                "老海盗恨恨地说：那帮小杂种嫌我老，就把我留在这个鬼岛上！\n",
                "老海盗骂骂咧咧地说：老子我迟早把你们都干掉！\n",
                "老海盗咬牙切齿地说：贼老天！\n",
		  }) );

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 230);

	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	
        if (me->query_temp(this_object()->query("id")) == 0 )
	{	
	        command("sneer " + me->query("id"));
		me->set_temp(this_object()->query("id"), 1);
	}
}

#include "/d/xiakedao/npc/xkdnpc.h"
