//Cracked by Roath
// feicui.c 翡翠池
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIG"翡翠池"NOR);
	set("long", @LONG
前面豁然开朗，是一大片平地。四周群山围绕，就如一只大
盆一般，盆子中心碧水莹然，绿若翡翠，是个圆形的池子(pool)
。洁白的玉峰映在碧绿的池中，白中泛绿，绿中泛白，明艳洁净
，幽绝清绝。
LONG
	);

	set("exits", ([
		"east" : __DIR__"houshan",
	]));
	set("resource/water", 1);

	set("item_desc", ([
	"pool" : "池水澄净清澈，更无纤毫苔泥，原来圆池四周都是翡翠，池水才映成绿色。\n"
		"据说美丽的人在翡翠池里洗了澡更加美，丑的人洗了就更加丑。\n",
	"翡翠池" : "池水澄净清澈，更无纤毫苔泥，原来圆池四周都是翡翠，池水才映成绿色。\n"
		"据说美丽的人在翡翠池里洗了澡更加美，丑的人洗了就更加丑。\n",
	]));

	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
}

void init()
{
	object *inv = all_inventory(find_object("/d/xingxiu/feicui"));
	object comer = this_player();
	int i;
	add_action("do_drink", "drink");
	add_action("do_swim", "swim");
	add_action("do_swim", "dive");
	if ( (string)comer->query("race") == "人类" )
		for ( i=0 ; i < sizeof(inv); i++)
			if ( inv[i]->query_temp("feicui_swimming") ) {
				if ( inv[i]->is_spouse_of(comer) ) {
					tell_object(inv[i], HIB"你发现有人走到池边，仔细一看，原来是你的" + inv[i]->query("spouse/title") + "，虚惊一场。\n"NOR);
					message("vision",CYN + comer->name() + "对着你会心地一笑。\n"NOR, inv[i]);
					message("vision",CYN"你对着" + inv[i]->name() + "会心地一笑。\n"NOR, comer);
				}
				else if ( (string)inv[i]->query("gender") != "女性"
					|| (string)comer->query("gender") == "女性" ) {
					tell_object(inv[i], HIW"你突然见到有外人路过，吓得赶紧跳出翡翠池，恨不得找个地缝钻进去。\n"NOR);
					tell_object(comer, "你见到一个人慌慌张张地从翡翠池中跳了上来。\n");
					inv[i]->delete_temp("feicui_swimming");
					inv[i]->set("jing", 0);
					inv[i]->start_busy(1);
				}
				else {
					tell_object(inv[i], HIW"你正打算走出翡翠池，突然发现" + comer->name() + "往这儿走来，吓得惊叫一声，又跌进了水里。\n"NOR);
					tell_object(comer, HIG"忽见翡翠池中微微起了一点漪涟，一只手臂从湖中伸了上来，接着一个湿淋淋的头从水中钻出，一转头，看见了你，一声惊叫，又钻入水中。\n"NOR);
					inv[i]->delete_temp("feicui_swimming");
					inv[i]->set("jing", 0);
					inv[i]->start_busy(1);
					if ( random(inv[i]->query_per()/6) ) inv[i]->unconcious();
				}	
			}
}

int do_swim(string arg)
{
	object me = this_player();
	object *inv;
	int i;
	
	if ( !arg || (arg != "pool" && arg != "翡翠池") ) 
		return 0;

	if ( me->query_temp("feicui_swimming") )
		return notify_fail("你正在池中戏水。\n");

	if ( me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");

	inv = all_inventory(me);	
	for (i=0; i<sizeof(inv); i++) {
		if ( (string)inv[i]->query("equipped")=="worn" ) 
			switch(inv[i]->query("armor_type")) {
				case "cloth":
				case "armor":
				case "suncoats":
					if ( inv[i]->query_weight() > 8000)
						return notify_fail("穿着沉重的甲胃下水，不怕淹死你啊？！\n");
					else 
						me->receive_damage("jing", 10, me);
						return notify_fail(BLU"你跳进翡翠池中，弄得浑身衣服湿漉漉的，赶紧爬回池外。冷风一吹，你不由得打了一个喷嚏。\n"NOR);
				case "boots":
					return notify_fail("穿着鞋下水？！\n");
				case "bandage":
					return notify_fail("你还裹着伤呢，不怕下水後伤口感染？！\n");
				default:
					break;
			}
	}
	inv = all_inventory(environment(me));
	for (i=0; i<sizeof(inv); i++) 
		if ( (string)inv[i]->query("race") == "人类" && inv[i] != me && !me->is_spouse_of(inv[i]) )
			return notify_fail("众目睽睽之下脱光衣裳下水，你不嫌害臊吗？！\n");

	message_vision(HIG"$N除去外衣，跳入了翡翠池中，在碧波中上下来去。\n"NOR, me);
	me->set_temp("feicui_swimming", 1);

	me->start_busy(21);
	call_out("out_of_pool", 20, me);

	return 1;
}

void out_of_pool(object me)
{
	if ( !me->query_temp("feicui_swimming") ) return;
	me->delete_temp("feicui_swimming");
//	me->improve_skill("force", random(me->query_con()/5));

		if(me->query("per") > 25) {
//		me->improve_skill("beauty", 5*me->query_per());
		tell_object(me, "过了一小会儿，你爬出翡翠池外，只觉疲劳尽去，精神抖擞。\n");
		message("vision", me->name()+"容光焕发地从翡翠池中爬了上来，脸上发上都是水珠。\n", environment(me), ({ me }) );
		
			if(!me->query("feicui_per") && me->query("gender") == "女性") {
			tell_object(me, HIM"你想到有关翡翠池的古老传说：“美丽的人在池里洗了澡更加美，丑的人洗了就更加丑”，不由得怦然心动，满脸晕红，不知道自己是不是真的更加美丽了些。\n"NOR);
			me->add("per",1);
			me->set("feicui_per",1);
			log_file("test/add_per", sprintf("%s(%s) add 1 per from 翡翠池 on %s\n", me->name(), me->query("id"), ctime(time())));
			}
		}

		else {
		tell_object(me, "过了一小会儿，你觉得游得有些累了，爬出翡翠池外。\n");
		message("vision", me->name()+"从翡翠池中爬了上来，脸上发上都是水珠。\n", environment(me), ({ me }) );
		
			if(!me->query("feicui_per") && me->query("per") < 20 && me->query("gender") == "女性") {
			tell_object(me, "你突然想到有关翡翠池的古老传说：“美丽的人在池里洗了澡更加美，丑的人洗了就更加丑”，不由得冷汗涔涔而下，不太敢低头看池水，以免无法接受现实。\n");
			me->add("per",-1);
			me->set("feicui_per",1);
			log_file("test/add_per", sprintf("%s(%s) lost 1 per from 翡翠池 on %s\n", me->name(), me->query("id"), ctime(time())));
			}

		}
	me->start_busy(1);
}

int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;

	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if( arg == "pool") {
	if (current_water<max_water) {
	    me->set("water", current_water+30);
	    if(me->query("jing") < me->query("eff_jing"))me->add("jing", 30);
	    message_vision("$N走近池边，伸下手去，只觉清凉入骨，双手捧起水来，就口而饮，一阵甘美沁入心脾。\n", me);
	}
	else write("你已经喝了个饱，再也喝不下一滴水了。\n");

	return 1;
	}
	else return 0;
}
