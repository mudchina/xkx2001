//Cracked by Roath
// hz_xilang2.c 华藏庵西廊
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "华藏庵西廊");
	set("long", @LONG
这里是峨嵋华藏庵西廊。走廊往南禅房，北边通往广场。
LONG
	);
	set("exits", ([
		"north" : __DIR__"hz_xilang1",
		"south" : __DIR__"hz_chanfang",
	]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
	replace_program(ROOM);

}


