//Cracked by Roath
// road: /zhongnan/water1.c

inherit ROOM;

void create()
{
        set("short", "地下水道");

        set("long",@LONG
	在地下潜流中,你只觉得水声轰轰,身子不由自主的被强大的水流向前
推送.
LONG);

        set("exits",([ "westup" : __DIR__"midao3",
                        "east" : __DIR__"water2",

                      ])
           );
	  set("cost",5);

		  setup();
}
