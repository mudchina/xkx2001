//Cracked by Roath
// haidao_s.c 受伤海盗


#include <ansi.h>
inherit NPC;

void create()
{
	set_name("受伤海盗", ({ "shang haidao", "haidao" }));
	set("long", 
                "一个凶巴巴的海盗，但是脸色枯黄，象是受了重伤。\n");
	set("gender", "男性");
	set("age", 44);
	set("attitude", "heroism");
        set("shen_type", -1);

        set("chat_chance", 5);
        set("chat_msg", ({
                "海盗恨恨地说：那帮家伙看我受了伤，就把我留在这个鬼岛上！\n",
                "海盗骂骂咧咧地说：大爷我迟早把你们都干掉！\n",
                "海盗咬牙切齿地说：贼老天！\n",
		  }) );

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 140);

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
	        command("nomatch " + me->query("id"));
		me->set_temp(this_object()->query("id"), 1);
	}
}

#include "/d/xiakedao/npc/xkdnpc.h"
