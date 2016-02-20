//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "永安寺");
	set("long", @LONG
这里是永安寺，历史已经很悠久了。由永安寺北上就可以到达白塔。永安寺南是
一座石桥，名永安石桥，是连接白塔山和团城的通道。
LONG
	);
	set("cost", 2);
	
      
	 
	set("exits", ([
                "northup" : __DIR__"baita",
                "south" : __DIR__"yonganqiao",
                "west" : __DIR__"yuexin",
                "northeast" : __DIR__"zhizhu",
                ]));
	
	
	setup();
	replace_program(ROOM);
}
