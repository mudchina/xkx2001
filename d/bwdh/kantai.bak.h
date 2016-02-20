//Cracked by Roath
// /d/bwdh/kantai.h
// 看台
// by sdong 09/25/98

#include <ansi.h>
inherit ROOM;
#define CANGKU "/d/bwdh/cangku"

int do_practice(string arg);
int do_study(string arg);
string long_desc();
int do_start(string arg);
int do_stop(string arg);
int do_baoming();
int start(string host,string challenger);
void sort_rank(object ob,int i);
int auto_check();
int let(string arg);
void full_all(object me);
int do_abandon();

void create()
{
	set("short", "看台");
	set("long", (: long_desc :));
	set("valid_startroom", 1);

	set("no_fight", 1);
	set("no_practice", 1);

	set("exits", ([
		"up" : LEITAI,
		"north" : KANTAI2,
		"out": "/d/bwdh/square",
	]));


	setup();
}

void init()
{
  object player = this_player();
  object *inv, cangku, *basket;
  int i;

  if ( objectp(player) && player->query("bwdh/fighting") ) {

    player->remove_all_killer();
    player->clear_condition();	
    inv = all_inventory(player);
    for (i=0; i<sizeof(inv); i++) {
    	if (! inv[i]->query_autoload()) 
	{
	        message_vision(NOR"$N把从擂台取的"+inv[i]->query("name")+"还给主持人。\n", player);
	        destruct(inv[i]);
	}
    }
  
  cangku = find_object(CANGKU);
  if (! objectp(cangku)) {
    cangku = load_object(CANGKU);
    if (!objectp(cangku)) {
      message_vision("$N请告诉 wiz: cangku not found\n", player);
      return 0;
    }
  }

  //player->restore();	
  full_all(player);	

  basket = cangku->query("basket/"+player->query("id"));

  if (basket) {
    for (i=0; i<sizeof(basket); i++) {
      if (objectp(basket[i])) {
        basket[i]->move(player);
        message_vision("$N从主持人手里拿回一"+
                basket[i]->query("unit")+ 
                basket[i]->query("name")+"。\n", player);
      }
    }
    cangku->delete("basket/"+player->query("id"));
  }
  player->delete("bwdh/admitted");
  player->delete("bwdh/fighting");

 }
		  add_action("do_practice",  "practice");
		  add_action("do_practice",  "lian");
		  add_action("do_study",  "study");
		  add_action("do_study",  "du");
		  add_action("do_baoming", "报名");
		  add_action("do_baoming", "baoming");
		  add_action("do_abandon", "放弃");
		  add_action("do_abandon", "abandon");
		  add_action("do_start", "start");
		  add_action("do_stop", "stop");
		  add_action("do_abandon", "abandon");

}


int do_practice(string arg)
{
		  object me = this_player();
		  tell_object(me, "这里不准练功!\n");
		  return 1;
}

int do_study(string arg)
{
  	object me = this_player();
  	tell_object(me, "这里不准读书!\n");
        return 1;
}

int do_abandon()
{
  	object me = this_player();
  	tell_object(me, "你决定放弃成绩不干了!\n");
	me->delete("bwdh");
	sort_rank(me, 0);
        return 1;
}


string long_desc()
{
  	string desc,temp;
	int nRank,i,j;

  	desc  = HIY"

		           /I______________I\\               "+HIC"|"+HIR"=====|"+HIY"
		         //||||||||||||||||||\\\\             "+HIC"|"+HIR" 武   |"+HIY"
		     T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T         "+HIC"|"+HIR"=====|"+HIY"
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIR"【比武擂台】"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIC"|"+HIY"
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"|"+HIY"
			/||||||||||||||||||||||\\            "+HIC"|"+HIY"
		    T\\//IIIIIIIIIIIIIIIIIIIIIIII\\\\/T        "+HIC"|"+HIY"
	            ^^^^"+HIG"||"+HIY"^^^^^^^^^^^^^^^^^^^^"+HIG"||"+HIY"^^^^        "+HIC"|"+HIG"
			||                    ||            "+HIC"|"+HIW"
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIG"
             ||                                          ||
             ||  ________       龙 虎 板       ________  ||
             ||  |                                    |  ||\n";

		

	if(query("age"))
	{
		desc += "     	     ||  |          "+query("age")+"岁以下组比武大赛        |  ||\n";
		desc += "     	     ||  |                                    |  ||\n";
	}

	nRank = this_object()->query("nRank");
	for ( i=1;i<=nRank && i <= 10;i++)
	{
		desc += "             ||  | ";
		desc += i + ". ";

		temp = this_object()->query("rank/"+i+"/name") + "("; 
		temp += this_object()->query("rank/"+i+"/id") + ") "; 
		temp += "胜："+this_object()->query("rank/"+i+"/win") + " "; 
		temp += "负："+this_object()->query("rank/"+i+"/loss");
		
		desc += temp; 
		for(j=strlen(temp);j<=31;j++)
		{
			if(i==10 &&j==31)break;
			desc += " ";
		}

		desc += "|  ||\n"; 
	}

	for(i=i;i<=12;i++)
	{
		desc += "     	     ||  |                                    |  ||\n";
	}
  
	desc+="             ||  |____________________________________|  ||\n";
  	return desc;
}


int valid_leave(object me, string dir)
{
	if( dir=="up" ) {
		if(  wizardp(me)  ) return 1;
		else return notify_fail("你不能自己上去。\n");
	}

	if( dir=="out" ) {
		if( wizardp(me) || me->query("bwdh/defeated") >= 5 || !me->query("bwdh") || !query("start") ) return 1;
		else
		{
			return notify_fail("你是选手,现在不能离开。除非你认输(abandon)不干了。\n");
		}
	}

	return ::valid_leave(me, dir);

}

void sort_rank(object ob, int n)
{
	int nRank = query("nRank");
	int i;
	string id = ob->query("id");
	
	if(n>0)
	{
		
		for(i=nRank;i>=1;i--)
		{
			if(query("rank/"+i+"/id")==id)break;
		}
		if( i<1 )
		{
			nRank ++;
			set( "nRank",nRank );
			set( "rank/"+nRank+"/name",ob->query("name") );
			set( "rank/"+nRank+"/id",ob->query("id") );
			set( "rank/"+nRank+"/win",ob->query("bwdh/win") );
			set( "rank/"+nRank+"/loss",ob->query("bwdh/defeated") );
			i=nRank;
		}

		for(i=i;i>=1;i--)
		{
			if( i>1 && query("rank/"+(i-1)+"/win") < ob->query("bwdh/win") )
			{
				set( "rank/"+i+"/name",query("rank/"+(i-1)+"/name") );
				set( "rank/"+i+"/id",query("rank/"+(i-1)+"/id") );
				set( "rank/"+i+"/win",query("rank/"+(i-1)+"/win") );
				set( "rank/"+i+"/loss",query("rank/"+(i-1)+"/loss") );

				set( "rank/"+(i-1)+"/name",ob->query("name") );
				set( "rank/"+(i-1)+"/id",ob->query("id") );
				set( "rank/"+(i-1)+"/win",ob->query("bwdh/win") );
				set( "rank/"+(i-1)+"/loss",ob->query("bwdh/defeated") );
			} 
			else
			{
				set( "rank/"+i+"/name",ob->query("name") );
				set( "rank/"+i+"/id",ob->query("id") );
				set( "rank/"+i+"/win",ob->query("bwdh/win") );
				set( "rank/"+i+"/loss",ob->query("bwdh/defeated") );
				break;
			}
		}
	}
	else if ( n<0 )
	{
		for(i=nRank;i>=1;i--)
		{
			if(query("rank/"+i+"/id")==id)break;
		}
		if( i<1 )
		{
			nRank ++;
			set( "nRank",nRank );
			set( "rank/"+nRank+"/name",ob->query("name") );
			set( "rank/"+nRank+"/id",ob->query("id") );
			set( "rank/"+nRank+"/win",ob->query("bwdh/win") );
			set( "rank/"+nRank+"/loss",ob->query("bwdh/defeated") );
			return;
		}
		set( "rank/"+i+"/name",ob->query("name") );
		set( "rank/"+i+"/id",ob->query("id") );
		set( "rank/"+i+"/win",ob->query("bwdh/win") );
		set( "rank/"+i+"/loss",ob->query("bwdh/defeated") );
	}
	else // just move this guy to the end
	{
		for(i=1;i<=nRank;i++)
		{
			if(query("rank/"+i+"/id")==id)break;
		}
		if( i>nRank )
		{
			nRank ++;
			set( "nRank",nRank );
			set( "rank/"+nRank+"/name",ob->query("name") );
			set( "rank/"+nRank+"/id",ob->query("id") );
			set( "rank/"+nRank+"/win",ob->query("bwdh/win") );
			set( "rank/"+nRank+"/loss",ob->query("bwdh/defeated") );
			return;
		}

		for(i=i;i<nRank;i++)
		{
			set( "rank/"+i+"/name",query("rank/"+(i+1)+"/name") );
			set( "rank/"+i+"/id",query("rank/"+(i+1)+"/id") );
			set( "rank/"+i+"/win",query("rank/"+(i+1)+"/win") );
			set( "rank/"+i+"/loss",query("rank/"+(i+1)+"/loss") );

		}
		
		set( "rank/"+i+"/name",ob->query("name") );
		set( "rank/"+i+"/id",ob->query("id") );
		set( "rank/"+i+"/win",ob->query("bwdh/win") );
		set( "rank/"+i+"/loss",ob->query("bwdh/defeated") );
	}
}

int do_start(string arg)
{
	object me = this_player();
	int age;

	if (!wizardp(me)) {
					 tell_object(me,"你不是巫师，不能发动比武大会！\n");
					 return 1;
		  }

	if (!arg || sscanf(arg, "%d", age)!=1)
		  {
					 tell_object(me,"usage: start age\n");
					 return 1;
		  }
	if(query("start"))
		{
					 tell_object(me,"比武已经开始了，如要终止，请用STOP命令。\n");
					 return 1;
		}

	this_object()->set("age",age);
	this_object()->set("start",1);
	this_object()->set("nRank",0);
	this_object()->delete("rank",0);
	message_vision("$N高声宣布：这个擂台现在开始"+age+"岁以下组比武大赛！\n",me);
	remove_call_out("auto_check");
	call_out("auto_check",30);
	return 1;
}

int do_stop(string arg)
{
	object ob1,ob2,me = this_player();
	int age;
	string host,challenger;

	if (!wizardp(me)) {
					 tell_object(me,"你不是巫师，不能终止比武大会！\n");
					 return 1;
		  }

	if(!query("start"))
		{
					 tell_object(me,"比武还没开始呢。如要开始，请用start age命令。\n");
					 return 1;
		}

        age = query("age");
	this_object()->delete("age");

	if( (host = query("host")) )
		ob1=find_player( query("host") );
	if(ob1 && ob1->query("bwdh/fighting") )
	{
		ob1->move(KANTAI);
	}

	if( ( challenger=query("challenger")) )
	{
	  ob2=find_player(challenger);
	  if( ob2 && ob2->query("bwdh/fighting") )
	 {
		ob2->move(KANTAI);
	 }
	}

	delete("start");
	delete("host");
	delete("challenger");
	delete("fighting");

	message_vision("$N高声宣布："+age+"岁以下组比武大赛现在结束！\n",me);
	return 1;
}

int do_baoming()
{
	string msg, name;
	object me;
	string host,challenger,girl;
	int i, age;

	remove_call_out("auto_check");
	call_out("auto_check",0);

	me = this_player();
	age = me->query("age");

	if(this_object()->query("start")!=1)
	{
	        tell_object(me,"对不起，现在没有比武大赛！\n");
		return 1;
	}


	if( me->query("age") > this_object()->query("age") )
	{
	  	tell_object(me,"主持人对你说： 对不起，这个擂台专门进行"+query("age")+"岁以下组比武大赛，你已经超龄！\n");
		return 1;
	}

	if( (age < 25 && me->query("combat_exp") < ( query("age")-15 ) * 4000 ) ||
	    (age > 24 && me->query("combat_exp") < ( query("age")-15 ) * 8000 ) 
	 )
	{
	  	tell_object(me,"主持人对你说： 武功这么差，你当武林大会是街头把戏呀？回去好好练吧！\n");
		return 1;
	}



	if( me->query("bwdh/defeated") >= 5 )
	{
	  	tell_object(me,"主持人对你说： 你这个连输五场的败将，回家好好练去吧！\n");
		return 1;
	}

	if( query("fighting"))
	{
		tell_object(me,"主持人对你说： 现在有人正在比武，等会儿再报名！\n");
		return 1;
	}


	if( !(host=query("host")) )
	{
		name = me->query("name")+"("+me->query("id")+")";
		set("host",me->query("id") );
		host = me->query("id");

		remove_call_out("let");
		call_out("let",0,me->query("id") + " play " + me->query("id"));
		message_vision("主持人说： 好，现在$N是擂主！\n", me);
		delete_temp("no_challenger");
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return 1;
	}



	name = me->query("name")+"("+me->query("id")+")";
	set("challenger",me->query("id") );
	challenger = me->query("id");

	remove_call_out("let");
	call_out("let",0,me->query("id") + " play " + me->query("id"));

	remove_call_out("start");
	call_out("start",30,host,challenger);
	message_vision("主持人说： 好，$N许参加比赛！\n", me);

	delete_temp("no_challenger");
	set("fighting",1);
	me->set("bwdh/fighting",1);
	remove_call_out("auto_check");
	remove_call_out("start");
	call_out("start",25,host,challenger);
	return 1;
}

int start(string host,string challenger)
{
	object ob1,ob2;
	ob1=find_player(host);
	ob2=find_player(challenger);


	if( ob1 && ob2 && ob1->query("bwdh/fighting") && ob2->query("bwdh/fighting") )
	{
		message_vision(HIR"一声锣响，$N和$n比赛开始。\n"NOR,ob1,ob2);
		ob1->kill_ob(ob2);
		ob2->kill_ob(ob1);
		ob1->set("bwdh/fighting",1);
		ob2->set("bwdh/fighting",1);
		set("fighting",1);
	}

	remove_call_out("auto_check");
	call_out("auto_check",20);
}



int auto_check()
{
		  object ob1,ob2;
		  object me,ob;
		  mapping boy;
		  int i, *times;
		  string host,girl,challenger,name;

		  if( !query("start") )
				return 0;

		  if( !( host=query("host")) )
		  {
                        tell_room( this_object(), "主持人高声说，"+query("age")+"岁以下比武大会正在进行，赶紧报名(baoming)呀！\n", this_object());
			delete("fighting");
			remove_call_out("auto_check");
			call_out("auto_check",20);
			return 0;
		  }	



		  set("fighting",1);

		  ob1=find_player(host);

			if(ob1 && ob1->query("bwdh/fighting") && living(ob1) && ob1->query("qi") > 0)
				message_vision("主持人高声说，$N是现在的擂主.\n", ob1);
			else 
			{
				delete("host");
				ob1->revive(1);
				ob1->move(KANTAI); // move out will restore data
				message_vision(RED"$N守擂失败，被抬下擂台.\n"NOR, ob1);
				ob1->set("bwdh/defeated",1+ob1->query("bwdh/defeated"));
				sort_rank(ob1,-1);
				ob1->save();
				delete("fighting");
			}

	  if( ( challenger=query("challenger") ) )
		{
				  ob2=find_player(challenger);
				  if( ob2)
				  {
					 if( !( host=query("host")) )
					  if( living(ob2) && ob2->query("bwdh/fighting") && !ob2->is_ghost() )
					 {
					   set("host",challenger);
					   delete("challenger");
					   host = challenger;
					   ob2->set("bwdh/win",1+ob2->query("bwdh/win") );
					   ob2->set("bwdh/once",1);
					   sort_rank(ob2,1);
					   full_all(ob2);	
					   message_vision(HIG"主持人高声说，$N艺高一筹，将$n打下擂台，是现在的擂主. 哪位好汉或者女英雄有种就上呀！\n"NOR, ob2,ob1);
					   remove_call_out("auto_check");
				           call_out("auto_check",1);
					   set("fighting",0); // host exchange, so no fighting

					   return 1;
					 }

					  if( !(living(ob2) ) )
					  {
						delete("challenger");
						ob2->revive(1);
						ob2->move(KANTAI);
						message_vision(RED"$N挑战$n失败，被抬下擂台.\n"NOR, ob2,ob1);
						ob2->set("bwdh/defeated",1+ob2->query("bwdh/defeated"));
					        ob2->save();
						sort_rank(ob2,-1);

						set("fighting",0);

						 if( ( host=query("host") ) && userp(ob1) && living(ob1) && !ob1->is_ghost() ) //host win twice, out to rest
						  {
							ob1->set("bwdh/win",1+ob1->query("bwdh/win") );
							message_vision("主持人高声说： $N打败$n，守擂成功！\n", ob1,ob2);
							if( ob1->query("bwdh/once") )
							{
								message_vision("主持人高声说： $N真是神勇，竟然连胜两场。请下场休息一会！\n", ob1);
								delete("host");
								ob1->move(KANTAI);
								message_vision(HIM"$N神彩飞扬地跳下擂台休息去了.\n"NOR, ob1);
								ob1->delete("bwdh/once");
								ob1->save();
								set("fighting",0);
							}
							else ob1->set("bwdh/once",1);

							full_all(ob1);	
							sort_rank(ob1,1);
                                                  }
					  }

				 }
				 else
				 {
					 // if this challenger not online, count as defeated

					 ob2 = new(USER_OB);
					 ob2->set("id", challenger);
					 if( !ob2->restore() ) 
					{
						destruct(ob2);
						// no this ppl, suicided ?
						return 0;
					 }
					 message_vision("主持人高声说： $N居然临战脱逃，按打败计。\n", ob2);

					delete("challenger");
					ob2->set("bwdh/defeated",1+ob2->query("bwdh/defeated") );
					sort_rank(ob2,-1);
					set("fighting",0);
					ob2->save();
					destruct(ob2);

						 // count host win once
						 if( ( host=query("host") ) && userp(ob1) && living(ob1) && !ob1->is_ghost() ) //host win twice, out to rest
						  {
							ob1->set("bwdh/win",1+ob1->query("bwdh/win") );
							if( ob1->query("bwdh/once") )
							{
								message_vision("主持人高声说： $N真是神勇，竟然连胜两场。请下场休息一会！\n", ob1);
								delete("host");
								ob1->move(KANTAI);
								message_vision("$N神彩飞扬地跳下擂台休息去了.\n", ob1);
								ob1->delete("bwdh/once");
								ob1->save();
							}
							else ob1->set("bwdh/once",1);

							full_all(ob1);	
							sort_rank(ob1,1);
                                                  }


					set("fighting",0); // no fighting
					remove_call_out("auto_check");
					call_out("auto_check",1);
					return 0;
				}
		}
		else 
		{
			set("fighting",0);
		}


		  if( query("fighting") )
		  {
			  remove_call_out("auto_check");
			  call_out("auto_check",10);
			  return 0;
		  }


	if( !( host=query("host") ) )
	{
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return 1;
	}

	// nobody come challenge

	set_temp("no_challenger",query_temp("no_challenger")+1);
	if( query_temp("no_challenger") >= 3 && ( host=query("host") ) && userp(ob1) && living(ob1) && !ob1->is_ghost() )
	{
		delete_temp("no_challenger");
		delete("host");
		message_vision(HIM"\n主持人高声说： $N真是威镇八方，居然无人敢上场挑战。这场算赢了.\n"NOR, ob1);
		ob1->move(KANTAI);
		message_vision(HIM"$N神彩飞扬地跳下擂台休息去了.\n"NOR, ob1);

		 // count host win once
		ob1->set("bwdh/win",1+ob1->query("bwdh/win") );
		sort_rank(ob1,1);

		remove_call_out("auto_check");
		call_out("auto_check",30);
		return 1;
	}

	if( query_temp("no_challenger") >= 2 )
	  {
		message_vision(HIY"主持人高声说，如果再过一会儿还没有人敢上来挑战的话，就算$N赢了.\n"NOR, ob1);
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return 1;
	  }	

	message_vision(HIW"主持人高声说，$N艺盖群雄，是现在的擂主，哪位豪杰上来挑战呀？\n", ob1);

	remove_call_out("auto_check");
	call_out("auto_check",30);
	
	return 1;
}



int let(string arg)
{
  object ob;
  string pl1, pl2;
  object room = this_object();
  object *inv;
  object *old_basket, *basket;
  object cangku;
  int i;

	if(!arg) return 0;
	if(sscanf(arg, "%s play %s", pl1, pl2) != 2) {
		pl1 = arg;
		pl2 = arg;
	}

	ob = find_player(pl1);
	if(!ob)return 0;
	ob->save();

	inv = all_inventory(ob);
  	basket = allocate(sizeof(inv));

  	cangku = find_object(CANGKU);
  	if (! objectp(cangku)) {
	    	cangku = load_object(CANGKU);
    		if (!objectp(cangku)) {
      			message_vision("$N请告诉 wiz: cangku not found\n", ob);
      			return 0;
    		}
  	}


	for (i=0; i<sizeof(inv); i++) {
	    	if (! inv[i]->query_autoload()) 
		{ // leave yudi etc.
		      basket[i] = inv[i];
		      inv[i]->move(cangku);
		      message_vision("$N将一"+
		        inv[i]->query("unit")+
		        inv[i]->query("name")+"交给主持人。\n", ob);
		}else{
	      		basket[i] = 0;
		}
	  }

  	old_basket=cangku->query("basket/"+ob->query("id"));

  	if (arrayp(old_basket)) basket = basket + old_basket;
  	cangku->set("basket/"+ ob->query("id"), basket);

	message_vision("$N进入擂台。\n", ob);

	ob->move(LEITAI);

	message_vision("$N进入擂台。\n", ob);
	
	tell_object(ob, "主持人告诉你" + RANK_D->query_respect(ob)+
								"，请从武器架上取武器(look jia; get armor from jia and get weapon from jia).\n");
	full_all(ob);
	ob->set("bwdh/fighting",1);
	delete_temp("no_challenger");
	return 1;
}



void full_all(object me)
{
	  if( !living(me) ) me->revive(0);
	  me->set("eff_jing", (int)me->query("max_jing"));
	  me->set("jing", (int)me->query("max_jing"));
	  me->set("eff_qi", (int)me->query("max_qi"));
	  me->set("qi", (int)me->query("max_qi"));
	  me->set("jingli", (int)me->query("max_jingli"));
	  me->set("neili", (int)me->query("max_neili"));
	  me->set("food", (int)me->max_food_capacity());
	  me->set("water", (int)me->max_water_capacity());
	  me->remove_all_killer();
          me->clear_condition();
}


