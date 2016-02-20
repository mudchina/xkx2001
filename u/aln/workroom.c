//Cracked by Kafei
// qfy's workroom

#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
	set("short",GRN "青天大地" NOR);
	set("long", @LONG
	
辽辽青天，巍巍大地，皆任我畅游。凡尘俗事，且去休去休！

------------------------------------------------------        
华山hs，泉州qz，杨州yz，泰山ts，少林sl，武当wd，祈连ql
丐帮gb，星宿xx，峨嵋em，白驼bt，雪山xs，昆仑kl，神龙sn  
西夏xi，归云gy，大理dl，杭州hz，急诊er，巫师wr
------------------------------------------------------

LONG
	);
	set("no_fight", 1);
	set("objects", ([
		__DIR__"yumiko" : 1,
	]));
					      
	set("valid_startroom",1);
					      
	set("exits", ([
                "kl" : "/d/kunlun/wall5",
                "sl" : "/d/shaolin/guangchang1",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wd" : "/d/wudang/sanqingdian",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
                "gy" : "/d/taihu/qianyuan",
                "hs" : "/d/huashan/buwei1",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1",
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
		"yz" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
                "hs" : "/d/huashan/buwei1",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1",
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
                "wr": "/d/wizard/meeting_room",                                                             
	]));

	setup();
	//replace_program(ROOM);
}

void init()
{
	object me = this_player();

	if( wizardp(me) && getuid(me)!="qfy ")
		message("vision", me->name()+"走了过来。\n", environment(me), ({me}));

	add_action("do_leave", "leave");
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me))
		return notify_fail("由美子挡在你面前，恭身说道：“非常抱歉，您不能到那儿去。”\n");

	return ::valid_leave(me, dir);
}

int do_leave()
{
	object me = this_player();
	if(me)
		me->move("/d/city/wumiao");
	return 0;
}
