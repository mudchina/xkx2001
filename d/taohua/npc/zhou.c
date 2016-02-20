// zhou.c 周伯通

#include <ansi.h>

inherit NPC;
int ask_jieyi();
int ask_jiuyin();
int ask_hubo();
int do_fangyuan();
int do_learn(string arg);
void create()
{
	set_name("周伯通", ({ "zhou botong", "zhou", "botong" }) );
	set("nickname",	"老顽童");
	set("title","全真教第一代弟子");
	set("long", 
		"他满头长发，直垂至地，长眉长须，鼻子嘴巴都被遮掩住了。\n"
		"他须发苍然，并未全白，只是不知有多少年不剃，就如野人一般毛茸茸地甚是吓人。\n"
		"他的举止犹如孩童一样。\n");
	set("gender", "男性" );
        set("age", 45);
	set("str",28);
	set("int",25);
	set("con",27);
	set("dex",29);
        set("combat_exp", 3600000);

        set("max_neili", 8000);
        set("neili", 8000);
        set("jiali", 0);

        set_skill("taoism", 400);
        set_skill("force", 350);
        set_skill("cuff", 350);
        set_skill("dodge", 350);
        set_skill("jinyangong", 350);
        set_skill("parry", 350);
        set_skill("kongming-quan",350);
	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
        map_skill("cuff","kongming-quan");
        map_skill("parry","kongming-quan");
	prepare_skill("cuff","kongming-quan");

        set("inquiry", ([
		"name": "叫我周伯通就好了。",
		"rumors": "我被那个臭东邪关在这里十几年，每天就是一个哑仆来送饭。",
		"here": "这里是桃花岛。",
		"东邪": "是黄药师这个无耻的家伙，骗了我的九....去看。",
		"黄药师": "这个无耻的家伙，骗了我的九....去看。",
		"中神通": "我的师兄是天下武功最高的，第一次华山论剑时公推为第一高手。",
		"王重阳": "我的师兄是天下武功最高的，第一次华山论剑时公推为第一高手。",
		"周伯通": "找我有什么事吗？",
		"瑛姑": "四张机，鸳鸯织就欲双飞....",
		"刘瑛": "四张机，鸳鸯织就欲双飞....",
		"段皇爷": "老顽童做事对不起他，没脸再见他了。",
		"段智兴": "老顽童做事对不起他，没脸再见他了。",
		"南帝": "老顽童做事对不起他，没脸再见他了。",
		"老顽童": "我就是啊，找我有什么事吗？",
		"空明拳": "空明拳共七十二路，口诀是：空朦洞松、风通容梦、冲穷中弄、童庸弓虫。",
		"kongming-quan": "空明拳共七十二路，口诀是：空朦洞松、风通容梦、冲穷中弄、童庸弓虫。",
		"黄蓉": "是几个月前来陪我聊天的那个小姑娘吗？",
		"郭靖": "那是我的结义兄弟，人虽然傻，心肠倒好。",
		"桃花岛": "这里就是桃花岛。",
		"方": "方要正方！",
		"fang": "方要正方！",
		"圆": "圆要浑圆！",
		"yuan": "圆要浑圆！",
		"九阴真经": (: ask_jiuyin :),
		"双手互搏": (: ask_hubo :),
		"左右互搏": (: ask_hubo :),
		"hubo": (: ask_hubo :),
		"结义": (: ask_jieyi :),
		"结拜": (: ask_jieyi :),
        ]) );
        set("double_attack", 1);
	set("rank_info/respect", "老顽童");
	create_family("全真教", 1, "弟子");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob = this_player();

	add_action("do_fangyuan","fangyuan");
	add_action("do_draw","draw");
	add_action("do_draw","hua");
	add_action("do_learn","learn");
	add_action("do_learn","xue");
	::init();
	if (ob->query("family/family_name") == "全真教") {
		command("angry " + ob->query("id"));
		command("say 怎么你到今天才来找我？！明天我就去和处机说让他打你屁股。");
	}
}

void kill_ob(object me)
{
	command("chat* crazy " + me->query("id"));
	::kill_ob(me);
}

void unconcious()
{
	command("chat* 叹道：老顽童今日是要归天了，到阴世玩玩两只鬼打架，那些大头鬼、无常鬼一定瞧得莫名其妙，鬼色大变。");
	::unconcious();
}

int ask_jieyi()
{
	object ob=this_player();

	if (ob->query("zhou/jieyi")) {
		command("? " + ob->query("id"));
		command("say 咱俩不是结拜过了吗？");
		return 1;
	}
        if (ob->query("gender") != "男性")
        {
		command("en " + ob->query("id"));
		command("say 我生平不喜同两种人打交道：一是女人，二是太监。我看你还是趁早请罢！？");
                return 1;
        }
	if (ob->query("int") > 25) {
		command("shake");
		command("say 你这个人鬼灵精，保不准打着什么主意呢。");
		return 1;
	}
	if ((int)ob->query("shen") <= -1000) {
		command("shake");
		command("say 我虽然天性随便，但师尊教诲不敢忘，于正邪之道还是要分清的。");
		return 1;
	}
	command("nod " + ob->query("id"));
	if (ob->query("gender") == "男性") {
		command("say 好吧，你我就结拜为兄弟吧。");
	}
	message_vision("周伯通与$N并肩而跪，朗声说道：“老顽童周伯通，今日与" + ob->name() +"义结金兰，日后有福共享，有难共当。若是违此盟誓，教我武功全失，连小狗小猫也打不过。”\n", ob);
	ob->set("zhou/jieyi", 1);
	return 1;
}

int ask_jiuyin()
{
	object ob=this_player();

	if (ob->query_temp("get_jiuyin") == 2) {
		command("? " + ob->query("id"));
		command("say 不是已经给你了吗？");
		return 1;
	}
	if (ob->query("zhou/jieyi")) {
		if (query_temp("jiuyin_send")) {
 			command("say 唉，你来迟了，那《九阴真经》我已经拿去害人了。");
			return 1;
		}
		command("say 那《九阴真经》的上卷经文，放在我身下土中的石匣之内，本该给了你，不过....");
		ob->set_temp("get_jiuyin", 1);
		return 1;
	}
	command("say 你打听这个干什么？！");
	return 1;
}

int ask_hubo()
{
	object ob=this_player();
	int hubo;

	if (ob->query("double_attack")) {
		command("? " + ob->query("id"));
		command("say 你不是已经学会了吗？");
		return 1;
	}
	hubo = ob->query_temp("zuoyou_hubo");
	if (hubo == 22) {
		command("say 接着练第一课！");
		return 1;
	}
	if (hubo == 1) {
		command("say 让你练你就快练嘛！");
		return 1;
	}
	if (hubo > 1 && hubo <= 21) {
		command("say 怎么样，练不会吧？就象黄蓉那女孩儿玲珑剔透，一颗心儿上生了十七八个窍，可是这门功夫她便始终学不会！");
		return 1;
	}
	if (ob->query_skill("force") < 100 || ob->query("max_neili") < 500 || ob->query("combat_exp") < 10000) {
		command("say 你还是先打好武学基础再说吧。");
		return 1;
	}
	command("say 这门功夫是我在洞中无聊之时想出来的玩意儿，说难是难到极处，说容易也容易之至。有的人一学便会，有的人一辈子也学不了，越是聪明，越是不成。");
	command("say 你先练练这第一课：左手画方(fang)，右手画圆(yuan)。");
	ob->set_temp("zuoyou_hubo", 1);
	return 1;
}

int do_fangyuan()
{
	object ob=this_player();
	int hubo;

	if (ob->is_busy() || ob->is_fighting())	return notify_fail("你正忙着呢！\n");
	hubo = ob->query_temp("zuoyou_hubo");
	if (!hubo) return 0;
	if (hubo < 21) {
		message_vision("$N伸出两根食指在地上划画，但画出来的方块有点象圆圈，圆圈又有点象方块。\n", ob);
		ob->add_temp("zuoyou_hubo", 1);
		return 1;
	}
	if (hubo == 21) {
		message_vision("$N伸出两根食指在地上划画，但画出来的方块有点象圆圈，圆圈又有点象方块。\n", ob);
		command("haha " + ob->query("id"));
		command("say 是么？你这一下便办不到！");
		ob->add_temp("zuoyou_hubo", 1);
		return 1;
	}
	if (hubo == 22) {
        if (ob->query("kar") > 26 && ob->query("int") < 16 || ob->query_skill("yunu-jue",1) > 200 && ob->query("gender") == "女性") {
			message_vision("$N微微一笑，凝神守一，心地空明，随随便便的伸出双手手指，左手画了一个方块，右手画了一个圆圈，方者正方，圆者浑圆。\n", ob);
			say("周伯通大吃一惊，过了半晌才道：“这定是你从娘胎里学来的本领，那便易办了。”\n");
			message_vision("周伯通将他领悟出来的这门天下无比的奇功，一古脑儿都教给了$N。\n", ob);
			ob->delete_temp("zuoyou_hubo");
			ob->set("double_attack", 1);
			if (ob->query_skill("force") < 100 || ob->query("max_neili") < 500)
				message_vision("可惜$N因为内功修为有限，终于还是没能理解。\n", ob);
			else
//			ob->set("double_attack", 1);
			return 1;
		}
		message_vision("$N又伸出两根食指在地上划画，但画出来的仍旧是方块有点象圆圈，圆圈又有点象方块。\n", ob);
		message_vision("$N终于发现自己是一辈子也练不会这门功夫了。\n", ob);
		ob->delete_temp("zuoyou_hubo");
		command("disapp " + ob->query("id"));
		return 1;
	}
	return 0;
}

int do_draw(string arg)
{
	object ob=this_player();

	if (!ob->query_temp("zuoyou_hubo")) return 0;
	if (arg == "fang" || arg == "方" || arg == "yuan" || arg == "圆") return notify_fail("周伯通怒道：让你同时画方圆！\n");
	if (arg == "fang yuan" || arg == "方圆") return do_fangyuan();
	return 0;
}
/*
int accept_object(object who, object ob)
{
	if (ob->id("jiuyin xiajuan") && ob->query("material") == "leather") 
	{
		if (who->query_temp("get_jiuyin") == 1) {
			tell_object(who, "周伯通忽然想到了一个顽皮点子，说道：“你我既然结义，我就把我在洞中这十五年悟出的其它一些功夫也教给你吧。”\n");
			new_ob("../obj/jiuyin1.c")->move(who);
			tell_object(who, "周伯通给你一本《九阴真经》上卷。\n");
			tell_object(who, "周伯通把《九阴真经》下卷还给了你。\n");
			command("hehe " + who->query("id"));
			who->set_temp("get_jiuyin", 2);
			set_temp("jiuyin_send", 1);
			return notify_fail("");
		}
		else {
			command("? " + who->query("id"));
			command("say 给我这个做什么？\n");
			return notify_fail("");
		}
	}
	return 0;
}
*/
int do_learn(string arg)
{
	object me=this_player();
	string skill, teacher, skill_name;
	object ob;
	int master_skill, my_skill, gin_cost, rand;

        if (me->is_busy())
                return 0;

	if(!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
		return 0;

	if (teacher != "zhou" && teacher != "botong")
		return 0;

	if( me->is_fighting() )
		return 0;

	if( !(ob = present(teacher, environment(me))) || !ob->is_character()) {
		write("你要向谁求教？\n");
		return 1;
	}

	if( !living(ob) ) {
		write("嗯....你得先把" + ob->name() + "弄醒再说。\n");
		return 1;
	}

	if( !me->query("zhou/jieyi")) {
		write("周伯通奇怪地看着你，问道：你是谁呀？\n");
		return	1;
	}

	if (skill != "kongming-quan" && skill != "空明拳") {
		write("这项技能你恐怕必须找别人学了。\n");
		return 1;
	}

	my_skill = me->query_skill(skill, 1);
	master_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill ) {
		write("你在空明拳上的造诣已经不下老顽童了！\n");
		return 1;
	}

	if( !SKILL_D(skill)->valid_learn(me) ) {
		write("你必须是空手并且有足够的内功和内力才可以学习空明拳。\n");
		return 1;
	}

	gin_cost = 150 / (int)me->query("int");

	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill(skill,0);
	}

	rand = random(20);
	if (rand == 4)
		gin_cost *= 2;
	else if (rand == 15)
		gin_cost += 4;

	if( (int)me->query("learned_points") >= (int)me->query("potential") ){
		write("你的潜能已经发挥到极限了，没有办法再学了。\n");
		return 1;
	}

	message_vision("$N向$n请教有关「空明拳」的问题。\n", me, ob);

	if( (int)me->query("jing") > gin_cost ) {
        write("周伯通念道：老子《道德经》里有句话道：“埏植以为器，当其无，有器之用。凿户牖以为室，当其无，有室之用。”\n");
		write("周伯通吟口诀道：大成若缺，其用不弊，大盈若冲，其用不穷。\n");
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			write("也许是缺乏实战经验，你对老顽童的讲解总是无法领会。\n");
		} 
		else {
			if (rand == 13) {
				write("就在你试图领悟其中道理的时候，老顽童忽然在你旁边大做鬼脸，又故意放了个屁来捣乱，搞得你心烦意乱。\n");
				write("结果你什么都没学到。\n");
				return 1;
			}
			else if (rand == 5) {
				write("周伯通讲解了两句，忽然不耐烦起来，拉着你道：“咱俩玩四个人打架可好？”\n");
				write("结果你只好陪他玩耍了一阵。\n");
				return 1;
			}
			else if (rand == 4) {
				write("就在你试图领悟其中道理的时候，老顽童忽然在你旁边大做鬼脸，又故意放了个屁来捣乱，搞得你心烦意乱。\n");
				write("结果你花了比平常多一倍的精力。\n");
			}
			else if (rand == 15) {
				write("就在你试图领悟其中道理的时候，老顽童忽然在你旁边大做鬼脸，又故意放了个屁来捣乱，搞得你心烦意乱。\n");
				write("结果你花了比平常多得多的精力。\n");
			}
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				write("你听了老顽童的指导，对「" + skill_name + "」这一招似乎有些心得。\n");
			else
				write("你听了老顽童的指导，似乎有些心得。\n");
			me->add("learned_points", 1);
			me->improve_skill(skill, random(me->query_int()));
		}
	} 
	else {
		gin_cost = me->query("jing");
		write("你今天太累了，结果什么也没有学到。\n");
	}

	me->receive_damage("jing", gin_cost );

	return 1;
}
