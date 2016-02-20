//Cracked by Roath
// /d/bwdh/square.c
// 看台
// by sdong 09/25/98
#include <localtime.h>
#include <ansi.h>
inherit ROOM;

string long_desc();
int do_start(string arg);
int do_stop(string arg);
int start(string host,string challenger);
int do_close_men();
int do_open_men(string arg);


void create()
{
    mixed *local;
    object *ob;
    local = localtime(time());

	set("short", HIR"武林大会大广场"NOR);
	set("long", (: long_desc :));
	set("valid_startroom", 1);

	set("no_fight", 1);
	set("no_practice", 1);


    if( local[LT_HOUR] == 2 || local[LT_HOUR] == 4 || 
		local[LT_HOUR] == 6 || local[LT_HOUR] == 8 || 
		local[LT_HOUR] >= 10 && local[LT_HOUR] <= 12 
		)
	{
  		set("exits", ([
		"1" : "/d/bwdh/kantai1",
		"2" : "/d/bwdh/kantai2",
		"3" : "/d/bwdh/kantai3",
		"4" : "/d/bwdh/kantai4",
		"5" : "/d/bwdh/kantai5",
		"6" : "/d/bwdh/kantai6",
		"7" : "/d/bwdh/kantai7",
		"8" : "/d/bwdh/kantai8",
		"out": "/d/city/kedian",
		"northup": "/d/bwdh/sjsz/gate",
                "north": "/d/bwdh/sjsz2/gate",
                "south": "/d/bwdh/sjsz3/gate",

			]));
	}
	else
	{
  		set("exits", ([
		"1" : "/d/bwdh/kantai1",
		"2" : "/d/bwdh/kantai2",
		"3" : "/d/bwdh/kantai3",
		"4" : "/d/bwdh/kantai4",
		"5" : "/d/bwdh/kantai5",
		"6" : "/d/bwdh/kantai6",
		"7" : "/d/bwdh/kantai7",
		"8" : "/d/bwdh/kantai8",
		"out": "/d/city/kedian",
			]));
	}

	setup();
}

void init()
{
	add_action("do_start", "start");
	add_action("do_stop", "stop");
	add_action("do_open_men", "open");	
	add_action("do_close_men", "close");
}

int do_open_men(string arg)
{
	object ob;
	object room;
	if ( !wizardp(this_player()) )
	  return notify_fail("你不是巫师。\n");

	if (query("exits/northup"))
	  return notify_fail("这扇门已经是打开的。\n");
	if (!arg || (arg != "men" ))
	  return notify_fail("你要打开什么？\n");
	set("exits/northup", "/d/bwdh/sjsz/gate");
	message_vision("$N用手指凌空一点，吱地一声，打开一道大门。\n", this_player());
	return 1;
}

int do_close_men()
{
	if ( !wizardp(this_player()) )
	  return notify_fail("你不是巫师。\n");

	if (!query("exits/northup"))
		return notify_fail("这扇门已经是关上的。\n");
	delete("exits/northup");
        delete("exits/north");
        delete("exits/south");


	message_vision("$N用手指凌空一点，大门慢慢地关上了。\n", this_player());
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
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIR"【武林大会】"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIC"|"+HIY"
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"|"+HIY"
			/||||||||||||||||||||||\\            "+HIC"|"+HIY"
		    T\\//IIIIIIIIIIIIIIIIIIIIIIII\\\\/T        "+HIC"|"+HIY"
	            ^^^^"+HIG"||"+HIY"^^^^^^^^^^^^^^^^^^^^"+HIG"||"+HIY"^^^^        "+HIC"|"+HIG"
			||                    ||            "+HIC"|"+HIW"
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIG"
             ||                                          ||
             ||  ________       龙 虎 板       ________  ||
             ||  |                                    |  ||
             ||  |                                    |  ||\n";

		

	nRank = 1;
	for ( i=1;i<=8;i++)
	{
		if ( ("/d/bwdh/kantai"+i+".c")->query("age") <= 0 
			|| ! (("/d/bwdh/kantai"+i+".c")->query("rank"))  ) continue;

		temp = ("/d/bwdh/kantai"+i+".c")->query("age") + "岁组冠军： ";
		temp += ("/d/bwdh/kantai"+i+".c")->query("rank/1/name") + "(";
		temp += ("/d/bwdh/kantai"+i+".c")->query("rank/1/id") + ") "; 
	
		desc += "             ||  |    ";
		desc += temp; 
		for(j=strlen(temp);j<=31;j++)
		{
			desc += " ";
		}

		desc += "|  ||\n"; 
		nRank ++;
	}

	for(i=nRank;i<=12;i++)
	{
		desc += "     	     ||  |                                    |  ||\n";
	}
  
	desc+="             ||  |____________________________________|  ||\n";
  	return desc;
}


int valid_leave(object me, string dir)
{

	if( dir=="out" ) {
		if( wizardp(me) || me->query("bwdh/defeated") >= 3 || !me->query("bwdh") ) return 1;
		else
		{
			return notify_fail("你是选手,现在不能离开。\n");
		}
	}

	return ::valid_leave(me, dir);

}


int do_start(string arg)
{
	object me = this_player();
	int age;

	if (!wizardp(me)) {
			 tell_object(me,"你不是巫师，不能发动比武大会！\n");
			 return 1;
		  }

	if(query("start"))
		{
		   tell_object(me,"比武已经开始了，如要终止，请用STOP命令。\n");
		   return 1;
		}

	this_object()->set("start",1);

	"/d/bwdh/kantai1.c"->do_start("25");
	"/d/bwdh/kantai2.c"->do_start("30");
	"/d/bwdh/kantai3.c"->do_start("35");
	"/d/bwdh/kantai4.c"->do_start("40");
	"/d/bwdh/kantai5.c"->do_start("45");
	"/d/bwdh/kantai6.c"->do_start("55");
	"/d/bwdh/kantai7.c"->do_start("65");
	"/d/bwdh/kantai8.c"->do_start("99");
	"/d/city/kedian.c"->do_open_men("men");
	

	message_vision("$N高声宣布：现在开始比武大赛！\n",me);
	CHANNEL_D->do_channel(me, "chat*","高声宣布：武林大会现在开始！大家请从扬州客店入场。\n");
	CHANNEL_D->do_channel(me, "xkx","武林大会现在开始！大家请从扬州客店入场。\n");
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

	delete("start");

	"/d/bwdh/kantai1.c"->do_stop("25");
	"/d/bwdh/kantai2.c"->do_stop("30");
	"/d/bwdh/kantai3.c"->do_stop("35");
	"/d/bwdh/kantai4.c"->do_stop("40");
	"/d/bwdh/kantai5.c"->do_stop("45");
	"/d/bwdh/kantai6.c"->do_stop("55");
	"/d/bwdh/kantai7.c"->do_stop("65");
	"/d/bwdh/kantai8.c"->do_stop("99");
	"/d/city/kedian.c"->do_close_men("men");
	message_vision("$N高声宣布：比武大赛现在结束！\n",me);
	CHANNEL_D->do_channel(me, "chat*","高声宣布：武林大会现在结束！大家请从扬州客店退场。\n");
	CHANNEL_D->do_channel(me, "xkx","武林大会现在结束！大家请从扬州客店退场。\n");
	return 1;
}

