//Cracked by Roath
// shenu.c 蛇奴
// maco

/***************************************************************

breed		: 现在可学poison的极限
new_breed	: 最新一次培养怪蛇成功後，可学poison的极限
new_breed_time	: 最新一次开始培养怪蛇的时间
checked_snake	: 是否检查过这次的怪蛇？

***************************************************************/
#include <ansi.h>

inherit NPC;

int ask_snake();
int ask_guaishe();
int do_order(string);

void create()
{
	set_name("蛇奴", ({ "she nu" ,"nu"}));
	set("long", "他是负责看管白驼山庄蛇场的蛇奴，担当替庄主、少主养育怪蛇的事务。\n");
	set("gender", "男性");
	set("title", "白驼山庄");
	set("age", 35);

	set_skill("hand", 30);
	set_skill("shexing-diaoshou", 30);
	set_skill("dodge", 20);
	set_skill("parry", 30);
	set_skill("force", 20);
	map_skill("hand","shexing-diaoshou");
	map_skill("dodge","chanchubu");
	prepare_skill("hand","shexing-diaoshou");

	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("max_neili", 200);
	set("jiali", 10);
	set("combat_exp", 10000);

	set("attitude", "peaceful");
	set("shen_type", -1);
	set("inquiry", ([
		"蛇" : (: ask_snake :),
		"snake" : (: ask_snake :),		
		"怪蛇" : (: ask_guaishe :),
		"guaishe" : (: ask_guaishe :),
	]));

	setup();
	carry_object("/d/xingxiu/obj/wcloth")->wear();
}

void init()
{
	::init();
	add_action("do_order", "order");
}

int ask_snake()
{
	object me, snake;
	int time, poison, breed, new_breed;

	me = this_player();

	poison = (int)me->query_skill("poison",1);
	breed = me->query("baituo/breed");
	new_breed = me->query("baituo/new_breed");

	if( me->query("family/family_name") != "白驼山" ) {
		command("say "+RANK_D->query_rude(me)+"想打听咱们的蛇儿，莫非动着什麽歪脑筋？");
		return 1;
	}

	if (me->query("family/master_name") != "欧阳锋") {
		command("say 场子里的蛇都是庄主和少主所饲养的。");
		return 1;
	}

	if( !me->query("baituo/new_breed_time") && !me->query("baituo/checked_snake")) {
		command("say 场子里没有少主养的蛇，您是也想养些麽？");
		return 1;
	}

	if( me->query("baituo/checked_snake") ) {
		command("say 少主上次培育的蛇种已有结果，是否要再捉新的品种来改良？");
		return 1;
	}

	time = time() - me->query("baituo/new_breed_time");

	if(time < 600) {
		command("say 少主前次捉回来的蛇群，小的日日夜夜都用心看顾，就等它们繁殖了。");
		return 1;
	}

	if(time < 1200) {
		command("say 少主前次捉回来的蛇已经下蛋了，想必近日便会孵化。");
		return 1;
	}

	command("say 小蛇已经出生了，小的这就去把它带来。");
	message_vision("\n蛇奴匆匆忙忙地退了下去。\n", me);
	
	this_object()->move("/d/baituo/temproom");

        remove_call_out("bring_snake");
        call_out("bring_snake", 3, me);
        return 1;
}

void bring_snake(object me)
{
	object snake;
	int poison, breed, new_breed;
	string result;

	poison = (int)me->query_skill("poison",1);
	breed = me->query("baituo/breed");
	new_breed = me->query("baituo/new_breed");

	if( new_breed > poison+10 )  new_breed = poison + 10; 
	if( new_breed > 400 ) new_breed = 400;

	this_object()->move("/d/baituo/shechang");

	snake = new("/d/baituo/npc/new_snake");

	if( new_breed > poison ) {
		snake->set_name("小怪蛇", ({ "guai she", "she", "snake" }) );
		snake->set_color("$HIW$");
		snake->set("long", 
		"一条银鳞闪闪的小蛇，形状怪异，是白驼山少主"+me->name()+"第"
		+chinese_number(me->query("baituo/manage"))+"次培养出的蛇种。\n"
		);
		if( breed >= 400 )
		result = HIW"这条怪蛇的毒性猛恶一如以往，可见你对蛇毒的掌握，已然纯熟如意。\n"NOR;
		else if( new_breed > breed ) 
		result = HIY"你成功地培养出了毒性更胜原种的怪蛇！\n"NOR
		+ "如今，你对掌握毒物的法门领会更多，自信已有能力将毒技钻研至"+chinese_number(new_breed)+"级。\n";
		else result = "虽然你培养出了怪蛇，但是神态不如以前的品种狰狞，想必毒性有所不及。\n";
	}
	else if( new_breed >= 240 ) {
		snake->set_name("小怪蛇", ({ "guai she", "she", "snake" }) );
		snake->set_color("$HIW$");
		snake->set("long", 
		"一条银鳞闪闪的小蛇，形状怪异，是白驼山少主"+me->name()+"第"
		+chinese_number(me->query("baituo/manage"))+"次培养出的蛇种。\n"
		);
		result = "虽然你培养出了怪蛇，但是以你的使毒本领而言，这等毒性的怪蛇称不上突破，仅是增生怪蛇数量而已。\n";
	}
	else {
		snake->set_name("小毒蛇", ({ "snake", "she"}) );
		snake->set("long", 
		"一条三角尖头的小蛇，是白驼山少主"+me->name()+"第"
		+chinese_number(me->query("baituo/manage"))+"次培养出的蛇种。\n"
		);
		if( !breed || breed == 0 )
		result = "这条毒蛇并无特异之处，看来这次培养的蛇种不甚成功。\n";
		else if( new_breed > breed ) 
		result = "你仔细检视，觉得这条蛇的毒性虽然胜过上回培养的品种，然而依旧不够理想。\n";
		else result = "你仔细端详，却见这条毒蛇毫无特异之处，看来毒性反而比从前弱了。\n";
	}

	message_vision("\n过了一会儿，蛇奴走了出来。\n", me);
	command("say 这是最近养育的小蛇中毒性最强的一，请少主过目。");
	message_vision("一条"+snake->name()+"蜿蜒地游了过来。\n", me);

	snake->move(environment(me));
	snake->set_leader(me);
	snake->set("who_breed", me->query("id"));
	snake->set("snake_poison", new_breed);

	write(result);

	log_file("test/breed_snake",
		sprintf("%s(%s) 第%d次培养结果：%s(毒性%d) on %s \n", 
		me->name(), me->query("id"), me->query("baituo/manage"), snake->name(), new_breed, ctime(time())));

	if(new_breed > breed) {
		me->set("baituo/breed", new_breed);
		me->add("baituo/success_breed", 1);
		if( me->query_skill("training") < 400 )
			me->improve_skill("training", new_breed*10 );
		if( me->query_skill("poison") < 400 )
			me->improve_skill("poison", new_breed*10 );
	}
	me->set("baituo/checked_snake", 1);
	me->delete("baituo/new_breed");
	me->delete("baituo/new_breed_time");

	return;
}

int ask_guaishe()
{
	object me;
	int num;
	me = this_player();
	num = me->query("baituo/snake_amount");

	if( me->query("family/family_name") != "白驼山" ) {
		command("say "+RANK_D->query_rude(me)+"想打听咱们白驼山的怪蛇，莫非动着什麽歪脑筋？");
		return 1;
	}

	if( me->query("family/master_name") != "欧阳锋" ) {
		command("say 庄主和少主费尽心思，以数种最毒之蛇相互杂交，才产下这些毒中之毒的怪蛇。");
		return 1;
	}
	if ( num < 1)
		command("say 现下场子里没有少主养的怪蛇。");
	else command("say 少主养在场子里的怪蛇，一共有"+chinese_number(num)+"条。");

	if ( num > 10 )
	command("admire "+me->query("id"));
	return 1;
}

int do_order(string arg)
{
	object me, room;
	int flag;
	me = this_player();
	
	if( me->query("family/family_name") != "白驼山" ) return 0;

	room = load_object("/d/baituo/shegu1");

	if( room->query("defense") ) flag = 1;
	
	if ( arg == "defense") {

		if( flag ) return notify_fail("蛇谷入口已经由毒气封住了。\n");

		if( me->query("family/master_name") != "欧阳锋" ) {
			message_vision(CYN"$N向蛇奴下令：放出密窖中的蛇毒，封住蛇谷的入口！\n"NOR, me);
			command("bored "+me->query("id"));
			command("say 哼，要不要封谷，你我都做不了主！");
			return 1;
		}

		message_vision(CYN"$N向蛇奴下令：放出密窖中的蛇毒，封住蛇谷的入口！\n"NOR, me);
		message_vision("蛇奴恭恭敬敬地答应，退到蛇场一角，启动了释放密窖毒气的机关。\n", me);
		message_vision(HIR"\n你听到蛇场外传来一阵嘶嘶轻响……\n"NOR, me);
		
		message("vision", HIR"你突然听到一阵嘶嘶轻响，一片血红色的雾气缓缓从土地下喷出，渐渐布满了整个谷口……\n\n"NOR,room );
		room->set("defense", 1);
		command("say 少主，办妥了！");
	}

	else if( arg == "remove" ) {
		if( !flag ) return notify_fail("蛇谷入口现在本就没有毒气。\n");


		if( me->query("family/master_name") != "欧阳锋" ) {
			message_vision(CYN"$N向蛇奴下令：停止从密窖释放毒气，开放蛇谷的入口！\n"NOR, me);
			command("kick "+me->query("id"));
			command("say 你想害死我不成？没有庄主下令，谁敢擅开蛇谷？");
			return 1;
		}
		message_vision(CYN"$N向蛇奴下令：停止从密窖释放毒气，开放蛇谷的入口！\n"NOR, me);
		message_vision(CYN"$N嘿嘿冷笑，说道："+RANK_D->query_self_rude(me)+"要让那些自居名门正派的人物，送上谷来给咱们蛇儿果腹！\n"NOR, me);

		command("fear "+me->query("id"));
		message_vision("蛇奴面有难色，但是被$N斜眼一瞪，还是战战兢兢地退开，解除了机关。\n", me);
		message_vision(WHT"\n你听到蛇场外传来一阵嘶嘶轻响，接着很快又安静下来。\n"NOR, me);
		message("vision", WHT"你突然听到一阵嘶嘶轻响，封锁在蛇谷前的红雾慢慢消散，土里也没有雾气再冒出来。\n不一会儿，烟消云散，蛇谷的入口完全呈现在眼前。\n\n"NOR,room );
		room->delete("defense");

		command("say 少主，小的依您吩咐，关了毒气，但庄主要问起来，您可得担待住……");
	}

	else return notify_fail("你要对蛇奴下什麽命令？ (defense or remove) \n");

	return 1;
}
