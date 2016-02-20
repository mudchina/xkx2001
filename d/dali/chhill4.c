//Cracked by Roath
// Room: /d/dali/chhill4.c
// ALN added dufeng part 4 / 98

inherit ROOM;

int do_pick(string);
int do_get(string);

void create()
{
	set("short", "茶花山");
	set("long", @LONG
你走在茶花山上，这里遍地生长着茂盛的茶花。当然，大部分是凡品，但偶
尔也会有一两株佳品藏匿其中。有一些毒蜂在飞来飞去，似乎毒蜂巢(fengchao)
就在附近茶花丛里。
LONG);
	set("objects", ([
		__DIR__"obj/chahua" : 1,
		]));
	set("exits", ([
		"south"  : __DIR__"chhill3.c",
		]));
	set("fengamount", 3 + random(3));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
}
void init()
{
	object *inv;
	object me = this_player();
	object newfeng;
	int myfeng, i;

	if( interactive(me) )
	{
		inv = all_inventory(this_object());
		for(i = 0; i < sizeof(inv); i++)
		{
			if( inv[i]->query("id") == "dufeng" )
			{
				myfeng++;
				if( !inv[i]->is_fighting() )
				{
					inv[i]->add_temp("apply/attack", 30);
					inv[i]->add_temp("apply/damage", 30);
					COMBAT_D->do_attack(inv[i], me);
					inv[i]->add_temp("apply/attack", -30);
					inv[i]->add_temp("apply/damage", -30);
					inv[i]->kill_ob(me);
				}
			}
		}
		for(i = 0; i < (query("fengamount") - myfeng); i++)
		{
			newfeng = new("/clone/beast/dufeng");
			newfeng->move(this_object());
			newfeng->add_temp("apply/attack", 30);
			newfeng->add_temp("apply/damage", 30);
			COMBAT_D->do_attack(newfeng, me);
			newfeng->add_temp("apply/attack", -30);
			newfeng->add_temp("apply/damage", -30);
			newfeng->kill_ob(me);
		}
	}
	add_action("do_pick", "pick");    
	add_action("do_get","get");
}
int do_pick(string arg)
{
	object me = this_player();
	object *inv = all_inventory(this_object());
	object ob;
	int myfeng, i;

	if( !arg || !(arg == "fengchao" || arg == "chao") ) return 0;
	if( time() < query("lastpick") + 300 )
	{
		write("这儿没有蜂巢。\n");
		return 1;
	}

	if( me->query_temp("pickchao") )
	{
		write("你一直呆在这儿把毒蜂都吓跑了，哪里来蜂巢？\n");
		return 1;
	}
	for(i = 0; i < sizeof(inv); i++ )
	{
		if( inv[i]->query("id") == "dufeng" )
		{
			myfeng++;
			inv[i]->add_temp("apply/attack", 50);
			inv[i]->add_temp("apply/damage", 50);
			COMBAT_D->do_attack(inv[i], me);
			inv[i]->add_temp("apply/attack", -50);
			inv[i]->add_temp("apply/damage", -50);
			inv[i]->kill_ob(me);
		}
	}
	if( myfeng > 0 )
	{
		write("蜂巢周围都是毒蜂，无法取下来。\n");
		return 1;
	}
	ob = new("/d/shenlong/obj/fengchao");
	ob->set("owner", me->query("id"));
	ob->move(me);
	set("lastpick", time());
	me->set_temp("pickchao", 1);
	message_vision("只见$N趁毒蜂们不在，赶紧摘下蜂巢藏在怀里\n", me);
	return 1;
}
int valid_leave(object me, string dir)
{
	if( me->query_temp("pickchao") )
	me->delete_temp("pickchao");
	return ::valid_leave(me, dir);
}

int do_get(string arg)
{
	object me, ob, weapon;
	me=this_player();

	if (arg=="cha" || arg=="all" || arg=="cha hua")
	{
		if (!objectp(ob=present("cha", environment(me))))
		{
			tell_object(me, "这里没什么好品种的茶花值得挖走。\n");
			return 1;
		}
		if (!objectp(weapon=me->query_temp("weapon"))
			|| weapon->query("id")!="huachu")
		{
			tell_object(me, "你没有称手的工具来移植这株茶花！\n");
			return 1;
		}
		if (random(2)==1)
		{
			message_vision("$N小心翼翼地用花锄掘出茶花的根，把整株茶花移了起来。\n", me);
			ob->move(me);
		}
		else
		{
			message_vision("$N急急忙忙地挖茶花，一不小心把根挖断了，好好的一株茶花，完了。\n", me);
			destruct(ob);
		}
		return 1;
	}
	return 0;
}
