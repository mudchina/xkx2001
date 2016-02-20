//Cracked by Roath
// xiakedao/yucun1.c

inherit ROOM;

void create()
{
        set("short", "小鱼村");
        set("long", @LONG
这个小鱼村里只有十来户人家，每家每户的门前都晒着网和鱼干。
村子中间的平地上停着一条破船。小村子後面就是大海了。
LONG );

      set("exits", ([
		"north" : "/d/quanzhou/gangkou4",
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("objects", ([ 
	    __DIR__ + "npc/helper" : 1,
      ]));
      set("no_clean_up", 1);
	setup();
	replace_program(ROOM);
}




