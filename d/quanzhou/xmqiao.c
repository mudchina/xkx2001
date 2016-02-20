//Cracked by Roath
// xmqiao.c 新门吊桥
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

int exit(int);
string look_gaoshi();

void create()
{
        set("short", "新门吊桥");
	set("long", @LONG
这是泉州西面的一座吊桥，从傍着晋河而建的城楼大门上以两个滑轮维系。
日出放下吊桥，日落绞起。城楼墙上有张官府告示(gaoshi)。西出城门便是乱
石岗，经常有土匪出没，没事还是别出城的好。南面有家瓷铺。
LONG
        );

        set("objects", ([ 
		__DIR__"npc/xunbu" : 1,
        ]));

	set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
//	replace_program(ROOM);
}

void init()
{
	int t;          // time of the day in minutes
        mixed *local;

	local = localtime(time()*60);
        t = local[2]*60 + local[1];

	set("exits", (: exit :));
}

int exit(int mode)
{
	int t, t1, t2, t3; 		// time of the day in minutes
	mixed *local;
	object room, *rooms;

	local = localtime(time()*60);
        t = local[2]*60 + local[1];
	if ( !( room = find_object(__DIR__"luanshi")) )
                room = load_object(__DIR__"luanshi");

	set("exits/east", __DIR__"xinmen");
        set("exits/south", __DIR__"taoci");
	set("exits/north", __DIR__"datiepu");
	set("exits/west", __DIR__"luanshi");
	room->set("exits/east", __DIR__"xmqiao");

	if ( ( t >= 1260 && t < 1440 ) || ( t >= 0 && t < 300 ) ) {
		delete("exits/west");
		room->delete("exits/east");
	}

	rooms=({ this_object(), room});
	if ( mode == 2 ) {
		message("info", "吊桥缓缓地绞了起来。\n", rooms);
		delete("check");
	}
	else if ( mode == 1 ) {
		message("info", "吊桥缓缓地绞放下来。\n", rooms);
		delete("check");
        }
	
	t1 = t - 1260; 
	t2 = t - 300;
	
	if ( t2 > t1 && t2 < 0 ) {
		t3 = -t2;
		mode = 1;
	}
	else if ( t2 > t1 && t2 > 0 && t1 < 0 ) {
		t3 = -t1;
		mode = 2;
	}
	else { 
		t3 = 1440 - t + 300;
		mode = 1;
	}
/*	
	write( "t1 ="+t1+"\n" );
	write( "t2 ="+t2+"\n" );
	write( "t3 ="+t3+"\n" );
	write( "t ="+t+"\n" );
	write( "mode ="+mode+"\n" );	
*/
	if ( !query("check") ) {
		call_out("exit", t3, mode);
		add("check", 1);
//		write( "check ="+query("check")+"\n" );
	}

	return 1;
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n泉州都督启\n";
}
