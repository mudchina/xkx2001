//Cracked by Roath
///d/zhongnan/danfang1.c
//sdong 07/98

inherit ROOM;

void create()
{
        set("short", "丹房");
        set("long", @LONG
这里是一个丹房，是重阳宫各位真人炼丹的地方。东首一个大架子(shelf)，
放着药材和无数小瓷瓶。地上有一只炼丹炉，空气中尽是药味。西首有一张椅子
(chair)。
LONG
        );
        set("no_clean_up", 0);

        set("item_desc", ([
        "chair" : 
"一张椅子，抹拭得很干净，椅背刻着双龙抢珠的图案，两条龙刻得
甚是生动，张牙舞爪地抢夺一个镶在椅背上青光发亮的铁球(Ball)。\n",
        "shelf" :
"一个大架子，堆放了不少东西，找找(search)没准能有好东西。\n",
        ]));

		  set("objects", ([
				__DIR__"obj/danlu" : 1,
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
        "丹房的门缓缓向一边移去，露出一个出口。\n",me);
        set("exits/east", __DIR__"xilang");
        remove_call_out("close_door");
        call_out("close_door",15,me);

                return 1;
        }
        else
                return notify_fail("你要干什么？\n");
}

void close_door(object me)
{
        tell_room(this_object(),"丹房的门又缓缓移了回来。\n");
        delete("exits/east");
}

int do_search(string arg)
{
        object ob,me;
        me = this_player();
        if (!arg || arg == "") return 0;
        
        if (arg == "jia" || arg == "shelf")
        {
                if (query("searched",1)>10)
                        return notify_fail("你在架子上翻寻了一阵，但什么都没找到。\n");

                switch (random(7))
                {
                        case 0:
                        ob = new(DRUG_D("huanzhi"));
                        break;
                        case 1:
                        ob = new(DRUG_D("tongshen"));
                        break;
                        case 2:
                        ob = new(DRUG_D("shengjing"));
                        break;
                        case 3:
                        ob = new(DRUG_D("dingyang"));
                        break;
                        case 4:
                        ob = new(DRUG_D("zhaohun"));
                        break;
                }

                set("searched",query("searched",1)+1);              
                message_vision("你从一个小瓶子里找到一颗"+ob->query("name")+"。\n",me);
                ob->move(me);
                return 1;
        }
}     
