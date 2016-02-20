//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "阅古楼");
	set("long", @LONG
阅古楼平面为一马蹄形，有廊二十五楹，左右围抱。内有蟠龙升天式楼梯。
壁砌三希堂法帖(tie)石刻。山坡上点缀假山、庭阁，高下曲折有致，如亩鉴室、
烟云尽态亭、水精域、甘露殿、蟠青室、揖山亭等。
LONG
	);
	set("cost", 2);
        set("item_desc", ([
	"tie" : "王羲之《快雪时晴帖》，王献之《中秋帖》，王徇《迫远帖》\n",
	    ]));
   
	set("exits", ([
                "northeast" : __DIR__"yilan",
                "southup" : __DIR__"qingxiao",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
