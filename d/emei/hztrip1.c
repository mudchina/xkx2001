//Cracked by Roath
//Jay 9/30/96

inherit ROOM;

void create()
{
        set("short", "小树林");
	set("long", @LONG
这是峨嵋山金顶华藏庵外的一片小树林。林中没有路，但地上依稀有些足
迹，似乎刚有人走过。北面有一扇小窗。
LONG);
	set("exits", ([
		"south" : __DIR__"hztrip2",
	]));
        set("item_desc", ([
                "chuang" : "窗子那边是华藏庵的西侧殿。\n",
                "窗" : "窗子那边是华藏庵的西侧殿。\n",
	]));


        set("outdoors", "emei" );

	set("cost", 2);
	setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{

        object me = this_player();

        if (arg!="chuang") return 0;
	if (present("song qingshu",environment(me)))
		return notify_fail("宋青书一把拉住你的腿。\n");
        message_vision("$N趁人不注意，跳进窗里。\n", me);
        me->move(__DIR__"hz_west");
        message_vision("$N从华藏庵外跳窗进来。\n", me);
        return 1;
}


