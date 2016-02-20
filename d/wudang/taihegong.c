//Cracked by Roath
// taihegong.c 太和宫玄帝殿 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "太和宫玄帝殿");
	set("long", @LONG
	玄帝殿阔五尺，高一丈八尺，精铜所铸，镀以黄金，制作精巧，美仑美奂
。殿中供着玄天真武上帝的金身和水火二将及金童玉女的雕像，与殿座连成一体。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"jinding",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

