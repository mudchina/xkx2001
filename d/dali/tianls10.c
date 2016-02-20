//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "松木屋");
        set("long", @LONG
你走过一条长廊来到一个小院，几间木屋全以松木搭成，板门木柱，木料均
不去皮。天然质朴，和一路行来的金碧辉的殿堂截然不同。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
		"enter" : __DIR__"tianls11.c",
        "southdown" : __DIR__"tianls9.c",
        "westdown" : __DIR__"tianls8",
		]));
	set("no_clean_up", 0);

	setup();
}
