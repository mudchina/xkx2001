//Cracked by Roath
// shenshui.c 神水庵
// Shan: 96/6/30

inherit ROOM;

void create()
{
        set("short", "神水庵");
        set("long", @LONG
神水庵位于宝掌峰下，庵前有大峨石和玉液泉，泉出石下，清澈无比，终
年不涸。一株大海棠树，已是数百苍龄，抱可数围，高达十余丈。旁边有福寿
庵；由此西上中峰寺，东下纯阳殿。
LONG
        );
        set("exits", ([
		"south" : __DIR__"fushou",
		"westup" : __DIR__"zhongfeng",
                "eastdown" : __DIR__"chunyang",
        ]));

        set("resource/water", 1);

	set("outdoors", "emei");
        set("item_desc",([
            "大峨石"        :
"这是神水阁前的大峨石，上有诸多历代题刻。其中“大峨”二字，传说为吕纯\n"
"阳所书。又有道家最著名的老祖，宋代的陈图南在此挥毫大书的“福寿”二字。\n",

	    "玉液泉"	:
"这就是玉液泉。泉水淙淙，清冽甘香，秀气透人。据说，隋朝时，中国佛教的\n"
"尊圣、天台宗创始人智觊大师在荆州患病，神女即取此泉为供养，所以此泉又\n"
"「神水泉」。\n"
        ]));

	set("cost", 1);
        setup();
//	replace_program(ROOM);
}

void init()
{
        add_action("do_drink", "drink");
}
// If someone is hurt, every drink will help to heal random(3) eff_qi

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
            message("vision", me->name()+"捧了一把玉液泉喝了下去。\n"
            , environment(me), ({me}) );
            write("你捧了一把玉液泉喝了下去。泉水一入胸腹，便犹如甘露洒心，爽透清凉。\n");
        if ((int)me->query("eff_qi") != 
            (int)me->query("max_qi"))
            me->receive_curing("qi", random(10));
        }
        else write("你一口气喝了好多玉液泉，已经再也喝不下了。\n");

        return 1;
}

