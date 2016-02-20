//Cracked by Roath
// Carriage: /clone/obj/car.c
// xbc: 04/15/1997
// modified by aln 4 / 98
// added check for hs dizi, sdong 07/24/98
// added check busy by maco 2/19/2000

#include <ansi.h>
inherit ITEM;

void arrive(object, object, object, string, string, string);
int do_hire(string arg);

void create()
{
	set_name("大车", ({ "da che", "che", "carriage"}) );
	set_weight(10000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "乘");
		set("long", @LONG
这是一乘由两匹马拉着的大车。大车前面坐着一个老车夫，手里握着只长鞭。
他嘴里不停着哼哼着什么，心不在焉地四周望着。

车夫见有人看他，就懒洋洋地说：雇大车吗？俺带您去扬州，杭州，泉州，
泰山，少林，神龙塘沽口，武当，峨嵋，大理，西夏，华山，星宿，雪山，
兰州，佛山、终南山……

LONG
	);
		set("value", 1000000);
		set("material", "steel");
		set("no_get",1);
		set("no_clean_up", 1);
	}
	setup();
}

void init()
{
	add_action("do_hire", "hire");
	add_action("do_hire", "gu");
	add_action("do_travel", "qu");
}

int do_hire(string arg)
{
	object me = this_player();

	if( !arg || arg== "" ) return 0;

	if( !(arg == "da che" || arg == "carriage" || arg == "che" || arg == "车") ) {
		message_vision("车夫疑惑地望着$N：嗯？ " + arg + "？\n", me);
		return 1;
	}

	message_vision("$N对车夫说：这位大叔，我想要雇大车！\n", me);

	if( me->query("mud_age") < 24000 && me->query("combat_exp") < 200 ) {
		message_vision("车夫盯着$N看了一会儿，说道：哈哈，我看您象是新来此地的吧？\n" +
		"车夫把$N拉到一旁说：此间有个大财主，说是要交朋友，所以包下这辆大车给你坐一个月。\n" +
		"车夫挺了挺腰，大声道：您说吧，去哪里？\n", me);
		me->set_temp("paid", 1);
		return 1;
	}

// modified by qfy: to prevent huashan dizi who are currently doing job to leave huashan.
	if( me->query_condition("hz_job") ) {
		message_vision("车夫连连拱手陪笑对$N说道：客官呐，真对不起，小的今天赶了一整天车，正打算在这里\n" +
		"打个盹儿歇一歇脚，请您多多包涵。\n", me);
		return 1;
	}

	if( me->query_temp("paid") ) {
		message_vision("车夫对$N说：客官呐，您刚才给的钱还够用一阵子呢。您说要去哪里吧！\n", me);
		return 1;
	}
			
	switch (MONEY_D->player_pay(this_player(), 1000)) {
	case 0:
		write("穷光蛋，一边呆着去！\n");
		return 1;
	case 2:
		write("您的零钱不够了，银票又没人找得开。\n");
		return 1;
	default:
		break;
	}

	message_vision("$N掏出十两银子给车夫。车夫拿在手里掂了掂，高兴地收了起来。\n", me);
	message_vision("车夫地对$N点点头说：多谢您老！您想要雇车去哪里？\n", me);
	me->add_temp("paid", 2);
	return 1;
}

int do_travel(string arg)
{
	object ob = this_object();
	object me = this_player();
	object ob1, ob2; 
	string destin, destch, destmg;

	if( !arg ) {
		write("车夫疑惑地问：去哪里？\n");
		return 1;
	}

	if( me->query_condition("hz_job") ) {
		write("车夫陪着笑脸道：岳不群掌门人有令：不许俺们载巡山的弟子出山！\n这位" + RANK_D->query_respect(me) +
		"，实在是对不起啦。\n");
		return 1;
	} // added by sdong


	if( !me->query_temp("paid") ) {
		if ( me->query("mud_age") < 24000 && me->query("combat_exp") < 200 ) {
		message_vision("车夫盯着$N看了一会儿，说道：哈哈，我看您象是新来此地的吧？\n" +
	       "车夫把$N拉到一旁说：此间有个大财主，说是要交朋友，所以包下这辆大车给你坐一个月。\n", me);
		me->set_temp("paid", 1);
		} else {
		write("车夫嚷嚷道：喂，这位" + RANK_D->query_respect(me) +
		"不付钱，就想白坐大车啊？\n" +
		"车夫嘿嘿一笑：我看您还是自己走路吧！\n");
		return 1;
		}
       
	}

	if( me->is_busy() ) {
		write("车夫说道：等" + RANK_D->query_respect(me) + "您忙完了，小的立刻上路。\n");
		return 1;
	}

	if( arg == "wudang" || arg == "武当" ) {
		destin = "/d/wudang/shanmen";
		destch = "武当";
		destmg = "您从这里向南上山，不是武当弟子的要去敬香才能上到三清殿。";
	} else if( arg == "shaolin" || arg == "少林" ) {
		destin = "/d/shaolin/shanmen";
		destch = "少林";
		destmg = "这是少林山门，女客不能再上了，男香客可以去广场。进少林寺只有少林弟子和客人们才行。";
	} else if( arg == "yangzhou" || arg == "扬州" ) {
		destin = "/d/city/kedian";
		destch = "扬州";
		destmg = "这是扬州客店。这里人多事儿多，好玩儿的地方也多着呐。";
	} else if( arg == "xingxiu" || arg == "星宿" ) {
		destin = "/d/xingxiu/xxh2";
		destch = "星宿海";
		destmg = "这星宿海人烟稀少，附近倒是有个小镇。可是您别乱走，小心碰到不讲理的星宿弟子，或是走到沙漠里迷了路。";
	} else if( arg == "shenlong" || arg == "神龙" || arg == "塘沽" ) {
		destin = "/d/beijing/tanggu";
		destch = "塘沽口";
		destmg = "小的只能拉您到这儿了。要去神龙岛，您得自己叫船过海。您要想去，可千万小心，小的在这里等您一会儿。";
	} else if( arg == "quanzhou" || arg == "泉州" ) {
		destin = "/d/quanzhou/zhongxin";
		destch = "泉州";
		destmg = "这是泉州中心，附近有几个海港。打这儿向西南再走几步，就是泉州武馆了。";
	} else if( arg == "huashan" || arg == "华山" ) {
		destin = "/d/huashan/yunu";
		destch = "华山";
		destmg = "华山派就在南边。山上风景不错，您去转转，我在这儿等您一会儿。";
	} else if( arg == "taishan" || arg == "泰山" ) {
		destin = "/d/taishan/wudafu";
		destch = "泰山";
		destmg = "唉，我的马上不去啦，您自己去吧。上山小心别摔着。山上有当今武林盟主，赏善罚恶使者。";
	} else if( arg == "emei" || arg == "峨嵋" ) {
		destin = "/d/emei/baoguomen";
		destch = "峨嵋山";
		destmg = "这是峨嵋山脚啦，山太陡，马车上不去。门口有个小贩卖地图。爬峨嵋山可累人了，您悠着点儿。";
	} else if( arg == "xueshan" || arg == "雪山" ) {
		destin = "/d/xueshan/shanmen";
		destch = "大雪山";
		destmg = "雪山派就在这附近，您别乱走，小心遇着雪崩。";
	} else if( arg == "dali" || arg == "大理" ) {
		destin = "/d/dali/wangfu1";
		destch = "大理国"; 
		destmg = "这就是大理国的王府大门了。这大理可是富裕的好地方，什么东西都有。您慢慢逛吧。";
	} else if( arg == "xixia" || arg == "西夏" ) {
		destin = "/d/xixia/oldwall";
		destch = "西夏国";
		destmg = "小的不能送您过河了，去西夏国，您自己叫船吧。小的在这儿等您一阵子。";
	} else if( arg == "hangzhou" || arg == "杭州" ) {
		destin = "/d/hangzhou/kedian";
		destch = "杭州";
		destmg = "杭州的风景可是天下一流的，您自己慢慢转吧。";
	} else if( arg == "lanzhou" || arg == "兰州" ) {
		destin = "/d/qilian/lanzhou";
		destch = "兰州";
		destmg = "兰州可有好些好地方，地方不小，您小心别转丢了。";
	} else if( arg == "foshan" || arg == "佛山" ) {
		destin = "/d/foshan/ngate";
		destch = "佛山";
		destmg = "佛山的路可是新开的。这里北接武当，东至泉州，西通大理，交通便利，您慢慢逛吧。";
	} else if( arg == "zhongnanshan" || arg == "zhongnan" || arg == "终南山" ) {
		destin = "/d/zhongnan/shenheyuan";
		destch = "终南山";
		destmg = "终南山可是全真教的大本营，全真武功是天下武学正宗。这里还有一座古墓，一般人是不让靠近的，听说里面有机关。终南山可大着呢，您慢慢逛吧。";
	} else if( arg == "dongbei" || arg == "东北" || arg == "changbai" || arg == "长白山" ) {
		destin = "/d/changbai/jishi";
		destch = "东北";
		destmg = "这儿是赫图阿拉城，往东去就是长白山了，一路上都是冰天雪地，上路前最好带些皮毛衣装，小的不能送您过去了。";
	} else {
		write("车夫不好意思地说：啊，小的不熟悉那边的路，不知道怎么去。\n");
		return 1;
	}

	message_vision("$N坐进大车，对车夫说了几句话。\n车夫扬起手中鞭，吆喝着：看车，看车！去"+destch+"喽！\n\n", me);
	tell_room(environment(me), "马车慢慢跑了起来，越走越远，过了一会儿就不见了。\n\n", me);

	ob2 = new(__DIR__"car2.c");
	me->move(ob2);

	if( !objectp(ob1 = find_object(__DIR__"car3")) ) 
		ob1 = load_object(__DIR__"car3");
	ob->move(ob1);
	tell_object(me, "你坐在马车里，浑然不知外面的情景。马车晃晃悠悠，停停走走，不知过了多少天……\n\n");

	me->start_busy(16); // set the busy time to the same as arrive time, otherwise player
						// may quit in da che and cannot arrive at dest.. sdong
	me->add_temp("paid", -1);

	remove_call_out("arrive");
	call_out("arrive", 30, me, ob2, ob, destin, destch, destmg);

	return 1;
}

void arrive(object me, object ob2, object ob, string destin, string destch, string destmg) 
{
    if( ob ) ob->move(destin);
	if( me ) me->move(destin);

	remove_call_out("destroy_it");
	call_out("destroy_it", 1, ob2);

	tell_room(environment(me),"两匹马拉着一乘大车跑了过来，车夫一声吆喝，马车停了下来。\n");

	message_vision("车夫大声说：“到啦，这里就是"+destch+"。”随即掀开车门。\n$N从车上走了下来。\n", me );
	message_vision(CYN "车夫又说：“"+destmg+"”\n" NOR, me );
	message_vision("车夫将大车赶到一旁，开始打盹儿。\n\n", me );
}

void destroy_it(object obj)
{
	destruct(obj);
}
