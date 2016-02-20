//Cracked by Roath
// Room: /city/zhulin2.c
// xbc June, 1997
// rewritten, fixed crash bug, xuy, 8/11/97
// 做法及原料有详细说明

inherit ROOM;

void create()
{
        set("short", "竹林小道");
        set("long", @LONG
这是一条竹林小道，两旁尽是遮天蔽日的茂密的竹林。扑鼻而来是一阵狗
肉香味。有两个小叫化正在一块大石边这里烤肉。看来这里是丐帮弟子为扬州
城内的帮中长老们烧菜做饭的地方。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"gbxiaowu",
		"south" : __DIR__"zhulin2",
		"west" : __DIR__"zhulin1",
	]));

	set("objects", ([
                "clone/food/gourou": 1,
                "clone/food/jitui": 1,
		__DIR__"npc/cook": 1,
        ]));

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_cook", "cook");
	add_action("do_cook", "shao");
}

int do_cook(string arg)
{
	object ob;
	object me = this_player();
	string cooking;
	
	if( !objectp(present("fire", me)) ) 
		return notify_fail("你身上没有火折，生不了火，没法烧菜做饭。\n");

	if( !arg || arg == "") return 0;

	if( stringp(cooking = me->query_temp("cooking")) )
		return notify_fail("你正在做"+cooking+"！\n");

	switch (arg) {
	case "牛肉条":
		if ( !objectp(ob = present("niu rou", me)) ) 
			return notify_fail("你拿什么来烧牛肉条啊？\n");
		break;
	case "好逑汤":
		if ( !objectp(ob = present("he ye", me)) ) 
			return notify_fail("你拿什么来烧汤啊？\n");
		break;
	case "炒白菜":
		// clone/food/baicai, buy a 白菜 from the seller in yangzhou at 水果摊
		if ( !objectp(ob = present("baicai", me)) ) 
                        return notify_fail("你拿什么来炒白菜啊？\n");
		break;
	case "蒸豆腐":
		// clone/food/tofu, buy from 曲三's tea shop
		if ( !objectp(ob = present("doufu", me)) ) 
                        return notify_fail("你拿什么来做蒸豆腐啊？\n");
		break;
	default:
		return notify_fail("你要烧什么？\n");
		break;
	}

	message_vision("$N打着火折开始生火做菜。\n", me);
	destruct(ob);
	me->set_temp("cooking", arg);
	call_out("cooking", 1, me, arg);
	return 1;
}

private int cooking(object me, string arg)
{
	int aux_count=0;
	object cooked, aux;
	
	if( !objectp(me) ) return 0;
	me->delete_temp("cooking");

	switch (arg) {
	case "牛肉条":
		if( objectp(aux = present("yang rou", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("zhu erduo", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("zhang rou", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("tu rou", me)) ) {
			++aux_count;
			destruct(aux);
		}
		cooked = new(__DIR__"obj/niurou-tiao");
               	message_vision("$N烧了一碗香喷喷的牛肉条来。\n", me);
		if (aux_count != 4)
			cooked->set("fake", 1);
		break;
	case "好逑汤":
		if( objectp(aux = present("zhu sun", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("ying tao", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("banjiu rou", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("flower", me)) ) {
			++aux_count;
			destruct(aux);
		}
		cooked = new(__DIR__"obj/haoqiu-tang");
               	message_vision("$N烧了一碗香喷喷的好逑汤来。\n", me);
		if (aux_count != 4)
			cooked->set("fake", 1);
		break;
	case "炒白菜":
		if( objectp(aux = present("ya zhang", me)) ) {
			++aux_count;
			destruct(aux);
		}
		if( objectp(aux = present("ji you", me)) ) {
			++aux_count;
			destruct(aux);
		}
               	message_vision("$N炒了一碟香喷喷的白菜来。\n", me);
		cooked = new(__DIR__"obj/chao-baicai");
		if (aux_count != 2)
			cooked->set("fake", 1);
		break;
	case "蒸豆腐":
		if( objectp(aux = present("huo tui", me)) ) {
			++aux_count;
			destruct(aux);
		}
               	message_vision("$N蒸了一碟豆腐来。\n", me);
		cooked = new(__DIR__"obj/zheng-doufu");
		if (aux_count != 1)
			cooked->set("fake", 1);
		break;
	default:
		return 0;
	}
	cooked->move(me);
	return 1;
}

