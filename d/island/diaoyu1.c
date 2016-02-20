//Cracked by Roath
// Jay 5/11/97

inherit ROOM;

void create()
{
        set("short", "通吃岛");
	set("long", @LONG
这里是一块礁石，当年韦小宝曾在此垂钓。由于他一家人走得匆忙，一
些生活用品便留在岛上，成了历史的见证。
LONG
        );

        set("exits", ([ 
		"south" : __DIR__"diaoyu",
	]));

        set("objects", ([ 
	        "/d/quanzhou/obj/beauty-book" : 1,
	        "/d/quanzhou/obj/touzi" : 1,
		"/d/dali/obj/diaogan" : 1,
        ]));

	set("cost", 1);
	set("outdoors", "island");
        setup();
        replace_program(ROOM);

}
