//Cracked by Roath
// duguan1.c 睹光台
// Shan: 96/06/22

#include <ansi.h>

inherit ROOM;
string long_desc();

void create()
{
        set("short", "睹光台");
        set("long", (: long_desc :));
//	set("long", @LONG
//这里是看日出、云海、佛光、神灯之地。台下深崖万丈，陡彻无底，云遮
//雾掩。极目四望，数百里外的大小雪山皆历历在目。
//LONG
//	);
	set("exits", ([
		"north" : __DIR__"huazang",
		"west" : __DIR__"duguang2",
	]));

        set("objects", ([
                "/kungfu/class/emei/bei.c" :1,
        ]));

        set("no_clean_up", 0);
//        set("outdoors", "emei" );

	setup();
//	replace_program(ROOM);

}

string long_desc()
{
        int t;  // time of the day in minutes
	mixed local;
        string desc;

        desc  = "这里是看日出、云海、佛光、神灯之地。台下深崖万丈，陡彻无底，云遮\n";
        desc += "雾掩。极目四望，数百里外的大小雪山皆历历在目。\n";

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
}

int do_jump(string arg)
{
        object me = this_player();

        int t; 
        mixed local;

        local = localtime(time()*60);
        t = local[2]*60 + local[1];

        if ( !arg || arg == "" ) return 0;

        if ( arg == "cliff" ) {
                if ( (t >= 720 && t < 840) && (me->query_temp("seen_fo")>0) 
                && (me->query("kar") > random(30) ) ) {
	                me->delete_temp("seen_fo");
			message_vision("$N纵身跳下舍身崖。\n", me);
			call_out("to_pool", 1, me);
	                return 1;
                }
                else {
			message_vision("$N纵身跳下舍身崖。\n", me);
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
//	me->move(__DIR__"clifftree2");
	call_out("climb_up", 1);

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

	tell_object(me, "你再向下爬了一会儿，发现绳子不够长，只得爬上来。\n");
	me->move(__DIR__"duguang1");
	message("vision", me->name()+"过了一会儿又满头大汗地爬上来了。\n", environment(me), ({me}) );
	me->add("jingli",-50);
	return 1;

}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("tied") && (dir == "north" || dir == "west"))
		me->delete_temp("tied");
		me->delete_temp("seen_fo");

	return ::valid_leave(me, dir);
}

#include "/d/emei/cliff.h"
