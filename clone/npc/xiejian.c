//Cracked by Roath
// xiejian.c 邪剑李四
// modified by aln 4 / 98
// Modified by Apache for enhancement 11/99
//  0. Fixed unlimited kill mission bug
//  1. Price raised to 600 gold
//  2. Kill ppl < 600k only
//  3. Check mission record to chase a ppl only once within a certain period of time (1 week)
//     This was done by applying a "last_lisi_mission" timestamp to each ppl when finishing
//     the job.

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif

#define XIEJIAN  NPCDATA + "xiejian"
#define OFFICE  "/d/village/shop"

#include <ansi.h>

inherit NPC;
inherit F_SAVE;

int auto_check();
void waiting();
void checking();
void do_chase();
void do_kill(object);

string query_save_file() { return XIEJIAN; }

void create() {
    seteuid(getuid());

    if (!restore()) {
		set_name("李四", ({ "li si", "li" }) );
	} else {
		set("id", "li si");
		set_name(query("name"), ({ query("id") }));
	}

	set("title", "小店老板");
	set("gender", "男性" );
	set("shen_type", -1);
	set("age", 40);
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("long", "这是整天笑咪咪的小店老板，虽然不卖什么东西，却也过得自在。\n" );

	set("combat_exp", 200000);
	set("attitude", "peaceful");
				
	set("max_qi", this_object()->query("max_qi"));
	set("eff_qi", this_object()->query("max_qi"));
	set("qi", 700);
	set("max_jing", 400);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 50);
	set("shen_type", -1);
	set("env/wimpy", 10);

	set_skill("force", 60); 
	set_skill("ding-force", 60);
	set_skill("unarmed", 80);
	set_skill("ding-unarmed", 80);
	set_skill("sword", 100);
	set_skill("huashan-jianfa", 100);
	set_skill("dodge", 100);
	set_skill("ding-dodge", 100);
	set_skill("parry", 100);

	map_skill("unarmed", "ding-unarmed");
	map_skill("dodge", "ding-dodge");
	map_skill("sword", "huashan-jianfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("force", "ding-force");

	setup();
	clear_condition();  

	set("inquiry", ([
		"邪剑"   : "我就是邪剑李四，你来找我有什么事吗？",
		"杀人"   : "我就是邪剑李四，你来找我有什么事吗？",
	]) );

	set("chat_chance", 5);
	set("chat_msg",({ (: auto_check :) }));

	carry_object("/d/city/obj/gangjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();

	add_money("silver", random(30));
}

void init() {
	object ob = this_player();

	::init();

	if( interactive(ob) && ob->query_temp("fee_paid") ) 
		ob->delete_temp("fee_paid");

	add_action("do_hire", "杀");
	add_action("do_hire", "sha");
	add_action("do_hire", "chase");
}

int do_hire(string arg) {
	object ob;
	string who;
	int i, when;
	int cur_time, cloned;

	if( is_busy() || is_fighting() ) 
		return notify_fail("李四正忙着！\n");

	if( base_name(environment()) != OFFICE )
		return notify_fail("李四嘿嘿一笑：我现在正忙着哪，您以后再找我吧！\n");

	if( !this_player()->query_temp("fee_paid") ) 
		return notify_fail("李四说道：不管叫我做什么，您可得先付钱哪！\n");

	if( !arg )
		return notify_fail("李四恶狠狠地说道：快告诉我那家伙的名字，我可没功夫听你闲聊！\n");

	if( sscanf(arg, "%s %d", who, when) != 2 ) {
		who = arg;
		when = 0;
	}

	cloned = 0;
	if( !(ob = find_player(who)) ) {
		ob = new(USER_OB);
		cloned = 1;
		ob->set("id", who);
		if( !ob->restore() ) {
			destruct(ob);
			return notify_fail("李四说道：没有这个人。\n");
		}
	}
	if ( ob->query("combat_exp") > 600000)
		return notify_fail("李四缩了缩脖子，干笑道：“这位我可惹不起，您还是另请高明吧。”\n");
			
	cur_time = time();
	if ( ob->query("last_lisi_mission") > cur_time - 3600*24*7 ) // one week
		return notify_fail("李四想了想，说道：“我前几天刚刚与这家伙拼命。盗亦有道，\n还是给这家伙一个机会吧。”\n");
	
	if (cloned) {		
		call_out("destroy_ob", 1, ob);
	}

	if (query_temp("busy")) 
			return notify_fail("李四摆手道：“慢慢说，慢慢说。”\n");

	set_temp("busy", 1);
	
	set("job/" + cur_time, who);
	set("job_time/" + cur_time, cur_time + when * 3600);
	save();

	log_file("Playing", sprintf("李四(Li si) is hired by %s(%s) at %s to kill %s(%s) after %s\n", 
		this_player()->query("name"), this_player()->query("id"), ctime(time()), 
		ob->query("name"), who, ctime(time() + when )));

	message("vision", HIY "李四嘿嘿嘿地乾笑了几声，说道：“您就静侯佳音吧!”\n"NOR, environment());

	this_player()->delete_temp("fee_paid");
	
	call_out("delete_busy", 1);
	
	return 1;
}

void delete_busy() {
	delete_temp("busy");
}

void destroy_ob(object ob) {
	if( ob ) destruct(ob);
}

int accept_object(object who, object ob) {
	
	if (ob->query("money_id") && ob->value() >= 6000000 && 
		!this_object()->query("waiting_target")) {
		if ((int)this_player()->query("age") < 16 || this_player()->query("combat_exp") < 10000){
			tell_object(who, "李四轻蔑地瞧了你一眼，不屑地说道：生意上的事儿，回去让你们家老爷子来找我谈吧。\n");
			return 1;
		}

		tell_object(who, "李四沉下脸来：好，爽快说吧，你要我帮你杀谁？\n");
		tell_object(who, "请键入：杀 目标英文名字 多少小时后行动\n");
		who->set_temp("fee_paid",1);
		return 1;
	} else if (ob->query("money_id") && ob->value() < 6000000) 	{
		tell_object(who, "李四嘿嘿一笑，说道：给我这么多钱？ 将来我可没法还你啊。\n");
		return 1;
	}

	return 0;
}

int auto_check() {
	object ob, dest;
	mapping job, job_time;
	int i, *times;
	string id;
	string *parts, *safp = ({
		"city",
		"death",
		"island",
		"shenlong",
		"taohua",
		"wizard",
		"xiakedao",
	});

	if( !living(this_object()) || is_busy() || is_fighting() ) return 0;
	if( base_name(environment()) != OFFICE ) return 0;
	if( query_temp("target") ) return 0;
	if( !(job = query("job")) ) return 0;

	job_time = query("job_time");
	times = keys(job_time);

	for(i = 0; i < sizeof(times); i++) {
		if( time() < job_time[times[i]] ) continue;
		if( !(ob = find_player(job[times[i]])) ) continue;
		if( !(dest = environment(ob)) ) continue;
		if( dest->query("no_fight") ) continue;

		parts = explode(base_name(dest), "/");
		if( parts[0] != "d" ) continue;
		if( member_array(parts[1], safp) != -1) continue;
		if( parts[2] == "duchuan" || parts[2] == "ship" ) continue;

		if( !ob->is_busy() && !ob->is_fighting()
			&&  (int)ob->query("qi")*10 > (int)ob->query("max_qi")*5
			&&  (int)ob->query("combat_exp") > 100000 )
        continue;
		break;
	}

	if( i >= sizeof(times) )
		return 0;

	map_delete(job, times[i]);
	map_delete(job_time, times[i]);
	save();

	set_temp("target/id", ob->query("id"));
	set_temp("target/name", ob->query("name"));

	set_temp("apply/attack",  100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage",  50);

	set("vendetta/authority", 1);
	set("bellicosity", 10000);

	set("title", HIR "邪剑" NOR);
	set("long", "邪剑李四，杀手帮十大高级剑士之一，有剑不染血不归鞘之名。\n" );

	message_vision("$N匆匆忙忙离开了。\n", this_object());
	call_out("do_chase", 1);
	return 1;
}

void do_chase() {
	object ob = find_player(query_temp("target/id"));

	if( !objectp(ob) || !environment(ob) ) {
		call_out("waiting", 0);
		return;
	}

	move(environment(ob));
	message_vision("$N走了过来。\n", this_object());
	set_leader(ob);
	command("look " + ob->query("id"));

	if ( !environment()->query("no_fight") )
		call_out("do_kill", 1, ob);
	else
		call_out("waiting", 0);
}

void do_kill(object ob) {
	if( objectp(ob) && present(ob, environment()) && !environment()->query("no_fight") ) {
		message_vision(HIR "$N对$n说道：阴司鬼王差我来，请你去他那儿做客，" + 
			RANK_D->query_rude(ob)+"，你认命吧！\n" NOR, this_object(), ob);
		set_leader(ob);
		kill_ob(ob);
		ob->fight_ob(this_object());

		call_out("checking", 0); 
	} else  
		call_out("waiting", 1); 
}

void waiting() {
	string id = query_temp("target/id");
	object ob = find_player(id);
	int cur_time;

	if ( objectp(ob) ) {
		if( ob->is_ghost()) {
			delete_temp("target");
			call_out("do_back", 1);
			return;
		}else if( is_fighting() && present(ob, environment())) {
			call_out("checking", 0);
			return;
		}else if( living(this_object()) && !environment(ob)->query("no_fight")) {
			call_out("do_chase", 0);
			return;
		}
	} else {			// Get back if target quit during fight.
		remove_call_out("waiting");
		cur_time = time();
		set("job/" + cur_time, id);
		set("job_time/" + cur_time, cur_time);
		save();
		delete_temp("target");
		message_vision("$N冷笑道：“躲得过初一，也躲不过十五！”\n", this_object());
		call_out("do_back", 1, 0);
		return;
	}
	

	remove_call_out("waiting");
	call_out("waiting", 60);
}

void label_player(string userid) {
	int cur_time, cloned;
	object ob;
	
	if( !(ob = find_player(userid)) ) {
		ob = new(USER_OB);
		cloned = 1;
		ob->set("id", userid);
		if( !ob->restore() ) {
			destruct(ob);
			return;
		}
	}
	
	cur_time = time();
	ob->set("last_lisi_mission", cur_time);
	
	if (cloned) {		
		call_out("destroy_ob", 1, ob);
	}
	
}

void checking() {
	string userid;
	object ob;

	if( is_fighting() ) {
		call_out("checking", 1);
		return;
	}

	if( objectp(ob = present("corpse", environment()) )
		&& ob->query("victim_name") ==	query_temp("target/name") ) {
		userid = query_temp("target/id");
		call_out("label_player", 1, userid);
		delete_temp("target");
		call_out("do_back", 1, 1);
		return;
	}

	call_out("waiting", 0);
}

void do_back(int success) {
	message_vision("$N匆匆忙忙离开了。\n", this_object());
	move(OFFICE);
	if (success) 
		message("vision", "李四走了进来，拍了拍身上的尘土，把剑上的血迹抹拭乾净，\n"
			"他接着一笑说道：老天爷保佑，活儿干得乾净利落，您老以后有什么事还可以找我。\n", 
			environment(), this_object());
	else
		message("vision", "李四走了进来，微笑道：“小子惭愧，让这家伙溜了。不过此人已如惊弓之鸟。\n" +
			"下次一定成功。”\n", environment(), this_object());

	set("title", "小店老板");
	set("long", "这是整天笑咪咪的小店老板，虽然不卖什么东西，却也过得自在。\n" );
	
	set_leader(0);

	delete_temp("apply/attack");
	delete_temp("apply/defense");
	delete_temp("apply/damage");
}
