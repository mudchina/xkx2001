//Cracked by Roath
// Room: ssmiao.c

inherit ROOM;

string look_lingwei();

void create()
{
	set("short", "山神庙");
	set("long", @LONG
这是一个用木板和石头垒成的小庙，庙前地上散落着一些然过的灰烬。
庙里供奉着山神爷老把头的灵位(lingwei)。传说他是所有采参人的祖师爷，
所以每个进山挖参的参客都要来这里祭拜，希望能得到他老人家的保佑。
LONG
	);

	set("exits", ([
		"out" : __DIR__"huanglu2",
	]));
        set("item_desc",([
                "lingwei" :  (: look_lingwei :),
        ]));
        set("cost", 1);

	setup();
}

void init()
{
	add_action("do_bai", "bai");
        add_action("do_bai", "kneel");
}

int do_bai(string arg)
{
	object me = this_player();
        int power;

        if( !arg || !(arg == "lingwei" || arg == "灵位") )
                return 0;

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙着。\n");

	message("vision", me->name() + "恭恭敬敬的向灵位拜了几拜。\n", environment(me), ({me}));
	write("你恭恭敬敬的向灵位拜了几拜。嘴中还喃喃念到：\n"
              "\n 山神爷老把头，\n"
              "\n 您给俺开开眼。\n"
              "\n 我要是发了财，\n"
              "\n 再来供奉您山神爷老把头！\n");
        me->add_temp("cbshen/bai", 1);
        me->start_busy(1);

        switch( (int)me->query_temp("cbshen/blw") ) {
                case 1:  return 1; break;
                case 2:  break;
                case 3:  return 1; break;
                default: me->set_temp("cbshen/blw", 2); break;
        }

        switch((int)me->query_temp("cbshen/ask_gun")) {
                case 1:   power = 2;  break;
                case 2:   power = 3;  break;
                case 3:   power = 0;  break;
                default:  power = 1;  break;
        }

        power *= (int)me->query_temp("cbshen/bai") / 3 + 1;
        power *= (int)me->query("kar");
        power = random(power);

        if( power > 100 && me->query_temp("cbshen/blw") == 2 )
                me->set_temp("cbshen/blw", 1);

        if( power < 3 && me->query_temp("cbshen/blw") == 2 )
                me->set_temp("cbshen/blw", 3);

	return 1;
}

string look_lingwei()
{
    return
    "\n"
 "**************\n"
 "*            *\n"
 "*     山     *\n"
 "*     神     *\n"
 "*     爷     *\n"
 "*     老     *\n"
 "*     把     *\n"
 "*     头     *\n"
 "*            *\n"
 "*     孙     *\n"
 "*     良     *\n"
 "*            *\n"
 "*     之     *\n"
 "*     位     *\n"
 "*            *\n"
 "*            *\n"
 "**************\n";
    "\n";
}
