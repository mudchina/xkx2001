//Cracked by Roath
// cliff.c 舍身崖下
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "舍身崖下");
	set("long", @LONG

你掉下舍身崖，身体一直往下落。没救了，你不禁大叫：啊¨¨¨

LONG
	);

//        set("outdoors", "emei" );

	set("cost", 1);
	setup();
	replace_program(ROOM);

}
