//Cracked by Roath
// road: /zhongnan/yuanneixiaojing2.c

inherit ROOM;

void create()
{
        set("short","院内小径");

        set("long",@LONG
这全真教的後院面积颇为广大，殿宇散於山间，山上遍植松杉翠林，
泉水淙淙，环境清幽肃静，小径曲回通幽。走到宁静处，只闻枝头鸟啼，
给人一种闲适的感觉，不少弟子於山林间找寻密处，打坐练功。往北和
往西各是一条小径。
LONG);

        set("exits",([ "west" : __DIR__"yuanneixiaojing1",
                        "north" : __DIR__"yuanneixiaojing3",
                      ])
           );
	  set("cost",1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}
