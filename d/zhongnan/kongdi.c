//Cracked by Roath

// road: /zhongnan/kongdi.c

inherit ROOM;

void create()
{
        set("short","空地");

        set("long",@LONG
这是终南山山腰处的一块空地，地势平坦。北面一条小路直攀山璧而
上，通往是终南山主峰。南边和西边一大片密林，只闻阵阵琴声自林中传
出。往北是一条山路。往南和西各有一条小径。
LONG);

        set("exits",([ "northup" : __DIR__"shanlu12",
                        "west" : __DIR__"milin1",
				"south" : __DIR__"milin2",
                      ])
           );
	  set("cost",1);
	  set("outdoors", "zhongnan");

        setup();
        replace_program(ROOM);
}

