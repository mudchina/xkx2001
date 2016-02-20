//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "永安石桥");
	set("long", @LONG
永安桥在永安寺南，又名“堆云积翠桥”。三孔券洞，曲尺形，桥面铺条石，坡度
平缓。桥身两侧有雕刻精美的栏板和望柱。桥南北分别置立四柱三楼式木牌坊一座，
绿筒瓦顶，朱红色圆柱，色彩鲜艳夺目。
LONG
	);
	set("cost", 2);
	
      
	 
	set("exits", ([
                "north" : __DIR__"yongansi",
                "south" : __DIR__"zhaojing",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
