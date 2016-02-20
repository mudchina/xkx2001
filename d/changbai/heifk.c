//Cracked by Roath
// Room: heifk.c
//change bu Wzfeng 99 12

inherit ROOM;
#include <ansi.h>
int do_search(string arg);
void create()
{
        set("short", "黑风口");
        set("long", @LONG
这里是长白山第一天险，两侧山崖壁立，中间仅余几米的宽度。由于前
后没有遮挡，且受附近地势影响，强劲的西北风从此处呼啸而过，风势之强
，即便是牛马车辆，亦会被狂风卷走。人们行到此处，都会小心翼翼，攀紧
山壁上的杂草树根而过。
LONG    );
        set("exits", ([ 
              "westdown" : __DIR__"milin4",
              "eastdown" : __DIR__"jiaxz",
        ]));
        
        set("outdoors", "changbai");
		set("cao_time",9);
  


      set("cost", 8);

        setup();
}

void init()
{       
        object me = this_player();
        int power;

        power = (int)me->query("neili") * (int)me->query("dex");

        if( random(power) < 3000 && interactive(me) ) {
                message_vision(HIR"一股狂风呼啸而过，$N只觉得身体一轻，已被劲风卷起，抛落山下！\n"NOR,me);
                me->move(__DIR__"baihe");
                me->unconcious(); 
        } else {
                me->add("neili", -10);
                message_vision(HIB"一股狂风呼啸而过，$N被吹得摇摇晃晃，差点摔下山去！\n"NOR, me);
        } 
		add_action("do_search",  "search");

}

int do_search(string arg)
{
        
		object cao,me;
		int i;
		me = this_player();
		
        if(me->query_skill("pixie-jian",1)<200)
		{
		tell_object(me, "什么？\n");
        return 1;
		}
		if(me->query("neili")>2000)
		{
			if(query("cao_time")>3)
				{
				tell_object(me, "你仔细寻找，发现山崖上有几颗深绿色的小草。\n"
				"你慢慢的爬过去，小心翼翼的摘下几颗小草放在身上。\n");
				me->add("neili",-1000);
				for(i=1;i<4;i++)
				{
					cao = new("/d/changbai/obj/yinyang-cao");
					cao->move(me);
					add("cao_time",-1);
				}
			}
			else
			{
				tell_object(me, "你仔细寻找了半天，却什么都没找到。\n");
			}

		}
		else
		{
			tell_object(me, "你仔细寻找，发现山崖上有几颗深绿色的小草。\n"
			"你慢慢的爬上山崖。如然一阵阴风吹来，你一口真气不足，重重的摔了下来。\n");

		}
		return 1;
}

