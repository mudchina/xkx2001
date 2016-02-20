//Cracked by Roath
// yapu_npc.c 哑仆候选
#include <ansi.h>
#include <room.h>

inherit NPC;
int auto_perform();

void create()
{
	switch( random(7) )
	{
	case 0:
	set_name("小贩", ({ "xiao fan", "seller", "fan" }) );
	set("long","这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
	set("gender", "男性");
	set("age", 32);
	set("real_name","大盗");
	set("real_long", "这是一个杀人不眨眼的盗匪，凭著一身武艺四处横行掳掠，杀人放火，无所不为。\n");
	set("real_title", "山寨头目");
	set("real_menpai", "huashan");
		break;
	case 1:
	set_name("书生", ({ "shu sheng", "sheng" }) );
	set("long","这是个饱读诗书，却手无搏鸡之力的年轻书生。\n");
	set("gender", "男性");
	set("age", 18 + random(4));
	set("int", 30);
	set("real_name","杀手");
	set("real_long", "他原本是当朝一名宫廷护卫，後来贪图重贿，变节投靠金国，\n金国朝廷派他暗杀中原官员，手段阴狠歹毒，已有数名将官死在他的手上。\n");
	set("real_title", "金国奸细");
	set("real_menpai", "dajin");
		break;
	case 2:
	set_name("趟子手", ({ "tangzi shou","shou" }) );
	set("gender", "男性");
	set("age", 30);
	set("real_name","恶霸");
	set("long","这是个镖局趟子手，长得虎背熊腰，一身横练功夫。\n");
	set("real_long", "他本来是铁掌帮中的一个无名小卒，乘著门中长辈卧病在床时杀师叛门，\n抢走本门武功秘诀，练就了一身功夫，恃著武艺精熟，四处为非作歹。\n");
	set("real_title", "铁掌帮");
	set("real_menpai", "tiezhang");
		break;
	case 3:
	set_name("僧人", ({ "seng ren", "seng"}));
	set("long","这是一位僧人。\n");
	set("gender", "男性");
	set("age", 35);
	set("class", "bonze");
	set("real_name","破戒僧");
	set("real_long", "他曾经拜在一名少林高僧门下，由于不守清规，时常被师父呵斥。\n他武功有成後，因为怀恨在心，居然下手杀死受业恩师，逃出少林寺，投入了西域金刚门。\n");
	set("real_title", "金刚门弟子");
	set("real_menpai", "shaolin");
		break;
	case 4:
	set_name("胡人", ({ "hu ren", "ren", "foreigner" }));
	set("long", "一个金发碧眼的胡人，正趾高气扬的吆喝着。\n");
	set("gender", "男性");
	set("age", 30 + random(10));
	set("real_name","蒙古武将");
	set("real_long", "这是一个来自西域番邦的武士，他因为曾在西域偷学得几样厉害功夫，\n投身蒙古军中之後颇受重用，职权也不小。\n他虽然骁勇，个性却十分残忍，时常带兵出外残杀百姓为乐，令人发指。\n");
	set("real_menpai", "xiyu");
		break;
	case 5:
	set_name("穷汉", ({ "poor man", "man" }));
	set("gender", "男性");
	set("age", 53);
	set("long", "一个骨瘦如柴，满脸菜色的穷汉。\n");
	set("real_name","护法喇嘛");
	set("real_long", "他是密宗教中旁支的一名护法喇嘛，由于沉溺武学，向佛之心日淡，\n一日里暗中窃取寺中武学典籍，杀了看管的同门师兄弟，逃到中原潜心修炼，\n因为好勇斗狠，经常滥杀无辜，在武林中也是声名狼藉。\n");
	set("real_title", "密宗旁支");
	set("real_menpai", "mizong");
		break;
	case 6:
	set_name("女孩",({ "girl" }) );
	set("gender", "女性" );
	set("age", 16+random(3));
	set("long", "这是个农家少女，虽然只有十来岁，身材已经开始发育。\n");
	set("real_name","苗疆巫女");
	set("real_long", "她是苗族中一个小部落的巫女，幼时因为好奇而钻研蛊毒，後来因故投入星宿派，\n将毒技融汇於武功之中，年纪轻轻，造诣竟也不凡。她久与星宿弟子相处，耳濡目染之下，\n行事也变得阴险狡猾，为了炼毒，已平白害死了不少族中同胞。\n");
	set("real_menpai", "miaojiang");
		break;
	}
	set("str", 20);
	set("con", 20);
	set("int", 20);
	set("dex", 20);

	set("attitude", "peaceful");
	set("combat_exp", 10000);
	set("yapu_target",1);
	
	set("chat_chance", 6);
	set("chat_msg", ({ (: random_move :) }));

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) ); 

	setup();
	carry_object("/clone/misc/cloth")->wear();
}


int checking(object me, object victim)
{
	victim = this_player();
	if ( !victim ) return 1;
	if (!query("real_face")) return 1;
/*
	if ( !victim = find_player(me->query("th_victim")) 
	&& victim->query("combat_exp") > me->query("combat_exp") ) {
	     message_vision("$N晃了个虚招，狼狈不堪地逃了开去。\n", me);
	     destruct(me);
	     return 1;
	}
*/
	if ( victim->is_ghost() && living(me)) {
	     command("grin");
	     command("say 想抓"+RANK_D->query_self_rude(me)+"，那有这麽容易！");
	     message_vision("$N冷笑几声，扬长而去。\n", me);
	     destruct(me);
	     return 1; 
	}

	else if ( !me->is_fighting() && me->query("real_face") && living(me)) {
	     command("kick corpse");
	     command("say 想抓"+RANK_D->query_self_rude(me)+"，那有这麽容易！");
	     message_vision("$N冷笑几声，扬长而去。\n", me);
	     destruct(me);
	     return 1;
	}

	remove_call_out("checking");
	call_out("checking", 1, me, victim);
	return 1;
}

int accept_fight(object victim)
{
	object me = this_object();

	if (!query("real_face")) return 1;
	if (!living(me)) return 1;

	if (is_fighting() && me->query("th_victim") 
	&& me->query("th_victim")!= victim->query("id") 
	&& victim->query("combat_exp") > me->query("combat_exp") ) {
	      command( "say 滚一边去！" );
	      return 0;
	}
	else {
	     command("say 哼哼，"+RANK_D->query_self_rude(me)+"就送你上西天去！" );
	     me->kill_ob(victim);
	     remove_call_out("checking");
	     call_out("checking", 1, me, victim);
	     return 1;
	}
}

int accept_kill(object victim)
{
	object me = this_object();

	if (!query("real_face")) return 1;
	if (!living(me)) return 1;

	if (is_fighting() && me->query("th_victim") 
	&& me->query("th_victim")!= victim->query("id") 
	&& victim->query("combat_exp")*3/2 > me->query("combat_exp") ) 	
	{
	    	command("say 想倚多为胜？"+RANK_D->query_self_rude(me)+"可不奉陪了！");
	     message_vision("\n$N突然卖一破绽，跳出战圈，逃了！\n", me);
	     remove_call_out("checking");
	     me->remove_all_enemy();
	     destruct(me);
		return 1;
	}
	else {
	     command( "say 你这"+RANK_D->query_rude(victim)+"也来跟"+RANK_D->query_self_rude(me)+"过不去？连你一起宰了！" );
	     me->kill_ob(victim);
	     remove_call_out("checking");
	     call_out("checking", 1, me, victim);
	return 1;
	}

}

void unconcious()
{
	object me = this_object();
	remove_call_out("checking");
	me->disable_player(" <昏迷不醒>");
	me->set("jing", 0);
	me->set("qi", 0);
	COMBAT_D->announce(me, "unconcious");
	call_out("revive", random(100 - query("con")) + 30);
}

void die()
{
	object corpse;
	mixed killer;

	remove_call_out("checking");
	
	if( !living(this_object()) ) revive(1);
	COMBAT_D->announce(this_object(), "dead");

	if( objectp(killer = query_temp("last_damage_from"))){
	     set_temp("my_killer", killer->query("id"));
	     COMBAT_D->killer_reward(killer, this_object());
	}

	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	     corpse->move(environment());
	     corpse->delete("combat_exp");
		corpse->set("th_victim",query("th_victim"));
		corpse->set("yapu_fail",query("th_victim"));

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());
	
	destruct(this_object());

}

int random_move()
{
	mapping exits, doors;
	string *dirs, dir;
	object me=this_object();

	if (is_fighting() || is_busy() || !living(me))
	     return 0;

	if (!me->query("steps")) {
	     remove_call_out("destroying");
	     call_out("destroying",1200,me);
	}

	if (me->query("steps")>=25) {
	     remove_call_out("destroying");
	     call_out("destroying",1,me);
	     return 0;
	}

	me->add("steps",1);

	if (!objectp(environment()) 
	     || !mapp(exits = environment()->query("exits")) 
	|| query("jingli") < query("max_jingli") / 2 )
	     return 0;

	dirs = keys(exits);

	if (this_object()->query("race") == "人类"
	     && mapp(doors = environment()->query_doors()))
	     dirs += keys(doors);

	if (sizeof(dirs) == 0) return 0;
	dir = dirs[random(sizeof(dirs))];

	if (mapp(doors) && !undefinedp(doors[dir])
	     && (doors[dir]["status"] & DOOR_CLOSED) )
	     command("open " + dir);

	command("go " + dir);
	return 1;
}

void destroying(object me)
{
	message_vision("$N看了看周遭，若无其事地离开了。\n",me);
	destruct(me);
	return;
}

#include "yapu_auto_perform.h"
