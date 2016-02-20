//Cracked by Roath
// d/emei/cliffpool.c 水潭
// xbc: 96/02/02

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "水潭");
	set("long", @LONG
这是一个大水潭，潭中水清凉无比，一下就把你激醒了。潭水正缓缓向东
流去。两岸山石峻峭，山上绿树荫蔽。不知道这是哪里呢？
LONG
	);
        set("no_clean_up", 0);
        set("outdoors", "emei" );
	set("cost", 6);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");

	object me = this_player();
	object *inv;
	int i, flag;
	
	inv = all_inventory(me);	
	flag = 0;
	for (i=0; i < sizeof(inv); i++) 
		if ( !inv[i]->query("armor_prop/armor") ) {
			destruct(inv[i]);
			flag += 1;
		}

	if ( flag ) write(HIB"你身上的钱物都掉进水中，再也找不到了：（\n"NOR);

}

int do_climb(string arg)
{
	object me = this_player();

	if ( arg && arg != "up")
		return notify_fail("什么？\n");

	if ( arg == "up" ){
                message_vision("$N向岸上爬去。\n", me);
       		me->move(__DIR__"qingyin");
                message_vision("$N水淋淋地从江中爬了上来。\n", me);
	        return 1;
	}
	return 0;
}


