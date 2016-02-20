//Cracked by Kafei
// rankd.c
// 1996-02-15 dts ranking related to "shen"
// 1996-11-26 xbc added emei ranking

#include <ansi.h>

string query_rank(object ob)
{
	int shen;
	int budd;
	int rank;
	int lama;
	int maha;
	int pixie;
	int dlrank;
	int taoism;

	if( ob->is_ghost() )
		return HIB "【 鬼  魂 】" NOR;

	shen = ob->query("shen");

	if ( ob->query("family/family_name") == "少林派" )
		budd = ob->query_skill("buddhism",1);

	if ( ob->query("family/family_name") == "丐帮" )
		rank = ob->query("rank");

	if ( ob->query("family/family_name") == "雪山派" ||
		  ob->query("family/family_name") == "血刀门" )
		lama = ob->query_skill("lamaism",1);

	if ( ob->query("family/family_name") == "峨嵋派" )
		maha = ob->query_skill("mahayana",1);

	//if ( ob->query("family/family_name") == "全真教" )
		taoism = ob->query_skill("taoism",1);

	if (ob->query("dali/employee"))
		dlrank = ob->query("dali/rank");

	// the following was to set class for those who became gonggong
	// before mongol add class eunuch
	//if ( ob->query("gender") == "无性" )
	//	ob->set("class", "eunuch");
	// should be eunach.  The following lines can be removed
	// after Aug 1/97 , except that line of "pixie =...
	//	if ( ob->query("class")=="eunuch") ob->set("class","eunach");
	if (ob->query("class")=="eunach") {
		ob->delete("rank_info/respect");
		ob->delete("rank_info/rude");
	}
	pixie = ob->query_skill("pixie-jian", 1);
		  if (pixie<60 && ob->query("class")=="eunach") ob->delete("class");
	// remove the above line after 8/1/97, except the line of "pixie =..

	switch(ob->query("gender")) {
	case "女性":
		switch(wizhood(ob)) {
		case "(admin)":
			return HIW "【 天  后 】" NOR;
		case "(arch)":
			return HIY "【 女  神 】" NOR;
		case "(wizard)":
			return HIG "【 仙  女 】" NOR;
		case "(designer)":
			return GRN "【 玄  女 】" NOR;
		case "(creator)":
			return HIC "【 仙  子 】" NOR;
		case "(caretaker)":
			return WHT "【 天  女 】" NOR;
		case "(virtuoso)":
			return HIM "【逍遥女仙】" NOR;
		case "(apprentice)":
			return MAG "【 仙  姑 】" NOR;
		case "(immortal)":
			return CYN "【 精  灵 】" NOR;
		default:
			if( ((int)ob->query("PKS") > 100) &&
				((int)ob->query("PKS") > (int)ob->query("MKS")) )
				return HIR "【 土匪婆 】" NOR;
//			if( (int)ob->query("thief") > 10 )
//				return "【 惯  窃 】";
			switch(ob->query("class")) {
			case "bonze":
				if (maha >= 120 )
					return WHT "【 神　尼 】" NOR;
				else if (maha >= 90)
					return WHT "【 师　太 】" NOR;
				else if (maha >= 60)
													 return WHT "【 比丘尼 】" NOR;
				else if (maha >= 30)
													 return WHT "【 沙弥尼 】" NOR;
				else
					return WHT "【 学戒女 】" NOR;

		case "taoist":
			if (taoism >= 150)
				return HIW "【 女真人 】" NOR;
			else if (taoism >= 90)
				return HIY "【 大女冠 】" NOR;
			else if (taoism >= 30)
				return HIG "【 女  冠 】" NOR;
			else
				return     "【 小道姑 】" NOR;

			case "bandit":
				return "【 女飞贼 】";
			case "dancer":
				return "【 舞  妓 】";
			case "scholar":
				return "【 才  女 】";
			case "officer":
				if (dlrank==5)
					return "【 王  妃 】";
				else if (dlrank==4)
					return "【诰命夫人】";
				else
					return "【 女  官 】";
			case "fighter":
				return "【 女武者 】";
			case "swordsman":
                return "【 女剑士 】";
			case "alchemist":
				return "【 方  士 】";
			case "shaman":		
				return "【 巫  医 】";
			case "beggar":		
				if (rank >= 9 && shen >= 100000)
					return HIG "【 女神丐 】" NOR;
				else if (rank >= 9 && shen <= -100000)
					return HIG "【 魔丐婆 】" NOR;
				else if (rank >= 7 && shen >= 10000)
					return HIG "【 女侠丐 】" NOR;
				else if (rank >= 7 && shen <= -10000)
					return HIG "【 恶丐婆 】" NOR;
				else if (rank >= 5 && shen >= 1000)
					return HIG "【 女义丐 】" NOR;
				else if (rank >= 5 && shen <= -1000)
					return HIG "【 凶丐婆 】" NOR;
				else if (rank >= 3 )
					return HIG "【 叫化婆 】" NOR;
				else
					return HIG "【 叫化妹 】" NOR;
			default:
				if (shen >= 1000000)
					return HIC "【旷世侠女】" NOR;
				else if (shen >= 100000)
					return HIC "【 大侠女 】" NOR;
				else if (shen >= 10000)
					return HIC "【 侠  女 】" NOR;
				else if (shen >= 1000)
					return HIC "【 小侠女 】" NOR;
				else if (shen <= -1000000)
													 return HIC "【旷世魔女】" NOR;
				else if (shen <= -100000)
					return HIC "【 女魔王 】" NOR;
				else if (shen <= -10000)
					return HIC "【 大魔女 】" NOR;
				else if (shen <= -1000)
					return HIC "【 魔  女 】" NOR;
				else if (shen <= -100)
					return HIC "【 小魔女 】" NOR;
				else
					return "【 民  女 】";
			}
		}
	default:
		switch(wizhood(ob)) {
		case "(admin)":
			return HIW "【 天  帝 】" NOR;
		case "(arch)":
			return HIY "【 大  神 】" NOR;
		case "(wizard)":
			return HIG "【 神  仙 】" NOR;
		case "(designer)":
			return GRN "【 天  师 】" NOR;
		case "(creator)":
			return HIC "【 天  仙 】" NOR;
		case "(caretaker)":
			return WHT "【 天  官 】" NOR;
		case "(virtuoso)":
			return HIM "【 散  仙 】" NOR;
		case "(apprentice)":
			return MAG "【 仙  人 】" NOR;
		case "(immortal)":
			return CYN "【 半  仙 】" NOR;
		default:
			if( ((int)ob->query("PKS") > 100)
			&&((int)ob->query("PKS") > (int)ob->query("MKS")) )
				return HIR "【 土  匪 】" NOR;
//			if( (int)ob->query("thief") > 10 )
//				return "【 惯  窃 】";
			switch(ob->query("class")) {
			case "eunach":
				if (pixie >= 180)
					return HIM "【 九千岁 】" NOR;
				else if (pixie >= 160)
					return HIM "【东厂指挥】" NOR;
				else if (pixie >= 140)
					return HIM "【 大档头 】" NOR;
				else if (pixie >= 120)
					return HIM "【东厂档头】" NOR;
				else if (pixie >= 100)
					return HIM "【东厂千户】" NOR;
				else if (pixie >= 80)
					return HIM "【东厂百户】" NOR;
				else if (pixie >= 60)
					return HIM "【东厂太监】" NOR;
				else if (pixie >= 40)
					return HIM "【 太  监 】" NOR;
				else if (pixie >= 20)
					return HIM "【九品太监】" NOR;
				else
					return HIM "【 小太监 】" NOR;
			case "bonze":
				if (budd >= 150)
					return HIY "【 长  老 】" NOR;
				else if (budd >= 120)
					return HIY "【 圣  僧 】" NOR;
				else if (budd >= 90)
					return HIY "【 罗  汉 】" NOR;
				else if (budd >= 60)
					return HIY "【 尊  者 】" NOR;
				else if (budd >= 40)
					return HIY "【 禅  师 】" NOR;
				else if (budd >= 30)
					return HIY "【 比  丘 】" NOR;
				else
					return HIY "【 僧  人 】" NOR;
			case "lama":
				if (lama >= 150)
					return HIY "【 法  王 】" NOR;
										  else if (lama >= 120)
					return HIY "【 活  佛 】" NOR;
										  else if (lama >= 90)
													 return HIY "【 国  师 】" NOR;
				else if (lama >= 60)
					return HIY "【 大喇嘛 】" NOR;
										  else if (lama >= 30)
													 return HIY "【 喇  嘛 】" NOR;
				else
					return HIY "【 小喇嘛 】" NOR;
			case "taoist":
				if (taoism >= 150)
					return HIW "【 真  人 】" NOR;
				else if (taoism >= 120)
					return HIC "【道学宗师】" NOR;
				else if (taoism >= 90)
					return HIM "【道学大师】" NOR;
				else if (taoism >= 60)
					return HIY "【 道  长 】" NOR;
				else if (taoism >= 30)
					return HIG "【 道  士 】" NOR;
				else
					return     "【 小道士 】" NOR;
			case "bandit":
				return "【 盗  贼 】";
			case "scholar":
				return "【 书  生 】";
			case "officer":
				if (dlrank==5)
                    return HIR "【 王  爷 】" NOR;
				else if (dlrank==4)
                    return HIM "【 侯  爷 】" NOR;
				else if (dlrank==3)
                    return HIY "【 武  将 】" NOR;
				else if (dlrank<=2)
					return "【 官  差 】";
			case "fighter":		
				return "【 武  者 】";
			case "swordsman":	
				return "【 剑  士 】";
			case "alchemist":	
				return "【 方  士 】";
			case "shaman":
				return "【 巫  医 】";
			case "beggar":
				if (rank >= 9 && shen >= 100000)
					return HIG "【 神  丐 】" NOR;
				else if (rank >= 9 && shen <= -100000)
					return HIG "【 魔  丐 】" NOR;
				else if (rank >= 7 && shen >= 10000)
					return HIG "【 侠  丐 】" NOR;
				else if (rank >= 7 && shen <= -10000)
					return HIG "【 恶  丐 】" NOR;
				else if (rank >= 5 && shen >= 1000)
					return HIG "【 义  丐 】" NOR;
				else if (rank >= 5 && shen <= -1000)
					return HIG "【 凶  丐 】" NOR;
				else if (rank >= 3 )
					return HIG "【 叫化子 】" NOR;
				else
					return HIG "【 小叫化 】" NOR;
			default:
				if (shen >= 1000000)
					return HIC "【旷世大侠】" NOR;
				else if (shen >= 100000)
					return HIC "【 大  侠 】" NOR;
				else if (shen >= 10000)
					return HIC "【 侠  客 】" NOR;
				else if (shen >= 1000)
					return HIC "【 少  侠 】" NOR;
				else if (shen <= -1000000)
													 return HIC "【旷世魔王】" NOR;
				else if (shen <= -100000)
					return HIC "【 魔  王 】" NOR;
				else if (shen <= -10000)
					return HIC "【 大  魔 】" NOR;
				else if (shen <= -1000)
					return HIC "【 魔  头 】" NOR;
				else if (shen <= -100)
					return HIC "【 少  魔 】" NOR;
				else
					return "【 平  民 】";
			}
		}
	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "小师太";
				else return "师太";
				break;

			case "taoist":
				if( age < 18 ) return "小仙姑";
				else return "仙姑";

			case "officer":
				if (ob->query("dali/rank")==5)
					return "娘娘";
				else if (ob->query("dali/rank")==4)
					return "贵夫人";
				else {
					if( age < 18 ) return "小姑娘";
					else if( age < 50 ) return "姑娘";
					else return "婆婆";
				}
				break;
			default:
				if( age < 18 ) return "小姑娘";
				else if( age < 50 ) return "姑娘";
				else return "婆婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "小师父";
				else return "大师";
				break;
			case "lama":
				if( age < 25 ) return "小师父";
				else return "上人";
				break;
			case "taoist":
				if( age < 18 ) return "小道兄";
				else return "道长";
				break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "小老弟";
				else if( age < 50 ) return "壮士";
				else return "老前辈";
				break;
			case "eunach":
				if (ob->query_skill("pixie-jian",1)>160)
					return "督公";
				if (age <18) return "小公公";
				else if (age < 50) return "公公";
				else return "老公公";
				break;
			case "officer":
				if (ob->query("dali/rank")==5)
					return "王爷";
				else if (ob->query("dali/rank")==4)
					return "侯爷";
				else if (ob->query("dali/rank")==3)
					return "将军";
				else return "差爷";
				break;
			default:
				if( age < 20 ) return "小兄弟";
				else if( age < 50 ) return "壮士";
				else return "老爷子";
				break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				return "贼尼";
				break;
			case "taoist":
				return "妖女";
				break;
			default:
				if( age < 18 ) return "小贱人";
				else if( age < 50 ) return "贱人";
				else return "死老太婆";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "死秃驴";
				else return "老秃驴";
				break;
			case "lama":
				if( age < 50 ) return "死秃驴";
				else return "老秃驴";
				break;
			case "taoist":
				return "死牛鼻子";
				break;
			case "eunach":
				return "阉贼";
				break;
			case "officer":
				if (ob->query("dali/rank")==5)
					return "狗王";
				else if (ob->query("dali/rank")>=3)
					return "狗官";
				else return "狗腿子";
				break;
			default:
				if( age < 20 ) return "小王八蛋";
				if( age < 50 ) return "臭贼";
				else return "老匹夫";
				break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "贫尼";
				else return "老尼";
				break;
			default:
				if( age < 30 ) return "小女子";
				else if( age < 50 ) return "妾身";
				else return "老身";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "贫僧";
				else return "老衲";
				break;
			case "lama":
				if( age < 50 ) return "贫僧";
                                else return "老衲";
                                break;
			case "eunach":
				return "下官";
				break;
			case "taoist":
				return "贫道";
				break;
			case "officer":
				if (ob->query("dali/rank")==5)
					return "小王我";
				else return "下官";
				break;
			default:
				if( age < 50 ) return "在下";
				else return "老头子";
				break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
	switch(ob->query("gender")) {
		case "女性":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "贫尼";
				else return "老尼";
				break;
			default:
				if( age < 30 ) return "本姑娘";
				else return "老娘";
				break;
			}
		case "男性":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "大和尚我";
				else return "老和尚我";
				break;
			case "eunach":
				if (age < 50) return "本官";
				else return "老身";
				break;
			case "lama":
				if( age < 50 ) return "本佛爷";
				else return "老佛爷我";
				break;	
			case "taoist":
				return "本山人";
				break;
			case "officer":
				if (ob->query("dali/rank")==5)
					return "本王";
				else if (ob->query("dali/rank")==4)
					return "本侯";
				else if (ob->query("dali/rank")==3)
					return "本官";
				else return "差爷我";
				break;
			default:
				if( age < 50 ) return "大爷我";
				else return "老子";
				break;
			}
	}
}
string query_close(object ob)
{
        int a1, a2;

	if (objectp(this_player()))
	{
        	if (a2 = (int)ob->query("mud_age"))
        	{
        		a1 = this_player()->query("mud_age");
       		} else 
       		{ 	
	       	 	a1 = this_player()->query("age");
			a2 = ob->query("age");
		}
	} else 
	{	
	 	a1 = previous_object()->query("age");
	 	a2 = ob->query("age");
	}
							
        switch (ob->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
	case "无性" :
		if (ob->query("class")== "eunach") {
		if (a1 >= a2)
			if (random(5)==1) return "妹妹";
			else return "弟弟";
		else
			if (random(5)==1) return "姐姐";
			else return "哥哥";
		}
	default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
                break;
        }
}

string query_self_close(object ob)
{
        int a1, a2;
	string gender;
	
	if( objectp(this_player()) )
	{
        	if (a2 = (int)ob->query("mud_age"))
        	{
        		a1 = this_player()->query("mud_age");
       		} else 
       		{ 	
	       	 	a1 = this_player()->query("age");
			a2 = ob->query("age");
		}
		gender = this_player()->query("gender");
	} else 
	{	
       	 	a1 = previous_object()->query("age");
       	 	a2 = ob->query("age");
		gender = previous_object()->query("gender");
	}
		
        switch (gender) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
	}
}
