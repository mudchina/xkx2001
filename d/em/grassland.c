//Cracked by Roath
// d/emei/grassland.c 郭襄墓前草地
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "草地");
	set("long", @LONG
眼前出现一片草地，草地上开着各色小花，微风吹过，频频点头。一条山
涧从石壁流下，几株果树上挂满红红绿绿的瓜果。草地尽头有一座墓，后面好
象有间小茅屋。
LONG
	);

        set("outdoors", "emei" );

        set("exits", ([
                "southwest" : __DIR__"valleypath",
		"north" : __DIR__"tomb",
		"northeast" : __DIR__"tombpath",
		"east" : __DIR__"tombhouse",
        ]));

        set("resource/water", 1);

	set("cost", 1);
	set("fruit_count", 10);
	setup();
}

void init()
{
        add_action("do_drink", "drink");
	add_action("do_pick", "pick");
	add_action("do_pick", "zhai");
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<me->max_water_capacity()) {
            me->set("water", current_water+random(30));
            message("vision", me->name()+"捧了一把山涧的泉水喝了下去。\n"
            , environment(me), ({me}) );
	    write("你捧了一把山涧的泉水喝了下去。\n");
	}
        else write("你一口气喝了好多泉水，再也喝不下了。\n");
        return 1;
}

int do_pick(string arg)
{
	object me = this_player();
	object fruit = new(__DIR__"obj/fruit");

	if ( !arg || arg == "") return 0;

	if ( arg == "fruit" ){
		if (query("fruit_count") < 1) {
			tell_object(me, "能摘的野果已经摘光了。\n", me);
			return 1;
		}
		else {
                	message_vision("$N摘下一只野果。\n", me);
			fruit->move(me);
			add("fruit_count", -1);
	        	return 1;
		}
	}
	return 0;
}


