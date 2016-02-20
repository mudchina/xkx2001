//Cracked by Roath
//程英的茅 by maco


inherit ROOM;

string long_desc();
string day_event(){ return NATURE_D->outdoor_room_event();}

void create()
{
        set("short", "茅");
	set("long", (: long_desc :));
	set("exits", ([
                "east" : __DIR__"doushi",
                "out" : __DIR__"kongdi",
        ]));
	set("objects", ([
                 "/kungfu/class/taohua/chengying" : 1,
        ]));
        set("cost", 1);
	set("cy_home",1);
        setup();
}
string long_desc()
{
        string desc;

        desc  = "这是茅之中，四周摆设简单，但是十分雅洁，一边桌上放著竹筷陶碗，虽
是粗器，却都是全新的，纵然一物之微，看来也均用了一番心思。东首是一间小
房间，西首一扇小窗半掩，";

        if (day_event() == "event_night" || day_event() == "event_midnight"){
desc += "月光淡淡，从窗中照射进来，铺在地下。\n" ;
	}
	else if (day_event() == "event_evening"){
desc += "一抹残阳自窗中照射进来，已是黄昏时分。\n" ;
	}
        else {
desc += "阳光从窗中照射进来，照得地上方寸之地一片明亮。\n";
	}
        return desc;
}

