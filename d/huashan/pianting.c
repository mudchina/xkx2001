//Cracked by Roath
// pianting1.c

inherit ROOM;
inherit F_SSERVER;

void create()
{
	set("short", "偏厅");
	set("long", @LONG
偏厅里供奉着华山历代祖师的神位。正中神案的墙上是华山派开山祖
师风祖师的画象。画象神情清隽，非常传神。神案上香炉里插着三柱清香，
香烟袅袅上升，散发着一股檀香味。南面有扇门通往外面的走廊。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south" : __DIR__"donglang",
	    "west" : __DIR__"buwei1",   
	]));

	set("item_desc", ([
      		"picture" : "一个神情清隽的中年书生，腰间配着一把长剑。\n",
		"画象" : "一个神情清隽的中年书生，腰间配着一把长剑。\n",
	]));

	set("paper_count", 1);

	set("cost", 0);
	setup();
	"/clone/board/huashan_b"->foo();
	//	replace_program(ROOM);
}

void init()
{
	add_action("do_ketou","ketou");
   	add_action("do_ketou","kneel");
}

int do_ketou(string arg)
{
   	object paper, me = this_player();
	int level1, level2, level3;
	
	message_vision("$N恭恭敬敬地在神案前的团蒲上跪了下来，对着神位磕了三个响头。\n", me);
	me->receive_damage("qi", 5, "力尽气绝而死");
	me->start_busy(1);

	if ( me->query("qi") <= 50 )
		write("你只觉得脑子有些昏昏沉沉的。\n");
	if ( me->query("qi") <= 20 )
		write("你觉得天旋地转，似乎马上便要晕去。\n");

	if ( !(me->query("family/family_name")=="华山派") ) return 1;
 
	if ( !me->query("huashan/yin-jue") && me->query("huashan/yinjue") < 500 ) {
		me->add("huashan/yinjue", 1);
		return 1;
	}
	  
	level1 = me->query_skill("ziyin-yin", 1);
	level2 = me->query_skill("zhengqi-jue", 1);
	level3 = me->query_skill("zixia-gong", 1);

	if ( level1>=120 && level2>=120 && level3>=150 && !me->query("huashan/yin-jue") ) {
		paper=new(__DIR__"obj/zixia_paper");
		if ( !paper ) return 1;
		
		paper->move(me);
		add("paper_count", -1);
		me->set("huashan/yin-jue", 1);
		me->delete("huashan/yinjue");

		write("你在团蒲上重重地一磕，团蒲的边上忽然裂了开来，露出一小段纸笺。\n");
		write("你仔细的将纸笺抽出一看，上面密密麻麻的记载了练功心法，似乎与紫霞\n");
		write("功一脉相承，但却更加深奥。\n");
		write("你细读良久，突然晃然大悟，原来这便是紫霞密笈失传多时的最後一页！\n");
		write("你连忙密笈收好。\n");
	}

	return 1;
}
