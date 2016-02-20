//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "濠濮间");
	set("long", @LONG
东岸之濠濮涧，为三间水榭。北邻画舫斋，东北有迭砌玲珑的山石环绕。
在嶙峋山石间有一泓池水，池中有敞轩、曲桥、回旋变化于咫尺之内，颇具
自然之趣。
LONG
	);
	set("cost", 2);
	set("exits", ([
                "northwest" : __DIR__"huafang",
             ]));
	
	
	setup();
	replace_program(ROOM);
}
