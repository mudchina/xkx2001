//Cracked by Roath
// /d/bwdh/kantai.h
// 赤火龙坛
// by sdong 09/25/98

#include <ansi.h>
inherit ROOM;
#define BOARD "/clone/board/bwboard"
#include "sjsz_room.h"
string long_desc();
int do_withdraw(string arg);
int do_plant(string arg);

void create()
{
	set("short", HIR"赤火龙坛"NOR);

	set( "long", (: long_desc :) );

	set("exits", ([
		"west" : "/d/bwdh/sjsz/wting",
		"east" : "/d/bwdh/sjsz/room_01",
	]));

	create_room();
	setup();
}


void init()
{
  init_room();
  add_action("do_withdraw", "ba");
  add_action("do_withdraw", "withdraw");
  add_action("do_plant", "plant");
}


string long_desc()
{
  	string desc,temp;
	int nRank,i,j;

	if( query("flag") >0 )
	  	desc  = HIY"

		           /I______________I\\               "+HIC"|"+HIR"=====|"+HIY"
		         //||||||||||||||||||\\\\             "+HIC"|"+HIR" 武   |"+HIY"
		     T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T         "+HIC"|"+HIR"=====|"+HIY"
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIR"【赤火龙坛】"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIC"|"+HIY"
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"|"+HIY"
			/||||||||||||||||||||||\\            "+HIC"|"+HIY"
		    T\\//IIIIIIIIIIIIIIIIIIIIIIII\\\\/T        "+HIC"|"+HIY"
	            ^^^^"+HIG"||"+HIY"^^^^^^^^^^^^^^^^^^^^"+HIG"||"+HIY"^^^^        "+HIC"|"+HIG"
			||                    ||            "+HIC"|"+HIW"
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIR"
             ||                                          ||
\n"NOR;
	else
	  	desc  = HIY"

		           /I______________I\\               
		         //||||||||||||||||||\\\\            
		     T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T       
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIR"【赤火龙坛】"NOR+HIY"^^^"+HIG"||"+HIY"^^^^
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"
			/||||||||||||||||||||||\\            
		    T\\//IIIIIIIIIIIIIIIIIIIIIIII\\\\/T
	            ^^^^"+HIG"||"+HIY"^^^^^^^^^^^^^^^^^^^^"+HIG"||"+HIY"^^^^
			||                    ||            
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIR"
             ||                                          ||
\n"NOR;

  	return desc;
}

int do_withdraw(string arg) {
    object flag, me=this_player(), *obj;
    string type;
    int i, bGuarded = 0;

    if(!arg) return 0;
    if(me->is_busy()) return 0;
    if ( arg != "flag" && arg != "qi") return 0;

	if ( query("flag") <= 0 ) return notify_fail("没旗可拔。\n");
	if ( me->query("sjsz/red") > 0 ) return notify_fail("偷自己的旗？\n");
	
	message_vision(HIY"$N向旗杆跃起，想一把拔下旗子。\n"NOR, me);

	obj = all_inventory(environment(me));
	for(i=0;i<sizeof(obj);i++)	 {
			if( living(obj[i]) &&
			obj[i]->query("sjsz/team_name") != me->query("sjsz/team_name") 
			&& obj[i]->query("env/invisibility") < 1
				)
			{
				obj[i]->kill_ob(me);
				message_vision(HIR"$N急对$n喝道：“$n竟敢偷旗，看招！”\n"NOR, obj[i],me,me);
				me->kill_ob(obj[i]);
				bGuarded = 1;
			}
	 }

	 if( !bGuarded )
	 {
	    flag = new("/d/bwdh/sjsz/obj/flag");
	    flag->set_name(query("team_name")+"大旗", ({ "flag" }) );
	    if(flag->move(me)) {
        	message_vision(HIG"$N一把扯下了大旗，高高举起。\n"NOR, me);
		set("flag",0);
	    } else {
        	destruct(flag);
	    }
	   CHANNEL_D->do_channel(this_object(), "rumor",
		"听说"+me->name()+"夺走了"+query("team_name")+"的大旗！" );		

	}
	

    return 1;
}

int do_plant(string arg) {
    object flag, me=this_player(), *obj;
    string type;
    int i, bGuarded = 0;
    object board;
    mapping entryA, entryB;
    int scoreA,scoreB;

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("找不到团体赛成绩版。\n");
	 }
	 entryA = board->query("team/" + board->query("east"));
	 entryB = board->query("team/" + board->query("west"));

	 if(!entryA || !entryB )return notify_fail("现在没有比赛。\n");

	 scoreA = entryA["this_score"];
	 scoreB = entryB["this_score"];

    if(!arg) return 0;
    if(me->is_busy()) return 0;
    if ( arg != "flag" && arg != "qi") return 0;

	if ( query("flag") > 0 ) return notify_fail("旗杆上已有旗了。\n");
	if ( !me->query("sjsz/red") ) return notify_fail("这可不是你的大本营。\n");

	flag= present("flag",me );
	if(!flag)return notify_fail("你手中没旗可以插。\n");

	if( flag->query("name") != query("team_name")+"大旗"  ) 
		return notify_fail("自己的大本营怎么能插人家的旗？\n");

	
	message_vision(HIY"$N把大旗哗啦啦展开，插上了旗杆。\n"NOR, me);

	destruct(flag);

	set("flag",1);

	CHANNEL_D->do_channel(this_object(), "rumor",
		"听说"+me->name()+"将大旗插回了大本营！" );		

	me->add("sjsz/flag",1);
	me->add("sjsz/bw_score",1000);
	me->add("sjsz/this_flag",1);
	me->add("sjsz/this_score",1000);
	if( me->query("sjsz/white") )scoreA += 1000;
	else if( me->query("sjsz/red") )scoreB += 1000;
	entryA["this_score"]=scoreA;
 	entryB["this_score"]=scoreB;
	board->set("team/" + board->query("east"),entryA);
	board->set("team/" + board->query("west"),entryB);
	board->save();

    return 1;
}


