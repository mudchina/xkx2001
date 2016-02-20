//Cracked by Roath
//room: dating.c
inherit ROOM;

void create()
{
        set("short","教主大厅");
        set("long", @LONG
走进这里，突感一阵肃穆之意，大厅中十分空旷，厅顶高悬八盏
金灯，两旁是精壮佩剑武士剑气森严逼人。正中设一宝座，前有一雕
花檀木案。教主殷天正常在这里与教中首脑人物议事。
LONG
           );

	set("exits",([
		"south" : __DIR__"zoulang8",
		"west" : __DIR__"xiangfang3",
		"east" : __DIR__"shufang",
        ]));

        setup();
	replace_program(ROOM);
}
