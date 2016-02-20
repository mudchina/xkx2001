//Cracked by Roath
// linzhennan.c 林震南
// modified by Jay 4/7/96
// modified by sdong to add job, 12/15/98

#include <ansi.h>

inherit NPC;
inherit F_SKILL;

string *Robber_Name = ({
	"土匪","山大王","路霸","山贼","毛贼","寨主","帮匪"
	});
string *Biaohuo_Name = ({
	"珍珠","玛瑙","金子","钻石","象牙","玉器","古玩"
	});
int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();
string ask_biao();
string ask_job();
string ask_jiebiao();
string ask_abandon();
void assign_biaotou(object me, object partner);
void setup_skill(object me,object obj);
int do_jobwith(string arg);
private int is_suitable(object victim, object killer);
private int is_suitable_rob(object victim, object killer);
string QueryDest(object obj);
int assign_rob(object me);
void award2(object dest,object owner);
void award(object me, object ob, object obj);

void create()
{
	set_name("林震南", ({ "lin zhennan", "lin", "zhennan" }));
	set("gender", "男性");
	set("age", 45);
	set("long", "他就是「福威镖局」的总镖头－－林震南。\n");

	set("combat_exp", 500000);
	set("shen_type", 1);

	set("max_neili", 3000);
	set("neili", 3000);
	set("jiali", 100);

	set_skill("force", 140);
	set_skill("sword", 140);
	set_skill("unarmed", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("san-sword", 140);
	map_skill("sword", "san-sword");
	map_skill("parry", "san-sword");

	set("inquiry", ([
		"向阳老宅" : "林震南说道：那是我从前在福建时住的家院，已经破败了。\n",
		"福威镖局" : (: ask_fuwei :),
		"远图公" : (: ask_yuantu :),
		"林远图" : "林震南大怒：小孩子这么没礼貌，直呼先人名讳！\n",
		"辟邪剑法" : (: ask_pixie:),
		"铜钱" : (: ask_tong:),
		"铜板" : (: ask_tong:),
		"保镖" : (: ask_biao:),
		"走镖" : (: ask_biao:),
		"工作" : (: ask_job:),
		"job" : (: ask_job:),
		"jiebiao" : (: ask_jiebiao:),
		"劫镖" : (: ask_jiebiao:),
		"abandon" : (: ask_abandon:),
		"放弃" : (: ask_abandon:),
		]) );
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object ob;

	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);

	add_action("do_jobwith", "jobwith");

	if( interactive(ob = this_player()) && !is_fighting())
	{
		//remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	int bonus,old_pot;
	string *skname;
	mapping skills;
	int i;

	if( !ob || environment(ob) != environment() ) return;
	if (present("pixie jianpu",ob))
	{
		message_vision(HIY "$N鼻子一耸，闻到$n身上有发霉的树叶的气味，喝道：好啊，你竟敢私闯我的老宅！拿命来！\n"NOR, this_object(), ob );
		kill_ob(ob);
	}
	if( ob->query("biao/bonus") )
	{
		bonus = ob->query("biao/bonus");
		message_vision( HIG"$N对着$n笑道：$n干的好！咱们福威镖局全靠你这样的人才。\n\n"NOR,this_object(),ob);
		command( "thumb "+ob->query("id") );
		if( ob->query("family/family_name") == "丐帮" ) bonus = bonus - 150; // 丐帮 ppl can send letter to get extra bonus
		if( ob->query("family/family_name") == "华山派" ) bonus = bonus - 150; // 华山派 ppl can get extra bonus from xuanshan
		ob->delete("biao");
		ob->add("combat_exp", bonus );
		old_pot = ob->query("potential");
		if(bonus>360)bonus=360;
		ob->add("potential", bonus );
		ob->remove_all_killer();
		if(ob->query_condition("biaoju")) ob->clear_one_condition("biaoju");
		ob->add("biaoju/succeed",1);
		if( ob->query("potential") > ob->query("max_potential") ) ob->set("potential",ob->query("max_potential") );
		add_temp("biao", -1);
		log_file("/test/BiaoJob", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")在福威镖局保镖获得" + bonus + "经验和"+ (ob->query("potential")-old_pot) + "潜能\n" );
	}
	if( ob->query("master_name") == "镖师" || ob->query("master_name") == "趟子手")
	{
		command( "say 本镖局镖师不收徒弟，你得另拜名师！");
		message_vision("\n$N对着$n说道：从今天起，你得另拜名师！\n\n", this_object(), ob);
		ob->delete("family");
		ob->delete("title");
		ob->delete("master_id");
		ob->delete("master_name");
		ob->set("score", 0);
		skills = ob->query_skills();
		if( mapp(skills) )
		{
			skname = keys(skills);
			for(i=0; i<sizeof(skname); i++) skills[skname[i]] /= 2;
		}
	}
	ob->delete_skill("lingbo-weibu");
	ob->delete_skill("dulong-dafa");
}

int ask_fuwei()
{
	say("林震南炫耀地说：我们林家三代走镖，一来仗着先祖远图公当年闯下的威名，二\n"
		"来靠著我们林家家传的玩艺儿不算含糊，这才有今日的局面，成为大江以南首屈\n"
		"一指的大镖局。江湖上提到『福威镖局』四字，谁都要翘起大拇指，说一声：『\n"
		"好福气！好威风！』哈哈，哈哈！\n");
	this_player()->set_temp("marks/林1", 1);
	return 1;
}

int ask_yuantu()
{
	if ((int)this_player()->query_temp("marks/林1"))
	{
		say("林震南磕一磕烟斗，说道：远图公是我的祖父，福威镖局是他一手创办的。当年\n"
			"祖父以七十二路辟邪剑法开创镖局，当真是打遍黑道无敌手。其时白道上英雄见\n"
			"他太过威风，也有去找他比试武艺的，青城派掌门余观主的师父长青子少年之时\n"
			"便在他辟邪剑法下输了几招。\n");
		this_player()->set_temp("marks/林2", 1);
		return 1;
	}
	else
	{
	say("林震南说道：远图公是我的祖父。\n");
	return 1;
	}
}

int ask_pixie()
{
	int p1, p2, p3, p4;

	if ((int)this_player()->query("passwd"))
	{
		say("林震南不悦地说道：我不是都告诉你了吗？我的剑法不及先祖。\n");
	}
	else if ((int)this_player()->query_temp("marks/林2"))
	{
		say("林震南一惊，说道：你怎么知道的？噢，我刚才说露嘴了。嗨，在下的功夫外人\n"
			"不知底细，其实及不上先祖。。\n");
		write("林震南顿一顿，接着对你低声说：先祖去世前，曾给家父留下");
		p1=random(4)+1;
		p2=random(4)+1;
		p3=random(4)+1;
		p4=random(4)+1;
		this_player()->set("passwd",p1*1000+p2*100+p3*10+p4);
		write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
			"百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
		write("个\n铜钱，我一直未解其中奥秘。\n");
	}
	else
	{
		message("vision",HIY "林震南勃然大怒，喝道：你也窥视我们林家的辟邪剑谱？！我跟你拼了！\n"NOR, environment(), this_object() );
		kill_ob(this_player());
	}
	this_player()->delete_temp("marks/林1");
	this_player()->delete_temp("marks/林2");
	return 1;
}

int ask_tong()
{
	int p, p1, p2, p3, p4;

	if (!(p=(int)this_player()->query("passwd")))
	{
		say("林震南一脸讥笑的样子，说：怎么混到这一步了到处要钱？\n");
	}
	else
	{
		write("林震南低声说：先祖去世前，曾给家父留下");
		p1=(int)p/1000;
		p2=(int)(p-p1*1000)/100;
		p3=(int)(p-p1*1000-p2*100)/10;
		p4=(int)(p-p1*1000-p2*100-p3*10);
		write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
			"百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
		write("个\n铜钱，我一直未解其中奥秘。\n");
	}
	return 1;
}

int accept_object(object me, object obj)
{
	object ob = this_player();

	if ( (obj->name() == "镖货" ) && obj->query("id") == "biao huo" )
	{
		call_out("award", 1, this_object(), ob, obj );
		return 1;
	}
	command( "say 这东西我不感兴趣。" );
	return 0;
}

void award2(object dest,object owner)
{
	object wage;
	object here = environment(dest);

	if(userp(owner))
	{
		if (MONEY_D->player_job_pay(owner, dest, (10 + random(10)) * 10000))
		{
			message_vision(HIY"$N"+HIY"递给$n几锭黄金，说：“这是你的赏金，找个地方玩乐去吧！”\n"NOR,dest,owner);
			command("hehe");
		}
		owner->delete_temp("riding");
	}
}

void award(object me, object ob, object obj)
{
	int bonus,old_pot;

	if( !ob || environment(ob) != environment() ) return;

	message_vision( HIY"$N把镖货打开，发现是一堆"+Biaohuo_Name[random(7)]+"。\n"NOR,me);

	if( obj->query("owner") != ob->query("id") )
	{
		message_vision( HIY"$N奸笑道：哪儿拣来的？不过既然落到我手，可没有再还你的道理喔！\n"NOR,me);
		destruct(obj);
		return;
	}
	destruct(obj);
	command( "thumb "+ob->query("id") );
	message_vision( HIG"$N对着$n笑道：$n干的好！福威镖局就要你这样的人才。\n\n"NOR,me,ob);
	ob->delete_temp("apply/name");
	ob->delete_temp("apply/long");
	ob->delete_temp("apply/short");
	ob->delete_temp("apply/id");
	ob->add("biaoju/succeed",1);
	ob->remove_all_killer();
	call_out("award2",1,me,ob);
	bonus = 1800 + random(1200);
	ob->add("combat_exp", bonus );
	old_pot = ob->query("potential");
	ob->add("potential", bonus/2 );
	if( ob->query("potential") > ob->query("max_potential") ) ob->set("potential",ob->query("max_potential") );
	if(ob->query_condition("biaoju")) ob->clear_one_condition("biaoju");
	log_file("/test/BiaoJob", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")在福威镖局劫镖获得" + bonus + "经验和"+ (ob->query("potential")-old_pot) + "潜能\n" );
	ob->delete("biao");
	add_temp("biao", -1);
}

private int is_suitable(object victim, object killer)
{
	string *no_kill_list = ({
	"mu ren",
	"huang zhen",
	"juexin dashi",
	"fighter dummy",
	"du e",
	"du nan",
	"du jie",
	"xie yanke",
	"ren woxing",
	"qu san",
	"yue buqun",
	"qiu chuji",
	"zhang sanfeng",
	"zuo lengchan",
	"ouyang zhan",
	"seng bing",
	"ma guangzuo",
	"black gargoyle",
	"white gargoyle",
	"tang nan",
	"zhu xi",
	"tangzi shou",
	"lao chaofeng",
	"hua tiegan",
	"yideng dashi",
	"lu tianshu",
	"liu chengfeng",
	"qu san",
	"zhao zhijing",
	"lu youjiao",
	"cheng buyou",
	"lin zhennan",
	"hong qigong",
	"master",
	"xun bu",
	"dongfang bubai",
	"du laoban",
	"ling tuisi",
	"zhao liangdong",
	"guai she",
	});
	if(  !victim || !clonep(victim) || !living(victim) || userp(victim)
		|| victim->query("race") != "人类"
		|| victim->query("shen") < 0
		|| victim->query("winner")
		|| strsrch(base_name(victim), "/kunfu/skill/") != -1
		|| strsrch(base_name(victim), "/clone/") != -1
		|| strsrch(base_name(victim), "/u/") != -1
		|| strsrch(base_name(victim), "/d/xiakedao/") != -1
		|| victim->query("combat_exp") < killer->query("combat_exp") * 1/4
		|| victim->query("combat_exp") > killer->query("combat_exp")*7/4
		|| victim->query("family/family_name") == "桃花岛"
		|| member_array(victim->query("id"), no_kill_list) != -1 || random(2)==0 )
	{
		return 0;
	}
	return 1;
}

void do_leave(object ob)
{
	if( objectp(ob) )
	{
		if( ob->is_busy() || ob->is_fighting())
		{
			message_vision("$N向后一跳，跳出战圈！\n",ob);
			message_vision("$N说道：风紧，扯呼！俺回去报信求援，\n你们坚守就是胜利，千万不要堕了福威镖局的威名！\n",ob);
		}
		if(!living(ob))ob->revive(0);
		message_vision("$N急急忙忙离开了。\n",ob);
		destruct(ob);
	}
}

void setup_skill(object me,object obj)
{
	mapping skills;
	string *names;
	int level,i;

	if(!objectp(me) || !objectp(obj) ) return;
	if( obj->query("combat_exp") < me->query("combat_exp") )
	{
		obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(50) )  );
	}
	level = pow( obj->query("combat_exp")*10.,0.33333 );
	if(level < 10) level = 10;
	if( obj->query("combat_exp") < 4000 )
	{
		level = level/2 + random(level/2);
	}
	else if( obj->query("combat_exp") < 30000)
	{
		level = level/2 + random(level/3);
	}
	else if( obj->query("combat_exp") < 60000)
	{
		level = level/2 + random(level/4);
	}
	else if( obj->query("combat_exp") < 300000)
	{
		level = level/2 + random(level/5);
	}
	else level = level/3 + random(level/6);
	skills = obj->query_skills();
	names = keys(skills);
	for (i=0; i<sizeof(names); i++)
	{
		obj->set_skill(names[i], level);
	}
	obj->set( "title", "福威镖局" );
	obj->delete( "nickname");
	obj->delete( "long");
	obj->delete( "family");
	obj->delete( "name" );
	obj->delete( "short" );
	if( obj->query("combat_exp") < 500000 ) obj->set_name("趟子手", ({ "tangzi shou", "shou" }));
	else obj->set_name("镖师", ({ "biao shi", "biaoshi" }));
	call_out("do_leave",1000,obj);
}

void assign_biaotou(object me, object partner)
{
	object ob,here;
	object *target_list;
	int i;

	if( !userp(me) ) return;
	here = environment(me);
	if(!here) return;
	if( strsrch(base_name(here), "/d/") == -1 ) return;
	target_list = filter_array(livings(), "is_suitable", this_object(), me);
	if( sizeof(target_list) == 0 )
	{
		// try again in 5 secs.
		call_out("assign_biaotou", 5, me,partner);
		return;
	}
	do
	{
		i = random(sizeof(target_list));
		ob=new( base_name(target_list[i]) + ".c" );
	}
	while( !living(ob) );
	ob->move(here);
	setup_skill(me,ob);
	ob->set_temp("biao/owner",me->query("id") );
	if(partner)ob->set_temp("biao/owner2",partner->query("id") );
	ob->set_leader(me);
	message_vision("\n$N快步走了过来!\n", ob);
	message_vision("\n$N对$n抱拳道：“"+RANK_D->query_respect(me)+"，林总镖头派俺跟您一道保这道镖。\n俺没啥说的，从今以後，有难同担，有福同享，共保咱们福威镖局的金字招牌“\n\n", ob,me);
}

int do_jobwith(string arg)
{
	object biaoche, ob = this_player(), me = this_object(), partner,here=environment(me);
	float diff;
	int penalty;

	if(!arg) return notify_fail("你要和谁搭档？\n");
	partner = present(arg,here);
	if(!partner) return notify_fail("这人不在这里，怎么搭档？\n");
	if( !userp(partner) ) return notify_fail("这人不是真人，怎么搭档？\n");
	message_vision("$N向$n请示说：请问林总镖头，我可不可以和"+partner->query("name")+"搭裆走一回镖？\n",ob,me);
	if( partner == ob) return notify_fail("自己和自己搭档？\n");
	if ( ob->query("biao/fail") )
	{
		ob->delete("biao");
		penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
		ob->apply_condition( "biao", penalty );
		ob->add("biaoju/fail",1);
		return notify_fail("你这不中用的家伙，亏你还有脸回来见我要求走镖！\n");
	}
	if ( ob->query_condition("biao") )
	{
		return notify_fail("我这里倒有几桩差事，可是暂时信不过你去干！\n");
	}
	if( ob->query("shen") <0 || ob->query("xbiao/dest") )
	{
		return notify_fail(RANK_D->query_respect(ob)+"是黑道上的英雄，就算我信得过你，我客户也信不过你。\n");
	}
	if ( ob->query("biao") )
	{
		command( "angry" );
		return notify_fail("你还没完成任务，怎么便想讨多桩差事？\n");
	}
	if ( ob->query("combat_exp") < 10000 )
	{
		command( "hmm" );
		return notify_fail("你武功这麽差，怎么配在本镖局任事？\n");
	}
	if ( ob->query("combat_exp") > 28000000 )
	{
		command( "hmm" );
		return notify_fail("你武功这么高，还要两人才能保这份镖？\n");
	}
	if( random(12) == 0 && assign_rob(ob) > 0 )
	{
		command("say 你单独一个人去干好了，要小心行事，务必在限定的时间内完成任务！");
		return 1;
	}
	if( partner->query("shen") <0 || partner->query("xbiao/dest") )
	{
		return notify_fail(RANK_D->query_respect(partner)+"是黑道上的英雄，就算我信得过，我客户也信不过。\n");
	}
	if ( (int)partner->query("biao/fail") )
	{
		partner->delete("biao");
		penalty = ( 1 + partner->query("biaoju/fail") * 10 / ( 1+ partner->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
		partner->apply_condition( "biao", penalty );
		partner->add("biaoju/fail",1);
		return notify_fail("那不中用的家伙，亏还有脸回来见我要求走镖！\n");
	}
	if ( partner->query_condition("biao") )
	{
		return notify_fail("我这里倒有几桩差事，可是暂时信不过那家伙去干！\n");
	}
	if ( (int)partner->query("biao") )
	{
		command( "angry" );
		return notify_fail("那不中用的家伙，还没完成任务，怎么便想讨多桩差事？\n");
	}
	diff = (float)(partner->query("combat_exp") - ob->query("combat_exp"))*10/(float)(partner->query("combat_exp") + ob->query("combat_exp"))*2.0 ;
	if( diff > 2 || diff < -2) return notify_fail("你们武功差距太大，不宜搭档。\n");
	command( "say 好吧，你来得正是时候，我这儿正缺人用。");
	switch( random(5) )
	{
		case 0:
			ob->set("biao/dest", "dao baifeng");
			ob->set("biao/dest2", "/d/dali/yuxuguan");
			command("say 你把这份东西送到大理王妃刀白凤那儿，这份镖非同小可，一定要小心。");
			break;
		case 1:
			ob->set("biao/dest", "hu laoye");
			ob->set("biao/dest2", "/d/xingxiu/house");
			command("say 这是北疆小镇巴依托送的重镖，你得多加小心，丢了可赔不起！");
			break;
		case 2:
			ob->set("biao/dest", "ye erniang");
			ob->set("biao/dest2", "/d/xixia/dawu");
			command("say 这份重镖是送到西夏叶二娘的，你得亲自交给她。");
			break;
		case 3:
			ob->set("biao/dest", "feng yiming");
			ob->set("biao/dest2", "/d/foshan/yxhuiguan");
			command("say 这有份要送给佛山英雄会馆凤一鸣的镖货，你帮我走一趟吧。");
			break;
		case 4:
			ob->set("biao/dest", "wang tongzhi");
			ob->set("biao/dest2", "/d/quanzhou/yaopu");
			command("say 这是泉州济世堂老店所重托的红镖，非同小可。你千万不可大意，务必交到药铺掌柜王通治手里。");
			break;
	}
	message_vision( "$N高声叫道：来人呐！\n", me);
	if (ob->query("family/family_name") == "大理段家") ob->add("dali/trust", -1);
	ob->add("biao/times", 1);
	ob->apply_condition("biaoju",40);
	ob->set_temp("apply/short", ({HIR"福威镖局镖师  "NOR+ob->name()+"("+ob->query("id")+")"}));
	ob->delete_temp("riding");
	ob->remove_all_killer();
	if(partner)
	{
		if (partner->query("family/family_name") == "大理段家") partner->add("dali/trust", -1);
		partner->add("biao/times", 1);
		partner->set_temp("apply/short", ({HIR"福威镖局镖师  "NOR + partner->name()+"("+partner->query("id")+")"}));
		partner->delete_temp("riding");
		partner->set("biao/dest", ob->query("biao/dest") );
		partner->set("biao/dest2",ob->query("biao/dest2") );
		partner->apply_condition("biaoju",40);
		partner->remove_all_killer();
	}
	biaoche = new(__DIR__"obj/biaoche");
	biaoche->move("/d/city/biaoju");
	biaoche->set_owner(ob,partner);
	me->add_temp("biao", 1);
	assign_biaotou(ob,partner);
	command("say 镖车就在外面等着你们。你们要小心行事，所谓镖在人在，镖亡人亡，务必在限定的时间内完成任务！");
	return 1;
}

string ask_abandon()
{
	object ob = this_player(), me = this_object();
	int penalty;

	if( !ob->query("biao") ) return "你又没有任务，放弃什么？\n";
	command("angry");
	command("disapp "+ob->query("id") );
	ob->delete("biao");
	if(ob->query_condition("biaoju")) ob->clear_one_condition("biaoju");
	penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) );
	ob->apply_condition( "biao", penalty );
	ob->add("biaoju/fail",1);
	ob->delete_temp("apply/name");
	ob->delete_temp("apply/long");
	ob->delete_temp("apply/short");
	ob->delete_temp("apply/id");
	ob->remove_all_killer();
	return "你真是不中用，下回再要差事，我可要考虑考虑！\n";
}

string ask_job()
{
	object biaoche, ob = this_player(), me = this_object();
	int penalty;

	if ( ob->query("biao/fail") )
	{
		ob->delete("biao");
		penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
		ob->apply_condition( "biao", penalty );
		ob->add("biaoju/fail",1);
		return "你这不中用的家伙，亏你还有脸回来见我要求走镖！\n";
	}
	if ( ob->query_condition("biao") )
	{
		return "我这里倒有几桩差事，可是暂时信不过你去干！\n";
	}
	if ( (int)me->query_temp("biao") >= 1000 )
	{
		return "今天所有的镖都已送完了，你明天早点来吧。";
	}
	if( ob->query("shen") <0 || ob->query("xbiao/dest") )
	{
		return RANK_D->query_respect(ob)+"是黑道上的英雄，就算我信得过你，我客户也信不过你。\n";
	}
	if ( ob->query("biao") ) {
		command( "angry" );
		return "你还没完成任务，怎么便想讨多桩差事？\n";
	}
	if ( ob->query("combat_exp") < 10000 )
	{
		command( "hmm" );
		return "你武功这麽差，怎么配在本镖局任事？";
	}
	if( random(12) == 0 && assign_rob(ob) > 0 )
	{
		command("say 你单独一个人去干好了，要小心行事，务必在限定的时间内完成任务！");
		return "";
	}
	if ( ob->query("combat_exp") < 200000 )
	{
		command( "hmm" );
		return "你武功差了点，必须至少两人才能保这份镖。再去找一位搭档吧！";
	}
	command( "say 好吧，你来得正是时候，我这儿正缺人用。");
	switch( random(5) )
	{
		case 0:
			ob->set("biao/dest", "dao baifeng");
			ob->set("biao/dest2", "/d/dali/yuxuguan");
			command("say 你把这份东西送到大理王妃刀白凤那儿，这份镖非同小可，一定要小心。");
			break;
		case 1:
			ob->set("biao/dest", "hu laoye");
			ob->set("biao/dest2", "/d/xingxiu/house");
			command("say 这是北疆小镇巴依托送的重镖，你得多加小心，丢了可赔不起！");
			break;
		case 2:
			ob->set("biao/dest", "ye erniang");
			ob->set("biao/dest2", "/d/xixia/dawu");
			command("say 这份重镖是送到西夏叶二娘的，你得亲自交给她。");
			break;
		case 3:
			ob->set("biao/dest", "feng yiming");
			ob->set("biao/dest2", "/d/foshan/yxhuiguan");
			command("say 这有份要送给佛山英雄会馆凤一鸣的镖货，你帮我走一趟吧。");
			break;
		case 4:
			ob->set("biao/dest", "wang tongzhi");
			ob->set("biao/dest2", "/d/quanzhou/yaopu");
			command("say 这是泉州济世堂老店所重托的红镖，非同小可。你千万不可大意，务必交到药铺掌柜王通治手里。");
			break;
	}
	if (ob->query("family/family_name") == "大理段家") ob->add("dali/trust", -1);
	message_vision( "$N高声叫道：来人呐！\n", me);
	ob->apply_condition("biaoju",40);
	ob->add("biao/times", 1);
	ob->set_temp("apply/short", ({HIR"福威镖局镖头  "NOR+ob->name()+"("+ob->query("id")+")"}));
	ob->delete_temp("riding");
	ob->remove_all_killer();
	biaoche = new(__DIR__"obj/biaoche");
	biaoche->move("/d/city/biaoju");
	biaoche->set_owner(ob);
	me->add_temp("biao", 1);
	assign_biaotou(ob,ob);
	return "镖车就在外面等着你们。你们要小心行事，所谓镖在人在，镖亡人亡，务必在限定的时间内完成任务！";
}

private int is_suitable_rob(object victim, object killer)
{
	if(  !userp(victim)
		|| victim->query("race") != "人类"
		|| victim->query("shen") > 0
		|| victim->query("xbiao/dest2") == 0
		|| strsrch(base_name(victim), "/u/") != -1
		|| strsrch(base_name(victim), "/d/xiakedao/") != -1
		|| victim->query("combat_exp") < killer->query("combat_exp") * 4/5
		|| victim->query("combat_exp") > killer->query("combat_exp") * 5/4
		|| victim->query_condition("biaoju") < 25)
	{
		return 0;
	}
	return 1;
}

string QueryDest(object obj)
{
	if ( obj->query("xbiao/dest") == "dao baifeng" ) return "大理王妃刀白凤";
	else if ( obj->query("xbiao/dest") == "hu laoye" ) return "北疆小镇巴依";
	else if ( obj->query("xbiao/dest") == "ye erniang" ) return "西夏叶二娘";
	else if ( obj->query("xbiao/dest") == "feng yiming" ) return "佛山英雄会馆凤一鸣";
	else if ( obj->query("xbiao/dest") == "wang tongzhi" ) return "泉州济世堂老店";
	return "神秘地带";
}

string ask_jiebiao()
{
	object biaoche, ob = this_player(), me = this_object();
	int penalty;
	if ( ob->query("biao/fail") )
	{
		ob->delete("biao");
		penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
		ob->apply_condition( "biao", penalty );
		ob->add("biaoju/fail",1);
		return "你这不中用的家伙，亏你还有脸回来见我！\n";
	}
	if ( ob->query_condition("biao") )
	{
		return "我这里倒有几桩差事，可是暂时信不过你去干！\n";
	}
	if( ob->query("shen") <0 )
	{
		return RANK_D->query_respect(ob)+"是黑道上的英雄，就算我信得过你，我客户也信不过你。\n";
	}
	if ( ob->query("biao") )
	{
		command( "angry" );
		return "你还没完成任务，怎么便想讨多桩差事？\n";
	}
	if ( ob->query("combat_exp") < 100000 )
	{
		command( "hmm" );
		return "你武功这麽差，怎么配在本镖局任事？";
	}
	if( assign_rob(ob) > 0 ) return "你要小心行事，务必在限定的时间内完成任务！";
	return "你来的不巧，现在没有这项任务让你去做！";
}

int assign_rob(object me)
{
	object ob,here;
	object *target_list;
	int i;
	string rename;

	if( !userp(me) ) return;
	here = environment(me);
	if(!here) return;
	if( strsrch(base_name(here), "/d/") == -1 ) return;
	target_list = filter_array( users(), "is_suitable_rob", this_object(), me);
	if( sizeof(target_list) == 0 )
	{
		return -1;
	}
	do
	{
		i = random(sizeof(target_list));
		ob= target_list[i];
	}
	while( !userp(ob) );
	rename = Robber_Name[random(7)];
	command( "say 好吧，你来得正是时候，我这儿正缺人用。");
	message_vision( "$N说道：兰州神鹰镖局一直和本镖局作对，近来更是多次派人来劫镖，是可忍，孰不可忍！\n",this_object());
	message_vision( "$N接着说道：听说他们正将劫来的重镖由"+ob->query("name")+"运往"+ QueryDest(ob) +"，不如你扮成"+rename+"去抢回来！\n",this_object());
	me->delete_temp("riding");
	me->set_temp("apply/short", ({rename+"(robber)"}));
	me->set_temp("apply/name", ({rename}) );
	me->set_temp("apply/long",  ({"一个黑布蒙面，神秘兮兮的家伙。\n"}));
	me->set_temp("apply/id", ({"robber","zei"}) );
	me->remove_all_killer();
	me->set("biao/owner",ob->query("id"));
	me->set("biao/dest",ob->query("xbiao/dest"));
	me->apply_condition("biaoju",50);
	return 1;
}

string ask_biao()
{
	object biao, ob = this_player(), me = this_object();

	if ( (int)ob->query_temp("biao/fail") )
	{
		return "你这不中用的家伙，亏你还有脸回来见我要求走镖！";
	}
	if ( (int)ob->query_temp("biao/times") >= 5 )
	{
		return "你已干了好多活儿，还是休息一下吧。";
	}
	if ( (int)me->query_temp("biao") >= 20 )
	{
		return "今天所有的镖都已送完了，你明天早点来吧。";
	}
	if ( ob->query_temp("biao/zhu")
		|| ob->query_temp("biao/bayi")
		|| ob->query_temp("biao/ma")
		|| ob->query_temp("biao/li")
		|| ob->query_temp("biao/jiang") )
	{
		command( "angry" );
		return "你还没将东西送到雇主手上，怎么便想讨多桩差事？";
	}
	command( "say 好吧，你来得正是时候，我这儿正缺人用。");
	switch( random(5) )
	{
		case 0:
			ob->set_temp("biao/zhu", 1);
			command("say 你把这份东西送到白鹿书院朱熹先生那儿，他便会付钱给你。");
			break;
		case 1:
			ob->set_temp("biao/bayi", 1);
			command("say 这是北疆小镇巴依托送的重镖，你得多加小心，丢了可赔不起！");
			break;
		case 2:
			ob->set_temp("biao/ma", 1);
			command("say 这份重镖是送到泉州扬威武馆的，你得亲自交给馆主马五德老师。");
			break;
		case 3:
			ob->set_temp("biao/li", 1);
			command("say 这有份要送给华山脚下玉泉院李铁嘴的镖货，你帮我走一趟吧。");
			break;
		case 4:
			ob->set_temp("biao/jiang", 1);
			command("say 这是当今武林盟主所重托的红镖，非同小可。你千万不可大意，务必交到亲兵队长江百胜手里。");
			break;
	}
	message_vision( "林震南交给$N一份镖货。\n", ob );
	ob->add_temp("biao/times", 1);
	ob->set_temp("apply/short", ({"镖客  "+ob->name()+"("+ob->query("id")+")"}));
	biao = new(__DIR__"obj/biaohuo");
	biao->move(ob);
	me->add_temp("biao", 1);
	return "你要小心行事，所谓镖在人在，镖亡人亡，务必在限定的时间内完成任务！";
}