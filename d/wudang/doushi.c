//Cracked by Roath
//maco
inherit ROOM;
string long_desc();

void create()
{
        set("short", "室");
	set("long", (: long_desc :));

	set("exits", ([
                "west" : __DIR__"maoshe",
        ]));

	set("objects", ([
                 "/d/jiaxing/obj/yaoqin" : 1,
                 "/d/taohua/obj/zhuxiao" : 1,
                 "/d/taohua/obj/music_book" : 2,
        ]));
        set("sleep_room", 1);
        set("no_fight", 1);
        set("cost", 1);

        setup();
}

string long_desc()
{
        string desc;

        desc  = "这是茅屋中一间室，板床木凳，俱皆简陋，四壁萧然，却是一应不染，清
幽绝俗，";

        if (present("zhu xiao", this_object()) && present("yao qin", this_object())  ){
desc += "床边竹上并列著一张瑶琴，一管竹箫。室中寂静无声。较之尘世喧嚣
，竟似到了另一世界。\n" ;
	}
	else if (present("zhu xiao", this_object())){
desc += "床边竹上放置著一管竹箫。室中寂静无声。较之尘世喧嚣，竟似到了
另一世界。\n" ;
	}
        else if (present("yao qin", this_object())){
desc += "床边竹上放置著一张瑶琴。室中寂静无声。较之尘世喧嚣，竟似到了
另一世界。\n";
	}
	else desc += "床边摆设著一张竹。室中寂静无声。较之尘世喧嚣，竟似到了另一世
界。\n";

        return desc;
}

