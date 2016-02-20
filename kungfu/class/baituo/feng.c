//Cracked by Roath
// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

#include "ansi.h"
inherit NPC;
inherit F_MASTER;

int auto_perform();
int waiting(object me);
int checking(object me);
int do_chase(object me);
int do_kill(object me, object dest);
string ask_me();
string ask_lingshe();
int ask_shegu();

void create()
{
	set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "他身形高大，高鼻深目，满脸雪白短须，根根似铁。\n"
		"他极善使毒，号称“西毒”。\n");
	set("nickname","西毒");
	set("title", "白驼山庄庄主");
	set("gender", "男性");
	set("age", 65);

	set("lingshe_count",3);
	set_skill("cuff", 400);
	set_skill("lingshe-quan", 400);
	set_skill("shentuo-zhang", 400);
	set_skill("strike", 360);
	set_skill("dodge", 360);
	set_skill("chanchubu", 360);
	set_skill("parry", 360);
	set_skill("force", 360);
	set_skill("hamagong", 400);
	set_skill("lingshe-zhang",400);
	set_skill("staff",400);
	set_skill("poison",400);
	set_skill("training",360);
//	map_skill("cuff","lingshe-quan");
	map_skill("strike","hamagong");
	map_skill("staff","lingshe-zhang");
	map_skill("dodge","chanchubu");
	map_skill("parry", "lingshe-zhang");
	map_skill("staff","lingshe-zhang");
	map_skill("force","hamagong");
//	prepare_skill("cuff","lingshe-quan");
	prepare_skill("strike","hamagong");

	set("str", 33);
	set("int", 28);
	set("con", 29);
	set("dex", 28);

	set("max_qi", 5500);
	set("qi",5500);
	set("max_jing", 3000);
	set("jing",3000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 300);
	set("combat_exp", 3600000);

		  set("attitude", "peaceful");
		  set("shen_type", -1);

		  create_family("白驼山", 1 , "庄主");
		  set("chat_chance_combat", 50);
		  set("chat_msg_combat", ({
			 (: auto_perform :),
		  }) );
	set("inquiry", ([
		"西毒" : "既有了西毒这个名号，若非在这“毒”字功夫上稍有独得之秘，未免愧对诸贤。",
		"毒" : "既有了西毒这个名号，若非在这“毒”字功夫上稍有独得之秘，未免愧对诸贤。",
		"欧阳克" : "便是舍侄。",
		"复仇": (: ask_me :),
		"报仇": (: ask_me :),
		"灵蛇" : (: ask_lingshe :),
		"蛇谷": (: ask_shegu :),
		"化尸粉" : "那是我从前用的小玩意，现在克儿还用，老夫已经不屑一用了。",
	]));

	setup();
	carry_object("/d/xingxiu/obj/lingshezhang")->wield();
	carry_object("/d/city/obj/cloth")->wear();
	set_temp("job_pos",10);

}

void attempt_apprentice(object ob)
{
		  mapping fam;
	string son;

		  if( !mapp(fam = ob->query("family")) || fam["family_name"] != "白驼山")
	{
		command ("say " + RANK_D->query_respect(ob) +
			"先去敝山庄武师或账房先生手下打打杂吧。");
		return;
	}
	if ((int)ob->query_skill("hamagong", 1) < 100) {
		command("say 我们白驼山庄的绝技是我创的蛤蟆功。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在蛤蟆功上多下点功夫？");
		return;
	}
	if ((int)ob->query_skill("training", 1) < 100) {
		command("say 我们白驼山庄经常要训驭毒虫，"); 
		command("say " + RANK_D->query_respect(ob) + 
			"的驭兽术还不够好。");
		return;
	}
	if ((int)ob->query_skill("poison",1) < 100) {
		command("say 你的毒技太低了。");
					 return;
	}

	if (ob->query("gender")=="女性") son = "义女";
	else son = "义子";
	command("look "+ob->query("id"));
	command("say 我看你天资聪颖，有心认你做"+ son +"。");
	command("say 你若肯拜我做义父，就给我"
		"磕个头(ketou)。");
	ob->set_temp("ouyangfeng",1);
	return;
}

int do_ketou(string arg)
{
	object ob = this_player();
	string son;
//	string name, new_name;

	if (!ob->query_temp("ouyangfeng")) return 0;
		  if (ob->query("gender")=="女性") son = "义女";
		  else son = "义子";

	message_vision("$N双膝跪倒，对着$n说道：“义父在上，请受孩儿一拜！”\n\n"
			"$n高兴得银须乱颤，将$N从地上扶起。\n\n", ob, this_object() );

//	name = ob->query("name");
 //      new_name = "欧阳"+ name[2..3];
  //      command("say 从今以后你的名字叫做" + new_name + "。");

	command("say 孩子，你要给为父争光。");
	command("recruit " + ob->query("id"));
	ob->set("title","白驼山庄少庄主");
	ob->set("fengdeath",ob->query("death_count"));
//	ob->set("name", new_name);
	command("chat 各位江湖朋友听着，从今往后"+ob->query("name")+
		"就是老夫的"+son+"，谁敢动我儿一根毫毛，莫怪老夫无情。");
	command("say 孩子，今后你要被人杀了，就来问我“复仇”，为父就帮你宰了仇家！");

	return 1;
}
void init()
{
	object ob, me;
	add_action("do_ketou","ketou");
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	
	if( !this_object()->query("waiting_target") && ob->query_temp("fengwait") ) 
		ob->delete_temp("fengwait");
	add_action("do_name","宰");

}

string ask_me()
{
	object me = this_player();
	if (me->query("family/family_name") != "白驼山") {
		command("say 是不是我们白驼山庄的人打了你，你想来复仇？");
		kill_ob(me);
		return ("找死！\n");
	}
	if (me->query("family/master_name") != "欧阳锋") 
		return ("你在外面闯了祸要我收拾？不争气的家伙！\n");
	if (! (me->query("fengdeath") < me->query("death_count")))
		return ("你别有事没事叫你爹我杀人。你爹还要抓紧练蛤蟆功呢。\n");
	
	command("say 孩子，谁欺负你了？快告诉为父，为父要宰了他！");
	tell_object(me, "请键入：宰 目标中文名字\n");
	me->set_temp("fengwait",1);
	return ("快点！");
}

int do_name(string target)
{
	object me, dest, *all;
		  int i;
 
	me = this_object();
	all = users();

	if(me->query("waiting_target"))
		 return notify_fail("欧阳锋说道：我现在正忙着呢！\n");

	if( !this_player()->query_temp("fengwait") ) 
		return notify_fail("欧阳锋说道：想让我宰了你？那容易！\n");

	if( !target || target==" ")
		return notify_fail("欧阳锋恶狠狠地说道：快告诉为父那家伙的名字！\n");


	for(i=0; i<sizeof(all); i++) 
	{
		if( target == all[i]->name() || target == all[i]->query("id") )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("欧阳锋长叹一声：他现在不在游戏中，过会再来吧。\n");

	if (dest->is_ghost())
		return notify_fail("欧阳锋高兴地说：他已经受到报应死了，老天有眼，为父也不必出马了。\n");

	if (dest->query("id") != this_player()->query_temp("my_killer"))
		return notify_fail("欧阳锋摇摇头：此人不该死。\n");

	me->set("waiting_target", dest->query("id"));
	me->set("target_name", target);
	log_file("Playing", sprintf("%s(%s) attempted to let Ouyang Feng to kill %s(%s)\n",
			this_player()->query("name"), getuid(this_player()),
			dest->query("name"), dest->query("id")) );

	this_player()->set("fengdeath",this_player()->query("death_count"));
	message("vision","欧阳锋说道：你先在这里等等，为父去去就来!\n", environment(), me );

	message_vision("$N走了出去。\n", me);

	call_out("do_chase", 1, me);

	return 1;
}

int do_chase(object me)
{

	object dest;
	dest = find_player(me->query("waiting_target"));

	if( !objectp(dest) || !environment(dest) )
	{
		call_out("waiting", 0, me);
		return 1;
	}

	me->move(environment(dest));
	message_vision("$N走了过来。\n", me);
	me->set_leader(dest);
	command("look " + dest->query("id"));

	if ( !environment(me)->query("no_fight"))
	{
		call_out("do_kill", 1, me, dest);
		return 1;
	}
	else
	{
		call_out("waiting", 0, me);
		return 1;
	}

	return 1;
}

int do_kill(object me, object dest)
{

	if( objectp(dest) && present(dest, environment(me)) 
	&& !environment(me)->query("no_fight"))
	{
		message_vision(HIR "$N对$n说道：大胆狂徒，竟敢欺负我们欧阳家的人！\n" NOR, me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);

		call_out("checking", 0,  me); 
	}
	else
		call_out("waiting", 1, me); 

	return 1;
}

int waiting(object me)
{
	object dest;
	dest = find_player(me->query("waiting_target"));

	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			me->delete("waiting_target");
			call_out("do_back", 1, me);
			return 1;
		}else if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}else if (living(me) && !environment(dest)->query("no_fight"))
		{
			call_out("do_chase", 0, me);
			return 1;
		}
	}

	remove_call_out("waiting");
		  call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
	object ob;

	if (me->is_fighting()) 
	{
		 call_out("checking", 1, me);
	return 1;
	}

	if( objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") == me->query("target_name") )
	{
		me->delete("waiting_target");
		call_out("do_back", 1, me);
	return 1;
	}

	call_out("waiting", 0, me);
	return 1;
}

int do_back(object me)
{

	me->move("/d/xingxiu/btroom");
	message("vision", "欧阳锋走了进来，擦了擦身上的血，说道：孩子，你的仇为父替你报了。\n", 
		environment(), me );


	me->set_leader(0);
	return 1;
}

void greeting(object me)
{
	int sxds, hand;

	sxds = me->query_skill("shexing-diaoshou",1);
	hand = me->query_skill("hand",1);

	if (me->query("family/family_name") != "白驼山") {
		me->apply_condition("snake_poison", 
		2 + me->query_condition("snake_poison"));
	}

	if( me->query("family/family_name") == "白驼山" 
	&& !me->query("baituo_updated") ) {
		me->set_skill("cuff", hand);
		me->set_skill("lingshe-quan", sxds);
		me->delete_skill("hand");
		me->delete_skill("shexing-diaoshou");
		me->set("baituo_updated",1);
	}

	if (me->query("enter_shegu")) {
		if ( environment(me) != environment(this_object())) return;

		me->delete("enter_shegu");

		if (me->query("family/family_name") != "白驼山") {
			command("hehe "+me->query("id"));
			command("say "+me->name()+RANK_D->query_rude(me)+"，竟敢擅闯蛇谷，我若不将你折磨得死不成活不了，岂不枉称“西毒”名号？");
			command("perform shoot "+me->query("id")); //for weapon
			kill_ob(me);
		}
		else if (me->query("family/family_name") == "白驼山" 
		&& !me->query("baituo/shegu_permit") ) {
			command("slap "+me->query("id"));
			command("say 谁叫你擅入蛇谷的？");
			message_vision(HIR"欧阳锋在$N的肩头重重按了一掌，蛤蟆功劲力直透腑脏，登时震得$N面如白纸，汗如雨下。\n"NOR, me);
			me->set("neili", 0);
			me->set("jingli", me->query("jingli")/10);
			me->set("qi", me->query("qi")/10);
			me->start_busy(3);
			command("say 这点惩罚，算是便宜你了。不许再有下次！");
		}
	}
	return;
}

string ask_lingshe()
{
	mapping fam;
	object obj, me;

	me = this_player();
	if (me->query("family/master_name") != "欧阳锋") {
		return ("娃娃功力不够，还是别要为妙！");
	}
	if (query("lingshe_count") < 1) {
		return ("灵蛇驯养不易，现在没有！");
	}
	message_vision(CYN"$N撮唇作啸，袖中缓缓游出一条银色小蛇，对着$n摇头摆尾，似在示意问好。\n"NOR,
	this_object(), me);
	obj = new("/d/xingxiu/npc/lingshe.c");
	obj->move(environment());
	add("lingshe_count", -1);
		  return ("灵蛇已显，娃娃不妨试试是否有缘成为它的主人。");
}

int ask_shegu()
{
	object me, staff;
	int lv;
	me = this_player();

	if( me->query("family/family_name") != "白驼山" && me->query("combat_exp") > 100000) {
		command("sneer "+me->query("id"));
		command("say 白驼山蛇谷的秘密，岂能透露给外人知晓？"+RANK_D->query_rude(me)+"，你太多嘴了！");
		kill_ob(me);
		command("perform bite "+me->query("id")); // has weapon
		command("perform puji "+me->query("id")); // no weapon
		return 1;
	}

	if( me->query("family/family_name") != "白驼山" ) {
		command("sneer "+me->query("id"));
		message_vision("$N没有回答$n。\n", this_object(), me);
		return 1;
	}

	if( me->query("baituo/shegu_permit") ) {
		command("say 蛇谷中的蛇儿，你可以随意捕捉。好好修炼毒技，莫要堕了西毒的威名！");
		return 1;
	}

	lv = (int)me->query_skill("poison", 1);

	if( lv < 80 ) {
		command("say 凭你这点使毒本事，想进蛇谷还早得很。乖乖的在庄里修炼！");
		return 1;
	}
	
	if( lv < 100 ) {
		command("pat "+me->query("id"));
		command("say 你的毒技是有点火候了，不过想进蛇谷，还得多下点功夫琢磨。");
		return 1;
	}

	command("nod "+me->query("id"));
	command("say 你用毒的能耐，似乎是进步多了。好，老夫就许你进蛇谷练练本领。");
	me->set("baituo/shegu_permit", 1);

	staff = new("/d/xingxiu/obj/lingshezhang");
	staff->move(me);

	message_vision("$N将一根"+staff->name()+"交给$n。\n",this_object(), me);
	command("say 从今以後，你可以自由进出蛇谷。用心从中钻研，你的毒技还可以更上层楼。");

	return 1;
}

#include "/kungfu/class/baituo/auto_perform.h"
