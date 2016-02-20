//Cracked by Roath
// 庄子
inherit ITEM;
inherit F_UNIQUE;

void init();

void create()
{
	set_name("《庄子》竹简", ({"zhujian", "bamboo" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
		else {
		set("value", 100);
		set("unit", "捆");
		set("huiwen", 1);
		set("no_get", 1);
		set("no_steal", 1);
		set("no_drop", 1);
		set("long", 
		"一捆竹简，简上涂了黑漆，简身仍属完整，简上用朱漆写着密密的汉字。\n"
		"头一句是“北冥有鱼，其名为鲲”，翻简看下去，见一篇篇都是《庄子》。\n"
		"只见中间有一片有些不同，每个字旁加了密密圈点，还写着几个古回文，意思是“破敌秘诀，都在这里”。\n");
		set("material", "bamboo");
	}
	setup();
	::create();
}

void init()
{
	add_action("do_lingwu", "lingwu");
}

int do_lingwu(string arg)
{
	mapping fam, skills, learned;
	object me;
	string skillname, msg;
	int skill_special, skill_basic, s, gain;

	me = this_player();
	skills = me->query_skills();
	learned = me->query_learned();


	if( base_name(environment(me)) != "/d/xingxiu/jadehall") 
		return notify_fail("“庖丁解牛”那一段中的章句，一字字在你心中流过：“方今之时，臣以神遇，而不以目视，官知止而神欲行，依乎天理，批大却，导大窍，因其固然……”\n"
		"你再想到：“行为迟，动刀甚微，砉然已解，如土委地，提刀而立，为之四顾，为之踌躇满志。”\n你心里想：“要是真能如此，我眼睛瞧也不瞧，刀子微微一动，就把敌人杀了……”\n");
	
	if( me->query("combat_exp") < 1000000)
		return notify_fail("竹简上的武功含意很高深，你还不能练。\n");

	if( !arg ) 
		return notify_fail("你要从竹简领悟何种基本武技？\n");

	if( arg == "force" )
		return notify_fail("对着一堆骸骨，再怎麽样也看不出有半点经脉运行的模样，如何领悟内功？\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你必须激发特殊武功才能配合领悟基本武技。\n");

	skill_basic = me->query_skill(arg, 1);
	skill_special = me->query_skill(skillname, 1);

	if( skill_special < 200 )
		return notify_fail("你的" + to_chinese(skillname) + "尚未精纯，无法配合领悟" + to_chinese(arg) + "！\n");

	if( skill_basic > skill_special )
		return notify_fail("你在" + to_chinese(skillname) + "上的修为不足，无法继续领悟" + to_chinese(arg) + "！\n");

	if( skill_basic < 1 )
		return notify_fail("你好像还没有学过这项基本技能吧？ 最好先去请教别人。\n");

	if ( me->query("jing") < 100 ) 
		return notify_fail("你现在精神不佳，领悟不到竹简中的精义。\n");

	if( (int)me->query("potential") <= 1 )
		return notify_fail("你的潜能已达极限。\n");

	me->receive_damage("jing", skill_basic/2 + random(skill_basic/2), "领悟了庄子达观顺天的理念而安息");

	s = (1+random(3))*2;

	skill_special = skill_special * me->query("max_neili") * 2 / (1000 + me->query("max_neili"));

	  	if(s == 2) msg = "$N喜容满脸，在大殿上的骸骨旁手舞足蹈，钻研着" + to_chinese(skillname) + "的奇妙之处。\n";
	  	else if(s == 4) msg = "只见$N依照着一具骸骨的姿势，手足动了起来，举手投足之中势挟劲风，道理和" + to_chinese(arg) + "暗暗契合。\n";
	  	else msg = "$N双掌一错，身子一转，虚踢一脚，犹如舞蹈一般。\n";

		if( arg == "dodge") {
			if(s == 2) msg = "祗见$N肩和手的伸缩，脚与膝的进退，无不因便施巧，合于音乐节拍，举动就如跳舞一般。\n";
			else if(s == 4) msg = "$N来回奔驰，初时还感生疏滞涩，这时越来越顺，到後来犹如行云流水，进退趋止，莫不中节。\n";
			else msg = "$N缓步前行，趋退转合，潇洒异常。\n";
		}
		
	gain = skill_special/s + random(skill_special/(s/2));

	if(random(15) != 0) {
		me->add("potential", -1);
		me->improve_skill(arg, gain);
		if(wizardp(me) && s)
		tell_object(me,"s = "+s+", add "+ gain +" \n");
		message_vision(msg, me);
	}
	else {
		message_vision("$N舞动了一会，呆呆瞪视着一堆骸骨，想从其中领悟" + to_chinese(arg) + "方面的奥秘，却一无所得。\n", me);
		me->start_busy(1);
		me->add("potential", -1);
		me->receive_damage("jing", skill_basic/2 + random(skill_basic/2), "领悟了庄子达观顺天的理念而安息");
	}

	if( me->query("potential") < 0) me->set("potential", 0);

	if( learned[arg] < 0 ) { 
		skills[arg]--;
		learned[arg] += skills[arg] * skills[arg];
	}

	return 1;

}
