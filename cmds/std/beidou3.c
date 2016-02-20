//Cracked by Roath
// beidou3.c
// 天罡北斗阵
// by sdong 10/10/98

inherit F_CLEAN_UP;

#include <ansi.h>
#include <skill.h>



inherit F_SSERVER;
string *position = ({
					 "天权","天枢","天璇","天玑","玉衡","开阳","摇光"
});

string *sword = ({
	"踏奇门，走偏锋，剑尖颤了几颤，一招巧妙无比的「分花拂柳」，似左实右往空中刺去。",
	"使一招「琴心三叠」，身形向上飘起，手中剑虚虚实实幻出三点寒光射向空中。",
	"身形一转，猛然一式「罡风扫叶」，舞出满天剑影，挟着劲风向前扫去。",
	"仰天长笑，身形飘然而起，在半空中身子一旋，一式「狂歌痛饮」狂风般地击向空中。",
	"左手捏着剑诀，右足踏开一招“定阳针”向上斜刺。",
	"向前迈去一大步，使出「探海屠龙」，手中剑舞成一个光球，迅若奔雷击出。",
	"运力一抖剑，一时「马蹴落花」，剑幻出点点剑花，飘然刺出。",
	"手中剑一指，纵起丈余，一时「横行漠北」，雷霆般击出。",
	"身形向上飘起，突然一转身，头下脚上，手握剑，一招「絮坠无声」，无声无息地攻出。",
	"大喝一声，一招「白虹经天」，剑闪电般划出一道大圆弧劈下。",
	"忽然身形高高跃起，使出「浪迹天涯」，手中剑幻出漫天花瓣，迅如雷霆射出。"
});

string *zhen =  ({
	"天罡北斗阵法滚滚推动，攻势连绵不绝，瞬间将敌人围在垓心。",
	"天罡北斗阵气势宏大，前攻后击，连环相接，让人眼花撩乱，方寸顿失。",
	"只见天罡北斗阵暗合五行八卦之理，阵中人步法精妙，攻守配合得天衣无缝。",
	"天罡北斗阵越缩越小，无形剑气象浪潮一般逼向中央，令人有窒息之感。"
});


int check_ob(object ob,object me);
void start_beidouzhen(object ob, int mypos,int beidou_time );
int beidouzhen(object me);
int halt_beidouzhen(object me);
int do_beidouzhen(string arg);
int beidouzhen(object me);
int halt_beidou(object me);
int stop_beidou();

void create() { seteuid(getuid()); }


int main(object me, string arg)
{
		  object enemy;
		  int beidou_time,i,mypos=0,power,bd_power;
		  object here;
		  string name1,name2,enemy_id;
		  object ob1,ob2,ob3;

		  if( this_player()->is_busy() )
		  {
		  		return notify_fail("你正忙着呢！\n");
		  }

		  here = environment( this_player() );

		  if( !arg || sscanf(arg, "%s %s %s", enemy_id,name1,name2)!=3 )
					 return notify_fail("beidou3 enemy friend1 friend2\n");

		  if( !(enemy = present(enemy_id, here) ) )
		  {
				return notify_fail(enemy_id+"不在这里！\n");
		  }

		  if( enemy->query("race") != "人类" )
		  {
				return notify_fail("杀鸡焉用牛刀？\n");
		  }

		  if( enemy->query("family/family_name") == "全真教" )
		  {
				return notify_fail("同门相残？\n");
		  }


		  if( !(ob1 = present(name1, here ) ) )
		  {
				return notify_fail(name1+"不在这里！\n");
		  }

		  if( ob1->is_busy() )
		  {
		  		return notify_fail(name1+"正忙着呢！\n");
		  }
		  
		  i = check_ob(ob1,me);
		  if(  i !=1) return i;

		  if( !(ob2 = present(name2, here) ) )
		  {
				return notify_fail(name2+"不在这里！\n");
		  }

		  if( ob2->is_busy() )
		  {
		  		return notify_fail(name2+"正忙着呢！\n");
		  }

		  i = check_ob(ob2,me);
		  if(  i !=1) return i;

		  if( name1 == me->query("id") ||   name2 == me->query("id")  )
		  {
				return notify_fail("想一身数用？你不会分身术吧？\n");
		  }

		  if( name1 == name2 )
		  {
				return notify_fail(name1 + "不会分身术吧？\n");
		  }


		  power = me->query("force") + ob1->query("force")+ob2->query("force");
		  power += me->query("sword") + ob1->query("sword")+ob2->query("sword");
		  power += me->query("str") + ob1->query("str")+ob2->query("str");
		  power += me->query("dex") + ob1->query("dex")+ob2->query("dex");
		  bd_power = me->query("beidou-zhenfa") + ob1->query("beidou-zhenfa")+ob2->query("beidou-zhenfa");
		  power = power / 140/2;
		  bd_power /= 70/5;
		  power *= bd_power;

		  if(power>50)power=50;
		  if(power,15)power=15;


		  start_beidouzhen(me,0,power);
		  start_beidouzhen(ob1,1,power);
		  start_beidouzhen(ob2,2,power);

		  here->set_temp("ob1",me->query("id"));
		  here->set_temp("ob2",ob1->query("id"));
		  here->set_temp("ob3",ob2->query("id"));

		  message_vision(HIR"\n$N对$n喝道：" + RANK_D->query_rude(enemy) + "你一向为非作歹，今天本教要替天行道，纳命来！\n"NOR, me, enemy);
		  me->kill_ob(enemy);
		  ob1->kill_ob(enemy);
		  ob2->kill_ob(enemy);
		  enemy->kill_ob(me);
		  enemy->kill_ob(ob1);
		  enemy->kill_ob(ob2);
		  message_vision(HIM"$N突然身形移动，发动众全真弟子抢占位置，正是摆的「天罡北斗阵」阵法。\n\n"NOR, me);
		  return 1;
}


int check_ob(object ob,object me)
{
	string ob_name;
	object weapon;
	float exp_diff;

			  if( !objectp(ob) )
			  {
					 return notify_fail("可惜没有这个人。\n");
			  }
				  ob_name = ob->query("name");

				  if ( !present( ob->query("id"), environment(me) ) )
				  {
					 return notify_fail("可惜"+ob_name+"不在这里。\n");
				  }

				  if ( ob->query("family/family_name") != "全真教" )
				  {
					 return notify_fail("可惜"+ob_name+"不是全真弟子，不会「天罡北斗阵」。\n");
				  }


				  if ( ob->query_skill("quanzhen-jian",1) <60 || ob->query("combat_exp",1)<50000 ||
						ob->query_skill("dodge") <60
					  )
				  {
					 return notify_fail("可惜"+ob_name+"武功太差，不会「天罡北斗阵」。\n");
				  }

				  exp_diff = (float)( ob->query("combat_exp" ) - me->query("combat_exp") ) / (float)me->query("combat_exp");

				  if( exp_diff > 0.3 || exp_diff < -0.3 )
				  	 return notify_fail("可惜"+ob_name+"武功和你差距太大，不能共摆「天罡北斗阵」。\n");

		 return 1;
}

void start_beidouzhen(object ob, int mypos,int beidou_time )
{
			ob->set_temp("pending/beidou", 1);
			ob->set_temp("beidou_time", beidou_time*2);
			ob->set_temp("bd_pos", mypos);
			ob->set_temp("bd_power",beidou_time);
			ob->start_busy((: beidouzhen :), (:halt_beidou:));
}




void destruct_me(object me)
{
	if(me)
		destruct(me);
}

void check_leaving(object me)
{
	string name = me->query("id");

	 if( !userp(me) )
		{
		 object enemy = offensive_target(me);
		 if( !objectp(enemy) && !me->is_busy() && !me->is_fighting() )
		 {
			 message_vision(HIY"\n$N作了个楫道：贫道先告退了！说完就快步离开了。\n"NOR, me);
			 call_out("destruct_me",10,me);
			 return;
		  }

		  call_out("check_leaving",5,me);
	  }
}

int beidouzhen(object me)
{
		  object  where = environment(this_player());
		  int beidou_time = (int)me->query_temp("beidou_time");
		  object room, obj,enemy,weapon;
		  int cost, bonus,mypos=me->query_temp("bd_pos");
		  int power;
		  object ob1,ob2,ob3,ob4,ob5,ob6,ob7;


		  if( !(room = environment(this_player())) )

		  {

				  if(!objectp(weapon = me->query_temp("weapon"))

						|| (string)weapon->query("skill_type") != "sword" )
						{
							message_vision(HIG"\n$N身子向后一纵，使一招『收山式』，右拳划了一圈，左掌往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);
						}
				else
					message_vision(HIG"\n$N身子向后一纵，使一招『收剑式』，将剑挽了一个剑花，往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);

				me->remove_all_enemy();

				me->delete_temp("pending/beidou");
				me->delete_temp("beidou_time");
				me->delete_temp("bd_pos");
				me->delete_temp("bd_power");
				call_out("check_leaving",2,me);

			  return 0;

			}

		  enemy = offensive_target(me);


		  if( enemy && enemy->query_temp("yield") )

		  {

				  if(!objectp(weapon = me->query_temp("weapon"))

						|| (string)weapon->query("skill_type") != "sword" )
						{
							message_vision(HIG"\n$N身子向后一纵，使一招『收山式』，右拳划了一圈，左掌往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);
						}
					else
					  message_vision(HIG"\n$N身子向后一纵，使一招『收剑式』，将剑挽了一个剑花，往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);


					message_vision(HIY"\n$N大声道：全真教不杀不抵抗之人，这位"+RANK_D->query_respect(enemy)+HIY"请走吧！\n"NOR, me);

					me->remove_all_enemy();

					me->delete_temp("pending/beidou");
					me->delete_temp("beidou_time");
					me->delete_temp("bd_pos");
					me->delete_temp("bd_power");
					room->delete_temp("ob1");
					room->delete_temp("ob2");
					room->delete_temp("ob3");

					call_out("check_leaving",2,me);
					return 0;
		  }


		  if ( me->query("neili") < 60 || me->query("jingli")<50 )
		  {
				  if(!objectp(weapon = me->query_temp("weapon"))
						|| (string)weapon->query("skill_type") != "sword" )
						{
							message_vision(HIY"\n$N体力不支，只好身子向后一纵，使一招『收山式』，右拳划了一圈，左掌往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);
						}
				  else
						message_vision(HIY"\n$N体力不支，只好身子向后一纵，使一招『收剑式』，将剑挽了一个剑花，往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);

					me->remove_all_enemy();
					me->delete_temp("pending/beidou");
					me->delete_temp("beidou_time");
					me->delete_temp("bd_pos");
					me->delete_temp("bd_power");
					call_out("check_leaving",2,me);
					 return 0;
		  }

		  if( !( room->query_temp("ob1",1) &&
				(objectp(ob1=present( room->query_temp("ob1",1),where) ) ) && ob1->query_temp("beidou_time") &&
				(objectp(ob2=present( room->query_temp("ob2",1),where) ) ) && ob2->query_temp("beidou_time") &&
				(objectp(ob3=present( room->query_temp("ob3",1),where) ) ) && ob3->query_temp("beidou_time") )
			 )
			 {
				  if(!objectp(weapon = me->query_temp("weapon"))
						|| (string)weapon->query("skill_type") != "sword" )
						{
							message_vision(HIG"\n$N身子向后一纵，使一招『收山式』，右拳划了一圈，左掌往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);
						}
					else
					  message_vision(HIG"\n$N身子向后一纵，使一招『收剑式』，将剑挽了一个剑花，往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);

					me->remove_all_enemy();
					me->delete_temp("pending/beidou");
					me->delete_temp("beidou_time");
					me->delete_temp("bd_pos");
					me->delete_temp("bd_power");
					room->delete_temp("ob1");
					room->delete_temp("ob2");
					room->delete_temp("ob3");

					call_out("check_leaving",2,me);
					return 0;
			 }


		  beidou_time = beidou_time-1;
		  me->set_temp("beidou_time", beidou_time);

		  bonus = random( ( me->query("int")+me->query("con")+25 ) / 30 ) + (me->query("int")+me->query("con")+25 ) / 30;
		  if( bonus > 3 ) bonus = 3;


		  if(enemy) bonus = bonus * 2 * ( enemy->query("combat_exp") - me->query("combat_exp") ) / me->query("combat_exp");
		  else bonus = 0;

		  if( bonus <0 ) bonus = 0;
		  if( bonus > 8 ) bonus = 8;

		  if( (int)me->query("potential") < (int)me->query("max_potential") )
					 me->add( "potential", bonus/2 );

		  me->add( "combat_exp", bonus*2/3 );
		  me->improve_skill( "beidou-zhenfa", random(bonus*2/3) );

		  enemy = offensive_target(me);

		  power = me->query_temp("bd_power",1)*4;


		  if( random(6)==1 )
		  {
			  tell_room(environment(me), HIR"\n" + zhen[(int)random(4)] +"\n"NOR, this_object());

			  if( objectp(enemy) && objectp( present( enemy->query("id"),environment(me) )) )
				  enemy->start_busy( random(2) );
		  }

		  if( objectp(enemy) && objectp( present( enemy->query("id"),environment(me) )) )
		  {
			  me->set_temp("apply/parry",me->query_temp("apply/parry",1)+power);
			  me->set_temp("apply/armor",me->query_temp("apply/armor",1)+power);
			  if( random(2)==1 )
			  {
				  if(random(2)==0)
					  message_vision("\n" + position[mypos] + "位上的$N气沉丹田，暗运神功，猛然吐气开声，身形往前一纵, 但见", me);
				  else message_vision("\n" + position[mypos] + "位上的$N挺身而出，步法精妙，长袖飘飘，攻势如虹。只见", me);

				  me->set_temp("apply/damage",me->query_temp("apply/damage",1)+power/2);
				  me->set_temp("apply/attack",me->query_temp("apply/attack",1)+power/2);
				  COMBAT_D->do_attack(me, enemy, me->query_temp("weapon"));
				  me->set_temp("apply/damage",me->query_temp("apply/damage",1)-power/2);
				  me->set_temp("apply/attack",me->query_temp("apply/attack",1)-power/2);
				  me->receive_damage("jingli", 15+random(15), "运转天罡北斗阵累死了");
				  me->add("neili", -20-random(20));
			  }
			  me->set_temp("apply/parry",me->query_temp("apply/parry",1)-power);
			  me->set_temp("apply/armor",me->query_temp("apply/armor",1)-power);
			  return 1;
		  }
		  else
		  {
				if ( random(3)==1 )
				{
					if( ( weapon = me->query_temp("weapon") )
						 && (string)weapon->query("skill_type") == "sword" )
					{
						message_vision("\n" + position[mypos] + "位上的$N"+ sword[random(10)]+"\n", me);
					}

					me->receive_damage("jingli", 15+random(10), "练习天罡北斗阵累死了");
					me->add("neili", -20-random(15) );
				}
		  }


	 me->delete_temp("pending/beidou");
	 me->delete_temp("beidou_time");
	 me->delete_temp("bd_pos", mypos);
	  if(!objectp(weapon = me->query_temp("weapon"))
			|| (string)weapon->query("skill_type") != "sword" )
			{
				message_vision(HIG"\n$N身子向后一纵，使一招『收山式』，右拳划了一圈，左掌往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);
			}
		else
			message_vision(HIG"\n$N身子向后一纵，使一招『收剑式』，将剑挽了一个剑花，往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);


	 call_out("check_leaving",5,me);
	 return 0;
}

void restart (object me)
{
	start_beidouzhen(me, me->query_temp("bd_pos"), me->query_temp("beidou_time",1) );
}

int halt_beidou(object me)
{
	  object weapon;
	  int beidou_time = (int)me->query_temp("beidou_time",1);
	  if (beidou_time > 0)
	  {
			if( !living(me) ) return 1;

			if(random(2)==1)
			{
				message_vision(HIG"\n$N踉跄了一步，差点摔出北斗阵。\n"NOR, me);
			}
			else message_vision(HIG"\n$N被打的晃了几晃，不过又站稳了步子。\n"NOR, me);
			call_out("restart",4,me);
			return 1;
	  }

	  if(!objectp(weapon = me->query_temp("weapon"))
			|| (string)weapon->query("skill_type") != "sword" )
		{
			message_vision(HIG"\n$N身子向后一纵，使一招『收山式』，右拳划了一圈，左掌往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);
		}
		else
			message_vision(HIG"\n$N身子向后一纵，使一招『收剑式』，将剑挽了一个剑花，往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);

	  me->delete_temp("pending/beidou");
	  me->delete_temp("beidou_time");
	  me->delete_temp("bd_pos");
	  me->delete_temp("bd_power");
	  return 1;
}

int stop_beidou()
{
	  object weapon,me=this_player();
	  if(!me->query_temp("pending/beidou"))
					 return notify_fail("停什么？你不在运行「天罡北斗阵」。\n");
	  if(!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword" )
	  {
		message_vision(HIG"\n$N身子向后一纵，使一招『收山式』，右拳划了一圈，左掌往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);
		}
	 else
		message_vision(HIG"\n$N身子向后一纵，使一招『收剑式』，将剑挽了一个剑花，往怀中一抱，退出「天罡北斗阵」。\n"NOR, me);

	  me->remove_all_enemy();
	  me->delete_temp("pending/beidou");
	  me->delete_temp("beidou_time");
	  me->delete_temp("bd_pos");
	  me->delete_temp("bd_power");
	  return 1;
}



int help(object me)
{
		  write(@HELP
指令格式 : beidou3 <enemy> <对象1> <对象2> <对象3>

这个指令能让你和同伴一起组成天罡北斗阵。

请参考相关指令 beidou
HELP
		  );
		  return 1;
}


