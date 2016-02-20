//Cracked by Roath
// road: /zhongnan/river.c

inherit ROOM;

void create()
{
		  set("short", "小河边");

		  set("long",@LONG
此处位於终南山角一偏僻处，只见浓荫匝地，花光浮动，周围尽是叁
天古木，颇具幽静之美。不远处的小河由山洞(dong)中涌出的泉水所形成，
淙淙的水声更让你觉得身心顺畅。往北可通往山林深处。往西可进入山洞
中。
LONG);

		  set("exits",([ "enter" : __DIR__"dong",
								"north" : __DIR__"xiaojing1",
							 ]));

	  set("item_desc",(["dong" : "
	小洞里黑幽幽的，一股泉水自里面流出，不知通往何处。
\n",]));

	  set("cost",2);
	  set("outdoors", "zhongnan");

		  setup();
	  set("outdoors","zhongnan");

		  replace_program(ROOM);
}

