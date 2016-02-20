//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "石桥");
	set("long", @LONG
只是一座小石桥，连接了漪澜堂和智珠殿。桥虽然不大，却非常精美。桥栏上
雕刻了许多花草动物，栩栩如生。
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "northwest" : __DIR__"yilan",
                "southup" : __DIR__"zhizhu",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
