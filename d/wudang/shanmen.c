//Cracked by Roath
// shanmen.c 武当玄岳门
// by Xiang

inherit ROOM;
#include <ansi.h>;
int do_exercise(string);

void create()
{
	set("short", "玄岳门");
	set("long", @LONG
你的面前是一座林木繁茂的高山，几座山峰在云雾中隐约可见，一条石
阶向山上延伸，走着几个进香客。一个五楼式的石坊跨山而建，写着“玄岳
门”三个大字，原来这就是天下闻名的武当山。武当山一名太和山，为七十
二福地之一，有二十七峰、三十六岩、二十四涧、五台、五井、三潭、三天
门、三洞天和一福地，百里内密树森罗，蔽日参天，景物幽绝。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"pine_road",
		"southup" : __DIR__"shijie1",
	]));
        set("objects", ([
                CLASS_D("wudang")+"/zhike" : 1]));
	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_exercise", "exercise");
	add_action("do_exercise", "dazuo");
	add_action("do_exercise", "respirate");
	add_action("do_exercise", "tuna");
	add_action("do_exercise", "lian");
	add_action("do_exercise", "practice");
	add_action("do_exercise", "study");
	add_action("do_exercise", "du");
	add_action("do_exercise", "sleep");
}

int do_exercise(string arg)
{
	object me = this_player();

	if ( me->query("job/description") == "守卫山门" || me->query("job/guarding") > 0 )
	{
		tell_object(me, "你还是专心守门吧！\n");
		return 1;
	}
	
	return 0;
}


int valid_leave(object me, string dir)
{
	mapping myfam;
	object wp, *inv;
	int i, j=0;

	myfam = (mapping)me->query("family");

	if ( (string)me->query("job/allow") > 0)
		return me->delete("job/allow");
			
				
	
	if ( (string)me->query("job/description") == "守卫山门" )
	if (objectp(present("zhike daozhang", environment(me))))
		return notify_fail("知客道长喝道：时辰未到，你就想溜！\n");
	else 		
	{
		message_vision("$N看知客道长不在，趁机溜走了。\n", me); 	

		me->delete("job/guarding");
		me->delete("job/allow");
		me->delete_temp("apply/short");
		me->add("job/fail", 1);
		me->delete("job/supervisor");
		me->delete("job/description");
		me->delete("job/wage");
		me->delete("job/object");
	}
	

	if ( dir == "southup" && (me->query("shen") < -99)
		&& !objectp(present("incense", me)) )
	{
        inv = all_inventory(this_object());
    
        for (i = 0; i < sizeof(inv); i++)
        if (userp(inv[i]) && (string)inv[i]->query("job/description") == "守卫山门")
		{
			j++;
			if (objectp(wp = inv[i]->query_temp("weapon")))
				message_vision("$N对$n喝道：尔等邪魔歪道人物，要想过此山门，得先问问我手中的"
				+ wp->query("name")+ "答应不答应！\n", inv[i], me); 
			else 
				message_vision("$N对$n喝道：只要我在，尔等邪魔歪道人物，便休想过此山门！\n", inv[i], me);
		}

        if ( objectp(present("zhike daozhang", environment(me))) )
            return notify_fail("知客道长拔出长剑对着你：如不是上山敬香，即刻请回！\n");
            
        if (j) return notify_fail("\n");    
	}
	
	return 
		
		::valid_leave(me, dir);
		
}

void reset() 
{
        int i;
        mapping worker = query_temp("worker");
        string* players;

        if ( mapp(worker) && sizeof(worker) ) {
                players = keys(worker);
                for(i=0; i<sizeof(players); i++) 
                        if (query_temp("worker/"+players[i])>0)
                                add_temp("worker/"+players[i], -1);
        }

	return ::reset();
}

