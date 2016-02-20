//Cracked by Roath
//GU MU FROM SANTA
//chaoyin.C

inherit ROOM;

void create()
{
	set("short", "朝英练功室");
	set("long", @LONG
这是古墓派创派主师林朝英钻研武学的所在，和王重阳的那一间
处处对称，而又处处相反，乃是後窄前宽，西圆东角。
LONG
	);
	 set("exits", ([
		"north" : __DIR__"linn",
		"south" : __DIR__"lins",
		"east"  : __DIR__"line",
		"west"  : __DIR__"linw",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}





