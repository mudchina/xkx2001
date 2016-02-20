//Cracked by Kafei
inherit ROOM;
#include <ansi.h>
void reset();
int valid_leave();

void create()
{
        set("short", HIG"柳荫"NOR);
        set("long", @LONG
你到目前为止总共杀了 2231 个人，其中有 29 个是其他玩家
---------------------------------------------------------------
    少林: sl      武当: wn      星宿: xx     丐帮: gb     白驼: bt
    华山: hs      侠客: xk      客店: kd     雪山: xs     峨嵋: em
    大理: dl      神龙: sn      西夏: xi     桃花: td     归云: gy
    
    剑室: cls     菜窖: xbc     枫林: qfy    狼窟: kane   丁洞: dg
    蒙古: mgl     燕窝: xuy     鱼缸: lyu    猫窝: ox 
    洞房: sdong   厨房: chu     卧房: ssy    龙潭: long   机场: acep 

---------------------------------------------------------------
LONG
        );

        set("exits", ([
                "sl" : "/d/shaolin/guangchang1",
		"sn" : "/d/shenlong/tingkou",
		"xi" : "/d/xixia/dawu",
		"hz" : "/d/hangzhou/kedian",
                "wn" : "/d/wudang/sanqingdian",
		"xk" : "/d/xiakedao/dadong",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
		"gb2" : "/d/gaibang/gbxiaowu",
		"gy" : "/d/taihu/qianyuan",
                "kd" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
		"hs" : "/d/huashan/pianting",
		"bt" : "/d/xingxiu/btyard",
		"wr" : "/d/wizard/meeting_room", 
		"wz" : "/d/wizard/wizard_room",
		"dl" : "/d/dali/wangfu1", 
		"em" : "/d/emei/hz_guangchang",
		"xs" : "/d/xueshan/guangchang",
		"qfy" : "/u/qfy/workroom",
		"lyu" : "/u/lyu/workroom",
		"kane" : "/u/kane/workroom",
		"xbc" : "/u/xbc/workroom",
		"ssy" : "/u/ssy/workroom",
		"cls" : "/u/cleansword/workroom",
		"rover" : "/u/rover/workroom",
		"marz" : "/u/marz/workroom",
		"acep" : "/u/acep/workroom",
		"long" : "/u/long/workroom",
		"chu" : "/u/chu/workroom",
		"aln" : "/u/aln/workroom",
		"mgl" : "/u/mongol/workroom",
		"xuy" : "/u/xuy/workroom",
		"ox" : "/u/oyxb/workroom",
		"dg" : "/u/ding/workroom", 
		"td" : "/d/taohua/jingshe",
		"enter" : "/u/ryu/room2",
		"up" : "/u/ryu/room3",
        ]));
	set("objects", ([
                __DIR__"obj/renshen-guo" : 1,
                __DIR__"obj/atm" : 1,
                __DIR__"obj/fan" : 1,
        ]));
        set("valid_startroom",1);

        setup();
}
int valid_leave(object me, string dir)
{
        if ((string)me->query("name")!="柳下逸"){
                return notify_fail("柳下逸一把揪住你的衣领说：“慢着，你脑袋没留下怎麽能走！”\n");
	}
        return ::valid_leave(me, dir);
}

