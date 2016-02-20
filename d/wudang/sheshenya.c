//Cracked by Roath
// sheshenya.c 飞升岩
// by Fang 8/19/96
// Modified by xQin 6/99

#define TRAVERSER "/clone/obj/traverser"
#include <combat.h>
#include <ansi.h>

inherit ROOM;
int fall_down(object me, string type, int stage);
void do_scream();

string *wudang = ({
	"taiziyan",
	"guangchang",
	"zixiao",
	"shijie3",
	"shijie2",
	"shibapan",
	"shiliang",
	"taizipo",
	"haohanpo",
	"bailin",
	"yuzhen",
	"shijie1",
	"shanmen"
});

void create()
{
	set("short", "飞升岩");
	set("long", @LONG
这是一处险峻的悬崖峭壁，相传真武帝在此舍身得道。此间峰岭奇峭，
树木苍翠，上接碧霄，下临绝涧，是武当山三十六岩中最美的一处，崖上立
有铁栅栏，防止有人自杀步真武帝的后尘。
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"nanyanfeng",
	]));
	set("cost", 3);
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_jump", "tiao");
	add_action("do_jump", "jump");
	add_action("do_push", "tui");
	add_action("do_push", "push");
}

int do_jump(string arg)
{
	object me = this_player();

	if( !arg || arg == "" )
		return notify_fail("什麽？\n");

	if( arg == "cliff" )
	{
		if( me->query_skill("dodge") < 150 )
			return notify_fail("那麽高的铁栅栏，你蹦得上去麽？\n");

		message_vision("$N纵身跃过铁栅栏，足底踏空，半个身子已在深渊之上，左足跟着跨出，全身向前急扑，往绝壁跳下！\n", me);
		me->set_temp("last_damage_from", "效仿真武跳崖飞升了");
		fall_down(me, "char", 0);
		return 1;
	}
	return 0;
}

int do_push(string who)
{
	object me = this_player();
	object victim, room, weapon;
	string attack_skill, dodge_skill, parry_skill;
	int ap, dp, pp;
	mapping prepare;

	victim = present(who, environment(me));
	if( !who )return notify_fail("你想推什么？\n");
	if( !victim ) return notify_fail("这个人不在这里吧。\n");
	if( victim==me ) return notify_fail("指令格式：jump cliff\n");

	if( me->is_busy() )
		return notify_fail("你现在自顾都不暇，还有心思害别人？\n");

	if( !victim->is_character() || victim->query("id") == "corpse" )
		return notify_fail("指令格式：throw <物品>\n");

	if( objectp(weapon = me->query_temp("weapon")) )
		return notify_fail("拿着"+weapon->name()+"怎麽推人？\n");

	message_vision(CYN"\n$N一晃之际，已绕到$n身旁，突然劲贯双臂，猛的将$p向峭壁推去"NOR"！\n", me, victim);
	me->start_busy(1);

	if( !living(victim) )
	{
		message_vision("$n往山谷中直栽下去。\n", me, victim);
		victim->set_temp("last_damage_from", "被"+me->name()+"推下悬崖摔死了");
		do_scream();
		fall_down(victim, "char", 0);
		victim->revive();
		return 1;
	}

	prepare = me->query_skill_prepare();
	if( !prepare ) prepare = ([]);

	switch( sizeof(prepare) )
	{
		case 0: attack_skill = "unarmed"; break;
		case 1: attack_skill = (keys(prepare))[0]; break;
		case 2: attack_skill = (keys(prepare))[random(2)]; break;
	}

	ap = COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( victim->is_busy() ) dp /= 3;

	if( random(ap + dp) < dp )
	{
		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		message_vision(SKILL_D(dodge_skill)->query_dodge_msg(), me, victim);

		if( random( ap * 2 ) < dp && !random(10) )
		{
			message_vision("$N全身力道都用在这一推之上，不料竟被$n避开，身形一晃，踏了个空，从悬崖旁摔了下去。\n", me, victim);
			me->set_temp("last_damage_from", "从百尺高空掉下，摔成一团肉泥");
			do_scream();
			fall_down(me, "char", 0);
			return 1;
		}
		else if( !victim->is_killing(me->query("id")) ) victim->kill_ob(me);
		return 1;
        }
        else
	{
		pp = COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
		if( victim->is_busy() ) pp /= 2;

		if( random(ap + pp) < pp )
		{
			parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill || !SKILL_D(parry_skill)->parry_available() ) 
				parry_skill = "parry";
			message_vision(replace_string(SKILL_D(parry_skill)->query_parry_msg(victim->query_temp("weapon"), 
				victim), "$w", "双手"), me, victim);
			if( !victim->is_killing(me->query("id")) ) victim->kill_ob(me);
			return 1;
		}

		message_vision("$n一个没站稳，不由自主的往山谷中掉了下去。\n", me, victim);
		victim->set_temp("last_damage_from", "被"+me->name()+"推下悬崖摔死了");
		do_scream();
		fall_down(victim, "char", 0);
                return 1;
        }
}

int fall_down(object me, string type, int stage)
{
	object *inv; 
	int i, count;
	string dodge_skill;

	if( stage < sizeof(wudang) )
	{
		switch( random(5) )
		{
			case 1 : tell_object(me, "你只觉身子虚浮，全做不得主，只是笔直的跌落。\n");
				 break;
			case 2 : tell_object(me, "你耳旁风声呼呼，虽是顷刻间之事，却似无穷无尽，永远跌个没完。\n");
				 break;
			case 3 : tell_object(me, "你人在半空，虚虚晃晃，实是身不由己，全无半分着力处。\n");
				 break;
			case 4 : tell_object(me, "你只觉身旁风声虎虎，身子不住的向下摔落。\n");
				 break;
			default: tell_object(me, "你但觉耳旁风声不绝，顷刻之间，已到了");
				 break;
		}
		me->move(__DIR__+wudang[stage]);

		message("vision", "你隐隐见到一人从山峰上直堕而下，一时却看不清是谁。\n",
			environment(me), me);

		fall_down(me, type, ++stage);
		return 1;
	}

	inv = all_inventory(environment(me));
	for( i = 0; i < sizeof(inv); i++ ) 
		if( inv[i]->is_character() && inv[i] != me )
		{
			if( !random(25) && random(inv[i]->query_kar()) < 15 )
			{
				tell_object(inv[i], "你赫然发现那人竟是向你直冲而来！！！\n");
				tell_object(me, "你不由自主的笔直堕下，冲向一人，依稀看出是"+ inv[i]->name() +"。\n");
				if( random(inv[i]->query_skill("dodge")) > 200 )
				{
					dodge_skill = inv[i]->query_skill_mapped("dodge");
					if( !dodge_skill ) dodge_skill = "dodge";
					message_vision(SKILL_D(dodge_skill)->query_dodge_msg(), me, inv[i]);
				}
				else if( !inv[i]->query_temp("weapon") &&
					random(inv[i]->query_skill("taiji-quan", 1)) > 100 &&
					inv[i]->query_skill_prepared("cuff") == "taiji-quan" &&
					inv[i]->query_skill_mapped("parry") == "taiji-quan" )
				{
					message_vision(CYN"$N当即使出一招「揽雀尾」，右脚实，左脚虚，运起“挤”字诀，粘连粘随，右掌已搭住$n，横劲发出，将$p下堕之力转直为横，将$n移得横飞出去。\n"NOR, inv[i], me);
					tell_object(inv[i], HIR"你只觉霎时之间头晕眼花，几欲坐倒。\n"NOR);
					inv[i]->set("neili", 0);
				}
				else
				{
					count++;
					message_vision("$n直冲入$N怀中，立时撞得$P腹破肠流，死于非命。\n", inv[i], me);
					inv[i]->receive_wound("qi", inv[i]->query("max_qi")+100, "被"+me->name()+"撞得腹破肠流，死于非命");
				}
			break;
			}
		}

	if( !count )
	{
		tell_object(me, "你直撞到石阶上，");
		switch( random(3) )
		{
			case 0 : tell_object(me, "鲜血迸流，鼻子歪在半边，却便似开了个油铺∶咸的，酸的，辣的，一发都滚出来。\n");
				 break;
			case 1 : tell_object(me, "眼棱缝裂，乌珠迸出，也似开了个彩帛铺的∶"HIR"红"NOR"的，"BLU"黑"NOR"的，"MAG"紫"NOR"的，都绽将出来。\n");
				 break;
			case 2 : tell_object(me, "太阳上正着，却似做了一全堂水陆的道场∶磐儿，钹儿，铙儿，一齐响。\n");
				 break;
		}
		message("vision", "只听得「砰」的一声巨响，" +me->name() 
			+"撞在石阶上，摔得粉身碎骨，成了一团肉浆。\n", environment(me), me);
	}

	me->receive_wound("qi", me->query("max_qi")+100, me->query_temp("last_damage_from"));

	inv = all_inventory(me);
	for( i = 0; i < sizeof(inv); i++ )
	{
		if( inv[i]->is_character() )
		inv[i]->receive_wound("qi", inv[i]->query("max_qi")+100, "被"+me->name()+"连累跌得粉身碎骨了");
	}
	return 1;
}

/*
int destroy_corpse()
{
        object obj, room;

        if ( !( room = find_object(__DIR__"cliff") ) )
                room = load_object(__DIR__"cliff");

        if ( obj = present("corpse", room) ) destruct(obj);

        return 1;
}
*/

int visit_room(string room_path, mapping info, mapping mapdb_info, mixed args)
{
	object room;

	if( strsrch(room_path, "/d/wudang/") != 0 ) return 1;
	room = find_object(room_path);
	if( !objectp(room) ) return 0;
	message("info", HIR"「啊～～～」半山突然传来一阵极凄厉的惨叫声。\n"NOR, room, 0);
}

void do_scream()
{
	object trav;

	trav = new(TRAVERSER);
	if( !objectp(trav) ) return;

	trav->traverse(base_name(this_object()), (:visit_room:), 0);
}