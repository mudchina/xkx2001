//Cracked by Roath
// wannian1.c 万年庵砖殿
// Shan: 96/07/09

inherit ROOM;

void create()
{
        set("short", "万年庵砖殿");
	set("long", @LONG
这里是万年庵的拱顶无梁砖殿。砖殿四壁为正方形，顶为穹窿圆拱形，殿
内有普贤菩萨骑六牙白象的铜铸像一尊。拱顶无梁砖殿四壁下方，有小龛二十
四个，内各供铁铸佛像一尊。四壁上方则有横龛六道，列置铜铸小佛三百零七
个。
LONG
	);
	set("exits", ([
		"out" : __DIR__"wannian",
		"east": __DIR__"chanfang_wn",
	]));

        set("objects",([
		__DIR__"npc/wenfang" : 1,
                CLASS_D("emei") + "/jingkong" : 1,
        ]));

	set("cost", 0);
	setup();
	replace_program(ROOM);

}

