//Cracked by Roath
// Dong 1/9/98
// modifiedy by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "礁石");
    	set("long", @LONG
岛的这一边风光就差多了，到处都是嶙峋的礁石，阴森森的，尤
其到了夜间，漆黑中鱼类的尸体散射出荧火，四下里奕奕发光，你还
是快点离开这里吧。
LONG
    	);

    	set("exits", ([
		       "northwest" : __DIR__"shatann3",
		       "south" : __DIR__"jiaoshi2",
		       "west": __DIR__"xiaolu3",
		       ]));
    	set("outdoors", "xiakedao");
        set("objects", ([ 
			 "/d/city/obj/stone" : 2
	]));
    	setup();
}


