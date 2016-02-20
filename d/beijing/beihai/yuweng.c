//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "玉瓮亭");
	set("long", @LONG
这里是殿之正南的一座石亭，内置元代玉瓮。此玉瓮通体晶莹剔透，
为一整块墨玉雕刻而出。玉质如此之美，体积如此之大，实是不可多得
之物。却不知道这玉瓮是用来做什么的。
LONG
	);
	set("cost", 2);
        
	 
	set("exits", ([
                "north" : __DIR__"chengguang",
        ]));
	
	
	setup();
	replace_program(ROOM);
}

