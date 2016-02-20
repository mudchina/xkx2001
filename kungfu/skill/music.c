//Cracked by Roath
//music.c 五音十二律
//乐律十二律，是为黄钟、大吕、太簇、夹钟、姑洗、中吕、蕤宾、林钟、夷则、南吕、无射、应钟。此是自古已有，据说当年黄帝命伶伦为律，闻凤凰之鸣而制十二律。瑶琴七弦，具宫、商、角、微、羽五音，一弦为黄钟，三弦为宫调。五调为慢角、清商、宫调、慢宫、及蕤宾调。

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl, lvl2;
	
	lvl = (int)me->query_skill("music", 1);

	if ( lvl > 100 && me->query_int()-15 < lvl/10 )
		return notify_fail("你悟性有限，难以领会音律中更高的意境。\n");

	return 1;
}

int practice_skill(object me)
{       
	return notify_fail("基本音律只能靠学(learn)来提高。\n");
}
