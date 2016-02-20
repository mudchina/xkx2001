//Cracked by Roath
// 看台
// by sdong 09/25/98

#include <ansi.h>
inherit ROOM;
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

#define LEITAI "/d/bwdh/leitai"
#define KANTAI "/d/bwdh/kantai"
#define CANGKU "/d/bwdh/cangku"

void create()
{
	set("short", "看台");
	set("long", (: long_desc :));
	set("valid_startroom", 1);

	set("no_fight", 1);
	set("no_practice", 1);

	set("exits", ([
		"up" : __DIR__"leitai",
		"out": "/d/bwdh/square",
	]));

	set("objects", ([
		__DIR__"npc/xiaolongnu":1,
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
        message_vision("$N把从擂台取的"+inv[i]->query("name")+"还给主持人。\n", 
        player);
        destruct(inv[i]);
    }
  
  cangku = find_object(CANGKU);
  if (! objectp(cangku)) {
    cangku = load_object(CANGKU);
    if (!objectp(cangku)) {
      message_vision("$N请告诉 wiz: cangku not found\n", player);
      return 0;
    }
  }

  player->restore();	

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
  player->delete("bwdh/once");

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
		if( wizardp(me) || me->query_temp("organizer") ) return 1;
		else return notify_fail("你不能自己上去。\n");
	}

	if( dir=="out" ) {
		if( wizardp(me) || !me->query_temp("admitted") ) return 1;
		else
		{
			return notify_fail("你是选手,现在不能离开。\n");
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
	else
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
	message_vision("$N高声宣布：这个擂台现在开始"+age+"岁以下组比武大赛！\n",me);
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
		ob1->delete("bwdh/fighting");
		ob1->delete("bwdh/admitted");
	}

	if( ( challenger=query("challenger")) )
	{
	  ob2=find_player(challenger);
	  if( ob2 && ob2->query("bwdh/fighting") )
	 {
		ob2->move(KANTAI);
		ob2->delete("bwdh/fighting");
		ob2->delete("bwdh/admitted");
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
	int i, age = 0;

	remove_call_out("auto_check");
	call_out("auto_check",0);

	me = this_player();

	if(this_object()->query("start")!=1)
	{
	        tell_object(me,"对不起，现在没有比武大赛！\n");
		return 1;
	}


	if( me->query("age") >= this_object()->query("age") )
	{
	  	tell_object(me,"主持人对你说： 对不起，这个擂台专门进行"+age+"岁以下组比武大赛，你已经超龄！\n");
		return 1;
	}


	if( me->query("bwdh/admitted") )
	{
	  	tell_object(me,"主持人对你说： 你已经报名。急什么？到时会叫你上！\n");
		return 1;
	}

	if( me->query("bwdh/defeated") >= 3 )
	{
	  	tell_object(me,"主持人对你说： 你这个连输三场的败将，回家好好练去吧！\n");
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

	if( query_temp("fighting"))
	{
		me->set("bwdh/admitted",1);
		tell_object(me,"主持人对你说： 好。现在有人正在比武，轮到你时会叫你！\n");
		set("boy/" + time(), me->query("id") );
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
	message_vision("一声锣响，$N和$n比赛开始。\n",ob1,ob2);

	if(ob1 && ob2)
	{
		ob1->kill_ob(ob2);
		ob2->kill_ob(ob1);
		ob1->set("bwdh/fighting",1);
		ob2->set("bwdh/fighting",1);
	}
	else
	{
		message_vision("$N和$n有人断线了。\n",ob1,ob2);
		remove_call_out("start");
		call_out("start",10,host,challenger);
	}

	set("fighting",1);
	remove_call_out("auto_check");
	call_out("auto_check",30);
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
			remove_call_out("auto_check");
			call_out("auto_check",30);
			return 0;
		  }	



		  set("fighting",1);

		  ob1=find_player(host);

			if(ob1 && ob1->query("bwdh/fighting") && living(ob1) )
				message_vision("主持人高声说，$N是现在的擂主.\n", ob1);
			else 
			{
				delete("host");
				ob1->revive(1);
				ob1->move(KANTAI); // move out will restore data
				message_vision("$N被抬下擂台.\n", ob1);
				if( ob1->query("bwdh/once") )
				{
					ob1->set("bwdh/win",1+ob1->query("bwdh/win"));
				}
				ob1->set("bwdh/defeated",1+ob1->query("bwdh/defeated"));
				sort_rank(ob1,-1);
				ob1->save();
				set("fighting",0);
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
					   message_vision("主持人高声说，$N艺高一筹，是现在的擂主. 哪位好汉或者女英雄有种就上呀！\n", ob2);
					   remove_call_out("auto_check");
				           call_out("auto_check",1);
					   return 1;
					 }

					  if( !(living(ob2) ) || ob2->is_ghost() || ob2->query("qi") <= 0 || !ob2->query("bwdh/fighting") )
					  {
						delete("challenger");
						ob2->revive(1);
						ob2->move(KANTAI);
						message_vision("$N被抬下擂台.\n", ob2);
						ob2->set("bwdh/defeated",1+ob2->query("bwdh/defeated"));
						sort_rank(ob2,-1);

						set("fighting",0);

						 if( ( host=query("host") ) && userp(ob1) && living(ob1) && !ob1->is_ghost() ) //host win twice, out to rest
						  {
							ob1->set("bwdh/win",1+ob1->query("bwdh/win") );
							if( ob1->query("bwdh/once") )
							{
								message_vision("主持人高声说： $N真是神勇，竟然连胜两场。请下场休息一会！\n", ob1);
								delete("host");
								ob1->move(KANTAI);
								message_vision("$N神彩飞扬地跳下擂台休息去了.\n", ob1);
								ob1->set("bwdh/win",2+ob1->query("bwdh/win") ); // when move to kantai, will retore data, so set 2 wins again
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
								ob1->set("bwdh/win",2+ob1->query("bwdh/win") ); // when move to kantai, will retore data, so set 2 wins again
							}
							else ob1->set("bwdh/once",1);

							full_all(ob1);	
							sort_rank(ob1,1);
                                                  }


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
			  //command("say 比武正在进行.\n");
			  ob1->kill_ob(ob2);
			  ob2->kill_ob(ob1);
			  remove_call_out("auto_check");
			  call_out("auto_check",20);
			  return 0;
		  }


	  if( (boy = query("boy")) )
	  {

		  times = keys(boy);
		  for(i = 0; i < sizeof(times); i++) {
			if(boy[times[i]] )
			 if( !(me = find_player( boy[times[i]] ) ) )
				continue;
			 break;
		  }

		 if( i < sizeof(times) )
		 {
	
		   map_delete(boy, times[i]);
		   if(objectp(me))
		   {
			host = query("host");
			ob2 = find_player(host);
			if(ob2)
			{
				message_vision("$N进入擂台和$n比武。\n",me,ob2 );
				delete_temp("no_challenger");
				set("challenger",me->query("id") );
				challenger = me->query("id");

				remove_call_out("let");
				call_out("let",0,me->query("id") + " play " + me->query("id"));
				tell_object(ob2,"有人上来和你比武了！\n");

				set("fighting",1);
				remove_call_out("auto_check");
				remove_call_out("start");
				call_out("start",25,host,challenger);
			}
			else // no host
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
			}
	
			return 1;
	          }
		}
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
		message_vision(HIM"\n主持人高声说： $N真是威镇八方，居然无人敢上场挑战。这场算$n赢了.\n\n"NOR, ob1,ob1);
		ob1->move(KANTAI);
		message_vision("$N神彩飞扬地跳下擂台休息去了.\n", ob1);

		 // count host win once
		ob1->set("bwdh/win",1+ob1->query("bwdh/win") );
		if( ob1->query("bwdh/once") )
		{
			ob1->set("bwdh/win",1+ob1->query("bwdh/win") ); // when move to kantai, will retore data, so set 1 win again
		}
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
      		basket[i] = inv[i];
	      	inv[i]->move(cangku);
      		message_vision("$N将一"+
        		inv[i]->query("unit")+
	        	inv[i]->query("name")+"交给主持人。\n", ob);
  	}
  	old_basket=cangku->query("basket/"+ob->query("id"));

  	if (arrayp(old_basket)) basket = basket + old_basket;
  	cangku->set("basket/"+ ob->query("id"), basket);

	ob->move(LEITAI);
	message_vision("$N进入擂台。\n", ob);
	
	tell_object(ob, "主持人告诉你" + RANK_D->query_respect(ob)+
								"，请从武器架上取武器(look jia; get armor from jia and get weapon from jia).\n");
	full_all(ob);
	ob->set("bwdh/fighting",1);
	return 1;
}


void full_all(object me)
{
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


