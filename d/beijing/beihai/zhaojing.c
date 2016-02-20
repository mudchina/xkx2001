//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "昭景门");
	set("long", @LONG
团城为一高台，圆形，台高4.6米，周长276米。城之两掖有门，东曰昭景，
西曰衍祥，入门有蹬道。这里就是团城的昭景门。门口有几个人在扫地。
LONG
	);
	set("cost", 2);
        
	 
	set("exits", ([
                "west" : __DIR__"chengguang",
                "northeast" : __DIR__"qianmen",
                "north" : __DIR__"yonganqiao",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
