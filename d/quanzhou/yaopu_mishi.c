//Cracked by Roath

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这里象是一个地窖，可能是药铺收藏珍贵药物的地方。东首一个
大架子(shelf)，放着药材和无数小瓷瓶。地上有一只炼药炉，空气中尽是药
味。西首有一张椅子(chair)。
LONG
	);
	set("no_clean_up", 0);

        set("item_desc", ([
        "chair" : "一张椅子，抹拭得很干净，椅背刻着双龙抢珠的图案，
两条龙刻得甚是生动，张牙舞爪地抢夺一个镶在椅背上青光发亮的铁球(Iron
Ball)。\n",
	"shelf" :
"一个大架子，堆放了不少东西，找找(search)没准能有好东西。\n",
	]));

    set("objects", ([
         __DIR__"obj/yaolu" : 1,
]));
	setup();
}


void init()
{
	add_action("do_turn","zhuan");
	add_action("do_turn","turn");
	add_action("do_search","search");
}

int do_turn(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg == "" ) return 0;
	if( arg == "ball" || arg == "qiu")
	{
        message_vision("$N走向西首一张椅子，伸手在椅背铁球上一按……\n\n"+
        "秘室顶部一块板子缓缓向一边移去，露出一个大洞。\n",me);
        set("exits/up", __DIR__"neitang");
        remove_call_out("close_door");
        call_out("close_door",15,me);

		return 1;
	}
	else
		return notify_fail("你要干什么？\n");
}

void close_door(object me)
{
	tell_room(this_object(),"秘室顶部的板子又缓缓移了回来。\n");
	delete("exits/up");
}

int do_search(string arg)
{
	object ob,me;
	me = this_player();
	if (!arg || arg == "") return 0;
	
	if (arg == "jia" || arg == "shelf")
	{
		if (query("searched"))
			return notify_fail("你在架子上翻寻了一阵，但什么都没找到。\n");

		switch (random(7))
		{
			case 0:
			ob = new(DRUG_D("yangxin"));
			break;
			case 1:
			ob = new(DRUG_D("jinchuang"));
			break;
			case 2:
			ob = new(DRUG_D("baicao-dan"));
			break;
			case 3:
			ob = new(DRUG_D("yulu-wan"));
			break;
			case 4:
			ob = new(DRUG_D("xxqingxin-san"));
			break;
			case 5:
			ob = new(DRUG_D("heishi-dan"));
			break;
			case 6:
			ob = new(DRUG_D("dali-wan"));
			break;
		}

		set("searched",1);		
		message_vision("你从一个小瓶子里找到一颗"+ob->query("name")+"。\n",me);
		ob->move(me);
		return 1;
	}
}	

