//Cracked by Roath
// dali bandit 1, low level

#include <ansi.h>
#include <room.h>

inherit NPC;

void create()
{
	switch (random(5))
	{
		case 0 :
			set_name("小贼", ({"xiao zei", "zei"}));
			break;
		case 1 :
			set_name("地痞", ({"di pi", "pi"}));
			break;
		case 2 :
			set_name("恶霸", ({"e ba", "ba"}));
			break;
		case 3 :
			set_name("流氓", ({"liu mang", "liu"}));
			break;
		case 4 :
			set_name("无赖", ({"wu lai", "lai"}));
			break;
	}
	switch (random(6))
	{
		case 0 :
			set("title", "星宿派拍马手");
			set("long", "这家伙在星宿派作过几天溜须拍马的事儿，也多少学了些功夫，回到乡里就为非作歹。\n他看起来功夫低微。\n");
			break;
		case 1 :
			set("title", "华山派弃徒");
			set("long", "此人曾经拜在华山门下学艺，因为行为不轨被逐出门墙，在地方上终日鬼混，打架斗殴。\n他看起来虽然有两斤力气，功夫却不怎么样。\n");
			break;
		case 2 :
			set("title", "武当派叛徒");
			set("long", "他曾经是武当派的低辈弟子，某次随师傅下山遭遇仇敌，卖师保命，此后再也不敢回武当，凭着一点功夫在江湖上厮混。\n他看起来功夫颇差劲。\n");
			break;
		case 3 :
			set("title", "雪山派小喇嘛");
			set("long", "他是新近才入大轮寺的小喇嘛，经常从雪山上下来，到大理边境的山村偷鸡摸狗。\n他还没有学到多少功夫。\n");
			break;
		case 4 :
			set("title", "丐帮恶贼");
			set("long", "这人一身乞丐打扮，其实早已因为恶迹被丐帮开除，在北方混不下去了，跑到南边来作恶。\n他除了厮打凶狠，没有多少真才实学。\n");
			break;
		case 5 :
			set("title", "五毒教打手");
			set("long", "五毒教总部在大理，自然要网罗爪牙培养势力，此人是地方上有名的恶棍，被收作打手。\n他虽然没学过多少功夫，身手倒是蛮矫健的。\n");
			break;
	}
	set("gender", "男性");
	set("age", 20+random(10));
	set("attitude", "heroism");
	set("str", 20+random(10));
	set("int", 10+random(10));
	set("con", 15+random(10));
	set("dex", 20+random(10));
	set("dalibandit",1);
	set("dalibandit1",1);
	set("shen_type", -1);
	set("chat_chance", 15);
	set("chat_msg", ({(: random_move :),}));
	setup();
	carry_object("/d/city/obj/beixin")->wear();
}

void init()
{
	object who=this_player(), me=this_object();

	if (interactive(who)) set_heart_beat(1);
	if (who->query("dalivictim") && !me->is_fighting() && random(3)==2)
	{
		remove_call_out("killvictim");
		call_out("killvictim", 1, me, who);
	}
}

void killvictim(object me, object who)
{
	if (present(who, environment(me)))
	{
		if (who->query("race")=="人类" && who->query("age")<15)
		{
			command("grin "+who->query("id"));
			message_vision("$N恶狠狠地对$n叫道：大爷今天不高兴，先拿你的小命儿来祭祭刀！  $N看来想杀死$n！\n", me, who);
			kill_ob(who);
			return;
		}
		if (who->query("gender")=="女性" && who->query("age")<30  && random(3)==2)
		{
			command("flirt "+who->query("id"));
			message_vision("$N上前调戏$n，$n却奋力挣扎不从。$N勃然大怒，看来想杀死$n！\n", me, who);
			me->set_temp("rapping",1);
			kill_ob(who);
			return;
		}
		else if (who->query("gender")=="女性" && who->query("age")<30 )
		{
			switch (random(4))
			{
				case 0 :
					command("flirt "+who->query("id"));
					break;
				case 1 :
					command("flirt2 "+who->query("id"));
					break;
				case 2 :
					command("miss4 "+who->query("id"));
					break;
				case 3 :
					command("miss2 "+who->query("id"));
					break;
			}
			switch (random(4))
			{
				case 0 :
					message_vision("$N上前调戏$n，$n却对$N理都不理。\n", me, who);
					break;
				case 1 :
					message_vision("$N集力讨好$n，$n却对$N视而不见。\n", me, who);
					break;
				case 2 :
					message_vision("$N对$n百般殷勤，$n却对$N无动于衷。\n", me, who);
					break;
				case 3 :
					message_vision("$N对$n甜言蜜语，$n却对$N怒目相视。\n", me, who);
					break;
			}
			me->start_busy(20);
			remove_call_out("action_start");
			call_out("action_start", 5, me, who);
			return;
		}
		else if (who->query("race")!="人类")
		{
			command("grin "+who->query("id"));
			message_vision("$N乐道：“老子的肚子正咕咕叫呢，有野味送上门来。”  $N想把$n杀了吃掉。\n", me, who);
			kill_ob(who);
			return;
		}
		else if (random(3)==2)
		{
			message_vision("$N冷笑着地对$n说：“老子我亲自出马，"+RANK_D->query_rude(who)+"还不乖乖地赶快金银珠宝交出来？\n", me, who);
			message_vision("$n迟疑不给，$N便阴笑着吼道：“"+RANK_D->query_rude(who)+"找死，今天老子要杀个鸡犬不留！”  看来$N想杀死$n！\n", me, who);
			kill_ob(who);
			return;
		}
		else
		{
			switch (random(4))
			{
				case 0 :
					message_vision(CYN"$N笑嘻嘻的走向$n说：“"+RANK_D->query_self_rude(me)+"我今天回乡，缺少些盘缠"+RANK_D->query_close(who)+"，借点银两来花花吧？\n"NOR, me, who);
					break;
				case 1 :
					command("poor "+who->query("id"));
					break;
				case 2 :
					message_vision(CYN"$N横刀当道对着$n一声大喊：“此山是我开，此树是我栽，若要从此过，留下买路财 !\n"NOR, me, who);
					break;
				case 3 :
					command("interest "+who->query("id"));
					break;
			}
			switch (random(4))
			{
				case 0 :
					message_vision(CYN"$n抓起一把瓜子递给$N：很无聊吧？来，尝尝这瓜子，注意不要乱吐壳儿啊！\n"NOR, me, who);
					break;
				case 1 :
					message_vision(CYN"$n柳眉倒竖，叱道：“少打我的主意了,真是无聊透顶！我不会答应的,你就死了心吧！”\n"NOR, me, who);
					break;
				case 2 :
					message_vision("$n取出一个绣花荷包来，往桌上一掷，只听得嗒的一声轻响，显然荷包中没什么金银。\n", me, who);
					break;
				case 3 :
					message_vision(CYN"$n对$N说：“我不认识你，凭什么要给你！\n"NOR, me, who);
					break;
			}
			me->start_busy(20);
			remove_call_out("action_start");
			call_out("action_start", 5, me, who);
			return;
		}
	}
	return;
}

void action_start(object me, object who)
{
	if (me->query_temp("arrestee"))
	{
		remove_call_out("action_start");
		remove_call_out("action_end");
		remove_call_out("action_stop");
		return;
	}
	if (who->query("gender")=="女性" && who->query("age")<30)
	{
		switch (random(4))
		{
			case 0 :
				message_vision(CYN"$N缠着$n不放的说：“"+RANK_D->query_close(who)+"别这样嘛，来让我香一个。\n"NOR, me, who);
				break;
			case 1 :
				message_vision(CYN"$N开始对$n动手动脚的说：“"+RANK_D->query_close(who)+"跟着"+RANK_D->query_self_rude(me)+"回去吧。\n"NOR, me, who);
				break;
			case 2 :
				message_vision(CYN"$N粗声粗气的对$n说：“"+RANK_D->query_close(who)+"跟着"+RANK_D->query_self_rude(me)+"保证你享福一辈子。\n"NOR, me, who);
				break;
			case 3 :
				message_vision(CYN"$N开始对$n上下其手说：“"+RANK_D->query_close(who)+"长的真标致，看的我心里消魂。\n"NOR, me, who);
				break;
		}
		switch (random(4))
		{
			case 0 :
				message_vision(CYN"$n呸了一声，对$N怒道：“就你这癞蛤蟆，不知砸坏了多少面镜子了，也配和我提一个爱字！”\n"NOR, me, who);
				me->set_temp("rapping",1);
				break;
			case 1 :
				message_vision(CYN"$n对着$N嚷道：“你当你是谁呀，你以为你是小龙女呀？”\n"NOR, me, who);
				me->set_temp("rapping",1);
				break;
			case 2 :
				message_vision("$n跨上一步，左右开弓，便是四记耳光。啪啪啪啪四声响过，$N两边脸颊登时红肿。\n", me, who);
				me->set_temp("rapping",1);
				break;
			case 3 :
				message_vision(CYN"$n对$N说道：“你这个人怎么脸皮比城墙拐弯儿还厚！”\n"NOR, me, who);
				me->set_temp("rapping",1);
				break;
		}
	}
	else
	{
		switch (random(4))
		{
			case 0 :
				command("stare "+who->query("id"));
				break;
			case 1 :
				message_vision(CYN"$N对着$n怒道：“"+RANK_D->query_rude(who)+"！"+RANK_D->query_self_rude(me)+"给你三分颜色你就开起染房来了。\n"NOR, me, who);
				break;
			case 2 :
				message_vision(CYN"$N对$n喝道：「"+RANK_D->query_rude(who)+"，你还要不要命？，还不快把身上的金银珠宝交出来？」\n"NOR, me, who);
				break;
			case 3 :
				message_vision(CYN"$N惊怒交集，指着$n道：「你这"+RANK_D->query_rude(who)+"，当真活得不耐烦了？」\n"NOR, me, who);
				break;
		}
		switch (random(4))
		{
			case 0 :
				message_vision(CYN"$n仰天长叹道：「难道这个世道竟然没有王法，天理何在啊？！ 」\n"NOR, me, who);
				me->set_temp("robbing",1);
				break;
			case 1 :
				message_vision(CYN"$n对$N喝道：「"+RANK_D->query_rude(me)+"，你竟敢当街行抢，我要去官府告你！！！ 」\n"NOR, me, who);
				me->set_temp("robbing",1);
				break;
			case 2 :
				message_vision(CYN"$n对着$N大叫：“$N，你这个臭流氓！”\n"NOR, me, who);
				me->set_temp("robbing",1);
				break;
			case 3 :
				message_vision("$n对$N的恐吓完全置之不理。\n", me, who);
				me->set_temp("robbing",1);
				break;
		}
	}
	me->start_busy(30);
	kill_ob(who);
	remove_call_out("action_end");
	call_out("action_end", 5, me, who);
	return;
}
void action_end(object me, object who)
{
	if (me->query_temp("arrestee"))
	{
		remove_call_out("action_start");
		remove_call_out("action_end");
		remove_call_out("action_stop");
		return;
	}
	if (who->query("gender")=="女性" && who->query("age")<30)
	{
		switch (random(6))
		{
			case 0 :
				command("stare "+who->query("id"));
				break;
			case 1 :
				command("loveshoe "+who->query("id"));
				break;
			case 2 :
				command("smell2 "+who->query("id"));
				break;
			case 3 :
				command("smell "+who->query("id"));
				break;
			case 4 :
				command("mo97 "+who->query("id"));
				break;
			case 5 :
				command("doufu "+who->query("id"));
				break;
		}
		switch (random(4))
		{
			case 0 :
				message_vision(CYN"$n对着$N大骂：「不要脸，无耻下流，调戏妇女。」\n"NOR, me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);

				break;
			case 1 :
				message_vision("$n对$N视而不见。\n", me, who);
				remove_call_out("action_start");
				call_out("action_start", 5, me, who);
				break;
			case 2 :
				message_vision(CYN"$n对着$N说了句：无聊！\n"NOR, me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);
				break;
			case 3 :
				message_vision(CYN"$n骂道：你无不无聊啊！\n"NOR, me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);
				break;
		}
	}
	else
	{
		switch (random(8))
		{
			case 0 :
				message_vision("$N恶狠狠地盯着$n："+RANK_D->query_rude(who)+"，我看你这次往哪儿跑。\n", me, who);
				break;
			case 1 :
				message_vision("$N恶狠狠地盯着$n："+RANK_D->query_rude(who)+"，我看你这次往哪儿跑。\n", me, who);
				break;
			case 2 :
				message_vision(CYN"$N对$n喝道：「气死我了，我先杀了你这"+RANK_D->query_rude(who)+"再说。」\n"NOR, me, who);
				break;
			case 4 :
				message_vision(CYN"$N惊怒交集，指着$n道：「你这"+RANK_D->query_rude(who)+"，当真活得不耐烦了？」\n"NOR, me, who);
				break;
			case 5 :
				message_vision("$N鄙夷地看着$n，恨不得把他大卸八块生吞活剥。\n", me, who);
				break;
			case 6 :
				message_vision(CYN"$N一拍桌子，对着$n生气的叫道：「你耍俺？！你把俺当猴子耍？！」\n"NOR, me, who);
				break;
			case 7 :
				message_vision(CYN"$N对着$n骂道：「"+RANK_D->query_rude(who)+"，我不狠狠揍你一顿，难消心头之恨。」\n"NOR, me, who);
				break;
		}
		switch (random(4))
		{
			case 0 :
				message_vision(CYN"$n大叫：「救命啊！杀人啊！来人啊！」\n"NOR, me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);
				break;
			case 1 :
				message_vision("$n对$N爱理不理的。\n", me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);
				break;
			case 2 :
				message_vision(CYN"$n对$N说：「看！你后面有孔雀！」\n"NOR, me, who);
				remove_call_out("action_stop");
				call_out("action_stop", 1, me, who);
				break;
			case 3 :
				message_vision("$n并未在意$N的话！\n", me, who);
				remove_call_out("action_start");
				call_out("action_start", 5, me, who);
				break;
		}
	}
	return;
}
void action_stop(object me, object who)
{
	object room, room1;
	int room_no;

	if (me->query_temp("arrestee"))
	{
		remove_call_out("action_start");
		remove_call_out("action_end");
		remove_call_out("action_stop");
		return;
	}
	switch (random(3))
	{
		case 0 :
			message_vision("$N自讨没趣，灰溜溜的走了。\n", me, who);
			break;
		case 1 :
			message_vision("$N见$n毫无反应，自顾走了。\n", me, who);
			break;
		case 2 :
			message_vision("$N见$n态度强硬，只好作罢。\n", me, who);
			break;
	}
	me->delete_temp("robbing");
	me->delete_temp("rapping");
	me->remove_all_killer();
	who->remove_all_killer();
	me->start_busy(1);
	return;
}

int random_move()
{
	mapping exits, doors;
	string *dirs, dir;
	object me=this_object();

	if (is_fighting() || is_busy() || !living(me)) return 0;

	if (!me->query("steps"))
	{
		remove_call_out("destroying");
		call_out("destroying",1200,me);
	}
	if (me->query("steps")>=50)
	{
		remove_call_out("destroying");
		call_out("destroying",1,me);
		return 0;
	}
	me->add("steps",1);
	if (!objectp(environment()) || !mapp(exits = environment()->query("exits")) || query("jingli") < query("max_jingli") / 2 ) return 0;
	dirs = keys(exits);
	if (this_object()->query("race") == "人类" && mapp(doors = environment()->query_doors())) dirs += keys(doors);
	if (sizeof(dirs) == 0) return 0;
	dir = dirs[random(sizeof(dirs))];
	if (strsrch(environment(me)->query("exits/"+dir), "/d/dali/minov") == -1) return 0;
	if (mapp(doors) && !undefinedp(doors[dir]) && (doors[dir]["status"] & DOOR_CLOSED)) command("open " + dir);
	command("go " + dir);
	return 1;
}
void destroying(object me)
{
	switch (random(3))
	{
		case 0 :
			message_vision("$N悻悻地自言自语道：“今天真倒霉，出来一大圈什么也没弄到。”  说罢就急匆匆地走了。\n",me);
			break;
		case 1 :
			message_vision("$N不满意地地嚷嚷道：“他妈的，今天真不走运！这么一大趟居然什么也没弄到。”  说罢就急匆匆地走了。\n",me);
			break;
		case 2 :
			message_vision("$N不满意地地嘟囔道：“今天怎么什么也没有找到 ... ... 明天带些人手再来吧。”  说罢就急匆匆地走了。\n",me);
			break;
	}
	destruct(me);
	return;
}

void unconcious()
{
	object ob, me=this_object();

	if (objectp(ob = me->query_temp("last_damage_from")) && ob->query_temp("marks/arrestee") != me->query("name")) me->set("wrong_fainted", 1);
	::unconcious();
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob=me->query_temp("last_damage_from")) && me->query("combat_exp")>ob->query("combat_exp")*2) ob->add("dali/trust", 1);
	::die();
}
