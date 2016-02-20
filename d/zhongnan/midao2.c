//Cracked by Roath
// road: /zhongnan/midao2.c

inherit ROOM;

void create()
{
        set("short", "密道");

        set("long",@LONG
密道中乌漆妈黑，伸手不见五指，但只觉越走越低，湿气也越来越重
。此时已可听到淙淙水声。往南和西都是黑黑的一片。
LONG);

		  set("exits",([ "westup" : __DIR__"midao1",
								"eastdown" : __DIR__"midao3",

                      ])
           );
	  set("cost",3);
	  setup();
}

