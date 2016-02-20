//Cracked by Roath
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "北帝庙");
        set("long", @LONG
北帝庙坐北朝南。院子中一个大水塘，塘中石龟石蛇，昂然盘踞。
大殿神像石板上血迹殷然。北帝神像立于大殿正中。
LONG
        );
        set("exits", ([
		"south" : __DIR__"street0",
	]));

/*	set("objects", ([
		__DIR__"npc/feng" : 1,
	]));
*/
	set("cost",1);
	setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_ketou","ketou");
	add_action("do_kaitang","kaitang");
}

int do_ketou(string arg)
{
	object me = this_player();
	if (!present("feng yiming",me) && !present("feng yiming",environment(me))) {
		message_vision("$N在北帝爷爷像前磕了几个头，说道：“北帝爷爷保佑我练成绝世武功！”\n",me);
		return 1;
	}

	message_vision("$N在北帝爷爷像前磕了几个响头，说道：“北帝爷爷，"+
		"你威灵显赫，替"+ RANK_D->query_self(me)+ "\n有冤伸冤，有仇报仇。" +
		"这厮鸟偷吃了我的凤凰肉，但旁人都说他没吃！”\n", me);
	me->set_temp("beidi-ketou",1);
	return 1;
}

int do_kaitang(string arg)
{
	object feng, feng_son;
        object me = this_player();
	object weapon;

	if (!arg)
		return notify_fail("要自杀？\n");
	if( arg !="feng" && arg !="feng yiming" && arg !="yiming"
		|| !me->query_temp("beidi-ketou")) 
		return notify_fail("北帝像前，不可造次！\n");
	if ( !feng_son = present("feng yiming",environment(me)))
		return notify_fail("可他不在庙里。\n");
	
        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword"
        && (string)weapon->query("skill_type") != "blade" )
        	return notify_fail("开膛可是要用工具的。\n"); 

	if(present("feng tiannan",environment(me))) {
		message_vision("凤天南对$N喊道：“休伤我儿！”\n", me);
		return 1;
	}

	message_vision("$N拉住凤一鸣的衣襟，向上一扯，露出肚腹肌肤，横过" + weapon->query("name") +
		"，叫道：“他是否吃了凤凰肉，大家睁大眼睛瞧个明白，别说我冤枉好人！”\n", me);
	message_vision("忽然间，门外抢进一人，对$N喝道：“休伤我儿！”，凤一鸣乘机逃走了。\n", me);
	feng = new(__DIR__"npc/feng");
	feng->move(environment(me));
	feng->kill_ob(me);
	destruct(feng_son);
	me->delete_temp("beidi-ketou");
	return 1;	
}	
