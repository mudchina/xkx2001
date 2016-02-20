//Cracked by Roath
// xiaolu1.c 华山密室
// qfy 10/8/1997

# include <room.h>
inherit ROOM;
inherit F_SSERVER;

void create()
{
	set("short", "密室");
	set("long", @LONG
密室内的石墙(wall)上由大青石砌成，里头空空荡荡的甚麽也没有。
周围放着几个数人才能合抱的大油缸，供应着灯火的燃料，把密室照得相
当明亮。
LONG
	);
	
	set ("item_desc", ([
		"wall" : 
"你伸手推向刚人的石门，用尽全力，石门却纹风不动，似乎只能由外面开\n"
"启。你仔细的在墙上敲打搜寻许久，又发现了另一扇与石墙吻合细密的石\n"
"门(door)。\n",
	])  ) ;

	set("cost", 0);
	setup();
}

void init()
{
	object me = this_player();

	if ( me->query("huashan/yin-jue") < 2 ) {
		remove_call_out("close_door");
		call_out("close_door", 1, me);
	}

	add_action("do_biguan", "biguan");
	add_action("do_biguan", "闭关");
	add_action("do_push", "push");
}

int close_door(object me)
{
	message_vision("你身後的石门自动缓缓的关上。\n", me);
	return 1;
}

int do_biguan(string arg)
{
	object me = this_player();
	int bili, wuxing, gengu, shenfa;
	int sum, num1, num2, num3, num4;

	if ( !arg ) return notify_fail("你还是再看看紫霞遗页吧，小心别把功法搞错了才来遗憾！\n");

	if ( sscanf(arg, "%d %d %d %d", bili, wuxing, gengu, shenfa) != 4  ) 
		return notify_fail("你还是再看看紫霞遗页吧，小心别把功法搞错了才来遗憾！\n");
	
	if ( me->query("huashan/yin-jue") > 1 )
		return notify_fail("你任督二脉及生死玄关已通，不必再闭关了。\n");

	if ( bili < 0 ) return notify_fail("膂力值须大於零！\n");
	if ( gengu < 0 ) return notify_fail("根骨值须大於零！\n");
	if ( shenfa < 0 ) return notify_fail("身法值须大於零！\n");
	if ( wuxing < 0 ) return notify_fail("悟性值须大於零！\n");

	sum =  bili + wuxing + gengu + shenfa;

	if ( sum != 4 ) return notify_fail("所增各项天赋值的总和须为四点！\n");

	message_vision("$N盘膝坐下，凝神定意，倚着心法缓吐深纳地打坐。\n", me);
	me->start_busy(12);

	remove_call_out("stage1");
	call_out("stage1", 3, me, (int)bili, (int)wuxing, (int)gengu, (int)shenfa);

	return 1;
}

int stage1(object me, int bili, int wuxing, int gengu, int shenfa)
{
	tell_object(me, "不久，你只觉得丹田中有股暖气渐渐凝聚，越聚越强。\n");
	tell_object(me, "你驱动这股内力扩向四肢百骸，游走於各处奇经八脉。\n");
	
	remove_call_out("stage2");
	call_out("stage2", 5, me, bili, wuxing, gengu, shenfa);

	return 1;
}

int stage2(object me, int bili, int wuxing, int gengu, int shenfa)
{
	tell_object(me, "良久，你全身真气澎湃，如置火炉，但平日内力难以运转的经脉有渐渐疏通的现向。\n");
		
	remove_call_out("stage3");
	call_out("stage3", 4, me, bili, wuxing, gengu, shenfa);

	return 1;
}

int stage3(object me, int bili, int wuxing, int gengu, int shenfa)
{
	object env, link_ob, obj, place;

	if ( !me->query_skill("ziyin-yin") || !me->query_skill("zhengqi-jue") || !me->query_skill("zixia-gong") ) {
		tell_object(me, "突然一股真气冲抵心口，似乎砰上了阻扰，你连连加力，却三番四次都冲不过去。\n");
		tell_object(me, "你觉得胸口逐渐麻木，而且麻处不断向周围扩散，四周也似乎愈来愈冷！\n");
		tell_object(me, "你张口欲呼却哑然无声，但耳边可闻阵阵焦雷在头顶上炸开！全身血气似乎涌在喉头！\n");
		message_vision("$N突然喷出一口紫红的鲜血！惊慌万状，不由得挥动双手，在地下激烈翻滚！\n", me);
		me->add("max_neili", -300);
		me->add("max_jingli", -300);
		me->add("str", -1);
		me->add("dex", -1);
		me->add("con", -1);
		me->receive_wound("qi", me->query("max_qi")+100, "打坐走火入魔死了");
	}
	else if ( me->query_skill("ziyin-yin", 1) < 80 || me->query_skill("zhengqi-jue", 1) < 80
	|| me->query_skill("zixia-gong", 1) < 100 ) {
		tell_object(me, "突然一股真气冲抵心口，似乎砰上了阻扰，你连连加力，却三番四次都冲不过去。\n");
		tell_object(me, "你觉得胸口逐渐麻木，而且麻处不断向周围扩散，四周也似乎愈来愈冷！\n");
		tell_object(me, "你张口欲呼却哑然无声，但耳边可闻阵阵焦雷在头顶上炸开！全身血气似乎涌在喉头！\n");
		message_vision("$N喷出一口紫红的鲜血！无奈之下，只好倒在地下照紫氤正气心法缓缓收敛真气。\n", me);
		me->add("max_neili", -150);
		me->add("max_jingli", -150);
		me->receive_wound("qi", me->query("max_qi")/2, "打坐走火入魔死了");
		tell_object(me, "过了良久，你觉得麻痹渐止，慢慢能动了。\n");
		message_vision("$N双手撑地，缓缓坐了起来，显得功力大损，体虚力弱，神情极之萎靡！\n", me);
	}
	else if ( me->query_skill("ziyin-yin", 1) < 120 || me->query_skill("zhengqi-jue", 1) < 120
	|| me->query_skill("zixia-gong", 1) < 150 ) {
		tell_object(me, "突然一股真气冲抵心口，似乎砰上了阻扰，你连连加力，却三番四次都冲不过去。\n");
		tell_object(me, "你觉得胸口逐渐麻木，而且麻处不断向周围扩散，四周也似乎愈来愈冷！\n");
		tell_object(me, "你连忙依照紫氤氤和正气诀的心法凝神思定，缓缓收敛散乱了的内力将其导入内腑。\n");
	}
	else {
		place = environment(me);

		tell_object(me, "你觉得真气飓盛，各处穴道彷如万针穿刺，难受之极！\n");
		tell_object(me, "突然似乎有个焦雷在你天庭穴上炸开，那往各处穴道穿刺的万针亦同时将穴道打通。\n");
		tell_object(me, "你只觉全身上下有十多条水柱在经脉间流窜，畅通无比，十分舒泰。\n");
		me->add("str", bili);
		me->add("dex", shenfa);
		me->add("int", wuxing);
		me->add("con", gengu);
		me->add("huashan/yin-jue", 1);
		me->add("max_neili", 200);

		link_ob = me->query_temp("link_ob");
		obj = LOGIN_D->make_body(link_ob);
		if (!obj) return 0;

		me->save();
		exec(link_ob, me);
		destruct(me);

		obj->restore();
		LOGIN_D->enter_world(link_ob, obj, 1);

		write("你天赋及功力大增了！\n\n");
		obj->move(place);
		obj->write_prompt();

		obj->set("neili", me->query("max_neili"));
		obj->set("jingli", me->query("max_jingli"));
		obj->set("eff_qi", me->query("max_qi"));
		obj->set("qi", me->query("max_qi"));
		obj->set("eff_jing", me->query("max_jing"));
		obj->set("jing", me->query("max_jing"));
		obj->save();
	}

	return 1;
}

int do_push(string arg)
{
	object me = this_player();

	if ( !arg ) return notify_fail("你想推甚麽？\n");

	if ( arg != "door" ) return notify_fail("你不能推动这样东西！\n");

	message_vision("$N双掌平伸，运起内力推向石门。\n", me);

	if ( me->query("huashan/yin-jue") < 2 ) {
		if ( me->query("neili") < 300 ) {
			me->set("neili", 0);
			message_vision("$N用尽全力，累得浑身大汗淋漓，石门却依然分毫不动。\n", me);
			return 1;
		}
		
		me->add("neili", -300 );
	}

	message_vision("石门在$N的推动下发出一阵轰响，缓缓往後移，一寸一寸的开启了。\n", me);
		
	set("exits/out", __DIR__"outmishi");            
	remove_call_out("auto_close");
	call_out("auto_close", 5, this_object());

	return 1;
}

void auto_close(object room)
{
	message("vision","石门突然发出一阵轰响，自动关闭起来。\n", room);
	room->delete("exits/out");
}       
