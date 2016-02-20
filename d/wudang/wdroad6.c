//Cracked by Roath
// wdroad6.c 黄土路
// by Xiang

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里是湖北境界，
据说经常有土匪出没，不可久留。向东南去可至湖南。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"caodian",
		"northwest" : "/d/emei/emroad3",
		"south" : __DIR__"wdroad7",
		"southeast" : "/d/foshan/road1",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

