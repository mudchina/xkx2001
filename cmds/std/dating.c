//Cracked by Roath
// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, man, *all, *inv;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp;
	int i, j, cost;

	seteuid(getuid());

	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++) {
		if( living(all[i]) && !userp(all[i]) && all[i]->query("race") == "人类") {
			man = all[i];
			break;
		}
	}

	if ( (!(fam = me->query("family")) || fam["family_name"] != "丐帮") )
		return notify_fail("只有乞丐才能打探别人的技能！\n");

	if ( !objectp(man) )
		return notify_fail("周围没人能帮你去了解别人的消息！\n");

	if ( me->query("rank") <= 1 )
		return notify_fail("你只是个不入流的小乞丐，对方肯定什么都不会告诉你！\n");

	if ( me->query_skill("checking",1) < 10 )
		return notify_fail("你的打探本领尚未纯熟，无法了解别人的消息！\n");

	if ( !arg )
		return notify_fail("你要打听谁的消息？\n");

	if ( present(arg, environment(me)) )
		return notify_fail("你要打听的人就在边上，在这里问不大妥当吧？\n");

	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("你要打听谁的消息？\n");

	if ( ob == me )
		return notify_fail("你没这麽笨吧，要别人告诉你自己的情况？\n");

	cost = me->query("max_jing")/(me->query_skill("checking",1)/10) - 10;

	if ( me->query("jing") <= cost )
		return notify_fail("现在你太累了，无法去打听别人的消息。\n");

	tell_object(me, "\n你走上前去，小心翼翼地向" + man->name() + "打听关于" + ob->name() + "的情况 ...\n\n");
	message("vision", "只见" + me->name() + "陪着笑脸跟" + man->name() + "说着话，好象在打听些什么。\n\n", 
		environment(me), ({ me, man }) );

	sp = me->query_skill("checking")*10 + me->query("kar")*5 + me->query("jing") + man->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;
	
	if ( random(sp) < random(dp) )
		return notify_fail( man->name() + "摇了摇头，说道：这事我可不清楚，"
		 	+ RANK_D->query_respect(me) + "还是去向别人打听一下吧！\n");

	me->receive_damage("jing", cost );

	write( GRN + man->name() + "偷偷摸摸地告诉你： \n" NOR);

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( ob->name() + "目前并没有学会任何技能。\n");
		return 1;
	} else {
		sname  = keys(skl);
		i = random(sizeof(skl));
		write( ob->name() + "学过" + chinese_number(skl[sname[i]]) + "级的" + to_chinese(sname[i])+ "。\n");
	}	

	inv = all_inventory(ob);
	if( !sizeof(inv) ) {
		write(ob->name() + "身上没有携带任何东西。\n");
		return 1;
	} else {
		j = random(sizeof(inv));
		write( ob->name() + "身上带著" + inv[j]->short() + "。\n");
	}	

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : check|dating [<某人>]

这个指令可以让你打听别人所学过的消息。

你也可以指定一个和你有师徒关系的对象，用 skills|cha 可以查知对方的技能状况。

此命令为丐帮弟子专用，并需学习相应的技能。

HELP
    );
    return 1;
}
