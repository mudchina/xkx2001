//Cracked by Roath
// road: /zhongnan/daolu.c

inherit ROOM;

void create()
{
        set("short","道路");

        set("long",@LONG
此处位於终南山山脚。巍峨的终南山，自古以来就是历代名人游览的
圣地。它西起甘肃的岐山，东至陕西的潼关，其间跨越十馀县，连绵八百
馀里。素有万里终南山之称。往东可看见一座寺庙。往西是一条通往密林
的幽静小路。往北可上终南山.
LONG);

		  set("exits",([ "west" : __DIR__"xiaojing1",
								"northup" : __DIR__"shanlu1",
								"south" : "/d/emei/emroad4",
								"east" : __DIR__"puguansi",
							 ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");


		  setup();


}

