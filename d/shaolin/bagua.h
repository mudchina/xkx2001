//Cracked by Roath
// Room: /d/shaolin/bagua.h
// Date: YZC 96/01/19

#include <ansi.h>

string* dirs = ({
	"坎", "坤", "离", "乾",
	"艮", "震", "巽", "兑"
	});

int check_dirs(object me, string dir)
{
	int i, bc, count;
	if (member_array(dir, dirs) != -1)
	{
		bc = me->query_temp("bagua/count");

		switch (dir)
		{
		case "坎":
			if (bc == 0 || bc == 13 || bc == 17)
				me->set_temp("bagua/count",  bc + 1);
			else    me->delete_temp("bagua/count");
			
			tell_object(me, HIR "\n四周朦胧一片，似乎天地都倒转了过来，你只觉得头脑中也是一阵晕眩....\n\n" NOR);
			me->receive_damage("jing",50);
			break;
		case "坤":
			me->delete_temp("bagua/count");
			break;
		case "离":
			if (bc == 1 || bc == 12 )
				me->set_temp("bagua/count",  bc + 1);
			else    me->delete_temp("bagua/count");

			tell_object(me, HIR "\n薄雾从石缝中升起，紧紧地把你裹了起来，你只觉全身内力寸寸消散！\n\n" NOR);
			if ((int)me->query("neili") >= 50)
				me->add("neili", -50);
			else 	me->set("neili", 0);	
			break;
		case "乾":
			if (bc == 8 )
				me->set_temp("bagua/count",  bc + 1);
			else    me->delete_temp("bagua/count");

			tell_object(me, HIR "\n扑通一声，你一下陷入齐腰深的污泥里，里面仿佛有无数小虫子抽吸着着你的真气！\n\n" NOR);
			me->receive_damage("qi", 50);
			break;
		case "艮":
			if (bc == 3 || bc == 4 || bc == 15)
				me->set_temp("bagua/count",  bc + 1);
			else    me->delete_temp("bagua/count");

			tell_object(me, HIR "\n你只觉头脑空荡荡的，似乎有什么东西离你而去，却又说不清是什么东西....\n\n" NOR);
			if ((int)me->query("combat_exp") >= 50)
				me->add("combat_exp", -50);
			else	me->set("combat_exp", 6);	
			break;
		case "震":
			if (bc == 2 || bc == 7 || bc == 9 )
				me->set_temp("bagua/count",  bc + 1);
			else    me->delete_temp("bagua/count");

			tell_object(me, HIR "\n岩壁间传出一阵阵闷雷，突然半空中窜出一道闪电，正中你的头顶！\n\n" NOR);
			me->unconcious();
			break;
		case "巽":
			if (bc == 6 || bc == 11 )
				me->set_temp("bagua/count",  bc + 1);
			else	me->delete_temp("bagua/count");

			tell_object(me, HIR "\n忽然间眼前黑影闪动，几十把飞刀斜斜射过，在你身上留下了长长的血痕！\n\n" NOR);
			me->receive_wound("qi", 50);
			break;
		case "兑":
			if (bc == 5 || bc == 10 || bc == 14 || bc == 16)
				me->set_temp("bagua/count",  bc + 1);
			else	me->delete_temp("bagua/count");

			tell_object(me, HIR "\n只听乒的一声，一只巨大的木锤从天而降，打得你眼前顿时金星乱冒！\n\n" NOR);
			me->receive_wound("jing", 50);
			break;
		default:
			me->delete_temp("bagua/count");
			break;
		}

		if (dir == "坤")
		{
			me->delete_temp("bagua");
		}
		else
		{
			count =  me->query_temp("bagua/"+dir);
			count++;
			me->set_temp("bagua/"+dir, count);
			if (count > 13)
			{
				me->delete_temp("bagua");
				me->move(__DIR__"jianyu");
				return (1);
			}
		}
	}

/*
	write("* " + me->query_temp("bagua/northwest"));
	write(" " + me->query_temp("bagua/north"));
	write(" " + me->query_temp("bagua/northeast") +"\n");
	
	write("* " + me->query_temp("bagua/west"));
	write(" " + me->query_temp("bagua/count"));
	write(" " + me->query_temp("bagua/east") +"\n");
	
	write("* " + me->query_temp("bagua/southwest"));
	write(" " + me->query_temp("bagua/south"));
	write(" " + me->query_temp("bagua/southeast") +"\n");
*/
	return (0);
}
