//Cracked by Roath

inherit ROOM;

void create()
{
        set("short", "报国寺西墙");
	set("long", @LONG
这里是峨眉山报国寺的西墙。寺院里的钟声从墙那边飘来，在空气中回
响。一条山溪从西面山上的解脱桥下流经这里，向山下淌去。
LONG
	);
	set("exits", ([
		"east" : __DIR__"baoguo",
	]));


        set("outdoors", "emei" );

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

