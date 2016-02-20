//Cracked by Roath
// /d/emei/leidong.c 雷洞坪
// Shan: 96/06/22

#include <ansi.h>
inherit ROOM;

void do_say(string);

void create()
{
        set("short", "雷洞坪");
	set("long", @LONG
雷洞坪一带，道路艰险骇人，路左是蔽日遮天的冷杉林，路右是深不见底
的绝壁峡谷。这里长年云遮雾罩，空蒙黑暗。岩上建有雷神殿，旁边竖一铁碑。
由此往上是「八十四盘」至接引殿，北下到洗象池。
LONG
	);
	set("exits", ([
		"southup" : __DIR__"pan84",
		"east" : __DIR__"lenshan1",
		"northdown" : __DIR__"lingyun",
	]));
        set("item_desc", ([
                "铁碑" :
"铁碑禁止人们言语，否则便会有惊雷迅电，霹雳而作，风雨暴来。\n",
		"bei" :
"铁碑禁止人们言语，否则便会有惊雷迅电，霹雳而作，风雨暴来。\n",
])  ) ;

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 2);
	setup();
}

void init()
{
	add_action("do_say", "say");
}

int valid_leave(object me, string dir)
{
        if ((dir == "southup" || dir == "east") && me->query("jingli") >12)
        {
                me->add("jingli",-random(12));
                me->improve_skill("dodge", random(10));
                write("你爬上八十四盘，有些累了。\n");
        }

        else if ((dir == "southup" || dir == "east") && me->query("jingli") <= 10)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

int do_say(string arg)
{
	int level, check;
    	string dir;
        object me = this_player();

   	level = (int)me->query_skill("force",1);
   	check = level*level*level;

	if( !userp(me)) return 0;
	
   	if ( level <= 100  && check < (int)me->query("combat_exp")*10 ) 
		me->improve_skill("force", me->query_con()+random(level));

	tell_object(me, HIR "你刚说出一个字，刹那间惊雷迅电，霹雳而作，风雨暴来。\n" NOR);

        message("vision", HIR + me->name()+"刚说出一个字，刹那间惊雷迅电，霹雳而作，风雨暴来。\n"NOR 
	, environment(me), ({me}));
        write(HIR"你一下子被打中，全身发麻。\n"NOR);

	if (me->query("jing") < level || me->query("qi") < level ) {
		me->set_temp("last_damage_from", "被惊雷迅电打死");
		if(random(me->query_kar()) == 3) me->die();
		else me->unconcious();
	} else {
		me->receive_damage("jing", random(2*level), "被惊雷迅电打死");
		me->receive_damage("qi", random(2*level), "被惊雷迅电打死");
	}

        return 1;

}
