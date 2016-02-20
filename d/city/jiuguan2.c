//Cracked by Roath
// jiuguan2.c
// xQin 7/00

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"酒馆二楼"NOR);
	set("long", @LONG
这里是酒馆二楼，走到这楼下的杂吵之声渐渐消失。几张八仙桌上座满了        
宾客。只见这里布置的甚为雅致，客人衣著光鲜，与方才楼下的情形大为不同
。四周挂著一些字画，其中还包括了一幅对联(duilian) ，和唐代著名诗人杜
甫的那首《饮中八仙歌》(poem)。柜台后挂着一块牌子(paizi) 。左边有位妙
龄少女正在卖艺。
LONG
	);
	set("no_beg", 1);
	set("exits", ([
	"down" : __DIR__"jiuguan",
	
	]));
	set("objects", ([
                __DIR__"npc/du" : 1,
                __DIR__"npc/genu" : 1,
                "/kungfu/class/misc/dingb3" : 1,
        ]));
        set("item_desc", ([ 
        "duilian" : WHT"
	＊＊＊＊＊                       ＊＊＊＊＊
	＊      ＊                       ＊      ＊
	＊  一  ＊	                 ＊  万  ＊
	＊  川	＊                       ＊  里  ＊
	＊  风	＊                       ＊  河  ＊
	＊  月  ＊                       ＊  山  ＊
	＊  留	＊                       ＊  尽  ＊
	＊  酣  ＊                       ＊  浩  ＊
	＊  饮  ＊                       ＊  歌  ＊
	＊      ＊                       ＊      ＊
	＊＊＊＊＊                       ＊＊＊＊＊\n\n"NOR,
	
	"poem" : CYN"
     ※※※※※※※※※※※※※※※※※※※※※※
     ※ ┏━━━━━━━━━━━━━━━━━┓ ※
     ※ ┃         <<饮中八仙歌>>           ┃ ※
     ※ ┃                                  ┃ ※
     ※ ┃  知章骑马似乘船，眼花落井水中眠。┃ ※
     ※ ┃  汝阳三斗始朝天，道逢曲车口流涎，┃ ※
     ※ ┃  恨不移封向酒泉。左相日兴费万钱，┃ ※
     ※ ┃  饮如长鲸吸百川，衔杯乐圣称避贤。┃ ※
     ※ ┃  宗之潇洒美少年，举觞白眼望青天，┃ ※
     ※ ┃  皎如玉树临风前。苏晋长斋绣佛前，┃ ※
     ※ ┃  醉中往往爱逃禅。李白一斗诗百篇，┃ ※
     ※ ┃  长安市上酒家眠，天子呼来不上船，┃ ※
     ※ ┃  自称臣是酒中仙。张旭三杯草圣传，┃ ※
     ※ ┃  脱帽露顶王公前，挥毫落纸如云烟，┃ ※
     ※ ┃  焦遂五斗方卓然，高谈阔论惊四筵。┃ ※
     ※ ┗━━━━━━━━━━━━━━━━━┛ ※
     ※※※※※※※※※※※※※※※※※※※※※※\n\n"NOR,
     "paizi" : "
     烤鸡腿(Jitui)              ：八十文铜板
     熟牛肉(Shou niurou)        ：一两白银又二十文铜板
     花雕酒(Huadiao)            ：一两白银又三十文铜板
     女儿红(Nuerhong)  		：一两白银又六十文铜板
     状元红(zhuangyuan hong)    ：一两白银又六十文铜板
     竹叶青(Zhuye qing)         ：一两白银又六十文铜板
     龙岩酒(Longyan jiu)	：三两白银
     香雪酒(Xiangxue jiu)	：三两白银\n\n",

	]));
	setup();

}
int valid_leave(object me, string dir)
{
        if( present("du laoban", me) && dir="down" )
                return notify_fail("好端端地你想带杜老板到那里去？！\n");
if( present("xiao lian", me) && dir="down" )
                return notify_fail("好端端地你想带小莲到那里去？！\n");
        return ::valid_leave(me, dir);
}

