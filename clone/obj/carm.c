//Cracked by Roath
// Carriage: /clone/obj/carm.c
// xbc: 04/15/1997

#include <ansi.h>
inherit ITEM;

void arrive(object, object, object, object, string, string, string);
int do_zuo(string arg);

void create()
{
        set_name(RED "大车" NOR, ({ "da che", "che", "carriage"}) );
	set_weight(500000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
	else {
		set("unit", "乘");
        	set("long", @LONG
这是一乘由两匹马拉着的大马车。大车前面坐着一个精神的老车夫。

车夫见有人看他，就高兴地说：俺是赶大车带新婚夫妇去扬州，杭州，泉州，
佛山，泰山，少林，神龙塘沽口，武当，峨嵋，大理，西夏，华山，星宿，
雪山，兰州等地旅游的。

LONG
	);
		set("value", 1000000);
		set("material", "steel");
		set("no_get",1);
	}
	setup();
}

void init()
{
//	add_action("do_zuo", "zuo");
//	add_action("do_zuo", "cheng");
	add_action("do_travel", "travel");
}

/*
int do_zuo(string arg)
{
	object me = this_player();
	object money = present("gold", me);

    	if( !arg || arg=="" ) return 0;

    	if( arg=="da che" || arg=="carriage" || arg=="che" || arg=="车") arg = "大车";

	message_vision(CYN "$N对车夫说：这位大叔，我想要雇" + arg + "！\n" NOR, me);

    	if( arg=="大车") {

		if ( !me->query_temp("marriage/newly_wed")) {
               		message_vision(CYN "车夫说道：哈哈，我是人家请来带新人们去旅行的！\n" +
				"车夫摇头道：我说您就别来这里凑热闹了吧。\n" NOR, me);
			return 1;
		}

      		message_vision(CYN "车夫说道：哈哈，我就是人家请来带你们去旅游的！\n" +
			"车夫高兴地说：您说吧，去哪里？\n" NOR, me);

        	return 1;
	}

    	else
        	message_vision(CYN "车夫疑惑地望着$N：嗯？ " + arg + "？\n" NOR, me);
    	return 1;
}
*/

int do_travel(string arg)
{
        object ob = this_object();
        object me = this_player();
        object spouse;

	object ob2; 
	string destin, destch, destmg;

	if ( !me->query_temp("marriage/newly_wed")) {
      		message_vision(CYN "车夫说道：哈哈，我是人家请来带新人们去旅行的！\n" +
			"车夫摇头道：我说您就别来这里凑热闹了吧。\n" NOR, me);
		return 1;
	}
        if( !(spouse = present(me->query("spouse/id"), environment(me)))) {
                message_vision(CYN "车夫笑眯眯地对$N说：怎么不见那位新人？两个人一起去嘛。 \n" NOR, me);
                return 1;
        }

	if ( !arg ) 
		return notify_fail(CYN "车夫疑惑地问：去哪里？\n" NOR);

	if ( arg == "wudang" || arg == "武当" ) {
		destin = "/d/wudang/shanmen";
		destch = "武当";
		destmg = "您从这里向南上山，不是武当弟子的要去进香才能上到三清殿。";
	}
	else if ( arg == "shaolin" || arg == "少林" ) {
		destin = "/d/shaolin/shanmen";
		destch = "少林";
		destmg = "这是少林山门，女客不能再上了，男香客可以去广场。进少林寺只有少林弟子和客人们才行。";
	}
	else if ( arg == "yangzhou" || arg == "扬州" ) {
		destin = "/d/city/kedian";
		destch = "扬州";
		destmg = "这是扬州客店。这里人多事儿多，好玩儿的地方也多着呐。";
	}
	else if ( arg == "xingxiu" || arg == "星宿" ) {
		destin = "/d/xingxiu/xxh2";
		destch = "星宿海";
		destmg = "这星宿海人烟稀少，附近倒是有个小镇。可是您别乱走，小心碰到不讲理的星宿弟子，或是走到沙漠里迷了路。";
	}
	else if ( arg == "shenlong" || arg == "神龙" ) {
		destin = "/d/shenlong/tanggu";
		destch = "塘沽口";
		destmg = "小的只能拉您到这儿了。要去神龙岛，您得自己叫船过海。您要想去，可千万小心，小的在这里等您一会儿。";
	}
	else if ( arg == "quanzhou" || arg == "泉州" ) {
		destin = "/d/quanzhou/zhongxin";
		destch = "泉州";
		destmg = "这是泉州中心，附近有几个海港。打这儿向西南再走几步，就是泉州武馆了。";
	}
	else if ( arg == "huashan" || arg == "华山" ) {
		destin = "/d/huashan/yunu";
		destch = "华山";
		destmg = "华山派就在南边。山上风景不错，您去转转，我在这儿等您一会儿。";
	}
	else if ( arg == "taishan" || arg == "泰山" ) {
		destin = "/d/taishan/wudafu";
		destch = "泰山";
		destmg = "唉，我的马上不去啦，您自己去吧。上山小心别摔着。山上有当今武林盟主，赏善罚恶使者。";
	}
	else if ( arg == "emei" || arg == "峨嵋" ) {
		destin = "/d/emei/baoguomen";
		destch = "峨嵋山";
		destmg = "这是峨嵋山脚啦，山太陡，马车上不去。门口有个小贩卖地图。爬峨嵋山可累人了，您悠着点儿。";
	}
	else if ( arg == "xueshan" || arg == "雪山" ) {
		destin = "/d/xueshan/shanmen";
		destch = "大雪山";
		destmg = "雪山派就在这附近，您别乱走，小心遇着雪崩。";
	}
	else if ( arg == "dali" || arg == "大理" ) {
		destin = "/d/dali/wangfu1";
		destch = "大理国"; 
		destmg = "这就是大理国的王府大门了。这大理可是富裕的好地方，什么东西都有。您慢慢逛吧。";
	}
	else if ( arg == "xixia" || arg == "西夏" ) {
		destin = "/d/xixia/oldwall";
		destch = "西夏国";
		destmg = "小的不能送您过河了，去西夏国，您自己叫船吧。小的在这儿等您一阵子。";
	}
	else if ( arg == "hangzhou" || arg == "杭州" ) {
		destin = "/d/hangzhou/kedian";
		destch = "杭州";
		destmg = "杭州的风景可是天下一流的，你们慢慢转吧。";
        }
	else if ( arg == "lanzhou" || arg == "兰州" ) {
		destin = "/d/qilian/lanzhou";
		destch = "兰州";
		destmg = "兰州可有好些好地方，地方不小，你们别走丢了。";
	}
        else if ( arg == "foshan" || arg == "佛山" ) {
                 destin = "/d/foshan/ngate";
                 destch = "佛山";
                 destmg = "佛山的路可是新开的。这里北接武当，东至泉州，西通大理，交通便利，您慢慢逛吧。";
	}
	else return notify_fail(CYN "车夫不好意思地说：啊，小的不熟悉那边的路，不知道怎么去。\n" NOR);

	message_vision(HIC "$N和$n坐进大车，$N对车夫说了几句话。\n车夫扬起手中鞭，吆喝着：看车，看车！去"+destch+"喽！\n" NOR, me, spouse);
  	tell_room(environment(me),"马车慢慢跑了起来，越走越远，过了一会儿就不见了。\n\n", me);

	ob2 = new(__DIR__"carm2.c");

	me->move(ob2);
	spouse->move(ob2);

	ob->move(__DIR__"car3");
	tell_room(environment(me), "你们坐在马车里，浑然不知外面的情景。马车晃晃悠悠，停停走走，不知过了多少天……\n\n");

	me->start_call_out( (:call_other, __FILE__, "arrive", me, spouse, ob2, ob, destin, destch, destmg :), 60);

	return 1;
}

void arrive(object me, object spouse, object ob2, object ob, string destin, string destch, string destmg)
{
	ob->move(destin);
	me->move(destin);
	spouse->move(destin);

        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob2);

	tell_room(environment(me),"两匹马拉着一乘大车跑了过来，车夫一声吆喝，马车停了下来。\n");

        message_vision("车夫大声说：“到啦，这里就是"+destch+"。”随即掀开车门。\n" + RED + "$N和$n携手从车上走了下来。\n" NOR, me, spouse );
        message_vision("车夫又说：“"+destmg+"”\n", me );
        message_vision("车夫将大车赶到一旁，开始打盹儿。\n\n", me );

}

void destroy_it(object obj)
{
        destruct(obj);
}

