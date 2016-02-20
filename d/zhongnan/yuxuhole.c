//Cracked by Roath
// road: /zhongnan/yuxuhole.c

#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short","玉虚洞");

		  set("long",@LONG
这玉虚洞为全真教前辈闭关修行之处。据闻全真七子就是在此领悟出
全真教的不传之秘：七星聚会。墙上刻有一副石画，画中人仙风道骨，他
眉宇间隐隐一股英侠正气。只见他腰悬长剑，一袭青袍似在风中轻轻飘动，
令人为之心折。神案上香炉里插着三柱清香，香烟袅袅上升，散发着一股
檀香味。
LONG);

		  set("exits",([ "out" : __DIR__"yushuidong",
							 ])
			  );
		  set("cost",1);

			set("objects", ([
//				 __DIR__"npc/wang-zd" : 1,
			 ]));

	 setup();
}

void init()
{
		  add_action("do_ketou","ketou");
		  add_action("do_dianhua","dianhua");
}


int do_ketou(string arg)
{
		  object paper, me = this_player();
		  int level1, level2, level3;

		  message_vision("$N恭恭敬敬地在神案前的团蒲上跪了下来，对着神位磕了三个响头。\n", me);
		  me->receive_damage("qi", random(30), "力尽气绝而死");
		  me->start_busy(1);

		  if ( me->query("qi") <= 50 )
					 write("你只觉得脑子有些昏昏沉沉的。\n");
		  if ( me->query("qi") <= 30 )
					 write("你觉得天旋地转，似乎马上便要晕去。\n");

		  if ( !(me->query("family/family_name")=="全真教") ) return 1;

		  level1 = me->query_skill("xiantian-gong", 1);
		  level2 = me->query_skill("taoism", 1);
		  level3 = me->query_skill("quanzhen-jian", 1);

		  if ( level1>300 && level2>300 && level3>300 && random(50) == 1 && !me->query_temp("quanzhen/shentong_paper") ) {
					 paper=new(__DIR__"obj/shentong_paper");
					 if ( !paper ) return 1;

					 add("paper_count", -1);
					 me->set_temp("quanzhen/shentong_paper", 1);

					 message_vision(HIG"$N在团蒲上重重地一磕，团蒲的边上忽然裂了开来，露出一小段丝绢。\n"NOR,me);
					 write("你仔细的将丝绢抽出一看，上面密密麻麻的记载了练功心法，似乎与先天\n");
					 write("功一脉相承，但却更加深奥。\n");
					 message_vision("$N连忙密笈收好。\n",me);
					 paper->move(me);
		  }

		  return 1;
}

int do_dianhua(string arg)
{
		  object paper, me = this_player();
		  object feng;
		  object here = environment(me);

		  if(!arg)return notify_fail("你要点化谁?\n");

		  /*if( arg != "feng" && arg != "ouyang" && arg != "ouyang feng" ) return notify_fail("此人无须你点化。\n");
*/

		  if(me->is_busy())return notify_fail("你在忙着呢。\n");

		  feng = present(arg,here);

		  if(!feng)return notify_fail("你要点化谁?\n");

		  if( feng->query("race") != "人类" )return notify_fail("可惜它不懂人事。\n");

	     	  if(userp(feng)|| feng->query("shen") > -100000 )return notify_fail("此人无须你点化。\n");
		  feng->set("combat_exp",me->query("combat_exp")+random(me->query("combat_exp")));
		  feng->set_temp("apply/attack",100+random(200));
		  feng->set_temp("apply/damage",100+random(200));
		  feng->set("jiali",50);
			
		  if( feng->query("combat_exp")*3 < me->query("combat_exp")*2 )
				return notify_fail("此人武功太差，无法和你切磋。\n");
		  if(!living(feng)) return notify_fail("你得等人家醒了才行。\n");


		  message_vision("$N对着$n口诵道德经。\n", me,feng);
		  me->receive_damage("jing", random(150), "精尽气绝而死");
		  me->start_busy(1+random(2));

		  if ( me->query("jing") <= 50 )
					 write("你只觉得脑子有些昏昏沉沉的。\n");
		  if ( me->query("jing") <= 20 )
					 write("你觉得天旋地转，似乎马上便要晕去。\n");

		  if ( !(me->query("family/family_name")=="全真教") ) return 1;

		  if( random(10) == 0 )
		  {
			  message_vision("$N很不耐烦地说：你这臭道士，这么烦，看招！\n", feng,me);
			  feng->kill_ob(me);
		  }
		  else if( random(7) == 0 )
		  {
			  message_vision("$N忽然点了点头，说：这一段好象有点道理。\n", feng,me);
			  feng->command("halt");
			  feng->remove_all_killer();

			  if( random(feng->query("combat_exp")) > me->query("combat_exp")/4 )
			  {
				 if( me->query_skill("taoism",1) < 400 )
				 {
				  me->improve_skill("taoism",800+random(1000));
				  write("你对道学心法好象有些领悟。\n");
				 }
				 else write("你的道学心法已经古今无比了。\n");
			  }
		  }
		  else if( random(1200)==0 )
		 {
			message_vision(HIY"$N趁你闭目摇头诵经的时候，偷偷溜走了
。\n", feng,me);      
			destruct(feng);
		 }

		  return 1;
}



