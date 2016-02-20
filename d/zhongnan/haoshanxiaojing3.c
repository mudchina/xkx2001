//Cracked by Roath

// road: /zhongnan/haoshanxiaojing3.c

inherit ROOM;

void create()
{
        set("short","後山小径");

        set("long",@LONG
这後山小路蜿蜒於终南山区中，也不知通往何处。只见浓荫蔽天，越
走越是阴森，越行越是荒凉，不时还有野兽吼声传来，令人心中发毛。往
北北和东南各是一条阴森森的小径。
LONG);

	  set("exits",([ "northeast" : __DIR__"haoshanxiaojing2",
								"southeast" : __DIR__"haoshanxiaojing4",
							 ])
			  );
	  set("outdoors", "zhongnan");

	  setup();
}

