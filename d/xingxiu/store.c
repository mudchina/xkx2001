//Cracked by Roath
// room: /d/xingxiu/nanjiang.c
// Jay 3/17/96
// Ryu 5/10/97
inherit ROOM;

void create()
{
        set("short", "巴扎");
        set("long", @LONG
伊犁是帕米尔高原之东一大都会，这里的巴扎上，奇珍异宝，往
往有之。牲畜果品，尤不可枚举。不仅有来自川、陕、江、浙的商队，
也有远道而来的天竺、波斯的行商坐贾。巴扎的主人坐在铺在地上的
地毯上，旁边堆着他的货。墙上有个牌子，是个价目表(sign)。
LONG
        );
        set("exits", ([ 
        "east" : __DIR__"beijiang",
]));
        set("objects", ([
                __DIR__"npc/maimaiti": 1 ,
		__DIR__"npc/trader": 1,
]));
        set("item_desc", ([ /* sizeof() == 1 */
"sign" : "牌子上写道：
中原钱币通用。
        马奶酒壶(hu)       一百文
        馕(nang)           五十文
        火折(fire)         一百文
        哈密瓜(gua)        四十文
        冬不拉(dongbula)   一百文
	扁担(biandan)      四十文
	绣花针(xiuhua zhen)一两白银
	硫磺(liu huang)    二两白银
	丝绢(Si juan)	   五两白银	
        伊犁马(horse)      一千文 ( 售完 )
\n"
]));
        set("no_clean_up", 0);

	set("cost", 0);
        setup();
        replace_program(ROOM);
}

 
