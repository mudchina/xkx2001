//Cracked by Roath
// Room: /d/xingxiu/xxroad3.c

inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", "六盘山");
        set("long", @LONG
这是一座不太高的小山。山顶望去，瓦蓝的天空(sky)飘着几朵淡淡的
白云。一群大雁发出「嘎嘎」的叫声，从头上飞过。西面山下长城的残垣断
壁依稀可辨。路旁有一处悬崖之上刻着首词(poem)。北边山下是永登城，东
面山下是一处小村庄。
LONG
        );
        set("exits", ([
  		"northdown" : "/d/qilian/yongdeng",
  		"eastdown" : "/d/village/wexit",
	]));

        set("item_desc", ([ 
"poem" : "崖壁上刻着一首清平乐：

  何  今  红  六  屈  不  望  天
  时  日  旗  盘  指  到  断  高
  缚  长  漫  山  行  长  南  云
  得  缨  卷  上  程  城  飞  淡
  苍  在  西  高  二  非  雁  
  龙  手  风  峰  万  好  
                      汉

你现在是好汉了！
\n",
"sky" : "
                              \\/             \\/
                   /*=*         \\/       \\/
                   (*=*=)         \\/  \\/
               {/*=**=/            \\/
                         __
                        /\\.\\_   
               /\\  /\\  /  ...\\   /\\
              / .\\/ .\\/    .. \\_/ .\\
             /  ..\\  /    ... . \\  .\\      /\\
            /凸凸凸\\/凸凸凸. ..凸\\凸.\\    / .\\  
  _凸凸凸凸/     ..凸     凸凸凸..\\__.\\凸/  ..\\_凸凸凸凸凸凸凸凸凸凸凸凸_\n\n"
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 3);
        setup();
}
void init()
{
        object ob, robber, *inv, me=this_player();
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("value") >= 10000
                && !inv[i]->query("money_id")) j++;
        }
        if (j>0) me->set_temp("rob_victim", 1);

        if ( interactive(ob=this_player())
        && me->query_temp("rob_victim") && random(5)==1) {

                message_vision(HIR"突然一个大汉由西边的树林跳了出来，拦住了$N。\n"NOR, me);
	        robber = new("/d/xixia/npc/mazei");
                robber->move(environment(ob));
        }
}	
int valid_leave(object me, string dir)
{
        if ( me->query_temp("rob_victim") && present("ma zei", environment(me) ))
                return notify_fail("马贼凶巴巴地叫道：放聪明点，快将宝贝交出来！ \n");
	else { me->delete_temp("rob_victim"); }

        return ::valid_leave(me, dir);
}
