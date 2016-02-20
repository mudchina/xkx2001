//Cracked by Roath
// xunbu.c 巡捕
// Fang 8/21/96
// modified Zhuang@XKX 960903
// fixed move in init(), xuy 08/11/97
// Don't move or destruct this_object or this_player in init()
// If necessary, use call_out to do it.
//
// This NPC is confined in the city now.
//
// if we call ::init() in init(), they'll start autofight because of hatred
// even after a player's death, which is not good.
//
// modified wzfeng 2000 7 Let the xunbu be tough.
//

#include <ansi.h>
inherit NPC;
#include "npc_skills_attrib_setup.h"
private string *home_locations = ({
	"/d/city/dongdajie1",
	"/d/city/xidajie1",
	"/d/city/nandajie1",
	"/d/city/beidajie1",
});
string *family_list=({"全真教","华山派","大理段家","少林派","峨嵋派"});
void remove_cantmove(object me);
void create()
{
	set_name("巡捕", ({ "xun bu", "bu" }));
        set_color("$YEL$");
	set("age", 32);
	set("gender", "男性");
	set("long", "这是一个经验老到的巡捕，一双精明的眼睛冷冷地盯着你。\n");
	set("attitude", "heroism");
//	set("vendetta_mark", "authority");
	set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 1000000);
	set("shen_type", 0);

	set_skill("unarmed", 150 + random(10));
	set_skill("dodge", 150 + random(10));
	set_skill("parry", 150 + random(10));
	set_skill("blade", 150 + random(10));
	set_skill("luan-blade", 150 + random(10));
	set_skill("force", 150 + random(10));
	map_skill("blade", "luan-blade");
	map_skill("parry", "luan-blade");

	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
        set("chat_chance", 5);
        set("chat_msg", ({
                "巡捕大喊: 闪开！\n",
                (: random_move :)
        }) );

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"巡捕喝道：大胆刁民，竟敢造反不成？\n",
		"巡捕喝道：跑得了和尚跑不了庙，你还是快快束手就擒！\n",
	}));
	setup();
	//carry_object(__DIR__"obj/gangdao")->wield();
	//carry_object(__DIR__"obj/junfu")->wear();
}

private void go_home()
{
	if( !living(this_object()) ) return;
	message_vision("$N快步走了过来。\n$N神色慌张地离开了。\n", this_object());
	this_object()->move(home_locations[random(sizeof(home_locations))]);
	message_vision("$N快步走了过来。\n", this_object());
}

void init()
{
	if( strsrch(file_name(environment()), "/d/city/") == -1 ) {
		remove_call_out("go_home");
		call_out("go_home", 1);
		return;
	} else if( interactive(this_player())
	&& (int)this_player()->query_condition("killer") ) 
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, this_player());
		} 
	else 
		if( is_killing(this_player()->query("id")) )
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
        return 1;
}
//////////add by wzfeng/////////////////////////////////
void kill_ob(object me)
{
	int exp,i,k;
	object *inv;
	string family;
	if(me->query("id")!=query("kill_player")
		&&(!me->is_fighting()))
	{
		set("kill_player",me->query("id"));
	inv = all_inventory(this_object());
	if(sizeof(inv) ) 
		for(i=0;i<sizeof(inv);i++)
		destruct(inv[i]);
		exp=500000+random(500000);
	

	Set_Npcattrib(20,10,
	 me->query("max_qi"),me->me("max_qi")/10,
 	 me->query("max_jing"),me->query("max_jing")/10,
	 me->query("max_jingli"),me->query("max_jingli")/10,
	me->query("max_neili"),me->query("max_neili")/10,
	exp,exp/10);
	exp=query("combat_exp");
	for (i=0;(i*i*i/10)<exp;i++);
	i=i*7/8;
	k=sizeof(family_list);
	command("fangqi all");
	reset_action();
	family=family_list[random(k)];
	if(random(2)>0)
		skills_setup_weapon(i,0,family);
	else
		skills_setup_none(i,0,family);


	set("chat_chance_combat", 99);
	me->set_temp("cannot_move",1);
	me->set_temp("cannot_move_msg","你被"+this_object()->query("name")+"攻势所逼，无法移动半步\n");
	remove_call_out("remove_cantmove");
	call_out("remove_cantmove",1+random(1),me);
	}


        ::kill_ob(me);

}
void remove_cantmove(object me)
{
	me->delete_temp("cannot_move_msg");
	me->delete_temp("cannot_move");
}
////////////////////////////////////////////////////////


