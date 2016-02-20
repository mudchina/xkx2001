//Cracked by Roath
//Kane
// Modified by xQin 04/01

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "试剑亭");
	set("long", @LONG
这座小亭孤零零立于水中，整座亭均以红松搭成，四面池水萦回，清幽古朴
兼而有之。亭内挂着一副对联 (duilian)，均以狂草写成，字里行间大有俯仰自
得，不可一世之意。
LONG
	);

        set("item_desc", ([
        "duilian" : " \n
※※※※※※※※※※※※※※※
※※    桃          碧    ※※
※※                      ※※
※※    花          海    ※※
※※                      ※※
※※    影          潮    ※※
※※                      ※※
※※    落          生    ※※
※※                      ※※
※※    飞          按    ※※
※※                      ※※
※※    神          玉    ※※
※※                      ※※
※※    剑          箫    ※※
※※※※※※※※※※※※※※※
\n", 
        ]));

	set("cost", 2);
	set("outdoors", "taohua");

	setup();
}

void init()
{
        add_action("do_jump", "fly");
	  add_action("do_lian", "lian");
}

int do_jump(string arg)
{
        object me = this_player();

        if ( !arg || arg != "bank" )
             return notify_fail( "什么？\n");

        message_vision("$N纵身跳回听鱼石。\n\n", me);
        me->move(__DIR__"tingyu");
        message("vision", me->name() + "纵身由试剑亭里跳了过来。\n",environment(me), ({me}) );

        return 1;
}

int do_lian(string arg)
{
        object me;
	string skillarg, skillname, skillzhao, multiple;
	int times, shijian, skill, skill_basic, qi;

	me = this_player();
	seteuid(getuid());

/*	if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");

	if (where->query("sleep_room"))
                return notify_fail("在睡房里不能练功，这会影响他人。\n");
*/
	if (me->query_temp("cursed", 1))
                return notify_fail("什么？\n");

	if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if( arg=="parry" )
		return notify_fail("你不能通过练习招架来提高这项技能。\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if(sscanf(arg, "%s %d", skillarg, times)!=2 )
	        skillarg = arg;
	
	if( skillarg != "sword" ) return notify_fail("什么？\n");
	
	if( skillarg=="parry" )
                return notify_fail("你不能通过练习招架来提高这项技能。\n");

	if(!times || times == 0) {
		times = 1;
		multiple="";
	}
	else	multiple="反复";
	shijian = times;
	
	if(!stringp(skillname = me->query_skill_mapped(skillarg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

	skill_basic = me->query_skill(skillarg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("你好像还没有学过这项技能吧？最好先去请教别人。\n");
	if( skill_basic < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

	notify_fail("你现在不能练习这项技能。\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

	notify_fail("你试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");
	
	if(times < 0 ) return notify_fail("你要练多少？！\n");
	
	for(times; times > 0; times--) {
		if( SKILL_D(skillname)->practice_skill(me) )
			me->improve_skill(skillname, skill_basic/3+1, skill_basic > skill? 0: 1);
		else return 0;
	}

	if(skillzhao = SKILL_D(skillname)->query_skill_name(me->query_skill(skillname, 1))) {
		message_vision( HIY"$N" + multiple + "练习著" + to_chinese(skillname) + "中的" 
				+ skillzhao + "这一招，看来有些进步。\n"NOR, me);
		if( me->query_skill("bitao-xuangong", 1) > 80 )
			me->add("shijian",shijian);
	} 
	else {
		message_vision( HIY"$N" + multiple + "练习著" + to_chinese(skillname) + "，看来有些进步。\n"NOR, me);
		if( me->query_skill("bitao-xuangong", 1) > 80 )
                        me->add("shijian", shijian);
	}

	return 1;
}

