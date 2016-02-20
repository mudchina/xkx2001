//Cracked by Roath
// road: /zhongnan/foyezhen.c

inherit ROOM;

void create()
{
        set("short","佛爷掌");

        set("long",@LONG
只见此处颇为荒凉，是一处寺院的遗址。四周青松翠柏环绕，寺院的
断垣残璧依稀可见，似乎还是一座不小的寺院。往北是一片平原。
LONG);

		  set("exits",([ "east" : __DIR__"shenheyuan",
							 ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");

		  setup();

}
