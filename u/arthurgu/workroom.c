//Cracked by Kafei
inherit ROOM;
#include <ansi.h>
void reset();
int valid_leave();

void create()
{
        set("short", MAG"情味小屋"NOR);
        set("long", "
    这是寻欢的工作室,你一走进来就有一种心动的感觉,似乎触动了
几根情丝.张眼望去,墙上挂着一张巨大的"+HIW"图画(picture)"NOR+"，让你忍
不住多看几眼,窗台上则放着一盆情花,花瓣色彩奇异,令人绚目.

"

        );

        set("exits", ([
                "sl" : "/d/shaolin/guangchang1",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wud" : "/d/wudang/sanqingdian",
                "xk" : "/d/xiakedao/dadong",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
                "gb2" : "/d/gaibang/gbxiaowu",
                "gy" : "/d/taihu/qianyuan",
                "kd" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",

                "hs" : "/d/huashan/pianting",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1", 
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
                "qfy" : "/u/qfy/workroom",
                "lyu" : "/u/lyu/workroom",
                "kane" : "/u/kane/workroom",
                "xbc" : "/u/xbc/workroom",
                "cls" : "/u/cleansword/workroom",
                "rover" : "/u/rover/workroom",

                "marz" : "/u/marz/workroom",
                "mgl" : "/u/mongol/workroom",
                "xuy" : "/u/xuy/workroom",
                "ox" : "/u/oyxb/workroom",
                "dg" : "/u/ding/workroom", 
                "chu" : "/u/chu/workroom",
                "ssy" : "/u/ssy/workroom",
                "dong" : "/u/sdong/workroom",
                "td" : "/d/taohua/jingshe",
                "yongan" : "/d/beijing/west/yonganmen.c",
                "tianan" : "/d/beijing/zijin/tiananmen",
        ]));
        set("objects", ([
                __DIR__"obj/renshen-guo" : 1,
                __DIR__"obj/fan" : 1,
                __DIR__"obj/namechange" : 1,
                __DIR__"npc/meimei" : 1,
    
        ]));
        set("item_desc", ([
              "picture" :
"
  ---------------------------------------------------------------
    少林: sl      武当: wud     星宿: xx     丐帮: gb     白驼: bt
    华山: hs      侠客: xk      客店: kd     雪山: xs     峨嵋: em
    大理: dl      神龙: sn      西夏: xi     桃花: td     归云: gy
   
    
    剑室: cls     菜窖: xbc     枫林: qfy    狼窟: kane   丁库: dg
    火星: marz    蒙古: mgl     燕窝: xuy    鱼缸: lyu    猫窝: ox 
    秦俑: chu     董室: dong    宠物: ssy
    
             
  ---------------------------------------------------------------
\n",
              ]));

        set("valid_startroom",1);
               
        setup();
        
}

int valid_leave(object me, string dir)
{
        if ((string)me->query("id")!="arthurgu"){
                return notify_fail("你为情所困，一步也迈不出去。\n");
        }
  
        return ::valid_leave(me, dir);        return 1;
}
