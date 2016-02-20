//Cracked by Roath
inherit ROOM;
inherit F_SAVE;


#include <ansi.h>

int do_lingwu();

void create()
{
        set("name", "广场");
        set("short", "广场");
        set("long", "这里是一个宽阔的广场，青石铺成的地板被全真道士打扫的干干\n净净，广场正中立着一座石碑(bei )。上面密密麻麻地刻着小字。石\n碑旁边坐着一个木头人，五心向天，形象逼真，怀中抱着一柄拂尘。\n\n");

        set("item_desc", ([
                "bei" : "碑上刻着断云鞭法的要义。\n\n",
        ]));

        set("objects", ([
        ]));

        set("exits", ([
                "left" 	   : "/d/zhongnan/taijie",
        ]));

	set("no_clean_up", 0);
	set("valid_startroom", 1);

        setup();     
 
}


void init()
{       
        add_action("do_lingwu", "lingwu");
        
}


int do_lingwu(){
	
	int skill, exp;
		
	object me=this_player();

	if (this_player()->is_busy()) return notify_fail("你正忙着呢。\n");
	
	if (me->query_skill("duanyun-bian",1)<150)
		return notify_fail("你断云鞭法修为不足以领悟其精华。\n");

	if (!present("fuchen", me) && me->query("id")!="wsky")
                        return notify_fail("你没有携带拂尘。\n\n");
	
	if (me->query_skill("duanyun-bian",1)>500)
		return notify_fail("你看了看碑上的小字，觉得那些对自己来说太浅了。\n");

	if (me->query("neili")<30)
		return notify_fail("你内力不足。\n");

	if (me->query("jingli")<30)
		return notify_fail("你精力不足。\n");

	exp=me->query("combat_exp");
	while(skill*skill*skill<exp*10) skill++;
	
	if (me->query_skill("duanyun-bian",1)>skill)
		return notify_fail("你看了看碑上的小字，觉得自己经验不够理解这些。\n");

	message_vision("\n$N手持拂尘站在石碑前，努力阅读着断云鞭的精义。\n",me);

	me->start_busy(3);
	me->add("jingli",20);
	me->add("neili",20);

	if (random(100)<10){

		message_vision("\n$N看了看碑旁的木人，手持拂尘轻轻晃动，似乎对断云鞭法略有所悟。\n",me);		
		this_player()->improve_skill("duanyun-bian", this_player()->query_skill("whip",1)/10);	

	}

	return 1;
}