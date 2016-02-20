//Cracked by Roath
// duguang2.c 睹光台舍身崖
// Shan: 96/06/22

#include <ansi.h>

inherit ROOM;
string long_desc();

void create()
{
        set("short", "睹光台舍身崖");
        set("long", (: long_desc :));

	set("exits", ([
		"enter" : __DIR__"woyun",
		"east" : __DIR__"duguang1",
	]));

        set("item_desc", ([
                "cliff": "舍身崖下浮云飘飘，深不见底，你不禁打了个哆嗦。\n",
        ])  ) ;

        set("no_clean_up", 0);
	setup();
}

string long_desc()
{
	object me = this_player();

        int t;  // time of the day in minutes
	mixed local;
        string desc;

        desc  = "从卧云庵出来，这里是看日出、云海、佛光、神灯之地。台下深崖万丈，\n";
        desc += "陡彻无底，云遮雾掩。极目四望，数百里外的大小雪山皆历历在目。因为这里\n";
        desc += "至高至洁，至险至奇，又至美至幻，常有人在这里投身云海，舍此肉身尘世。\n";

        local = localtime(time()*60);
        t = local[2]*60 + local[1];

        // morning    5:00am -  7:30am   日出
        // noon      10:30am - 12:00pm   云海
        // afternoon 12:00am -  2:00pm   佛光 
        // afternoon  2:00pm - 18:00pm   云海
        // night     19:00pm -  5:00am   神灯

        // 05:00 - 11:30
        if ( t >= 400 && t < 600) {
               desc += HIR "    启明星刚刚升起，一道道微白的光在东方云层闪现，一轮红日托地跳出，\n" NOR;
               desc += HIR "大千世界顿时在彩阳映照下呈现出无限生机。\n" NOR;
        }
        // 11:30 - 12:30
        else if (( t >= 630 && t < 720) || ( t >= 840 && t < 1080)) {
                desc += HIC "　　金顶云海，迷迷茫茫，笼罩四野，远接天际。云海轻荡时，你在金顶，脚\n" NOR;
                desc += HIC "踏白云，大有飘飘欲仙之感；当云涛迅猛涌来时，整个金顶都似在向前浮动，\n" NOR;
                desc += HIC "令人有乘舟欲风之意。\n" NOR;
        }
        // 12:30 - 20:00
        else if ( t >= 720 && t < 840 ) {
                if( this_player()->query("kar") > random(30) ) {
                desc += HIY "　　日丽风静，云海平铺，美丽以极。阳光从你背面斜射下来，在舍身崖下形\n" NOR;
                desc += HIY "成彩色光环，你见到自己的身影清晰地出现在银色世界上。『光环随人动，人\n" NOR;
                desc += HIY "影在环中』，这就是奇妙的　※※※※※※※佛光※※※※※※※　。\n" NOR;
                desc += MAG "　　这里有一种使人献身的超人力量，令你不禁想要在此投身云海，摆脱人世\n" NOR;
                desc += MAG "的俗累，与天相接。\n" NOR;
		me->set_temp("seen_fo",1);
                }
                else
                        desc += NATURE_D->outdoor_room_description();
        }
        // 20:00 - 05:00
        else if (( t >= 1260 && t < 1440 ) || ( t >= 0 && t < 300)) {
                desc += HIB "　　初见金顶下黑黝黝一片，忽而闪现出一点、两点带蓝色的亮光，这种亮点\n" NOR;
                desc += HIB "越来越多，转眼便布满山谷，有的如流萤飘飞，有的如繁星闪烁。\n" NOR;

//              desc += HIB "    ※※※※※神灯※※※※※\n" NOR;
	}

        else 
                desc += NATURE_D->outdoor_room_description();

        return desc;
}

void init()
{
	add_action("do_tie", "tie");
	add_action("do_tie", "bang");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_jump", "jump");
	add_action("do_pull", "pull");
	add_action("do_push", "tui");
	add_action("do_push", "push");
}

int do_jump(string arg)
{
        object me = this_player();

        int t; 
        mixed local;

        local = localtime(time()*60);
        t = local[2]*60 + local[1];

        if ( !arg || arg == "" ) return 0;

	if(me->query_encumbrance() * 10 / me->query_max_encumbrance() > 10/100)
        return notify_fail("你带着太多东西，跳不下去。\n");
        if ( arg == "cliff" ) {
		message_vision("$N纵身跳下舍身崖。\n", me);
		remove_action("do_jump", "jump");
                if ( (t >= 720 && t < 840) && (me->query_temp("seen_fo")>0)) {
	                me->delete_temp("seen_fo");
                        if (me->query("kar") > 10+random(20) ) {
//Emei dizi will have a better chance, because they need to learn from zhou.
//佛法读得多，与佛有缘
				if ( (me->query_skill("mahayana", 1) > 90+random(20))
					|| (me->query_str() > 20+random(10) 
						&& me->query("dex") < 18
						&& me->query("con") > 18 
						&& me->query("int") < 25) 
					|| (random(100) == 1) ){
//require a low int here. 傻人有傻福。
					call_out("to_branch2", 1, me);
		                	return 1;
                        	}
			}
			switch( random(2) ) {
			case 0:
				call_out("to_branch1", 1, me);
				break;
			case 1:
				call_out("to_pool", 1, me);
				break;
			}
	                return 1;
                }
                else {
			call_out("to_cliff", 1, me);
	                return 1;
	        }
		return 0;
	}
	return 0;
}

int do_tie(string arg)
{
	object me = this_player();

        if ( !arg || arg == "" ) return 0;

	if ( arg == "tree" ) {
		if ( !present("sheng zi", me) )
			write("你拿什么来绑树啊？\n");
		else {
			message_vision("$N将绳子仔细地在松树上捆绑好。\n", me);
			me->set_temp("tied", 1);
		}
		return 1;
	}
	return 0;
}

int do_climb(string arg)
{
	object me = this_player();

	if ( arg && arg != "down" )
		return notify_fail("什么？\n");

	if ( !me->query_temp("tied") ){
		message_vision("$N向舍身崖下爬，忽然一个失手，直摔了下去。\n", me);
		call_out("to_cliff", 1, me);
		return 1;
	}
		
	message_vision("$N拉着绳子开始往下爬。\n", me);
	tell_object(me, "下面云雾缭绕，什么也看不清。\n");
//	me->move(__DIR__"clifftree1");
	call_out("climb_up", 2);

	return 1;
}

int destroy_corpse()
{
	object obj, room;

	if ( !( room = find_object(__DIR__"cliff") ) )
                room = load_object(__DIR__"cliff");

	if ( obj = present("corpse", room) ) destruct(obj);

	return 1;
}

int climb_up()
{
        object me = this_player();

	tell_object(me, "你向下爬了一会儿，发现绳子不够长，只得爬上来。\n");
	me->move(__DIR__"duguang2");
	message("vision", me->name()+"过了一会儿又满头大汗地爬上来了。\n", environment(me), ({me}) );
	tell_object(me, "唉，看来爬是爬不下去了。\n");
	me->receive_damage("jingli", 20, "爬山累死了");
	return 1;

}

int do_pull(string str)
{
        object ob, room;
	object me = this_player();
        int i;

        if (!str) return notify_fail("你想拉什么？\n");
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("这个人好象不在这里吧？\n");

	room = environment(ob);
//	if ( (string)file_name(room) != __DIR__"clifftree1" )
	if ( (string)room->query("short") != "罗汉松" )
        	return notify_fail("这个人好象不在舍身崖下的树上吧？\n");
	
	if ( (me->query_str() < ob->query_str()) || (me->query("jingli") < ob->query("jingli")) )
		return notify_fail("你没那么大劲能拉这个人上来。\n");

        tell_room(environment(ob),CYN"\n忽然有人从舍身崖上放下一根绳子，"+
        (string)ob->query("name")+"抓住绳子，被绳子拉了上去。\n"NOR, ob);
        tell_object(ob,CYN"\n忽然有人从舍身崖上放下一根绳子来，你抓住绳子，被人拉了上去。\n"NOR);
        ob->move(environment(me));
        tell_object(me, CYN"\n你使劲把"+(string)ob->query("name")+"从舍身崖下拉了上来。\n"NOR);
        tell_object(ob,CYN"你看到"+(string)me->query("name")+
        "正在绳子另一头，把你拉了上来。\n"NOR);
        tell_room(environment(ob),CYN + (string)me->query("name")+"放下一根粗绳子，"
		+"使劲把" + (string)ob->query("name")+"从崖下拉了上来。\n"NOR,({me,ob}));
	me->add("jingli", -(int)ob->query("jingli"));
        return 1;
}


int valid_leave(object me, string dir)
{
	if ( me->query_temp("tied") && (dir == "enter" || dir == "east"))
		me->delete_temp("tied");
		me->delete_temp("seen_fo");

	if ( me->query_temp("exit") && (dir == "enter" || dir == "east"))
                me->delete_temp("exit");

	return ::valid_leave(me, dir);
}


int do_push(string who)
{
        object victim, room;
	object me = this_player();
        int i;

        victim = present(who, environment(me));
        if (!who ) return notify_fail("你想推什么？\n");
        if (!victim ) return notify_fail("这个人不在这里吧。\n");
        if (victim==me) return notify_fail("自己跳吧。\n");

	message_vision("$N趁人不注意，猛的伸手去推$n！\n\n", me, victim);

	if ( (me->query_str() < victim->query_str()) || (me->query("jingli") < victim->query("jingli")) ) {
		message_vision("$N推了一下，没推动，反而摔倒了，头撞到一块大石上。\n", me);		
		me->unconcious();
		return 1;
	}

	else {
		message_vision("$n一个没站稳，直栽下去。\n", me, victim);		
		call_out("to_pool", 1, victim);
        	return 1;
	}
}
#include "/d/emei/cliff.h"
