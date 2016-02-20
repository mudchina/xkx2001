//Cracked by Roath
// road: /zhongnan/yuanneixiaojing3.c

inherit ROOM;

void create()
{
        set("short","院内小径");

        set("long",@LONG
	这全真教的後院面积颇为广大，殿宇散於山间，山上遍植松杉翠林，
泉水淙淙，环境清幽肃静，小径曲回通幽。走到宁静处，只闻枝头鸟啼，给
人一种闲适的感觉，不少弟子於山林间找寻密处，打坐练功。往北是一座三
层高的楼阁。往南是一条小径。
            
LONG);

        set("exits",([ "north" : __DIR__"jingge",
                        "south" : __DIR__"yuanneixiaojing2",
                      ])
           );
	  set("cost",1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
