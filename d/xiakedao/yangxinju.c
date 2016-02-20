//Cracked by Roath
// xiakedao/yangxinju.c 养心居
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "养心居");
        set("long", @LONG
这间小室中充满了草药味，细看时发现墙角边有不少药箱，里面
装满了草药。小室正中是一张方桌，桌后坐了一位老者。
LONG );

	set("exits", ([
		       "south" : __DIR__"yongdao4",
		       ]));

	set("indoors", "xiakedao" );
        set("no_fight", 1);

	set("cost", 0);
    	set("objects", ([ 
		__DIR__ +"npc/doctor" : 1, 
    	]));

	set("no_clean_up", 1);
	setup();
}

