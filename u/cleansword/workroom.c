//Cracked by Kafei
// Room: workroom.c
// CLEANSWORD

#include <ansi.h>

inherit ROOM;

void create()
{

	set("short", "清平剑工作室");
	set("long", @LONG
	这里是清平剑的工作室。房间里黑乎乎的，有一只打碎了半边的灯泡
挂在空中荡来荡去。地板年久失修，踩上去吱呀吱呀地响。一把断了一条腿的凳
子斜靠在墙角边。地上堆满了各种各样破破烂烂的程序。有些已经放了好久，并
开始发霉腐烂了。
LONG
	);


	set("valid_startroom",1);

	set("exits", ([
                "hs" : "/d/huashan/buwei1",
                "kd" : "/d/city/kedian",
                "sl" : "/d/shaolin/guangchang1",
                "wg" : "/d/wudang/sanqingdian",
                "gb" : "/d/gaibang/undertre",
                "xx" : "/d/xingxiu/xxh2",
                "wz" : "/d/wizard/guest_room",
                "xs" : "/d/xueshan/guangchang",
                "bt" : "/d/xingxiu/btyard",
                "em" : "/d/emei/hz_guangchang",
                "sg" : "/d/shenlong/tingkou",
                "dl" : "/d/dali/wangfu1",
                "th" : "/d/taihu/qianyuan",
	]));

	setup();
//	replace_program(ROOM);

}

void init()
{
	if(this_player()->query("id") == "cleansword") {
		this_player()->set("title",HIR"一步"HIW"杀"HIR"十人，万里不留行"NOR);
		this_player()->set("nickname",HIW"之"HIY"剑定乾坤"NOR);
	}
}


