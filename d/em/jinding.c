//Cracked by Roath
// jinding.c 金顶
// Shan: 96/06/22

#include <ansi.h>

inherit ROOM;
string long_desc();

void create()
{
        set("short", "金顶");
	set("long", (: long_desc :));
	set("exits", ([
		"northdown" : __DIR__"wanxing",
		"south" : __DIR__"huazang",
		"southwest" : __DIR__"woyun",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 2);
	setup();
//        replace_program(ROOM);

}

string long_desc()
{
	int t;	// time of the day in minutes
	mixed *local;
	string desc;
	
	desc  = "这就是峨嵋山的主峰金顶了。此峰耸立大地，高入云表，秀丽而又壮美，\n";
	desc += "李白赞颂它：『青冥倚天开，彩错疑画出。』登上金顶，视野豁然开朗，鸟看\n";
	desc += "脚下，但见群峰涌绿叠翠，三江如丝如带；回首远眺，则见大雪山横亘天际，\n";
	desc += "贡嘎山直插苍穹。\n";
/*
	local = localtime(time()*60);	
	t = local[2]*60 + local[1];

	// morning    5:00am -  7:30am   日出
	// noon      10:30am - 12:00pm   云海
	// afternoon 12:00am -  2:00pm   佛光 
	// afternoon  2:00pm - 18:00pm   云海
	// night     19:00pm -  5:00am   神灯

    	// 05:00 - 11:30
    	if ( t >= 300 && t < 450) {
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
                desc += HIY "影在环中』，这就是奇妙的『※※佛光※※』。\n" NOR;
                desc += MAG "　　这里至高至洁，至险至奇，至幻至美，有一种使人献身的超人力量。你不\n" NOR;
                desc += MAG "禁想要在此投身云海，舍此肉身尘世，摆脱人世的俗累，与天相接。\n" NOR;
//			desc += HIM "    ※※※※※佛光※※※※※\n" NOR;
		}
		else
			desc += NATURE_D->outdoor_room_description();
	}	
	// 20:00 - 05:00
	else if (( t >= 1260 && t < 1440 ) || ( t >= 0 && t < 300)) {
                desc += HIB "　　初见金顶下黑黝黝一片，忽而闪现出一点、两点带蓝色的亮光，这种亮点\n" NOR;
                desc += HIB "越来越多，转眼便布满山谷，有的如流萤飘飞，有的如繁星闪烁。\n" NOR;

//		desc += HIB "    ※※※※※神灯※※※※※\n" NOR;
	
	}
	else 
		desc += NATURE_D->outdoor_room_description();
*/
        return desc;

}


