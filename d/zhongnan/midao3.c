//Cracked by Roath
// road: /zhongnan/midao3.c

inherit ROOM;

void create()
{
        set("short", "密道");

        set("long",@LONG
密道中乌漆妈黑，伸手不见五指，水面已升到了膝盖，并且不断上升
，渐与胸齐。你只觉得一股暗流把你往水里拉，再往东走可能就要淹死了。
往北是黑黑的一片。往东就要进入水里了。
LONG);

		  set("exits",([ "westup" : __DIR__"midao2",
								"eastdown" : __DIR__"water1",

							 ])
			  );
	  set("cost",3);

	  setup();
}


