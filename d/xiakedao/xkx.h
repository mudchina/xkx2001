//Cracked by Roath
// xiakedao/xkx.h

string* bskills = ({
	"force", 
	"dodge", 
	"sword", 
	"strike",
	"", 
	"", 
	"", 
	"", 
	"", 
	"", 
	"", 
	"", 
	"", });


//	"cuff", 
//	"claw",
//	"blade",
//	"throwing", 
//	"club",
//	"whip",
//	"finger", 
//	"stick",
//	"hand", });

string* askills = ({
	"taixuan-gong", 
	"liuxing-bu",
	"wugou-jianfa", 
	"wuyu-zhangfa", 
	"",
	"",
	"", 
	"",
	"", 
	"",
	"",
	"",
	"", });
int do_study(string arg)
{	object me = this_player();
	int check;

	if ( !arg )
		return notify_fail( "你想学什麽?\n");
	if ( arg != "wall" )
		return notify_fail( "老老实实 study wall 吧。\n");
	call_out("do_learn", 0, me, flag);
	return 1;
}

int do_learn(object me, int flag)
{	//object me = this_player();
	//string here, 
	int check;
	string bskill = bskills[flag-1];
	string askill = askills[flag-1];
	// 如果你经验不到250，或基本功不到10，就无法学侠客行功夫。
	if (bskill == "")
	{	write("你看了一会图谱，发觉无法从中再领悟什麽了。\n");
		return 1;
	}
	
	if (askill == "")
	{	write("你看了一会图谱，发觉无法从中再领悟什麽了。\n");
		return 1;
	}

	if (((int)me->query("combat_exp") < 250) || ((int)me->query_skill(bskill, 1) < 10))
	{	if ((int)me->query_skill(bskill, 1) > 20)
		{	write("你看了一会图谱，发觉已经无法从中再领悟什麽了。\n");
			return 1;
		}
		check = (int)me->query_skill(bskill,1)*(int)me->query_skill(bskill,1)*(int)me->query_skill(bskill,1);       
		if (check > (int)me->query("combat_exp") * 10)
		{	write ("你实战经验不足，无法领悟。\n");
			return 1;
		}
		if ((int)me->query("jing") < 30 ) 
		{	write("你精神无法集中。\n");
			return 1;
		}
		write("你领悟了" + to_chinese(bskill) + "方面的几个疑难。\n");
		me->improve_skill(bskill, me->query("int"));
		me->receive_damage("jing", 20, "心力交瘁死了");
		
	}
	else
	{	if ((int)me->query_skill("literate", 1) == 0)
		{	write("你一字不识，看不懂墙上的注解。\n");
			return 1;
		} 
		//if (((int)me->query("learned") > 0) && ((int)me->query("learned") != flag))
		//{	write("你已学侠客行中其他一门功夫，就不能再学别的了。\n");
		//	return 1;
		//}

		if ((int)me->query_skill(askill, 1) > 20 || askill == "")
		{	write("你看了一会图谱，发觉已经无法从中再领悟什麽了。\n");
			return 1;
		}
		check = (int)me->query_skill(askill,1)*(int)me->query_skill(askill,1)*(int)me->query_skill(askill,1);
		if (check > (int)me->query("combat_exp") * 10)
		{	write ("你实战经验不足，无法领悟。\n");
			return 1;
		}
		if ((int)me->query("jing") < 30 ) 
		{	write("你精神无法集中。\n");
			return 1;
		}
		
		//if ((int)me->query_temp(here) == 0)
		//{	write("你一字不识只好看着石壁上的画谱发呆。\n");
		//	me->set_temp(here, 1);
		//}
		write("你领悟了" + to_chinese(askill) + "中的几个疑难。\n");
		me->set("learned", flag);
		me->improve_skill(askill, me->query("int"));
		if (me->query_skill(askill, 1) == 1)
		{	write("你可以用enable "+bskill + " " +askill+"来激发这种特殊技能。\n");
			if (flag == 1)
			{	write("你的太玄功学到第十级而且内力超过十点时就可运气疗伤(yun heal)。\n");
				write("等到了第十五级内力有二十点时就可以为他人疗伤(yun heal xxx)。\n");
				write("然而其他门派的内功却需要较高等级才有以上的功能。\n");
				write("在你的内力超过二十点时你还可以exert regenerate 来恢复自己的精\n");
				write("exert recover 恢复自己的气，exert refresh 恢复自己的精力。\n");
			}
		}
		me->receive_damage("jing", 20, "心力交瘁死了");
	}

	return 1;
}
