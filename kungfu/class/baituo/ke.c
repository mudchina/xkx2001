//Cracked by Roath
// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96
// modified by sdong for job system, 11/23/98

inherit NPC;
inherit F_MASTER;
int auto_perform();
string ask_job();
void reward_dest(object obj,object ob);
void destroy_dest(object obj,object ob);
void destroy_staff(object obj,object ob);
void thank_dest(object obj,object ob);

void create()
{
	set_name("欧阳克", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "他一身白衣，轻裘缓带，神态甚是潇洒，双目斜飞，面目俊雅，却又英气逼人。"
	"身上服饰打扮，俨然是一位富贵王孙。\n");
	set("title", "白驼山少庄主");
	set("gender", "男性");
	set("age", 35);

	set_skill("cuff", 140);
	set_skill("strike", 140);
	set_skill("shentuo-zhang", 140);
	set_skill("lingshe-quan", 140);
	set_skill("dodge", 140);
	set_skill("chanchubu", 140);
	set_skill("parry",140);
	set_skill("force", 140);
	set_skill("hamagong", 140);
	set_skill("lingshe-zhang",140);
	set_skill("staff",140);
	set_skill("strike",140);
	set_skill("poison",140);
	set_skill("training",140);
	map_skill("cuff","lingshe-quan");
	map_skill("strike","shentuo-zhang");
	map_skill("dodge","chanchubu");
	map_skill("parry", "lingshe-zhang");
	map_skill("staff","lingshe-zhang");
	map_skill("force","hamagong");
	prepare_skill("cuff","lingshe-quan");
	prepare_skill("strike","shentuo-zhang");

	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);

	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 40);
	set("combat_exp", 900000);

	set("attitude", "peaceful");
	set("shen_type", -1);

	create_family("白驼山", 2 , "弟子");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("inquiry", ([
		"欧阳峰" : "他是我叔父。",
		"化尸粉" : "我只有一份化尸粉，不能给你。不过你要是给我一具尸体，我可以给你做些。",
		"活" : (: ask_job :),
		"job" : (: ask_job :),
	]));

	setup();
	set_temp("job_pos",20);
	carry_object("/d/xingxiu/npc/obj/shezhang")->wield();
	carry_object("/d/xingxiu/obj/wcloth")->wear();
	carry_object("/d/xingxiu/obj/diaoqiu")->wear();
}


void attempt_apprentice(object ob)
{
		mapping fam;

		if( !mapp(fam = ob->query("family")) || fam["family_name"] != "白驼山")
	{
		command ("say " + RANK_D->query_respect(ob) +
			"先去敝山庄武师或账房先生手下打打杂吧。");
		return;
	}
	if ((int)ob->query_skill("hamagong", 1) < 30) {
		command("say 我们白驼山庄的绝技是叔父所创的蛤蟆功。");
		command("say " + RANK_D->query_respect(ob) + "是否还应该在蛤蟆功上多下点功夫？");
		return;
		}
	command("say 好吧，你就在我山庄做个护庄武师吧。");
	command("recruit " + ob->query("id"));
	ob->set("title","白驼山庄武师");
	return;
}

void init()
{
		object ob;
		::init();
		if (interactive(ob = this_player()) && !is_fighting()) {
			 remove_call_out("greeting");
			 call_out("greeting", 1, ob);
		}
}

void greeting(object me)
{
        int sxds, hand;
		sxds = me->query_skill("shexing-diaoshou",1);
        hand = me->query_skill("hand",1);
 
		if( me->query("family/family_name") == "白驼山"
		&& !me->query("baituo_updated") ) {
			 me->set_skill("cuff", hand);
			 me->set_skill("lingshe-quan", sxds);
			 me->delete_skill("hand");
			 me->delete_skill("shexing-diaoshou");
			 me->set("baituo_updated",1);
		}
		return;
}

string ask_job()
{
	mapping job_stat;
	object ob2;
	object ob = this_player();
	object me = this_object();
	object guaishe,staff,here=environment(me);
	int good_skill;

	job_stat = ob->query_temp("baituo/feeding");

	if ( ob->query("family/family_name") != "白驼山" )
		return RANK_D->query_rude(ob)+"莫非别有用心！\n";

	if( ob->is_busy() ){
		command("hmm "+ob->query("id"));
		return "你还在忙着干别的事呢！\n";
	}

	if( job_stat ){
		command("hmm "+ob->query("id"));
		return "你还没干完活呢!\n";
	}

/*
	if( ob->query("combat_exp") < 100 ) {
		command("hmm");
		return "小毛孩自个玩去，本少爷忙着呢。\n";
	}
*/

	if( ob->query_skill("training") < 10 && random(4)!=0 ) {
		return "你的驯兽术太低，随便拿只蛇练练去吧。\n";
	}


	ob->start_busy(random(4));
	good_skill = (int)( pow(ob->query("combat_exp")*10,0.33333) * 0.7 ) * 3/2 ;

	if( ob->query("combat_exp") > 20000 && ( ob->query_skill("force") < good_skill ) && random(15) > 0 ) {
		command("say 你去好好练习一下蛤蟆功吧！");
		return "蛤蟆功是本派的独门绝技，练成之後一定可以帮本少爷多抓几个美女来！\n";
		}

	if( ob->query("combat_exp") > 5000 && 
	ob->query("max_neili") < ob->query_skill("force") * 7 && random(5) > 0 ) {
		command("say 你内力不够，去好好打坐一下吧！");
		return "内力越高，蛤蟆功的威力就越大，嘿黑，和美眉在一起也。。。\n";
		}



	if ( me->query_temp("job_pos") == 0 ) {
		if(random(8)==1)
		me->set_temp("job_pos",1);
		return "现在没什么事，你自个儿晃荡去吧。\n";
	}

	me->add_temp("job_pos", -1);

	command("nod");
	command("say 好，我这里有一只奇毒的怪蛇，"+ob->query("name")+"你拿去好好调养。");
	command("say 这怪蛇吃鸟类、吸人血。越是所谓名门正派的高手的气血越是滋养怪蛇。");
	command("hehe");
	command("say 它吃饱了以後，就会乖乖的爬进蛇杖里成为天下最厉害的兵器。");


	guaishe = present("guai she",me );
	if(guaishe)destruct(guaishe);
	guaishe = present("guai she",me );
	if(guaishe)destruct(guaishe);
	ob2 = new("/d/xingxiu/npc/guaishe");
	ob2->move(me);
	ob2->set_owner(ob);
	ob->set_temp("baituo/feeding",1);
	command("give guai she to "+ob->query("id"));
	guaishe = present("guai she",me );
	if(guaishe)command("drop guai she");

	staff = present("guai shezhang",here);
	if(!staff)staff=present("guai shezhang",ob);
	if(staff)destruct(staff);
	staff = new("/clone/weapon/gshezhan");
	staff->move(me);
	command("give guai shezhang to "+ob->query("id"));
	guaishe = present("guai shezhang",me );
	if(guaishe)command("drop guai shezhang");

	return "千万别弄丢了！\n";
}

int accept_object(object me, object obj)
{
	object hsf, ob = this_player();

	if (obj->query("id")=="corpse")
	{
		if (!me->query("family") || me->query("family/family_name")!= "白驼山"){
			command("say 你要我给你收尸不成？\n");
			return 0;
		}
		if (me->query("family/master_name") != "欧阳锋" &&
			me->query("family/master_name") != "欧阳克") {
			command("say 你还是先练好功夫吧。\n");
			return 0;
		}
		if (me->query_temp("huashifen")) {
			 command("say 化尸粉这样烈性的药物不要用得过多。\n");
			return 0;
		 }

		message_vision("$N将" + obj->name() + "放在地上，从怀中掏出一份化尸粉撒在上面。\n",this_object());
		message_vision("片刻之间，" + obj->name() + "化作一滩黄水。黄水干了后成了一堆发出荧荧的黄光的粉末。\n" ,obj);
		message_vision("$N将其中一份收在怀中，其余的交给$n。\n",this_object(),me);
		command("say 你可以把化尸粉倒在尸体上，可即刻将其融化掉。");
		command("say 你也可以把它涂在绷带上给人佯装裹伤，待毒性深入其伤口，他就死定了。");
		command("hehe ouyang ke");

		hsf = new(DRUG_D("huashi"));
		hsf->set_amount(10);
		hsf->move(me);
		me->set_temp("huashifen",1);
		return 1;
	}

		command( "say "+obj->name()+"?");

		if (obj->query("id") == "guai she") {
			call_out("destroy_dest", 1, obj, ob);
			return 1;
		}

		if ( obj->query("id") == "guai shezhang") {
			if ( ob->query("family/family_name") == "白驼山" ) {
				if( obj->query("snake")>0 )
					call_out("reward_dest", 1, obj, ob);
				else
					call_out("destroy_staff", 1, obj, ob);
			}
			else {
				call_out("thank_dest", 1, obj, ob);
			}
			return 1;
		}

		command( "hmm" );
		command( "say 你给我这东西做什麽？" );

		return 0;
}

void reward_dest(object obj,object ob)
{
	command( "pat "+ob->query("id"));
	command( "say "+ob->query("name")+"干的还不错，这样多干活，将来本少爷一定会赏你的！\n");
	if(ob->query("gender") == "女性" )
		command( "kiss1 " + ob->query("id") );

	if(ob->query_temp("baituo/feeding",1) )
	{
		ob->delete_temp("baituo/feeding");
		add_temp("job_pos", 1);
	}
	destruct(obj);
}


void destroy_staff(object obj,object ob)
{
	command( "hmm" );
	command( "kick "+ob->query("id") );
	command( "say 怎么就这样还给我？蛇呢？小心少爷我赏你一蛇杖！" );
	command( "angry" );

	destruct(obj);
}

void destroy_dest(object obj,object ob)
{
	command( "hmm" );
	command( "kick "+ob->query("id") );
	command( "say 怎么就这样还给我？应该喂饱变成蛇杖再交给我。小心少爷我赏你给蛇吃！" );
	command( "angry" );

	if(ob->query_temp("baituo/feeding",1) )
	{
		ob->delete_temp("baituo/feeding");
		add_temp("job_pos", 1);
	}
	destruct(obj);
}


void thank_dest(object obj,object ob)
{
	command( "ah");
	command( "jump");
	command( "say 本少爷的蛇杖？多谢啦！\n");
	destruct(obj);
}


#include "/kungfu/class/baituo/auto_perform.h"
