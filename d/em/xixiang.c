//Cracked by Roath
// /d/emei/xixiang.c 洗象池
// Shan: 96/06/22

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洗象池");
	set("long", @LONG
洗象池原只是一亭，亭前有一个石砌的小池(pool)，池边不远就是危岩。
洗象池寓于一片冷杉林中，有若白云深处的仙山琼阁。若是云收雾敛、碧空万
里、月朗中天时，便觉万籁俱寂，清光无限，宛若身在天宫，彻体生凉。这正
是著名的「象池池夜」。由此向南上攀，便至雷洞坪，东下至莲花石。
LONG
	);
	set("exits", ([
		"southup" : __DIR__"lingyun",
		"eastdown" : __DIR__"po2",
	]));

        set("resource/water", 1);

        set("item_desc", ([
		"pool" :
"这是一个石砌的六角小池，传说普贤乘象至此，必先在此池沐浴其象，而后才\n"
"升至金顶，故为「洗象池」。\n",

		"危岩" :
"危岩边刻有「岩谷灵光」四个大字。岩下终年为白云环绕，难见其底。\n",

		"rock" :
"危岩边刻有「岩谷灵光」四个大字。岩下终年为白云环绕，难见其底。\n"

])  ) ;

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 2);
	setup();
//	replace_program(ROOM);

}

void init()
{
	object *inv = all_inventory(find_object("d/emei/xixiang"));
	object comer = this_player();
	int i;

	add_action("do_swim", "swim");
	add_action("do_swim", "dive");
	if ( (string)comer->query("race") == "人类" )
		for ( i=0 ; i < sizeof(inv); i++)
			if ( inv[i]->query_temp("xixiang_swimming") ) {
				if ( inv[i]->is_spouse_of(comer) ) {
					tell_object(inv[i], HIB"你发现有人走到池边，仔细一看，原来是你的"
							+ inv[i]->query("spouse/title")
							+ "，虚惊一场。\n"NOR);
					message("vision",CYN + comer->name()
							+ "对着你会心地一笑。\n"NOR, inv[i]);
					message("vision",CYN"你对着" + inv[i]->name()
							+ "会心地一笑。\n"NOR, comer);
				}
				else if ( (string)inv[i]->query("gender") != "女性"
					|| (string)comer->query("gender") == "女性" ) {
					tell_object(inv[i], RED"你突然见到有外人路过，吓得赶紧跳出象池，恨不得找个地缝钻进去。\n"NOR);
					tell_object(comer, RED"你见到一个人慌慌张张地从洗象池中跳了上来。\n"NOR);
					inv[i]->delete_temp("xixiang_swimming");
					inv[i]->set("jing", 0);
					inv[i]->start_busy(1);
				}
				else {
					tell_object(inv[i], RED"你突然发现" + comer->name()
						+ "正对你不怀好意地窥视，你吓得几乎要晕了过去。\n"NOR);
					tell_object(comer, RED"你突然发现象池中有女子沐浴，她几乎要被你吓得晕了过去。\n"NOR);
					inv[i]->delete_temp("xixiang_swimming");
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
	int i, flag;
	int t; // time of the day in minutes
	mixed local;
	
	if ( !arg || (arg != "pool" && arg != "洗象池") ) {
		return notify_fail("什么？\n");
	}

	if ( me->query_temp("xixiang_swimming") )
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
						return notify_fail(BLU"你跳进洗象池中，弄得浑身衣服湿漉漉的，赶紧爬回池外。冷风一吹，你不由\n得打了一个喷嚏。\n"NOR);
				case "boots":
					return notify_fail("穿着鞋下水？！\n");
				case "bandage":
					return notify_fail("你还裹着伤呢，不怕下水后伤口感染？！\n");
				default:
					break;
			}
	}
	inv = all_inventory(environment(me));
	for (i=0; i<sizeof(inv); i++) 
		if ( (string)inv[i]->query("race") == "人类" && inv[i] != me && !me->is_spouse_of(inv[i]) )
			return notify_fail("众目睽睽之下脱光衣裳下水，你不嫌害臊吗？！\n");

        local = localtime(time()*60);
        t = local[2]*60 + local[1];

	message_vision(CYN"$N往洗象池中跳去。\n"NOR, me);
	me->set_temp("xixiang_swimming", 1);
	inv = all_inventory(me);
	flag = 0;
	for (i=0; i < sizeof(inv); i++) 
		if ( !inv[i]->query("armor_prop/armor") ) {
			destruct(inv[i]);
			flag += 1;
		}

	me->start_busy(10);
	if ( t > 1200 || t < 300 ) {
		write(HIB"此时夜深人静，你尽情地在池中戏水，想借清凉的池水解除一天的疲劳。\n"NOR);	
		call_out("out_of_pool", 20+random(12), me, 1);
	}
	else {
		write(HIB"池水清凉，你尽情地在池中戏水，但仍时时担心是否有人路过窥视。\n"NOR);
		call_out("out_of_pool", 20+random(12), me, 0);
	}
	if ( flag ) write(HIB"不过你身上的钱物都掉进水中，再也找不到了：（\n"NOR);

	return 1;
}

void out_of_pool(object me, int recover)
{
	if ( !me->query_temp("xixiang_swimming") ) return;
	me->delete_temp("xixiang_swimming");

	if ( recover ) {
		tell_object(me, GRN"过了一小会儿，你爬出池外，只觉疲劳尽去，精神抖擞。\n"NOR);
		if ( me->query("gender") == "女性" ) {
			me->add("jing", (me->query("eff_jing") - me->query("jing"))/2);
			me->add("qi", (me->query("eff_qi") - me->query("qi"))/2);
			me->add("jingli", (me->query("max_jingli") - me->query("jingli"))/2);
			me->add("neili", ((int)me->query("max_neili")-(int)me->query("neili"))/2);
			me->improve_skill("beauty", 15*me->query_per());
		}
		else {
			me->add("jing", ((int)me->query("eff_jing")-(int)me->query("jing"))/3);
			me->add("qi", ((int)me->query("eff_qi")-(int)me->query("qi"))/3);
			me->add("jingli", ((int)me->query("max_jingli")-(int)me->query("jingli"))/3);
			me->add("neili", ((int)me->query("max_neili")-(int)me->query("neili"))/3);
		}
		message("vision", "只见"+me->name()+"精神焕发地从洗象池中爬了上来。\n",
			 environment(me), ({ me }) );
	}
	else {
		tell_object(me, GRN"过了一小会儿，你觉得在池中游累了，爬回池外。\n"NOR);
		message("vision", "只见"+me->name()+"从洗象池中爬了上来。\n",
                         environment(me), ({ me }) );
		me->improve_skill("force", random(me->query_con()/5));
		if (me->query("gender") == "女性")
			me->improve_skill("beauty", 5*me->query_per());
	}
	me->start_busy(1);
}
