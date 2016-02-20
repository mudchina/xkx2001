//Cracked by Roath
///d/zhongnan/npc/killer.c 杀手
// sdong 08/15/98

inherit NPC;

void create()
{
	set_name("杀手", ({ "killer","killer" }) );
   set("age", 40);
	set("gender", "男性");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "heroism");
	setup();
	add_money("silver", random(50));
}

void init()
{
	object *inv, *ob,me = this_object();
	mapping skill_status;
	string *sname;
	int i, max = 0, max1, j=0,sum_exp=0;


	if ( !me->query_temp("copied") ) {

	inv = all_inventory(environment());
	ob = all_inventory(environment());

	j=0;
	for(i=0;i<sizeof(inv);i++)
	{
	 if( inv[i]->query_temp("pending/beidou",1) )
		 {
			ob[j] = inv[i]; j++;
		 }
	}

	if( j==0) return;

	if(j>0)
	{
		sum_exp = 0;
		for(i=0;i<j;i++)
		{
			sum_exp += (ob[i])->query("combat_exp",1);
		}
	}

		j -= 1;
      if (j==0)j=1;
		max = sum_exp / j ;


		max = pow(max*10.,0.33333);

		max1 = (int)max + 1;
		max = (int)max + 1 + random((int)max/4);

		me->set_skill("dodge", max1);
		me->set_skill("parry", max1 );
		me->set_skill("force", max1);

		switch( random(6) )
		{
			case 0:
				me->set_skill("cuff", max1);
				me->set_skill("yujiamu-quan", max1);
				me->map_skill("cuff", "yujiamu-quan");
				me->prepare_skill("cuff", "yujiamu-quan");
				me->set_skill("hand", max1);
				me->set_skill("dashou-yin", max1);
				me->map_skill("hand", "dashou-yin");
				me->prepare_skill("hand", "dashouyin");
				me->set_skill("longxiang-banruo", max1);
				me->map_skill("force", "longxiang-banruo");
				me->set_skill("shenkongxing", max1);
				me->map_skill("dodge", "shenkongxing");
				switch( random(2) ) {
					case 0:
								set_name("达尔巴", ({ "darba","da" }) );
								set("long",
"他是金轮法王的二弟子，已得法王五、六分真传，兼天生神力，一身外门功夫 \n"
"甚是了得，虽身形高瘦，却使一根长达四尺的纯金降魔杵。\n");
								set("age", 40);
								me->set_skill("staff", max);
								me->set_skill("jingang-chu", max);
								me->map_skill("staff", "jingang-chu");
								me->map_skill("parry", "jingang-chu");
								setup();
								me->carry_object("/clone/weapon/tiezhang")->wield();
								break;
					case 1:
								if(random(10)==0)
								{
								  set_name("金轮法王", ({ "jinlun fawang","fawang" }) );
								  set("long",
"一个中年番僧，身形极高极瘦，婉如一跟长竹杆。脑门微陷，由如一个碟子。\n"
"他就是当今蒙古国护国法王。\n");
								  set("title", "蒙古国师");
								  set("gender", "男性");
								  set("age", 50);
								  set("class","lama");
								  set("shen_type", -1);

									me->set_skill("hammer", max*5/4);
									me->set_skill("riyue-lun", max*5/4);
									me->map_skill("hammer", "riyue-lun");
									me->map_skill("parry", "riyue-lun");
									setup();
									me->carry_object("/clone/weapon/falun")->set_amount(4);
									me->carry_object("/clone/weapon/falun")->wield();
									command("wield falun");
								}
								else
								{
									set_name("霍都", ({ "huo du","huo" }) );
									set("long",
"他是金轮法王的三弟子，他轻裘缓带，神态甚是潇洒，双目斜飞。\n");
									set("title", "蒙古王子");
									me->set_skill("sword", max);
									me->set_skill("mingwang-jian", max);
									me->map_skill("sword", "mingwang-jian");
									me->map_skill("parry", "mingwang-jian");
									setup();
									me->carry_object("/clone/weapon/changjian")->wield();
								 }
								break;
				}
				break;
			case 1:
				  set_name("沙通天", ({ "sha tongtian", "sha" }));
				  set("nickname", "鬼门龙王");
				  set("long",
"沙通天是个秃子，头上油光光地没半根头发，双目布满红丝，眼\n"
"珠突出，生就一副异相。性子暴躁，武功却是出奇地高，江湖上\n"
"无人不晓。\n");
				  set("title", "黄河帮帮主");
				  set("gender", "男性");
				  set("age", 48);
				  set("attitude", "peaceful");
				  set("shen_type", -1);
				  me->set_skill("force", max1);
				  me->set_skill("dodge", max1);
				  me->set_skill("parry", max1);
				  me->set_skill("cuff", max1);
				  set_skill("wuxingbu", max);
				  set_skill("wuxing-quan", max);
				  set_skill("wuhu-gun", max);
				  set_skill("staff", max1);
				  set_skill("ding-force", max1);

				  map_skill("dodge", "wuxingbu");
				  map_skill("staff", "wuhu-gun");
				  map_skill("parry", "wuhu-gun");
				  map_skill("cuff", "wuxing-quan");
				  map_skill("force", "ding-force");

				  prepare_skill("cuff", "wuxing-quan");

				  setup();
				  carry_object("/clone/weapon/tiejiang")->wield();
				  carry_object("/d/city/obj/tiejia")->wear();
				break;
			case 2:
				  set_name("梁子翁", ({ "liang ziweng", "liang" }));
				  set("nickname", "参仙老怪");
				  set("long",
"梁子翁身材中等，满头白发如银，但脸色光润，神采弈弈，穿一\n"
"件葛布长袍，打扮非道非俗。他是长白山武学的一派宗师。\n");
				  set("gender", "男性");
				  set("age", 45);
				  set("shen_type", -1);

				  set_skill("force", max1);
				  set_skill("ding-force", max1);
				  set_skill("wuxingbu", max1);
				  set_skill("yanqing-quan", max);
				  set_skill("cuff", max);
				  set_skill("hammer", max1);
				  set_skill("taoism",50);

				  map_skill("force", "ding-force");
				  map_skill("dodge", "wuxingbu");
				  map_skill("cuff", "yanqing-quan");
				  map_skill("parry", "yanqing-quan");

				  prepare_skill("cuff", "yanqing-quan");

				  setup();
				  carry_object("/clone/weapon/yaochu2");
				  carry_object("/clone/anqi/tougu-ding")->set_amount(7);
				  carry_object("/clone/armor/gebu-changpao")->wear();

				break;
			case 3:

				set_name("欧阳克", ({ "ouyang ke", "ouyang", "ke" }));
				set("long", "他一身白衣，轻裘缓带，神态甚是潇洒，双目斜飞，面目俊雅，却\n又英气逼人。"
					 "身上服饰打扮，俨然是一位富贵王孙。\n");
				set("title", "白驼山少庄主");
				set("gender", "男性");
				set("shen_type", -1);
				set("age", 35);
				me->set_skill("strike", max1);
				me->set_skill("hamagong", max1);
				me->set_skill("hand", max1);
				me->set_skill("shexing-diaoshou", max1);
				me->map_skill("hand", "shexing-diaoshou");
				if ( max > 100 ) {
					me->map_skill("strike", "hamagong");
					me->prepare_skill("strike", "hamagong");
				}
				else {
					me->prepare_skill("hand", "shexing-diaoshou");
				}
				me->map_skill("force", "hamagong");
				me->set_skill("staff", max);
				me->set_skill("lingshe-zhang", max);
				me->map_skill("staff", "lingshe-zhang");
				me->map_skill("parry", "lingshe-zhang");
				me->set_skill("chanchubu", max1);
				me->map_skill("dodge", "chanchubu");
				setup();
				me->carry_object("/clone/weapon/tiezhang")->wield();
				break;
			 case 4:
			  set_name("彭连虎", ({ "peng lianhu", "peng" }));
			  set("nickname", "千手人屠");
			  set("long",
"彭连虎五短身材，满眼红丝，目光如电，上唇短须翘起。他生性残暴，和沙通天有深厚的交情。\n");
			  set("gender", "男性");
			  set("age", 49);
			  set("shen_type", -1);
			  set_skill("force", max1);
			  set_skill("dodge", max1);
			  set_skill("wuxingbu", max1);
			  set_skill("parry", max1);
			  set_skill("cuff", max);
			  set_skill("wuxing-quan", max);
			  set_skill("club", max1);
			  set_skill("ding-force", max1);
			  set_skill("liuhe-qiang", max);

			  map_skill("club", "liuhe-qiang");
			  map_skill("parry", "liuhe-qiang");
			  map_skill("dodge", "wuxingbu");
			  map_skill("cuff", "wuxing-quan");
			  map_skill("force", "ding-force");

			  prepare_skill("cuff", "wuxing-quan");

			  setup();
			  carry_object("/clone/weapon/panguanbi")->wield();
			  carry_object("/d/shaolin/obj/beixin")->wear();
			  carry_object("/clone/weapon/jqbiao")->set_amount(7);

			  break;

			 case 5:
				  set_name("尹克西", ({ "yin kexi","yin","kexi" }));
				  set("long", "尹克西是个波斯胡人，高鼻深目，先前是个珠宝商，因为精通算帐，被欧阳峰招来做个账房先生。\n");
				  set("gender", "男性");
				  set("title","白驼山庄账房先生");
				  set("age", 35);
				  set_skill("hand", max);
				  set_skill("shexing-diaoshou", max);
				  set_skill("dodge", max1);
				  set_skill("chanchubu", max1);
				  set_skill("parry", max1);
				  set_skill("force", max1);
				  set_skill("hamagong", max1);
				  set_skill("strike",max1);
				  set_skill("poison",max1);
				  set_skill("training",max1);
				  map_skill("hand","shexing-diaoshou");
				  map_skill("dodge","chanchubu");
				  map_skill("force","hamagong");
				  setup();
				  prepare_skill("hand","shexing-diaoshou");
			  break;
		}

		sum_exp = sum_exp/j;
		me->set("combat_exp", sum_exp+random(sum_exp/2));
		me->set("max_qi", ob[0]->query("max_qi"));
		me->set("eff_qi", ob[0]->query("max_qi"));
		me->set("max_jing", ob[0]->query("max_jing"));
		me->set("eff_jing", ob[0]->query("max_jing"));
		me->set("qi", me->query("max_qi"));
		me->set("jing", me->query("max_jing"));
		me->set("jiali", 50);
		if ( ob[0]->query("max_neili") > 0 ) {
			me->set("max_neili", ob[0]->query("max_neili"));
		}
		else me->set("max_neili", 500);
		if ( ob[0]->query("max_jingli") > 0 ) {
			me->set("max_jingli", ob[0]->query("max_jingli"));
		}
		else me->set("max_jingli", 500);
		me->set("neili", me->query("max_neili"));
		me->set("jingli", me->query("max_jingli"));

		me->set("no_sing", 1);
		me->set_temp("copied", 1);
	}

	me->set("shen", (int)(-me->query("combat_exp")/10) );


	if ( !me->query_temp("said") ) {
		  switch( random(4) )
		  {
		case 0:
			command( "grin" );
			command( "say 就凭你死牛鼻子的三脚猫功夫，也配在这里比划？让老子来教训教训你，看招！" );
			break;
		case 1:
			command( "hehe" );
			command( "say 听说九阴真经落在重阳宫里，老子千里迢迢特地赶来，你们就认命吧！" );
			break;
		case 2:
			command( "hehe" );
			command( "say 全真教这么大的名头，老子看来也不过如此。死牛鼻子，你就认命吧！" );
			break;
		default:
			command( "hehe" );
			command( "say 老子我看你死牛鼻子不顺眼，特地来铲除重阳宫。贼道，你就认命吧！" );
			break;
		  }
		  me->set_temp("said", 1);
	}

		for(i=0;i<j;i++)
		{
			ob[i]->kill_ob(me);
			kill_ob(ob[i]);
		}

}

void destruct_me(object me)
{
	if(me) {
		message_vision("$N匆匆忙忙地离开了。\n\n", me);
		destruct(me);
	}
}


int accept_fight(object victim)
{
	object me = this_object();

	command( "say 你吃了狼心豹子胆啦，竟敢反抗！" );
	me->set_temp("fought", 1);
	me->kill_ob(victim);

	remove_call_out("checking");
	call_out("checking", 1, me, victim,me->query_temp("bonus",1)+random(2));
	return 1;
}

int accept_kill(object victim)
{
	object me = this_object();

	command( "say 不知死活的东西，让大爷我超渡你吧！" );
	me->kill_ob(victim);

	remove_call_out("checking");
	call_out("checking", 1, me, victim,me->query_temp("bonus",1)+random(2));
	return 1;
}

/*
void unconcious()
{
	object me=this_object();
	object ob = me->query_temp("last_damage_from");

	if( random(20) == 10)
	{
		message_vision("\n$N恨恨地说道：没想到牛鼻子们爪子这么硬，下次再找麻烦。\n", this_object());
		message_vision("$N身子向后一跳，匆匆忙忙离开了。\n", this_object());
		destruct(me);
		tell_object(ob,"\n你的潜能好象增加了！\n");
		ob->add("potential",me->query_temp("bonus",1) );
		if(ob->query("potential",1)>ob->query("max_potential",1) )
			ob->set("potential",ob->query("max_potential",1));
	}
	::unconcious();

}

void die()
{
	int pot,exp;
	object me=this_object();
	object ob = me->query_temp("last_damage_from");

	 if( !living(me) ) {revive(1);reincarnate();}

	if( me->query("combat_exp") > ob->query("combat_exp")/2 && random(2) == 0)
	{
		exp = 6*me->query_temp("bonus",1)+6*random(me->query_temp("bonus",1));
		if(exp<50)exp=50;
		if(exp>140)exp=140;
		pot = 3*me->query_temp("bonus",1)+3*random(me->query_temp("bonus",1));
		if(pot<25)pot=25;
		if(pot>65)pot=65;
		ob->add("combat_exp", exp);
		ob->add("potential", pot);
		if ( ob->query("potential") > ob->query("max_potential") )
			ob->set("potential", ob->query("max_potential"));
		tell_object(ob,"\n你的经验和潜能好象进步了！\n");
		::die();
	}
	else
	{
		message_vision("\n墙上忽然有人跳下来，把$N一把抱起，喝道：秃贼，休伤我的兄弟。\n", this_object());
		message_vision("蒙面人带着$N往墙上一跳，匆匆忙忙离开了。\n", this_object());
		tell_object(ob,"\n你的潜能好象增加了！\n");
		ob->add("potential",me->query_temp("bonus",1)*2 );
		if(ob->query("potential",1)>ob->query("max_potential",1) )
			ob->set("potential",ob->query("max_potential",1));
		destruct(me);
	}
}
*/
