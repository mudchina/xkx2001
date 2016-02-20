//Cracked by Roath
// xiakedao/yingbin.c
// modifiedy by aln 5 / 98

inherit "/d/xiakedao/no_pk_room";

string* foods = ({
	"/d/xiakedao/obj/shaomai.c",
	"/d/xiakedao/obj/chunjuan.c",
	"/d/xiakedao/obj/jianbing.c",
	"/d/xiakedao/obj/zhenggao.c", 
});

void create()
{
        set("short", "迎宾馆");
        set("long", @LONG
走进玉石洞门，只见洞中桌椅俱全，地上是整齐的青石板路。三
枝粗如儿臂的红烛一字排开，照耀得满洞通明。几名青衣小僮走来走
去，给宾客奉上清茶和点心。
LONG );

        set("exits", ([
		"west" : __DIR__"yongdao2",
        ]));

	set("indoors", "xiakedao" );
        set("resource/water", 1);
	set("cost", 0);
	set("objects",([
		__DIR__"npc/xiaotong" : 1,
	]));

	setup();
}

void init()
{
        ::init();

	add_action("do_serve", "serve");
}

int do_serve()
{	object xiaotong, curtea, newtea, newfood;
	object me = this_player(), room;
	int i, total, flag;

	room = environment(me);
	if( !objectp(xiaotong = present("xiao tong", room)) )
	 	return notify_fail("你四处张望，不知小僮都跑哪去了。\n");

	if (objectp(curtea = present("wan", room)))
	{	message_vision("小僮把剩茶端走，再端上一碗茶放在$N的桌上\n", me);
		destruct(curtea);
	}
	else
		message_vision("小僮端上一碗茶放在$N的桌上。\n", me);

	newtea = new("d/wudang/obj/dawancha");
	newtea->move(room);
	
	total = (int)sizeof(foods);
	flag = 0;

	for (i = 1; i < total; i++)
	{	if (  present(foods[i]->query("id"), room) || present(foods[i]->query("id"), me) )
			flag = 1;
	}
	if (flag != 1)
	{	newfood = new(foods[random(total)]);
		newfood->move(room);
		message_vision("小僮端上一" + newfood->query("unit") + newfood->query("name") 
					+ "，放在$N的桌上。\n", me);
	}
	else
	{	message_vision("小僮对$N笑了笑说道：先吃完再要吧。\n", me);
	}
	return 1;
}
