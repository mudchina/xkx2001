//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "画舫斋");
	set("long", @LONG
濠濮涧北之画舫斋，又称水殿。为一环绕方形游泳池对称布置之庭院，四面
迥廊相通。建筑坐北朝南，以池水为中心，南为春雨林塘殿，东西分别是镜香，
观妙室，四面厅廊回抱，构成一处幽胜的庭院。古柯庭前有一粗壮繁茂的古槐，
相传已有千年，庭因名古柯。
LONG
	);
	set("cost", 2);
	
     
	set("exits", ([
                "southwest" : __DIR__"dongmen",
                "north" : __DIR__"houmen",
                "southeast" : __DIR__"haopu",
                ]));
	
	
	setup();
	replace_program(ROOM);
}
