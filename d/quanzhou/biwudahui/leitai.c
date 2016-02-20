//Cracked by Roath
// d/quanzhou/leitai.c 比武擂台;
inherit ROOM;

void create()
{
        set("short", "比武擂台");
        set("long", @LONG
这是一座坚实壮观的擂台。擂台高约丈余，面积大约有三丈方圆，全
由碗口粗的木头搭成。台后的墙上书着一个笔力劲秀，气势磅礴的大字—
「武」。擂台前有面大鼓和只牌子(sign)，照规矩所有比武的人都需击鼓
宣布，让江湖得知。江湖中的豪客们常在此切磋比试，甚至了断恩冤。当
然不时也有江湖儿女来此「比武招亲」，玉成喜事，留下一段武林佳话。
LONG
        );
        
	set("exits", ([
		"east" : __DIR__"leitai2",
		"south" : __DIR__"leitai_gate",
	]));

	set("item_desc", ([
		"sign" : "击鼓指令：dagu [zhaoqin(marryfight)|qiecuo(fight)|juezhan(kill)] <sb>\n\n"
			"这里只供比武招亲(zhaoqin)，切磋比试(qiecuo)及生死绝战(juezhan)所用。\n" 
			"若有死伤，生死自负！！\n",
	]));

	set("no_death", 1);

	set("cost", 1);
        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_dagu", "dagu");
        add_action("do_say", "say");
}

int do_dagu(string arg)
{
	object ob, me = this_player();
	string opp, str, event;

	if ( !arg ) return notify_fail("你要宣布什么？\n");

	if ( sscanf(arg, "%s %s", event, opp) != 2  ) return notify_fail("你要宣布什么？\n");

	if ( me->query("id") == opp ) return notify_fail("你有毛病啊？\n");

	if ( !present(opp, environment(me)) ) return notify_fail("这里并无此人，还是约好再来吧。\n");

	if ( !find_living(opp) ) return notify_fail("你鬼迷心窍啦？那不是活物！\n");

	if ( event == "marryfight" || event == "zhaoqin" ) {
		if ( me->query("gender") == "无性" )
		     	return notify_fail("你这辈子别指望了！\n");
		else if ( me->query("class") == "bonze" )
			return notify_fail("你凡心未净，罪过！罪过！\n");
                else if ( me->query("gender") == "男性" )
                        return notify_fail("唯有女方才能举行比武招亲！\n");
		else str = "比武招亲";
	}
	else if ( event == "fight" || event == "qiecuo" ) {
		str = "切磋比试";
	}
	else if ( event == "kill" || event == "juezhan" ) {
		str = "生死绝战";
	}
	else return notify_fail("这里只供比武招亲(zhaoqin)，切磋比试(qiecuo)及生死绝战(juezhan)所用。\n"); 

	ob = find_player(opp);

	message_vision("$N拿起鼓槌，打了大鼓一下，大鼓发出「嗵」的一声巨响，传出老远。\n", me);
	CHANNEL_D->do_channel(me,"rumor",sprintf("%s拿起鼓槌，打了大鼓一下，大鼓发出「嗵」的一声巨响，传出老远。", me->name()));
	CHANNEL_D->do_channel(me,"chat",sprintf("本人现与%s于擂台进行%s，请各位江湖同道做个见证。", ob->name(), str));

	return 1;
}


void do_say();

int do_say(string arg)
{
    	string dir;

        object me = this_player();

	if( !wizardp(me))
	{
		tell_object(me, "这里吵吵哄哄的，怎么大声说话都听不清。\n");
        	return 1;
	}
	return 0;
}

