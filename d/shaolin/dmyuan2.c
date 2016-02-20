//Cracked by Roath
// Room: /d/shaolin/dmyuan2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "达摩院二楼");
	set("long", @LONG
这是一座古朴的殿堂。西首的墙上挂满了各类武功图谱，不
少白须白眉的老僧们正端坐在图谱画轴之前，似乎在苦苦思索。
南北山墙是高及屋顶的大书架，走近细看，它们是各门各派的武
功秘笈，屋正中摆着几张矮几诃和几个团，几位老僧正在入定中。
LONG
	);

	set("exits", ([
		"down" : __DIR__"dmyuan",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/xuan-bei" : 1,
		__DIR__"npc/xiao-bei" : 1,
	]));
	set("cost", 1);
	setup();
}

void init()
{
	add_action("do_understand", "understand");
	add_action("do_understand", "lingwu");
}

int do_understand(string arg)
{
	mapping fam, skills, learned;
	object me;
	string skillname;
	int skill_special, skill_basic;

	me = this_player();
	skills = me->query_skills();
	learned = me->query_learned();

	if( !me->query("luohan_winner") )
		return notify_fail("玄悲说道：你级别不够，不能在达摩院里进修。\n");

	if( mapp(fam = me->query("family")) 
	&&  fam["family_name"] == "少林派" 
	&&  fam["generation"] > 37  )
		return notify_fail("玄悲说道：你级别不够，不能在达摩院里进修。\n");

	if( !arg ) 
		return notify_fail("你要研究何种基本武技？");

	if( arg == "force" )
		return notify_fail("你不能自行修炼基本内功！\n");

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你必须有特殊武功方能与基本武技参照领悟！\n");

	skill_basic = me->query_skill(arg, 1);
	skill_special = me->query_skill(skillname, 1);

	if( skill_special < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
	if( skill_basic > skill_special )
		return notify_fail("你" + to_chinese(skillname) + "功力不够，无法继续领悟" + to_chinese(arg) + "！\n");
	if( skill_basic < 1 )
		return notify_fail("你好像还没有学过这项基本技能吧？ 最好先去请教别人。\n");

	if ( me->query("jing") < 100 ) 
		return notify_fail("你现在精神不佳，无法定下心来思考！\n");

	if( (int)me->query("potential") <= 1 )
		return notify_fail("你的潜能不足，无法领悟基本武功！\n");

	me->receive_damage("jing", random(skill_basic), "在达摩院冥思苦想把脑袋给想破了，白白的脑浆流了一地");
	if( me->query("potential") < 0) me->set("potential", 0);

  // modified by aln here to show the importance of max jing
        skill_special = skill_special * me->query("max_jing") * 2 / (1000 + me->query("max_jing"));

	if(random(20) == 0) {
		me->add("potential", -2);
		me->improve_skill(arg, skill_special + random(skill_special*2));
		write( "只觉脑中豁然开朗，你对" + to_chinese(arg) + "的领悟又进了一层！\n" );
	}
	else if(random(10) == 0) {
		me->add("potential", -1);
		me->improve_skill(arg, skill_special/2 + random(skill_special/1));
		write( "你冥思苦想，对" + to_chinese(arg) + "渐渐加深一层体会！\n" );
	}
	else if(random(5) == 0) {
		me->add("potential", 0);
		me->improve_skill(arg, skill_special/4 + random(skill_special/2));
		write( "你拿手比划着，似乎对" + to_chinese(arg) + "中的几个招数有所体会。\n" );
	}
	else if(random(2) == 0) {
		me->improve_skill(arg, skill_special/8 + random(skill_special/4));
		write( "你坐立不安，潜心苦思" + to_chinese(arg) + "上的难解之处。\n" );
	}
	else if(random(5) == 0) {
		write( "你心中说不出的烦燥，对" + to_chinese(arg) + "始终不得一解。\n" );
	}
	else if(random(10) == 0) {
		me->improve_skill(arg, - (skill_special/10 + random(skill_special/5)));
		write( "你只觉得体内真气乱窜，" + to_chinese(arg) + "中的招式象走马灯一般在面前显现！\n" );
	}
	else if(random(20) == 0) {
		me->improve_skill(arg, - (skill_special/6 + random(skill_special/3)));
		write( "你的大脑中一片空白。对" + to_chinese(arg) + "是越想越糊涂。\n" );
	}
	else {
		write( "你坐立不安，潜心苦思" + to_chinese(arg) + "上的难解之处。\n" );
	}

	if( learned[arg] < 0 ) { 
		skills[arg]--;
		learned[arg] += skills[arg] * skills[arg];
	}

	return 1;

}

